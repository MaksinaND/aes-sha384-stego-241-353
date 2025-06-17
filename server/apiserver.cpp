#include "apiserver.h"
#include <QBuffer>
#include <QImageReader>
#include <QImageWriter>
#include <QSqlDatabase>
#include <QSqlQuery>
#include <QSqlError>
#include "databasemanager.h"

ApiServer::ApiServer(QObject *parent)
    : QObject(parent),
      tcpServer(new QTcpServer(this)),
      aes(new AES(this)),
      steganography(new Steganography(this)),
      sha384(new SHA384(this)),
      chordMethod(new ChordMethod(this)),
      dbManager(DatabaseManager::getInstance())
{
    connect(tcpServer, &QTcpServer::newConnection, this, &ApiServer::onNewConnection);
}

bool ApiServer::startServer(quint16 port)
{
    if (!tcpServer->listen(QHostAddress::Any, port)) {
        qDebug() << "Ошибка запуска сервера:" << tcpServer->errorString();
        return false;
    }
    
    qDebug() << "Сервер запущен на порту" << port;
    return true;
}

void ApiServer::stopServer()
{
    tcpServer->close();
    qDebug() << "Сервер остановлен";
}

void ApiServer::onNewConnection()
{
    QTcpSocket *clientSocket = tcpServer->nextPendingConnection();
    connect(clientSocket, &QTcpSocket::readyRead, this, &ApiServer::onReadyRead);
    connect(clientSocket, &QTcpSocket::disconnected, this, &ApiServer::onClientDisconnected);
    
    qDebug() << "Новое подключение от" << clientSocket->peerAddress().toString();
}

void ApiServer::onReadyRead()
{
    QTcpSocket *clientSocket = qobject_cast<QTcpSocket*>(sender());
    if (!clientSocket) return;

    buffer.append(clientSocket->readAll());

    while (buffer.contains('\n')) {
        int newlineIndex = buffer.indexOf('\n');
        QByteArray jsonData = buffer.left(newlineIndex).trimmed();
        buffer.remove(0, newlineIndex + 1);

        if (jsonData.isEmpty()) continue;

        QString requestStr = QString::fromUtf8(jsonData);
        qDebug() << "Получен запрос:" << requestStr;

        QJsonParseError parseError;
        QJsonDocument requestDoc = QJsonDocument::fromJson(jsonData, &parseError);
        
        QJsonObject response;
        if (parseError.error != QJsonParseError::NoError) {
            response = createErrorResponse("Ошибка парсинга JSON: " + parseError.errorString());
        } else {
            response = processRequest(requestDoc.object());
        }

        QJsonDocument responseDoc(response);
        QByteArray responseData = responseDoc.toJson(QJsonDocument::Compact);
        
        qDebug() << "Отправляем ответ:" << QString::fromUtf8(responseData);
        
        clientSocket->write(responseData + "\n");
        clientSocket->flush();
    }
}

void ApiServer::onClientDisconnected()
{
    QTcpSocket *clientSocket = qobject_cast<QTcpSocket*>(sender());
    if (clientSocket) {
        qDebug() << "Клиент отключился:" << clientSocket->peerAddress().toString();
        clientSocket->deleteLater();
    }
}

QJsonObject ApiServer::processRequest(const QJsonObject &request)
{
    QString endpoint = request["endpoint"].toString();
    QJsonObject data = request["data"].toObject();

    if (endpoint.startsWith("/aes")) {
        return handleAesRequest(endpoint, data);
    } else if (endpoint.startsWith("/stego")) {
        return handleStegoRequest(endpoint, data);
    } else if (endpoint.startsWith("/sha384")) {
        return handleSha384Request(endpoint, data);
    } else if (endpoint.startsWith("/chord_method")) {
        return handleChordMethodRequest(endpoint, data);
    } else if (endpoint.startsWith("/user")) {
        return handleUserRequest(endpoint, data);
    } else if (endpoint.startsWith("/message")) {
        return handleMessageRequest(endpoint, data);
    } else {
        return createErrorResponse("Unknown endpoint");
    }
}

QJsonObject ApiServer::handleAesRequest(const QString &endpoint, const QJsonObject &data)
{
    if (endpoint == "/aes/encrypt") {
        QString keyBase64 = data["key"].toString();
        QString plaintextBase64 = data["plaintext"].toString();
        
        if (keyBase64.isEmpty() || plaintextBase64.isEmpty()) {
            return createErrorResponse("Отсутствуют обязательные параметры: key, plaintext");
        }

        QByteArray key = fromBase64(keyBase64);
        QByteArray plaintext = fromBase64(plaintextBase64);

        if (!aes->setKey(key)) {
            return createErrorResponse("Ошибка установки ключа: " + aes->lastError());
        }

        QByteArray ciphertext = aes->encrypt(plaintext);
        if (ciphertext.isEmpty()) {
            return createErrorResponse("Ошибка шифрования: " + aes->lastError());
        }

        QJsonObject result;
        result["ciphertext"] = toBase64(ciphertext);
        return createSuccessResponse(result);

    } else if (endpoint == "/aes/decrypt") {
        QString keyBase64 = data["key"].toString();
        QString ciphertextBase64 = data["ciphertext"].toString();
        
        if (keyBase64.isEmpty() || ciphertextBase64.isEmpty()) {
            return createErrorResponse("Отсутствуют обязательные параметры: key, ciphertext");
        }

        QByteArray key = fromBase64(keyBase64);
        QByteArray ciphertext = fromBase64(ciphertextBase64);

        if (!aes->setKey(key)) {
            return createErrorResponse("Ошибка установки ключа: " + aes->lastError());
        }

        QByteArray plaintext = aes->decrypt(ciphertext);
        if (plaintext.isEmpty()) {
            return createErrorResponse("Ошибка дешифрования: " + aes->lastError());
        }

        QJsonObject result;
        result["plaintext"] = QString::fromUtf8(plaintext);
        return createSuccessResponse(result);

    } else {
        return createErrorResponse("Неизвестная AES конечная точка: " + endpoint);
    }
}

QJsonObject ApiServer::handleStegoRequest(const QString &endpoint, const QJsonObject &data)
{
    if (endpoint == "/stego/embed") {
        QString imageBase64 = data["image"].toString();
        QString message = data["message"].toString();
        
        if (imageBase64.isEmpty() || message.isEmpty()) {
            return createErrorResponse("Отсутствуют обязательные параметры: image, message");
        }

        QImage image = imageFromBase64(imageBase64);
        if (image.isNull()) {
            return createErrorResponse("Ошибка загрузки изображения");
        }

        QImage embeddedImage = steganography->embedMessage(image, message);
        if (embeddedImage.isNull()) {
            return createErrorResponse("Ошибка внедрения сообщения: " + steganography->lastError());
        }

        QJsonObject result;
        result["embedded_image"] = imageToBase64(embeddedImage);
        return createSuccessResponse(result);

    } else if (endpoint == "/stego/extract") {
        QString imageBase64 = data["image"].toString();
        
        if (imageBase64.isEmpty()) {
            return createErrorResponse("Отсутствует обязательный параметр: image");
        }

        QImage image = imageFromBase64(imageBase64);
        if (image.isNull()) {
            return createErrorResponse("Ошибка загрузки изображения");
        }

        QString extractedMessage = steganography->extractMessage(image);
        if (extractedMessage.isEmpty() && !steganography->lastError().isEmpty()) {
            return createErrorResponse("Ошибка извлечения сообщения: " + steganography->lastError());
        }

        QJsonObject result;
        result["message"] = extractedMessage;
        return createSuccessResponse(result);

    } else if (endpoint == "/stego/has_message") {
        QString imageBase64 = data["image"].toString();
        
        if (imageBase64.isEmpty()) {
            return createErrorResponse("Отсутствует обязательный параметр: image");
        }

        QImage image = imageFromBase64(imageBase64);
        if (image.isNull()) {
            return createErrorResponse("Ошибка загрузки изображения");
        }

        bool hasMessage = steganography->hasEmbeddedMessage(image);

        QJsonObject result;
        result["has_message"] = hasMessage;
        return createSuccessResponse(result);

    } else {
        return createErrorResponse("Неизвестная Steganography конечная точка: " + endpoint);
    }
}

QJsonObject ApiServer::handleSha384Request(const QString &endpoint, const QJsonObject &data)
{
    if (endpoint == "/sha384/hash") {
        QString dataBase64 = data["data"].toString();
        
        if (dataBase64.isEmpty()) {
            return createErrorResponse("Отсутствует обязательный параметр: data");
        }

        QByteArray inputData = fromBase64(dataBase64);
        QString hash = sha384->hashToHex(inputData);
        
        if (hash.isEmpty()) {
            return createErrorResponse("Ошибка хеширования: " + sha384->lastError());
        }

        QJsonObject result;
        result["hash"] = hash;
        return createSuccessResponse(result);

    } else {
        return createErrorResponse("Неизвестная SHA384 конечная точка: " + endpoint);
    }
}

QJsonObject ApiServer::createSuccessResponse(const QJsonObject &result)
{
    QJsonObject response;
    response["status"] = "success";
    response["result"] = result;
    response["error"] = "";
    return response;
}

QJsonObject ApiServer::createErrorResponse(const QString &error)
{
    QJsonObject response;
    response["status"] = "error";
    response["result"] = QJsonObject();
    response["error"] = error;
    return response;
}

QString ApiServer::toBase64(const QByteArray &data)
{
    return data.toBase64();
}

QByteArray ApiServer::fromBase64(const QString &base64)
{
    return QByteArray::fromBase64(base64.toUtf8());
}

QString ApiServer::imageToBase64(const QImage &image)
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

QImage ApiServer::imageFromBase64(const QString &base64)
{
    QByteArray imageData = QByteArray::fromBase64(base64.toUtf8());
    QImage image;
    
    if (!image.loadFromData(imageData)) {
        qDebug() << "Ошибка загрузки изображения из Base64";
        return QImage();
    }
    
    return image;
}



QJsonObject ApiServer::handleChordMethodRequest(const QString &endpoint, const QJsonObject &data)
{
    if (endpoint == "/chord_method/solve") {
        QString functionName = data["function"].toString();
        double a = data["a"].toDouble();
        double b = data["b"].toDouble();
        double epsilon = data["epsilon"].toDouble();
        int maxIterations = data["max_iterations"].toInt();

        if (functionName.isEmpty()) {
            return createErrorResponse("Отсутствует обязательный параметр: function");
        }

        QString errorMessage;
        QPair<double, int> resultPair = chordMethod->solve(functionName, a, b, epsilon, maxIterations, errorMessage);

        QJsonObject result;
        if (qIsNaN(resultPair.first) || qIsInf(resultPair.first)) {
            result["root"] = QJsonValue::Null;
        } else {
            result["root"] = resultPair.first;
        }
        result["iterations"] = resultPair.second;
        result["message"] = errorMessage;

        qDebug() << "Chord Method Result:" << result;
        return createSuccessResponse(result);

    } else {
        return createErrorResponse("Неизвестная Chord Method конечная точка: " + endpoint);
    }
}




QJsonObject ApiServer::handleUserRequest(const QString &endpoint, const QJsonObject &data)
{
    if (endpoint == "/user/register") {
        QString username = data["username"].toString();
        QString password = data["password"].toString();
        if (dbManager->registerUser(username, password)) {
            return createSuccessResponse({{"message", "User registered successfully"}});
        } else {
            return createErrorResponse("User registration failed");
        }
    } else if (endpoint == "/user/login") {
        QString username = data["username"].toString();
        QString password = data["password"].toString();
        if (dbManager->loginUser(username, password)) {
            return createSuccessResponse({{"message", "User logged in successfully"}});
        } else {
            return createErrorResponse("Invalid username or password");
        }
    }
    return createErrorResponse("Invalid User endpoint");
}

QJsonObject ApiServer::handleMessageRequest(const QString &endpoint, const QJsonObject &data)
{
    if (endpoint == "/message/send") {
        QString sender = data["sender"].toString();
        QString receiver = data["receiver"].toString();
        QString message = data["message"].toString();
        if (dbManager->sendMessage(sender, receiver, message)) {
            return createSuccessResponse({{"message", "Message sent successfully"}});
        } else {
            return createErrorResponse("Failed to send message");
        }
    } else if (endpoint == "/message/get") {
        QString username = data["username"].toString();
        QJsonArray messagesArray;
        QVector<QPair<QString, QString>> messages = dbManager->getMessages(username);
        for (const auto &msg : messages) {
            messagesArray.append(QJsonObject{{"sender", msg.first}, {"message", msg.second}});
        }
        QJsonObject resultObject;
        resultObject["messages"] = messagesArray;
        return createSuccessResponse(resultObject);
    }
    return createErrorResponse("Invalid Message endpoint");
}


