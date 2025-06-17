/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.15.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QFormLayout>
#include <QtWidgets/QGraphicsView>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTabWidget>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QVBoxLayout *verticalLayout;
    QTabWidget *tabWidget;
    QWidget *tabSteganography;
    QVBoxLayout *verticalLayout_2;
    QHBoxLayout *horizontalLayout;
    QVBoxLayout *verticalLayout_3;
    QGroupBox *groupBoxEmbed;
    QVBoxLayout *verticalLayout_5;
    QLineEdit *editEmbedMessage;
    QPushButton *btnSelectImageEmbed;
    QPushButton *btnEmbed;
    QPushButton *btnSaveImage;
    QGroupBox *groupBoxExtract;
    QVBoxLayout *verticalLayout_6;
    QPushButton *btnSelectImageExtract;
    QPushButton *btnExtract;
    QVBoxLayout *verticalLayout_4;
    QLabel *labelImage;
    QTextEdit *textOutput;
    QWidget *tabChordMethod;
    QVBoxLayout *verticalLayout_7;
    QHBoxLayout *horizontalLayout_2;
    QVBoxLayout *verticalLayout_8;
    QGroupBox *groupBoxFunction;
    QVBoxLayout *verticalLayout_9;
    QComboBox *comboFunction;
    QGroupBox *groupBoxInterval;
    QFormLayout *formLayout;
    QLabel *labelA;
    QLineEdit *editA;
    QLabel *labelB;
    QLineEdit *editB;
    QGroupBox *groupBoxParams;
    QFormLayout *formLayout_2;
    QLabel *labelEpsilon;
    QLineEdit *editEpsilon;
    QLabel *labelMaxIter;
    QLineEdit *editMaxIter;
    QPushButton *btnSolve;
    QPushButton *btnClear;
    QGroupBox *groupBoxResult;
    QVBoxLayout *verticalLayout_10;
    QTextEdit *textResult;
    QGraphicsView *graphicsView;
    QWidget *tabSHA384;
    QVBoxLayout *verticalLayout_91;
    QGroupBox *groupBoxSHA384;
    QVBoxLayout *verticalLayout_11;
    QTextEdit *editSha384Data;
    QPushButton *btnHashSha384;
    QTextEdit *editSha384Result;
    QWidget *tabAES;
    QVBoxLayout *verticalLayout_101;
    QGroupBox *groupBoxAES;
    QVBoxLayout *verticalLayout_12;
    QLineEdit *editAesKey;
    QTextEdit *editAesPlaintext;
    QPushButton *btnEncryptAes;
    QTextEdit *editAesCiphertext;
    QPushButton *btnDecryptAes;
    QWidget *tabEmpty;
    QVBoxLayout *verticalLayout_71;
    QLabel *labelEmpty;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(800, 600);
        MainWindow->setStyleSheet(QString::fromUtf8("background-color: #2E3440;\n"
"color: #D8DEE9; "));
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        verticalLayout = new QVBoxLayout(centralwidget);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        tabWidget = new QTabWidget(centralwidget);
        tabWidget->setObjectName(QString::fromUtf8("tabWidget"));
        tabWidget->setStyleSheet(QString::fromUtf8("QTabWidget::pane {\n"
"    border: 1px solid #4C566A;\n"
"    background-color: #2E3440;\n"
"    border-radius: 5px;\n"
"}\n"
"\n"
"QTabBar::tab {\n"
"    background-color: #3B4252;\n"
"    color: #D8DEE9;\n"
"    padding: 8px 16px;\n"
"    border-top-left-radius: 5px;\n"
"    border-top-right-radius: 5px;\n"
"    border: 1px solid #4C566A;\n"
"    border-bottom: none;\n"
"    margin-right: 2px;\n"
"}\n"
"\n"
"QTabBar::tab:selected {\n"
"    background-color: #4C566A;\n"
"    color: #ECEFF4;\n"
"}\n"
"\n"
"QTabBar::tab:hover:!selected {\n"
"    background-color: #434C5E;\n"
"}"));
        tabSteganography = new QWidget();
        tabSteganography->setObjectName(QString::fromUtf8("tabSteganography"));
        verticalLayout_2 = new QVBoxLayout(tabSteganography);
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        verticalLayout_3 = new QVBoxLayout();
        verticalLayout_3->setObjectName(QString::fromUtf8("verticalLayout_3"));
        groupBoxEmbed = new QGroupBox(tabSteganography);
        groupBoxEmbed->setObjectName(QString::fromUtf8("groupBoxEmbed"));
        groupBoxEmbed->setStyleSheet(QString::fromUtf8("QGroupBox {\n"
"    border: 1px solid #4C566A;\n"
"    border-radius: 5px;\n"
"    margin-top: 1ex;\n"
"    font-weight: bold;\n"
"    color: #88C0D0;\n"
"}\n"
"\n"
"QGroupBox::title {\n"
"    subcontrol-origin: margin;\n"
"    subcontrol-position: top center;\n"
"    padding: 0 5px;\n"
"}"));
        verticalLayout_5 = new QVBoxLayout(groupBoxEmbed);
        verticalLayout_5->setObjectName(QString::fromUtf8("verticalLayout_5"));
        editEmbedMessage = new QLineEdit(groupBoxEmbed);
        editEmbedMessage->setObjectName(QString::fromUtf8("editEmbedMessage"));
        editEmbedMessage->setStyleSheet(QString::fromUtf8("QLineEdit {\n"
"    background-color: #3B4252;\n"
"    color: #D8DEE9;\n"
"    border: 1px solid #4C566A;\n"
"    border-radius: 4px;\n"
"    padding: 4px;\n"
"}"));

        verticalLayout_5->addWidget(editEmbedMessage);

        btnSelectImageEmbed = new QPushButton(groupBoxEmbed);
        btnSelectImageEmbed->setObjectName(QString::fromUtf8("btnSelectImageEmbed"));
        btnSelectImageEmbed->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"    background-color: #5E81AC;\n"
"    color: white;\n"
"    border-radius: 5px;\n"
"    padding: 5px;\n"
"}\n"
"QPushButton:hover {\n"
"    background-color: #81A1C1;\n"
"}"));

        verticalLayout_5->addWidget(btnSelectImageEmbed);

        btnEmbed = new QPushButton(groupBoxEmbed);
        btnEmbed->setObjectName(QString::fromUtf8("btnEmbed"));
        btnEmbed->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"    background-color: #A3BE8C;\n"
"    color: white;\n"
"    border-radius: 5px;\n"
"    padding: 5px;\n"
"}\n"
"QPushButton:hover {\n"
"    background-color: #B9D39C;\n"
"}"));

        verticalLayout_5->addWidget(btnEmbed);

        btnSaveImage = new QPushButton(groupBoxEmbed);
        btnSaveImage->setObjectName(QString::fromUtf8("btnSaveImage"));
        btnSaveImage->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"    background-color: #5E81AC;\n"
"    color: white;\n"
"    border-radius: 5px;\n"
"    padding: 5px;\n"
"}\n"
"QPushButton:hover {\n"
"    background-color: #81A1C1;\n"
"}"));

        verticalLayout_5->addWidget(btnSaveImage);


        verticalLayout_3->addWidget(groupBoxEmbed);

        groupBoxExtract = new QGroupBox(tabSteganography);
        groupBoxExtract->setObjectName(QString::fromUtf8("groupBoxExtract"));
        groupBoxExtract->setStyleSheet(QString::fromUtf8("QGroupBox {\n"
"    border: 1px solid #4C566A;\n"
"    border-radius: 5px;\n"
"    margin-top: 1ex;\n"
"    font-weight: bold;\n"
"    color: #88C0D0;\n"
"}\n"
"\n"
"QGroupBox::title {\n"
"    subcontrol-origin: margin;\n"
"    subcontrol-position: top center;\n"
"    padding: 0 5px;\n"
"}"));
        verticalLayout_6 = new QVBoxLayout(groupBoxExtract);
        verticalLayout_6->setObjectName(QString::fromUtf8("verticalLayout_6"));
        btnSelectImageExtract = new QPushButton(groupBoxExtract);
        btnSelectImageExtract->setObjectName(QString::fromUtf8("btnSelectImageExtract"));
        btnSelectImageExtract->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"    background-color: #5E81AC;\n"
"    color: white;\n"
"    border-radius: 5px;\n"
"    padding: 5px;\n"
"}\n"
"QPushButton:hover {\n"
"    background-color: #81A1C1;\n"
"}"));

        verticalLayout_6->addWidget(btnSelectImageExtract);

        btnExtract = new QPushButton(groupBoxExtract);
        btnExtract->setObjectName(QString::fromUtf8("btnExtract"));
        btnExtract->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"    background-color: #A3BE8C;\n"
"    color: white;\n"
"    border-radius: 5px;\n"
"    padding: 5px;\n"
"}\n"
"QPushButton:hover {\n"
"    background-color: #B9D39C;\n"
"}"));

        verticalLayout_6->addWidget(btnExtract);


        verticalLayout_3->addWidget(groupBoxExtract);


        horizontalLayout->addLayout(verticalLayout_3);

        verticalLayout_4 = new QVBoxLayout();
        verticalLayout_4->setObjectName(QString::fromUtf8("verticalLayout_4"));
        labelImage = new QLabel(tabSteganography);
        labelImage->setObjectName(QString::fromUtf8("labelImage"));
        labelImage->setMinimumSize(QSize(400, 300));
        labelImage->setStyleSheet(QString::fromUtf8("QLabel {\n"
"    background-color: #3B4252;\n"
"    border: 1px solid #4C566A;\n"
"    border-radius: 5px;\n"
"}"));
        labelImage->setAlignment(Qt::AlignCenter);

        verticalLayout_4->addWidget(labelImage);

        textOutput = new QTextEdit(tabSteganography);
        textOutput->setObjectName(QString::fromUtf8("textOutput"));
        textOutput->setStyleSheet(QString::fromUtf8("QTextEdit {\n"
"    background-color: #3B4252;\n"
"    color: #D8DEE9;\n"
"    border: 1px solid #4C566A;\n"
"    border-radius: 5px;\n"
"    padding: 5px;\n"
"}"));
        textOutput->setReadOnly(true);

        verticalLayout_4->addWidget(textOutput);


        horizontalLayout->addLayout(verticalLayout_4);


        verticalLayout_2->addLayout(horizontalLayout);

        tabWidget->addTab(tabSteganography, QString());
        tabChordMethod = new QWidget();
        tabChordMethod->setObjectName(QString::fromUtf8("tabChordMethod"));
        verticalLayout_7 = new QVBoxLayout(tabChordMethod);
        verticalLayout_7->setObjectName(QString::fromUtf8("verticalLayout_7"));
        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        verticalLayout_8 = new QVBoxLayout();
        verticalLayout_8->setObjectName(QString::fromUtf8("verticalLayout_8"));
        groupBoxFunction = new QGroupBox(tabChordMethod);
        groupBoxFunction->setObjectName(QString::fromUtf8("groupBoxFunction"));
        groupBoxFunction->setStyleSheet(QString::fromUtf8("QGroupBox {\n"
"    border: 1px solid #4C566A;\n"
"    border-radius: 5px;\n"
"    margin-top: 1ex;\n"
"    font-weight: bold;\n"
"    color: #88C0D0;\n"
"}\n"
"\n"
"QGroupBox::title {\n"
"    subcontrol-origin: margin;\n"
"    subcontrol-position: top center;\n"
"    padding: 0 5px;\n"
"}"));
        verticalLayout_9 = new QVBoxLayout(groupBoxFunction);
        verticalLayout_9->setObjectName(QString::fromUtf8("verticalLayout_9"));
        comboFunction = new QComboBox(groupBoxFunction);
        comboFunction->addItem(QString());
        comboFunction->addItem(QString());
        comboFunction->addItem(QString());
        comboFunction->addItem(QString());
        comboFunction->addItem(QString());
        comboFunction->setObjectName(QString::fromUtf8("comboFunction"));
        comboFunction->setStyleSheet(QString::fromUtf8("QComboBox {\n"
"    background-color: #3B4252;\n"
"    color: #D8DEE9;\n"
"    border: 1px solid #4C566A;\n"
"    border-radius: 4px;\n"
"    padding: 4px;\n"
"}"));

        verticalLayout_9->addWidget(comboFunction);


        verticalLayout_8->addWidget(groupBoxFunction);

        groupBoxInterval = new QGroupBox(tabChordMethod);
        groupBoxInterval->setObjectName(QString::fromUtf8("groupBoxInterval"));
        groupBoxInterval->setStyleSheet(QString::fromUtf8("QGroupBox {\n"
"    border: 1px solid #4C566A;\n"
"    border-radius: 5px;\n"
"    margin-top: 1ex;\n"
"    font-weight: bold;\n"
"    color: #88C0D0;\n"
"}\n"
"\n"
"QGroupBox::title {\n"
"    subcontrol-origin: margin;\n"
"    subcontrol-position: top center;\n"
"    padding: 0 5px;\n"
"}"));
        formLayout = new QFormLayout(groupBoxInterval);
        formLayout->setObjectName(QString::fromUtf8("formLayout"));
        labelA = new QLabel(groupBoxInterval);
        labelA->setObjectName(QString::fromUtf8("labelA"));

        formLayout->setWidget(0, QFormLayout::LabelRole, labelA);

        editA = new QLineEdit(groupBoxInterval);
        editA->setObjectName(QString::fromUtf8("editA"));
        editA->setStyleSheet(QString::fromUtf8("QLineEdit {\n"
"    background-color: #3B4252;\n"
"    color: #D8DEE9;\n"
"    border: 1px solid #4C566A;\n"
"    border-radius: 4px;\n"
"    padding: 4px;\n"
"}"));

        formLayout->setWidget(0, QFormLayout::FieldRole, editA);

        labelB = new QLabel(groupBoxInterval);
        labelB->setObjectName(QString::fromUtf8("labelB"));

        formLayout->setWidget(1, QFormLayout::LabelRole, labelB);

        editB = new QLineEdit(groupBoxInterval);
        editB->setObjectName(QString::fromUtf8("editB"));
        editB->setStyleSheet(QString::fromUtf8("QLineEdit {\n"
"    background-color: #3B4252;\n"
"    color: #D8DEE9;\n"
"    border: 1px solid #4C566A;\n"
"    border-radius: 4px;\n"
"    padding: 4px;\n"
"}"));

        formLayout->setWidget(1, QFormLayout::FieldRole, editB);


        verticalLayout_8->addWidget(groupBoxInterval);

        groupBoxParams = new QGroupBox(tabChordMethod);
        groupBoxParams->setObjectName(QString::fromUtf8("groupBoxParams"));
        groupBoxParams->setStyleSheet(QString::fromUtf8("QGroupBox {\n"
"    border: 1px solid #4C566A;\n"
"    border-radius: 5px;\n"
"    margin-top: 1ex;\n"
"    font-weight: bold;\n"
"    color: #88C0D0;\n"
"}\n"
"\n"
"QGroupBox::title {\n"
"    subcontrol-origin: margin;\n"
"    subcontrol-position: top center;\n"
"    padding: 0 5px;\n"
"}"));
        formLayout_2 = new QFormLayout(groupBoxParams);
        formLayout_2->setObjectName(QString::fromUtf8("formLayout_2"));
        labelEpsilon = new QLabel(groupBoxParams);
        labelEpsilon->setObjectName(QString::fromUtf8("labelEpsilon"));

        formLayout_2->setWidget(0, QFormLayout::LabelRole, labelEpsilon);

        editEpsilon = new QLineEdit(groupBoxParams);
        editEpsilon->setObjectName(QString::fromUtf8("editEpsilon"));
        editEpsilon->setStyleSheet(QString::fromUtf8("QLineEdit {\n"
"    background-color: #3B4252;\n"
"    color: #D8DEE9;\n"
"    border: 1px solid #4C566A;\n"
"    border-radius: 4px;\n"
"    padding: 4px;\n"
"}"));

        formLayout_2->setWidget(0, QFormLayout::FieldRole, editEpsilon);

        labelMaxIter = new QLabel(groupBoxParams);
        labelMaxIter->setObjectName(QString::fromUtf8("labelMaxIter"));

        formLayout_2->setWidget(1, QFormLayout::LabelRole, labelMaxIter);

        editMaxIter = new QLineEdit(groupBoxParams);
        editMaxIter->setObjectName(QString::fromUtf8("editMaxIter"));
        editMaxIter->setStyleSheet(QString::fromUtf8("QLineEdit {\n"
"    background-color: #3B4252;\n"
"    color: #D8DEE9;\n"
"    border: 1px solid #4C566A;\n"
"    border-radius: 4px;\n"
"    padding: 4px;\n"
"}"));

        formLayout_2->setWidget(1, QFormLayout::FieldRole, editMaxIter);


        verticalLayout_8->addWidget(groupBoxParams);

        btnSolve = new QPushButton(tabChordMethod);
        btnSolve->setObjectName(QString::fromUtf8("btnSolve"));
        btnSolve->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"    background-color: #A3BE8C;\n"
"    color: white;\n"
"    border-radius: 5px;\n"
"    padding: 5px;\n"
"}\n"
"QPushButton:hover {\n"
"    background-color: #B9D39C;\n"
"}"));

        verticalLayout_8->addWidget(btnSolve);

        btnClear = new QPushButton(tabChordMethod);
        btnClear->setObjectName(QString::fromUtf8("btnClear"));
        btnClear->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"    background-color: #BF616A;\n"
"    color: white;\n"
"    border-radius: 5px;\n"
"    padding: 5px;\n"
"}\n"
"QPushButton:hover {\n"
"    background-color: #CF717A;\n"
"}"));

        verticalLayout_8->addWidget(btnClear);

        groupBoxResult = new QGroupBox(tabChordMethod);
        groupBoxResult->setObjectName(QString::fromUtf8("groupBoxResult"));
        groupBoxResult->setStyleSheet(QString::fromUtf8("QGroupBox {\n"
"    border: 1px solid #4C566A;\n"
"    border-radius: 5px;\n"
"    margin-top: 1ex;\n"
"    font-weight: bold;\n"
"    color: #88C0D0;\n"
"}\n"
"\n"
"QGroupBox::title {\n"
"    subcontrol-origin: margin;\n"
"    subcontrol-position: top center;\n"
"    padding: 0 5px;\n"
"}"));
        verticalLayout_10 = new QVBoxLayout(groupBoxResult);
        verticalLayout_10->setObjectName(QString::fromUtf8("verticalLayout_10"));
        textResult = new QTextEdit(groupBoxResult);
        textResult->setObjectName(QString::fromUtf8("textResult"));
        textResult->setStyleSheet(QString::fromUtf8("QTextEdit {\n"
"    background-color: #3B4252;\n"
"    color: #D8DEE9;\n"
"    border: 1px solid #4C566A;\n"
"    border-radius: 4px;\n"
"    padding: 4px;\n"
"}"));
        textResult->setReadOnly(true);

        verticalLayout_10->addWidget(textResult);


        verticalLayout_8->addWidget(groupBoxResult);


        horizontalLayout_2->addLayout(verticalLayout_8);

        graphicsView = new QGraphicsView(tabChordMethod);
        graphicsView->setObjectName(QString::fromUtf8("graphicsView"));
        graphicsView->setMinimumSize(QSize(400, 300));
        graphicsView->setStyleSheet(QString::fromUtf8("QGraphicsView {\n"
"    background-color: #3B4252;\n"
"    border: 1px solid #4C566A;\n"
"    border-radius: 5px;\n"
"}"));

        horizontalLayout_2->addWidget(graphicsView);


        verticalLayout_7->addLayout(horizontalLayout_2);

        tabWidget->addTab(tabChordMethod, QString());
        tabSHA384 = new QWidget();
        tabSHA384->setObjectName(QString::fromUtf8("tabSHA384"));
        verticalLayout_91 = new QVBoxLayout(tabSHA384);
        verticalLayout_91->setObjectName(QString::fromUtf8("verticalLayout_91"));
        groupBoxSHA384 = new QGroupBox(tabSHA384);
        groupBoxSHA384->setObjectName(QString::fromUtf8("groupBoxSHA384"));
        groupBoxSHA384->setStyleSheet(QString::fromUtf8("QGroupBox {\n"
"    border: 1px solid #4C566A;\n"
"    border-radius: 5px;\n"
"    margin-top: 1ex;\n"
"    font-weight: bold;\n"
"    color: #88C0D0;\n"
"}\n"
"\n"
"QGroupBox::title {\n"
"    subcontrol-origin: margin;\n"
"    subcontrol-position: top center;\n"
"    padding: 0 5px;\n"
"}"));
        verticalLayout_11 = new QVBoxLayout(groupBoxSHA384);
        verticalLayout_11->setObjectName(QString::fromUtf8("verticalLayout_11"));
        editSha384Data = new QTextEdit(groupBoxSHA384);
        editSha384Data->setObjectName(QString::fromUtf8("editSha384Data"));
        editSha384Data->setStyleSheet(QString::fromUtf8("QTextEdit {\n"
"    background-color: #3B4252;\n"
"    color: #D8DEE9;\n"
"    border: 1px solid #4C566A;\n"
"    border-radius: 4px;\n"
"    padding: 4px;\n"
"}"));

        verticalLayout_11->addWidget(editSha384Data);

        btnHashSha384 = new QPushButton(groupBoxSHA384);
        btnHashSha384->setObjectName(QString::fromUtf8("btnHashSha384"));
        btnHashSha384->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"    background-color: #A3BE8C;\n"
"    color: white;\n"
"    border-radius: 5px;\n"
"    padding: 5px;\n"
"}\n"
"QPushButton:hover {\n"
"    background-color: #B9D39C;\n"
"}"));

        verticalLayout_11->addWidget(btnHashSha384);

        editSha384Result = new QTextEdit(groupBoxSHA384);
        editSha384Result->setObjectName(QString::fromUtf8("editSha384Result"));
        editSha384Result->setStyleSheet(QString::fromUtf8("QTextEdit {\n"
"    background-color: #3B4252;\n"
"    color: #D8DEE9;\n"
"    border: 1px solid #4C566A;\n"
"    border-radius: 4px;\n"
"    padding: 4px;\n"
"}"));
        editSha384Result->setReadOnly(true);

        verticalLayout_11->addWidget(editSha384Result);


        verticalLayout_91->addWidget(groupBoxSHA384);

        tabWidget->addTab(tabSHA384, QString());
        tabAES = new QWidget();
        tabAES->setObjectName(QString::fromUtf8("tabAES"));
        verticalLayout_101 = new QVBoxLayout(tabAES);
        verticalLayout_101->setObjectName(QString::fromUtf8("verticalLayout_101"));
        groupBoxAES = new QGroupBox(tabAES);
        groupBoxAES->setObjectName(QString::fromUtf8("groupBoxAES"));
        groupBoxAES->setStyleSheet(QString::fromUtf8("QGroupBox {\n"
"    border: 1px solid #4C566A;\n"
"    border-radius: 5px;\n"
"    margin-top: 1ex;\n"
"    font-weight: bold;\n"
"    color: #88C0D0;\n"
"}\n"
"\n"
"QGroupBox::title {\n"
"    subcontrol-origin: margin;\n"
"    subcontrol-position: top center;\n"
"    padding: 0 5px;\n"
"}"));
        verticalLayout_12 = new QVBoxLayout(groupBoxAES);
        verticalLayout_12->setObjectName(QString::fromUtf8("verticalLayout_12"));
        editAesKey = new QLineEdit(groupBoxAES);
        editAesKey->setObjectName(QString::fromUtf8("editAesKey"));
        editAesKey->setStyleSheet(QString::fromUtf8("QLineEdit {\n"
"    background-color: #3B4252;\n"
"    color: #D8DEE9;\n"
"    border: 1px solid #4C566A;\n"
"    border-radius: 4px;\n"
"    padding: 4px;\n"
"}"));

        verticalLayout_12->addWidget(editAesKey);

        editAesPlaintext = new QTextEdit(groupBoxAES);
        editAesPlaintext->setObjectName(QString::fromUtf8("editAesPlaintext"));
        editAesPlaintext->setStyleSheet(QString::fromUtf8("QTextEdit {\n"
"    background-color: #3B4252;\n"
"    color: #D8DEE9;\n"
"    border: 1px solid #4C566A;\n"
"    border-radius: 4px;\n"
"    padding: 4px;\n"
"}"));

        verticalLayout_12->addWidget(editAesPlaintext);

        btnEncryptAes = new QPushButton(groupBoxAES);
        btnEncryptAes->setObjectName(QString::fromUtf8("btnEncryptAes"));
        btnEncryptAes->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"    background-color: #A3BE8C;\n"
"    color: white;\n"
"    border-radius: 5px;\n"
"    padding: 5px;\n"
"}\n"
"QPushButton:hover {\n"
"    background-color: #B9D39C;\n"
"}"));

        verticalLayout_12->addWidget(btnEncryptAes);

        editAesCiphertext = new QTextEdit(groupBoxAES);
        editAesCiphertext->setObjectName(QString::fromUtf8("editAesCiphertext"));
        editAesCiphertext->setStyleSheet(QString::fromUtf8("QTextEdit {\n"
"    background-color: #3B4252;\n"
"    color: #D8DEE9;\n"
"    border: 1px solid #4C566A;\n"
"    border-radius: 4px;\n"
"    padding: 4px;\n"
"}"));

        verticalLayout_12->addWidget(editAesCiphertext);

        btnDecryptAes = new QPushButton(groupBoxAES);
        btnDecryptAes->setObjectName(QString::fromUtf8("btnDecryptAes"));
        btnDecryptAes->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"    background-color: #A3BE8C;\n"
"    color: white;\n"
"    border-radius: 5px;\n"
"    padding: 5px;\n"
"}\n"
"QPushButton:hover {\n"
"    background-color: #B9D39C;\n"
"}"));

        verticalLayout_12->addWidget(btnDecryptAes);


        verticalLayout_101->addWidget(groupBoxAES);

        tabWidget->addTab(tabAES, QString());
        tabEmpty = new QWidget();
        tabEmpty->setObjectName(QString::fromUtf8("tabEmpty"));
        verticalLayout_71 = new QVBoxLayout(tabEmpty);
        verticalLayout_71->setObjectName(QString::fromUtf8("verticalLayout_71"));
        labelEmpty = new QLabel(tabEmpty);
        labelEmpty->setObjectName(QString::fromUtf8("labelEmpty"));
        labelEmpty->setStyleSheet(QString::fromUtf8("QLabel {\n"
"    color: #D8DEE9;\n"
"    font-size: 16pt;\n"
"    font-weight: bold;\n"
"}"));
        labelEmpty->setAlignment(Qt::AlignCenter);

        verticalLayout_71->addWidget(labelEmpty);

        tabWidget->addTab(tabEmpty, QString());

        verticalLayout->addWidget(tabWidget);

        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 800, 25));
        MainWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        MainWindow->setStatusBar(statusbar);

        retranslateUi(MainWindow);

        tabWidget->setCurrentIndex(0);


        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "\320\234\320\275\320\276\320\263\320\276\321\204\321\203\320\275\320\272\321\206\320\270\320\276\320\275\320\260\320\273\321\214\320\275\320\276\320\265 \320\277\321\200\320\270\320\273\320\276\320\266\320\265\320\275\320\270\320\265", nullptr));
        groupBoxEmbed->setTitle(QCoreApplication::translate("MainWindow", "\320\222\320\275\320\265\320\264\321\200\320\265\320\275\320\270\320\265 \321\201\320\276\320\276\320\261\321\211\320\265\320\275\320\270\321\217", nullptr));
        editEmbedMessage->setPlaceholderText(QCoreApplication::translate("MainWindow", "\320\241\320\276\320\276\320\261\321\211\320\265\320\275\320\270\320\265 \320\264\320\273\321\217 \320\262\320\275\320\265\320\264\321\200\320\265\320\275\320\270\321\217", nullptr));
        btnSelectImageEmbed->setText(QCoreApplication::translate("MainWindow", "\320\222\321\213\320\261\321\200\320\260\321\202\321\214 \320\270\320\267\320\276\320\261\321\200\320\260\320\266\320\265\320\275\320\270\320\265", nullptr));
        btnEmbed->setText(QCoreApplication::translate("MainWindow", "\320\222\320\275\320\265\320\264\321\200\320\270\321\202\321\214", nullptr));
        btnSaveImage->setText(QCoreApplication::translate("MainWindow", "\320\241\320\276\321\205\321\200\320\260\320\275\320\270\321\202\321\214 \320\270\320\267\320\276\320\261\321\200\320\260\320\266\320\265\320\275\320\270\320\265", nullptr));
        groupBoxExtract->setTitle(QCoreApplication::translate("MainWindow", "\320\230\320\267\320\262\320\273\320\265\321\207\320\265\320\275\320\270\320\265 \321\201\320\276\320\276\320\261\321\211\320\265\320\275\320\270\321\217", nullptr));
        btnSelectImageExtract->setText(QCoreApplication::translate("MainWindow", "\320\222\321\213\320\261\321\200\320\260\321\202\321\214 \320\270\320\267\320\276\320\261\321\200\320\260\320\266\320\265\320\275\320\270\320\265", nullptr));
        btnExtract->setText(QCoreApplication::translate("MainWindow", "\320\230\320\267\320\262\320\273\320\265\321\207\321\214", nullptr));
        labelImage->setText(QCoreApplication::translate("MainWindow", "\320\230\320\267\320\276\320\261\321\200\320\260\320\266\320\265\320\275\320\270\320\265 \320\261\321\203\320\264\320\265\321\202 \320\276\321\202\320\276\320\261\321\200\320\260\320\266\320\260\321\202\321\214\321\201\321\217 \320\267\320\264\320\265\321\201\321\214", nullptr));
        textOutput->setPlaceholderText(QCoreApplication::translate("MainWindow", "\320\240\320\265\320\267\321\203\320\273\321\214\321\202\320\260\321\202\321\213 \320\261\321\203\320\264\321\203\321\202 \320\276\321\202\320\276\320\261\321\200\320\260\320\266\320\260\321\202\321\214\321\201\321\217 \320\267\320\264\320\265\321\201\321\214", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(tabSteganography), QCoreApplication::translate("MainWindow", "\320\241\321\202\320\265\320\263\320\260\320\275\320\276\320\263\321\200\320\260\321\204\320\270\321\217", nullptr));
        groupBoxFunction->setTitle(QCoreApplication::translate("MainWindow", "\320\244\321\203\320\275\320\272\321\206\320\270\321\217", nullptr));
        comboFunction->setItemText(0, QCoreApplication::translate("MainWindow", "x^2 - 4", nullptr));
        comboFunction->setItemText(1, QCoreApplication::translate("MainWindow", "sin(x) - 0.5", nullptr));
        comboFunction->setItemText(2, QCoreApplication::translate("MainWindow", "x^3 - 2*x - 5", nullptr));
        comboFunction->setItemText(3, QCoreApplication::translate("MainWindow", "exp(x) - 3", nullptr));
        comboFunction->setItemText(4, QCoreApplication::translate("MainWindow", "log(x) - 1", nullptr));

        groupBoxInterval->setTitle(QCoreApplication::translate("MainWindow", "\320\230\320\275\321\202\320\265\321\200\320\262\320\260\320\273", nullptr));
        labelA->setText(QCoreApplication::translate("MainWindow", "a:", nullptr));
        editA->setText(QCoreApplication::translate("MainWindow", "0", nullptr));
        labelB->setText(QCoreApplication::translate("MainWindow", "b:", nullptr));
        editB->setText(QCoreApplication::translate("MainWindow", "3", nullptr));
        groupBoxParams->setTitle(QCoreApplication::translate("MainWindow", "\320\237\320\260\321\200\320\260\320\274\320\265\321\202\321\200\321\213", nullptr));
        labelEpsilon->setText(QCoreApplication::translate("MainWindow", "\320\242\320\276\321\207\320\275\320\276\321\201\321\202\321\214:", nullptr));
        editEpsilon->setText(QCoreApplication::translate("MainWindow", "0.0001", nullptr));
        labelMaxIter->setText(QCoreApplication::translate("MainWindow", "\320\234\320\260\320\272\321\201. \320\270\321\202\320\265\321\200\320\260\321\206\320\270\320\271:", nullptr));
        editMaxIter->setText(QCoreApplication::translate("MainWindow", "100", nullptr));
        btnSolve->setText(QCoreApplication::translate("MainWindow", "\320\235\320\260\320\271\321\202\320\270 \320\272\320\276\321\200\320\265\320\275\321\214", nullptr));
        btnClear->setText(QCoreApplication::translate("MainWindow", "\320\236\321\207\320\270\321\201\321\202\320\270\321\202\321\214", nullptr));
        groupBoxResult->setTitle(QCoreApplication::translate("MainWindow", "\320\240\320\265\320\267\321\203\320\273\321\214\321\202\320\260\321\202", nullptr));
        textResult->setPlaceholderText(QCoreApplication::translate("MainWindow", "\320\240\320\265\320\267\321\203\320\273\321\214\321\202\320\260\321\202 \320\262\321\213\321\207\320\270\321\201\320\273\320\265\320\275\320\270\320\271", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(tabChordMethod), QCoreApplication::translate("MainWindow", "\320\234\320\265\321\202\320\276\320\264 \321\205\320\276\321\200\320\264", nullptr));
        groupBoxSHA384->setTitle(QCoreApplication::translate("MainWindow", "\320\245\320\265\321\210\320\270\321\200\320\276\320\262\320\260\320\275\320\270\320\265 SHA384", nullptr));
        editSha384Data->setPlaceholderText(QCoreApplication::translate("MainWindow", "\320\222\320\262\320\265\320\264\320\270\321\202\320\265 \320\264\320\260\320\275\320\275\321\213\320\265 \320\264\320\273\321\217 \321\205\320\265\321\210\320\270\321\200\320\276\320\262\320\260\320\275\320\270\321\217", nullptr));
        btnHashSha384->setText(QCoreApplication::translate("MainWindow", "\320\222\321\213\321\207\320\270\321\201\320\273\320\270\321\202\321\214 SHA384 \321\205\320\265\321\210", nullptr));
        editSha384Result->setPlaceholderText(QCoreApplication::translate("MainWindow", "\320\240\320\265\320\267\321\203\320\273\321\214\321\202\320\260\321\202 \321\205\320\265\321\210\320\270\321\200\320\276\320\262\320\260\320\275\320\270\321\217", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(tabSHA384), QCoreApplication::translate("MainWindow", "SHA384", nullptr));
        groupBoxAES->setTitle(QCoreApplication::translate("MainWindow", "AES \320\250\320\270\321\204\321\200\320\276\320\262\320\260\320\275\320\270\320\265/\320\224\320\265\321\210\320\270\321\204\321\200\320\276\320\262\320\260\320\275\320\270\320\265", nullptr));
        editAesKey->setPlaceholderText(QCoreApplication::translate("MainWindow", "\320\222\320\262\320\265\320\264\320\270\321\202\320\265 \320\272\320\273\321\216\321\207 (16, 24 \320\270\320\273\320\270 32 \320\261\320\260\320\271\321\202\320\260)", nullptr));
        editAesPlaintext->setPlaceholderText(QCoreApplication::translate("MainWindow", "\320\222\320\262\320\265\320\264\320\270\321\202\320\265 \320\276\321\202\320\272\321\200\321\213\321\202\321\213\320\271 \321\202\320\265\320\272\321\201\321\202", nullptr));
        btnEncryptAes->setText(QCoreApplication::translate("MainWindow", "\320\227\320\260\321\210\320\270\321\204\321\200\320\276\320\262\320\260\321\202\321\214", nullptr));
        editAesCiphertext->setPlaceholderText(QCoreApplication::translate("MainWindow", "\320\222\320\262\320\265\320\264\320\270\321\202\320\265 \320\267\320\260\321\210\320\270\321\204\321\200\320\276\320\262\320\260\320\275\320\275\321\213\320\271 \321\202\320\265\320\272\321\201\321\202", nullptr));
        btnDecryptAes->setText(QCoreApplication::translate("MainWindow", "\320\240\320\260\321\201\321\210\320\270\321\204\321\200\320\276\320\262\320\260\321\202\321\214", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(tabAES), QCoreApplication::translate("MainWindow", "AES", nullptr));
        labelEmpty->setText(QCoreApplication::translate("MainWindow", "\320\237\321\203\321\201\321\202\320\260\321\217 \320\262\320\272\320\273\320\260\320\264\320\272\320\260 \320\264\320\273\321\217 \320\261\321\203\320\264\321\203\321\211\320\265\320\263\320\276 \321\200\320\260\321\201\321\210\320\270\321\200\320\265\320\275\320\270\321\217", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(tabEmpty), QCoreApplication::translate("MainWindow", "\320\237\321\203\321\201\321\202\320\260\321\217 \320\262\320\272\320\273\320\260\320\264\320\272\320\260", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
