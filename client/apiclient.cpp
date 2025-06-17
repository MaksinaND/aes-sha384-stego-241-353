#include "apiclient.h"

ApiClient* ApiClient::instance = nullptr;

ApiClient::ApiClient(QObject *parent)
    : QObject(parent)
    , socket(new QTcpSocket(this))
    , m_lastSentEndpoint("")
{
    connect(socket, &QTcpSocket::connected, this, &ApiClient::onConnected);
    connect(socket, &QTcpSocket::readyRead, this, &ApiClient::onReadyRead);
    connect(socket, &QTcpSocket::disconnected, this, &ApiClient::onDisconnected);
    connect(socket, &QTcpSocket::errorOccurred, this, &ApiClient::onError);
}

ApiClient* ApiClient::getInstance()
{
    if (!instance) {
        instance = new ApiClient();
    }
    return instance;
}

void ApiClient::connectToServer(const QString &host, quint16 port)
{
    if (socket->state() == QAbstractSocket::ConnectedState) {
        qDebug() << "Уже подключен к серверу";
        return;
    }

    qDebug() << "Подключение к серверу" << host << ":" << port;
    socket->connectToHost(host, port);
}

void ApiClient::disconnectFromServer()
{
    if (socket->state() == QAbstractSocket::ConnectedState) {
        socket->disconnectFromHost();
    }
}

bool ApiClient::isConnected() const
{
    return socket->state() == QAbstractSocket::ConnectedState;
}

void ApiClient::aesEncrypt(const QByteArray &key, const QByteArray &plaintext)
{
    QJsonObject data;
    data["key"] = toBase64(key);
    data["plaintext"] = toBase64(plaintext);
    sendRequest("/aes/encrypt", data);
}

void ApiClient::aesDecrypt(const QByteArray &key, const QString &ciphertext)
{
    QJsonObject data;
    data["key"] = toBase64(key);
    data["ciphertext"] = ciphertext;
    sendRequest("/aes/decrypt", data);
}

void ApiClient::stegoEmbed(const QImage &image, const QString &message)
{
    QJsonObject data;
    data["image"] = imageToBase64(image);
    data["message"] = message;
    sendRequest("/stego/embed", data);
}

void ApiClient::stegoExtract(const QImage &image)
{
    QJsonObject data;
    data["image"] = imageToBase64(image);
    sendRequest("/stego/extract", data);
}

void ApiClient::stegoHasMessage(const QImage &image)
{
    QJsonObject data;
    data["image"] = imageToBase64(image);
    sendRequest("/stego/has_message", data);
}

void ApiClient::sha384Hash(const QByteArray &data)
{
    QJsonObject requestData;
    requestData["data"] = toBase64(data);
    sendRequest("/sha384/hash", requestData);
}

void ApiClient::onConnected()
{
    qDebug() << "Подключен к серверу";
}

void ApiClient::onReadyRead()
{
    buffer.append(socket->readAll());

    while (true) {
        int newlineIndex = buffer.indexOf("\n");
        if (newlineIndex == -1) {
            // No complete JSON object yet, wait for more data
            break;
        }

        QByteArray jsonData = buffer.left(newlineIndex).trimmed();
        qDebug() << "Raw JSON data from buffer:" << QString::fromUtf8(jsonData);
        QJsonParseError parseError;
        QJsonDocument responseDoc = QJsonDocument::fromJson(jsonData, &parseError);

        if (parseError.error == QJsonParseError::NoError) {
            // Successfully parsed a complete JSON object
            QJsonObject response = responseDoc.object();
            QString status = response["status"].toString();
            QJsonObject result = response["result"].toObject();
            QString error = response["error"].toString();

            bool success = (status == "success");
            // Use the stored endpoint from the last request
            QString currentEndpoint = m_lastSentEndpoint;
            qDebug() << "Endpoint used for response:" << currentEndpoint;
            qDebug() << "Full response object:" << response;

            emit responseReceived(currentEndpoint, success, result, error);

            // Remove the parsed JSON (and the newline) from the buffer
            buffer.remove(0, newlineIndex + 1);
        } else {
            // Error parsing JSON, clear buffer and report error
            qDebug() << "Ошибка парсинга JSON ответа: " << parseError.errorString();
            emit responseReceived("", false, QJsonObject(), "Ошибка парсинга JSON: " + parseError.errorString());
            buffer.clear();
            break;
        }
    }
}

void ApiClient::onDisconnected()
{
    qDebug() << "Отключен от сервера";
}

void ApiClient::onError(QAbstractSocket::SocketError /*error*/)
{
    qDebug() << "Ошибка сокета:" << socket->errorString();
    emit responseReceived("", false, QJsonObject(), "Ошибка сокета: " + socket->errorString());
}

void ApiClient::sendRequest(const QString &endpoint, const QJsonObject &data)
{
    if (!isConnected()) {
        qDebug() << "Не подключен к серверу";
        emit responseReceived(endpoint, false, QJsonObject(), "Не подключен к серверу");
        return;
    }

    // Store the endpoint before sending the request
    m_lastSentEndpoint = endpoint;

    QJsonObject request;
    request["endpoint"] = endpoint;
    request["data"] = data;

    QJsonDocument requestDoc(request);
    QByteArray requestData = requestDoc.toJson(QJsonDocument::Compact);
    
    qDebug() << "Отправляем запрос:" << QString::fromUtf8(requestData);
    
    socket->write(requestData + "\n");
    socket->flush();
}

QString ApiClient::toBase64(const QByteArray &data)
{
    return data.toBase64();
}

QByteArray ApiClient::fromBase64(const QString &base64)
{
    return QByteArray::fromBase64(base64.toUtf8());
}

QString ApiClient::imageToBase64(const QImage &image)
{
    QByteArray byteArray;
    QBuffer buffer(&byteArray);
    buffer.open(QIODevice::WriteOnly);
    
    if (!image.save(&buffer, "PNG")) {
        qDebug() << "Ошибка сохранения изображения в буфер";
        return QString();
    }
    
    return byteArray.toBase64();
}

QImage ApiClient::imageFromBase64(const QString &base64)
{
    QByteArray imageData = QByteArray::fromBase64(base64.toUtf8());
    QImage image;
    
    if (!image.loadFromData(imageData)) {
        qDebug() << "Ошибка загрузки изображения из Base64";
        return QImage();
    }
    
    return image;
}




void ApiClient::registerUser(const QString& username, const QString& password)
{
    QJsonObject data;
    data["username"] = username;
    data["password"] = password;
    sendRequest("/user/register", data);
}

void ApiClient::loginUser(const QString& username, const QString& password)
{
    QJsonObject data;
    data["username"] = username;
    data["password"] = password;
    sendRequest("/user/login", data);
}

void ApiClient::sendMessage(const QString& sender, const QString& receiver, const QString& message)
{
    QJsonObject data;
    data["sender"] = sender;
    data["receiver"] = receiver;
    data["message"] = message;
    sendRequest("/message/send", data);
}

void ApiClient::getMessages(const QString& username)
{
    QJsonObject data;
    data["username"] = username;
    sendRequest("/message/get", data);
}


