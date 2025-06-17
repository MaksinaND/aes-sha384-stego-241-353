/**
 * @file loginwindow.cpp
 * @brief Реализация окна входа в приложение
 * @date 2025
 */

#include "loginwindow.h"
#include "ui_login.h"
#include "registerdialog.h"
#include "apiclient.h"
#include "mainwindow.h"

LoginWindow::LoginWindow(QWidget *parent)
    : QDialog(parent), ui(new Ui::LoginWindow)
{
    ui->setupUi(this);
    ApiClient::getInstance()->connectToServer();
    setWindowTitle("Вход");
    ui->textEdit_3->setReadOnly(true);

    // обработка ответа от сервера
    connect(ApiClient::getInstance(), &ApiClient::responseReceived, this, 
            [this](const QString& endpoint, bool success, const QJsonObject& /*result*/, const QString& error) {
                qDebug() << "LoginWindow: Received response for endpoint:" << endpoint << "Success:" << success;
                if (endpoint == "/user/login") {
                    if (success) {
                        ui->textEdit_3->append("> Ответ: Вход выполнен успешно.");
                        if (!mainWindow)
                            mainWindow = new MainWindow();
                        mainWindow->show();
                        this->hide();
                    } else {
                        ui->textEdit_3->append("> Ошибка входа: " + error);
                    }
                }
            });

    // регистрация
    connect(ui->pushButton, &QPushButton::clicked, this, [this]() {
        RegisterDialog reg(this);
        reg.exec();
    });

    // кнопка OK
    connect(ui->pushButton_2, &QPushButton::clicked, this, &LoginWindow::onOkClicked);


    // выводим сообщение о подключении
    ui->textEdit_3->append("> Подключение к серверу...");
}

LoginWindow::~LoginWindow() {
    delete ui;
}

void LoginWindow::handleServerResponse(const QString& response) {
    ui->textEdit_3->append("> Ответ:\n" + response);
}

void LoginWindow::onOkClicked() {
    QString login = ui->lineEdit->text().trimmed();
    QString password = ui->lineEdit_2->text().trimmed();

    if (login.isEmpty() || password.isEmpty()) {
        ui->textEdit_3->append("> Ошибка: введите логин и пароль.");
        return;
    }

    ApiClient::getInstance()->loginUser(login, password);
}

