/********************************************************************************
** Form generated from reading UI file 'dialog.ui'
**
** Created by: Qt User Interface Compiler version 6.9.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_DIALOG_H
#define UI_DIALOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_RegisterDialog
{
public:
    QLabel *label;
    QPushButton *pushButton;
    QWidget *gridLayoutWidget;
    QGridLayout *gridLayout;
    QLabel *label_3;
    QLabel *label_2;
    QWidget *gridLayoutWidget_2;
    QGridLayout *gridLayout_2;
    QLineEdit *lineEdit;
    QLineEdit *lineEdit_2;
    QTextEdit *textEdit_3;

    void setupUi(QDialog *RegisterDialog)
    {
        if (RegisterDialog->objectName().isEmpty())
            RegisterDialog->setObjectName("RegisterDialog");
        RegisterDialog->resize(267, 320);
        RegisterDialog->setStyleSheet(QString::fromUtf8("QDialog {\n"
"    background-color: #2E3440;\n"
"    color: #D8DEE9;\n"
"    font-family: Segoe UI;\n"
"    font-size: 12pt;\n"
"}"));
        label = new QLabel(RegisterDialog);
        label->setObjectName("label");
        label->setGeometry(QRect(80, 10, 121, 20));
        label->setStyleSheet(QString::fromUtf8("QLabel {\n"
"    color: #D8DEE9;\n"
"    background: transparent; /* \320\230\320\273\320\270 \321\203\320\261\321\200\320\260\321\202\321\214 \321\204\320\276\320\275 \320\262\320\276\320\276\320\261\321\211\320\265 */\n"
"    font-weight: bold;\n"
"    font-size: 12pt;\n"
"}"));
        pushButton = new QPushButton(RegisterDialog);
        pushButton->setObjectName("pushButton");
        pushButton->setGeometry(QRect(60, 260, 161, 29));
        pushButton->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"    background-color: #5E81AC;\n"
"    color: white;\n"
"    border-radius: 6px;\n"
"    padding: 6px;\n"
"    font-weight: bold;\n"
"}"));
        gridLayoutWidget = new QWidget(RegisterDialog);
        gridLayoutWidget->setObjectName("gridLayoutWidget");
        gridLayoutWidget->setGeometry(QRect(0, 70, 91, 80));
        gridLayout = new QGridLayout(gridLayoutWidget);
        gridLayout->setObjectName("gridLayout");
        gridLayout->setContentsMargins(0, 0, 0, 0);
        label_3 = new QLabel(gridLayoutWidget);
        label_3->setObjectName("label_3");
        label_3->setStyleSheet(QString::fromUtf8("QLabel {\n"
"    color: #D8DEE9;\n"
"    background: transparent; /* \320\230\320\273\320\270 \321\203\320\261\321\200\320\260\321\202\321\214 \321\204\320\276\320\275 \320\262\320\276\320\276\320\261\321\211\320\265 */\n"
"    font-weight: bold;\n"
"    font-size: 12pt;\n"
"}"));

        gridLayout->addWidget(label_3, 2, 0, 1, 1);

        label_2 = new QLabel(gridLayoutWidget);
        label_2->setObjectName("label_2");
        label_2->setStyleSheet(QString::fromUtf8("QLabel {\n"
"    color: #D8DEE9;\n"
"    background: transparent; /* \320\230\320\273\320\270 \321\203\320\261\321\200\320\260\321\202\321\214 \321\204\320\276\320\275 \320\262\320\276\320\276\320\261\321\211\320\265 */\n"
"    font-weight: bold;\n"
"    font-size: 12pt;\n"
"}"));

        gridLayout->addWidget(label_2, 1, 0, 1, 1);

        gridLayoutWidget_2 = new QWidget(RegisterDialog);
        gridLayoutWidget_2->setObjectName("gridLayoutWidget_2");
        gridLayoutWidget_2->setGeometry(QRect(100, 70, 160, 80));
        gridLayout_2 = new QGridLayout(gridLayoutWidget_2);
        gridLayout_2->setObjectName("gridLayout_2");
        gridLayout_2->setContentsMargins(0, 0, 0, 0);
        lineEdit = new QLineEdit(gridLayoutWidget_2);
        lineEdit->setObjectName("lineEdit");
        lineEdit->setStyleSheet(QString::fromUtf8("QLineEdit {\n"
"    background-color: #ECEFF4;\n"
"    color: black;\n"
"    border: 1px solid #4C566A;\n"
"    border-radius: 4px;\n"
"    padding: 4px;\n"
"}"));

        gridLayout_2->addWidget(lineEdit, 0, 0, 1, 1);

        lineEdit_2 = new QLineEdit(gridLayoutWidget_2);
        lineEdit_2->setObjectName("lineEdit_2");
        lineEdit_2->setStyleSheet(QString::fromUtf8("QLineEdit {\n"
"    background-color: #ECEFF4;\n"
"    color: black;\n"
"    border: 1px solid #4C566A;\n"
"    border-radius: 4px;\n"
"    padding: 4px;\n"
"}"));

        gridLayout_2->addWidget(lineEdit_2, 1, 0, 1, 1);

        textEdit_3 = new QTextEdit(RegisterDialog);
        textEdit_3->setObjectName("textEdit_3");
        textEdit_3->setGeometry(QRect(40, 160, 181, 81));
        textEdit_3->setStyleSheet(QString::fromUtf8("QTextEdit {\n"
"    background-color: #2E3440;\n"
"    color: #A3BE8C;\n"
"    border: 1px solid #4C566A;\n"
"    border-radius: 5px;\n"
"    padding: 6px;\n"
"}"));

        retranslateUi(RegisterDialog);

        QMetaObject::connectSlotsByName(RegisterDialog);
    } // setupUi

    void retranslateUi(QDialog *RegisterDialog)
    {
        RegisterDialog->setWindowTitle(QCoreApplication::translate("RegisterDialog", "Dialog", nullptr));
        label->setText(QCoreApplication::translate("RegisterDialog", "Registration", nullptr));
        pushButton->setText(QCoreApplication::translate("RegisterDialog", "\320\227\320\260\321\200\320\265\320\263\320\265\321\201\321\202\321\200\320\270\321\200\320\276\320\262\320\260\321\202\321\214\321\201\321\217", nullptr));
        label_3->setText(QCoreApplication::translate("RegisterDialog", "Password", nullptr));
        label_2->setText(QCoreApplication::translate("RegisterDialog", "Login", nullptr));
    } // retranslateUi

};

namespace Ui {
    class RegisterDialog: public Ui_RegisterDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DIALOG_H
