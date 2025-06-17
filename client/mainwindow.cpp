/**
 * @file mainwindow.cpp
 * @brief Реализация MainWindow - главного окна GUI приложения с вкладками
 * @date 2025
 */

#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "myclient.h"
#include <QFileDialog>
#include <QMessageBox>
#include <QPixmap>
#include <QBuffer>
#include <QImageReader>
#include <QImageWriter>
#include <QDebug>
#include <QCoreApplication>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    setWindowTitle("Стеганография");
    
    // Подключаемся к серверу
    ApiClient::getInstance()->connectToServer();
    
    // Подключаем сигналы к слотам
    connect(ui->btnEmbed, &QPushButton::clicked, this, &MainWindow::onEmbedMessageClicked);
    connect(ui->btnExtract, &QPushButton::clicked, this, &MainWindow::onExtractMessageClicked);
    connect(ui->btnSelectImageEmbed, &QPushButton::clicked, this, &MainWindow::onSelectImageForEmbedClicked);
    connect(ui->btnSelectImageExtract, &QPushButton::clicked, this, &MainWindow::onSelectImageForExtractClicked);
    connect(ui->btnSaveImage, &QPushButton::clicked, this, &MainWindow::onSaveImageClicked);
    connect(ui->tabWidget, &QTabWidget::currentChanged, this, &MainWindow::onTabChanged);

    // Подключаем сигналы для новых вкладок
    connect(ui->btnEncryptAes, &QPushButton::clicked, this, &MainWindow::onEncryptAesClicked);
    connect(ui->btnDecryptAes, &QPushButton::clicked, this, &MainWindow::onDecryptAesClicked);
    connect(ui->btnHashSha384, &QPushButton::clicked, this, &MainWindow::onHashSha384Clicked);
    connect(ui->btnSolve, &QPushButton::clicked, this, &MainWindow::onSolveChordMethodClicked);
    connect(ui->btnClear, &QPushButton::clicked, this, &MainWindow::onClearChordMethodClicked);

    // Настраиваем начальное состояние интерфейса
    ui->btnSaveImage->setEnabled(false);
    
    // Подключаем сигнал от API клиента для получения ответов от сервера
    connect(ApiClient::getInstance(), &ApiClient::responseReceived, this, &MainWindow::onApiResponse);

    qDebug() << "MainWindow setup complete. ui->textResult object name:" << ui->textResult->objectName();
}

MainWindow::~MainWindow() {
    delete ui;
}

void MainWindow::onEmbedMessageClicked() {
    // Проверяем, выбрано ли изображение
    if (m_originalImage.isNull()) {
        QMessageBox::warning(this, "Ошибка", "Сначала выберите изображение");
        return;
    }
    
    // Получаем сообщение
    QString message = ui->editEmbedMessage->text().trimmed();
    
    // Проверяем, что сообщение не пустое
    if (message.isEmpty()) {
        QMessageBox::warning(this, "Ошибка", "Введите сообщение для внедрения");
        return;
    }
    
    // Отправляем запрос на сервер для внедрения сообщения
    ApiClient::getInstance()->stegoEmbed(m_originalImage, message);
    
    appendToOutput("> Отправлен запрос на внедрение сообщения...");
    
    // Очищаем поле ввода сообщения
    ui->editEmbedMessage->clear();
}

void MainWindow::onExtractMessageClicked() {
    // Проверяем, выбрано ли изображение
    if (m_originalImage.isNull()) {
        QMessageBox::warning(this, "Ошибка", "Сначала выберите изображение");
        return;
    }
    
    // Отправляем запрос на сервер для извлечения сообщения
    ApiClient::getInstance()->stegoExtract(m_originalImage);
    
    appendToOutput("> Отправлен запрос на извлечение сообщения...");
}

void MainWindow::onSelectImageForEmbedClicked() {
    // Открываем диалог выбора файла
    QString filePath = QFileDialog::getOpenFileName(this, "Выберите изображение", 
                                                  QString(), "Изображения (*.png *.jpg *.jpeg *.bmp)");
    
    // Проверяем, выбран ли файл
    if (filePath.isEmpty()) {
        return;
    }
    
    // Загружаем изображение
    m_originalImage = QImage(filePath);
    
    // Проверяем, загружено ли изображение
    if (m_originalImage.isNull()) {
        QMessageBox::critical(this, "Ошибка", "Не удалось загрузить изображение");
        return;
    }
    
    // Сохраняем путь к изображению
    m_lastImagePath = filePath;
    
    // Отображаем информацию об изображении
    appendToOutput("> Изображение загружено:");
    appendToOutput(QString("Размер: %1x%2 пикселей").arg(m_originalImage.width()).arg(m_originalImage.height()));
    appendToOutput(QString("Формат: %1").arg(m_originalImage.format()));
    
    // Отображаем изображение
    displayImage(m_originalImage);
    
    // Сбрасываем состояние кнопки сохранения
    ui->btnSaveImage->setEnabled(false);
}

void MainWindow::onSelectImageForExtractClicked() {
    // Открываем диалог выбора файла
    QString filePath = QFileDialog::getOpenFileName(this, "Выберите изображение", 
                                                  QString(), "Изображения (*.png *.jpg *.jpeg *.bmp)");
    
    // Проверяем, выбран ли файл
    if (filePath.isEmpty()) {
        return;
    }
    
    // Загружаем изображение
    m_originalImage = QImage(filePath);
    
    // Проверяем, загружено ли изображение
    if (m_originalImage.isNull()) {
        QMessageBox::critical(this, "Ошибка", "Не удалось загрузить изображение");
        return;
    }
    
    // Сохраняем путь к изображению
    m_lastImagePath = filePath;
    
    // Проверяем, содержит ли изображение внедренное сообщение через API
    ApiClient::getInstance()->stegoHasMessage(m_originalImage);
    
    // Отображаем информацию об изображении
    appendToOutput("> Изображение загружено:");
    appendToOutput(QString("Размер: %1x%2 пикселей").arg(m_originalImage.width()).arg(m_originalImage.height()));
    appendToOutput("> Проверяем наличие внедренного сообщения...");
    
    // Отображаем изображение
    displayImage(m_originalImage);
}

void MainWindow::onSaveImageClicked() {
    // Проверяем, есть ли изображение для сохранения
    if (m_stegoImage.isNull()) {
        QMessageBox::warning(this, "Ошибка", "Нет изображения для сохранения");
        return;
    }
    
    // Открываем диалог сохранения файла
    QString filePath = QFileDialog::getSaveFileName(this, "Сохранить изображение", 
                                                  QString(), "PNG (*.png);;JPEG (*.jpg);;BMP (*.bmp)");
    
    // Проверяем, выбран ли файл
    if (filePath.isEmpty()) {
        return;
    }
    
    // Сохраняем изображение
    if (!m_stegoImage.save(filePath)) {
        QMessageBox::critical(this, "Ошибка", "Не удалось сохранить изображение");
        return;
    }
    
    // Отображаем информацию о сохранении
    appendToOutput("> Изображение успешно сохранено:");
    appendToOutput(filePath);
}

void MainWindow::onTabChanged(int index) {
    // Обработка изменения вкладки
    if (index == 0) {
        // Вкладка "Стеганография"
        if (!m_originalImage.isNull()) {
            displayImage(m_originalImage);
        }
    } else if (index == 1) {
        // Вкладка "Метод хорд"
        // Здесь можно добавить логику для отображения элементов вкладки "Метод хорд"
    } else if (index == 2) {
        // Вкладка "SHA384"
        // Здесь можно добавить логику для отображения элементов вкладки "SHA384"
    } else if (index == 3) {
        // Вкладка "AES"
        // Здесь можно добавить логику для отображения элементов вкладки "AES"
    }
}

void MainWindow::onEncryptAesClicked() {
    // Получаем ключ и открытый текст
    QString keyString = ui->editAesKey->text().trimmed();
    QString plaintextString = ui->editAesPlaintext->toPlainText().trimmed();

    if (keyString.isEmpty() || plaintextString.isEmpty()) {
        QMessageBox::warning(this, "Ошибка", "Введите ключ и открытый текст для шифрования");
        return;
    }

    // Преобразуем строки в QByteArray
    m_aesKey = keyString.toUtf8();
    m_aesPlaintext = plaintextString.toUtf8();

    // Отправляем запрос на сервер для шифрования
    ApiClient::getInstance()->aesEncrypt(m_aesKey, m_aesPlaintext);
    appendToOutput("> Отправлен запрос на шифрование AES...");
}

void MainWindow::onDecryptAesClicked() {
    // Получаем ключ и зашифрованный текст
    QString keyString = ui->editAesKey->text().trimmed();
    QString ciphertextString = ui->editAesCiphertext->toPlainText().trimmed();

    if (keyString.isEmpty() || ciphertextString.isEmpty()) {
        QMessageBox::warning(this, "Ошибка", "Введите ключ и зашифрованный текст для дешифрования");
        return;
    }

    // Преобразуем строки в QByteArray
    m_aesKey = keyString.toUtf8();
    ApiClient::getInstance()->aesDecrypt(m_aesKey, ciphertextString.toUtf8());
    appendToOutput("> Отправлен запрос на дешифрование AES...");
}

void MainWindow::onHashSha384Clicked() {
    // Получаем данные для хеширования
    QString dataString = ui->editSha384Data->toPlainText().trimmed();

    if (dataString.isEmpty()) {
        QMessageBox::warning(this, "Ошибка", "Введите данные для хеширования SHA384");
        return;
    }

    // Преобразуем строку в QByteArray
    QByteArray dataToHash = dataString.toUtf8();

    // Отправляем запрос на сервер для хеширования
    ApiClient::getInstance()->sha384Hash(dataToHash);
    appendToOutput("> Отправлен запрос на хеширование SHA384...");
}



void MainWindow::displayImage(const QImage &image) {
    if (image.isNull()) {
        return;
    }
    
    // Создаем QPixmap из QImage
    QPixmap pixmap = QPixmap::fromImage(image);
    
    // Масштабируем изображение, чтобы оно поместилось в метку
    pixmap = pixmap.scaled(ui->labelImage->width(), ui->labelImage->height(), 
                          Qt::KeepAspectRatio, Qt::SmoothTransformation);
    
    // Отображаем изображение в метке
    ui->labelImage->setPixmap(pixmap);
}

void MainWindow::appendToOutput(const QString &message) {
    ui->textOutput->append(message);
}


void MainWindow::onApiResponse(const QString &endpoint, bool success, const QJsonObject &result, const QString &error) {
    qDebug() << "onApiResponse called for endpoint:" << endpoint << ", success:" << success;
    qDebug() << "Result JSON:" << result;

    if (success) {
        if (endpoint.contains("/chord_method/solve")) {
            // Обработка ответа на метод хорд
            qDebug() << "Handling /chord_method/solve response.";
            qDebug() << "Result is empty:" << result.isEmpty();
            qDebug() << "Result keys:" << result.keys();
            qDebug() << "Result contains 'root':" << result.contains("root");
            qDebug() << "Result contains 'iterations':" << result.contains("iterations");
            qDebug() << "Result contains 'message':" << result.contains("message");

            if (result.contains("root") && result.contains("iterations") && result.contains("message")) {
                double root = result["root"].toDouble();
                int iterations = result["iterations"].toInt();
                QString message = result["message"].toString();
                QString outputText = QString("Корень: %1\nИтераций: %2\nСообщение: %3").arg(root).arg(iterations).arg(message);
                qDebug() << "Formatted outputText:" << outputText;
                ui->textResult->setPlainText(outputText);
                qDebug() << "textResult content after setPlainText:" << ui->textResult->toPlainText();
                ui->textResult->repaint(); // Force repaint
                QCoreApplication::processEvents();
            } else {
                qDebug() << "/chord_method/solve response missing expected keys.";
                appendToOutput("> Ошибка: Неполный ответ от сервера для метода хорд.");
            }
        } else if (endpoint.contains("/stego/embed")) {
            // Обработка ответа на внедрение сообщения
            QString embeddedImageBase64 = result["embedded_image"].toString();
            if (!embeddedImageBase64.isEmpty()) {
                // Конвертируем Base64 обратно в изображение
                QByteArray imageData = QByteArray::fromBase64(embeddedImageBase64.toUtf8());
                m_stegoImage.loadFromData(imageData);
                
                if (!m_stegoImage.isNull()) {
                    appendToOutput("> Сообщение успешно внедрено в изображение");
                    appendToOutput("> Теперь вы можете сохранить изображение");
                    
                    // Отображаем изображение с внедренным сообщением
                    displayImage(m_stegoImage);
                    
                    // Активируем кнопку сохранения
                    ui->btnSaveImage->setEnabled(true);
                } else {
                    appendToOutput("> Ошибка: не удалось загрузить изображение из ответа сервера");
                }
            }
        } else if (endpoint.contains("/stego/extract")) {
            // Обработка ответа на извлечение сообщения
            QString extractedMessage = result["message"].toString();
            appendToOutput("> Извлеченное сообщение:");
            appendToOutput(extractedMessage);
        } else if (endpoint.contains("/stego/has_message")) {
            // Обработка ответа на проверку наличия сообщения
            bool hasMessage = result["has_message"].toBool();
            if (hasMessage) {
                appendToOutput("> Изображение содержит внедренное сообщение");
            } else {
                appendToOutput("> Изображение не содержит внедренного сообщения");
            }
        } else if (endpoint.contains("/aes/encrypt")) {
            // Обработка ответа на шифрование AES
            QString ciphertext = result["ciphertext"].toString();
            appendToOutput("> Данные зашифрованы (Base64): " + ciphertext);
            ui->editAesCiphertext->setPlainText(ciphertext);
        } else if (endpoint.contains("/aes/decrypt")) {
            // Обработка ответа на дешифрование AES
            QString plaintext = result["plaintext"].toString();
            appendToOutput("> Данные расшифрованы (Base64): " + plaintext);
            ui->editAesPlaintext->setPlainText(plaintext);
        } else if (endpoint.contains("/sha384/hash")) {
            // Обработка ответа на хеширование SHA384
            QString hash = result["hash"].toString();
            appendToOutput("> SHA384 хеш: " + hash);
            ui->editSha384Result->setPlainText(hash);
        } else {
            appendToOutput("> Получен успешный ответ от сервера для неизвестного endpoint: " + endpoint);
        }
    } else {
        appendToOutput("> Ошибка: " + error);
    }
}



void MainWindow::onSolveChordMethodClicked() {
    // Получаем выбранную функцию
    QString functionName = ui->comboFunction->currentText();
    // Получаем интервал и точность
    double a = ui->editA->text().toDouble();
    double b = ui->editB->text().toDouble();
    double epsilon = ui->editEpsilon->text().toDouble();
    int maxIterations = ui->editMaxIter->text().toInt();

    // Отправляем запрос на сервер для вычисления метода хорд
    QJsonObject data;
    data["function"] = functionName;
    data["a"] = a;
    data["b"] = b;
    data["epsilon"] = epsilon;
    data["max_iterations"] = maxIterations;

    ApiClient::getInstance()->sendRequest("/chord_method/solve", data);
    appendToOutput("> Отправлен запрос на вычисление метода хорд...");
}

void MainWindow::onClearChordMethodClicked() {
    qDebug() << "onClearChordMethodClicked called.";
    ui->textResult->clear();
    appendToOutput("> Результаты метода хорд очищены.");
}


