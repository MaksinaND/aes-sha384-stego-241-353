#include "registerdialog.h"
#include "ui_dialog.h"
#include "apiclient.h"

RegisterDialog::RegisterDialog(QWidget *parent)
    : QDialog(parent),
    ui(new Ui::RegisterDialog)
{
    ui->setupUi(this);
    setWindowTitle("Регистрация");
    ui->textEdit_3->setReadOnly(true);

    // Кнопка "Зарегистрироваться"
    connect(ui->pushButton, &QPushButton::clicked, this, &RegisterDialog::onRegisterClicked);

    // Обработка ответа от сервера
    connect(ApiClient::getInstance(), &ApiClient::responseReceived, this, 
            [this](const QString& endpoint, bool success, const QJsonObject& /*result*/, const QString& error) {
        qDebug() << "RegisterDialog: Received response for endpoint:" << endpoint << "Success:" << success;
        if (endpoint == "/user/register") {
            if (success) {
                ui->textEdit_3->setText("Регистрация успешна");
                this->accept();  // Закрыть окно при успехе
            } else {
                ui->textEdit_3->setText("Ошибка: " + error);
            }
        }
    });
}

RegisterDialog::~RegisterDialog()
{
    delete ui;
}

void RegisterDialog::onRegisterClicked()
{
    QString login = ui->lineEdit->text().trimmed();
    QString password = ui->lineEdit_2->text().trimmed();

    if (login.isEmpty() || password.isEmpty()) {
        ui->textEdit_3->setText("Введите логин и пароль.");
        return;
    }

    ApiClient::getInstance()->registerUser(login, password);
}
