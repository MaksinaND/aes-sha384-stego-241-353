/********************************************************************************
** Form generated from reading UI file 'mainwindow_tabs.ui'
**
** Created by: Qt User Interface Compiler version 6.5.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_TABS_H
#define UI_MAINWINDOW_TABS_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QFormLayout>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTabWidget>
#include <QtWidgets/QTextBrowser>
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
    QFormLayout *formLayout_3;
    QLabel *labelRootText;
    QLabel *labelRoot;
    QLabel *labelFunctionValueText;
    QLabel *labelFunctionValue;
    QLabel *labelIterationsText;
    QLabel *labelIterations;
    QVBoxLayout *verticalLayout_10;
    QLabel *labelPlot;
    QTextEdit *textChordOutput;
    QWidget *tabAES;
    QVBoxLayout *verticalLayout_11;
    QHBoxLayout *horizontalLayout_3;
    QVBoxLayout *verticalLayout_12;
    QGroupBox *groupBoxAESSettings;
    QFormLayout *formLayout_4;
    QLabel *labelKeyAES;
    QLineEdit *editKeyAES;
    QLabel *labelKeySizeAES;
    QComboBox *comboKeySizeAES;
    QLabel *labelOutputFormatAES;
    QComboBox *comboOutputFormatAES;
    QLabel *labelKeySize;
    QPushButton *btnEncrypt;
    QPushButton *btnDecrypt;
    QPushButton *btnClearAES;
    QPushButton *btnCopyAESResult;
    QLabel *labelAESStatus;
    QVBoxLayout *verticalLayout_13;
    QGroupBox *groupBoxPlainText;
    QVBoxLayout *verticalLayout_14;
    QTextEdit *editPlainTextAES;
    QGroupBox *groupBoxCipherText;
    QVBoxLayout *verticalLayout_15;
    QTextEdit *editCipherTextAES;
    QWidget *tabSHA384;
    QVBoxLayout *verticalLayout_16;
    QHBoxLayout *horizontalLayout_4;
    QVBoxLayout *verticalLayout_17;
    QGroupBox *groupBoxSHA384Settings;
    QFormLayout *formLayout_5;
    QLabel *labelOutputFormatSHA384;
    QComboBox *comboOutputFormatSHA384;
    QPushButton *btnCalculateHash;
    QPushButton *btnClearSHA384;
    QPushButton *btnCopyHash;
    QGroupBox *groupBoxFileHash;
    QVBoxLayout *verticalLayout_18;
    QPushButton *btnSelectFile;
    QLabel *labelSelectedFile;
    QPushButton *btnCalculateFileHash;
    QGroupBox *groupBoxVerify;
    QVBoxLayout *verticalLayout_19;
    QLineEdit *editExpectedHash;
    QPushButton *btnVerifyHash;
    QLabel *labelVerifyResult;
    QLabel *labelSHA384Status;
    QVBoxLayout *verticalLayout_20;
    QGroupBox *groupBoxInputText;
    QVBoxLayout *verticalLayout_21;
    QTextEdit *editInputTextSHA384;
    QGroupBox *groupBoxHashResult;
    QVBoxLayout *verticalLayout_22;
    QLineEdit *editHashResult;
    QGroupBox *groupBoxInfo;
    QVBoxLayout *verticalLayout_23;
    QTextBrowser *textBrowserInfo;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName("MainWindow");
        MainWindow->resize(800, 600);
        MainWindow->setStyleSheet(QString::fromUtf8("background-color: #2E3440;\n"
"color: #D8DEE9; "));
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName("centralwidget");
        verticalLayout = new QVBoxLayout(centralwidget);
        verticalLayout->setObjectName("verticalLayout");
        tabWidget = new QTabWidget(centralwidget);
        tabWidget->setObjectName("tabWidget");
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
        tabSteganography->setObjectName("tabSteganography");
        verticalLayout_2 = new QVBoxLayout(tabSteganography);
        verticalLayout_2->setObjectName("verticalLayout_2");
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName("horizontalLayout");
        verticalLayout_3 = new QVBoxLayout();
        verticalLayout_3->setObjectName("verticalLayout_3");
        groupBoxEmbed = new QGroupBox(tabSteganography);
        groupBoxEmbed->setObjectName("groupBoxEmbed");
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
        verticalLayout_5->setObjectName("verticalLayout_5");
        editEmbedMessage = new QLineEdit(groupBoxEmbed);
        editEmbedMessage->setObjectName("editEmbedMessage");
        editEmbedMessage->setStyleSheet(QString::fromUtf8("QLineEdit {\n"
"    background-color: #3B4252;\n"
"    color: #D8DEE9;\n"
"    border: 1px solid #4C566A;\n"
"    border-radius: 4px;\n"
"    padding: 4px;\n"
"}"));

        verticalLayout_5->addWidget(editEmbedMessage);

        btnSelectImageEmbed = new QPushButton(groupBoxEmbed);
        btnSelectImageEmbed->setObjectName("btnSelectImageEmbed");
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
        btnEmbed->setObjectName("btnEmbed");
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
        btnSaveImage->setObjectName("btnSaveImage");
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
        groupBoxExtract->setObjectName("groupBoxExtract");
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
        verticalLayout_6->setObjectName("verticalLayout_6");
        btnSelectImageExtract = new QPushButton(groupBoxExtract);
        btnSelectImageExtract->setObjectName("btnSelectImageExtract");
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
        btnExtract->setObjectName("btnExtract");
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
        verticalLayout_4->setObjectName("verticalLayout_4");
        labelImage = new QLabel(tabSteganography);
        labelImage->setObjectName("labelImage");
        labelImage->setMinimumSize(QSize(400, 300));
        labelImage->setStyleSheet(QString::fromUtf8("QLabel {\n"
"    background-color: #3B4252;\n"
"    border: 1px solid #4C566A;\n"
"    border-radius: 5px;\n"
"}"));
        labelImage->setAlignment(Qt::AlignCenter);

        verticalLayout_4->addWidget(labelImage);

        textOutput = new QTextEdit(tabSteganography);
        textOutput->setObjectName("textOutput");
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
        tabChordMethod->setObjectName("tabChordMethod");
        verticalLayout_7 = new QVBoxLayout(tabChordMethod);
        verticalLayout_7->setObjectName("verticalLayout_7");
        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName("horizontalLayout_2");
        verticalLayout_8 = new QVBoxLayout();
        verticalLayout_8->setObjectName("verticalLayout_8");
        groupBoxFunction = new QGroupBox(tabChordMethod);
        groupBoxFunction->setObjectName("groupBoxFunction");
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
        verticalLayout_9->setObjectName("verticalLayout_9");
        comboFunction = new QComboBox(groupBoxFunction);
        comboFunction->addItem(QString());
        comboFunction->addItem(QString());
        comboFunction->addItem(QString());
        comboFunction->addItem(QString());
        comboFunction->addItem(QString());
        comboFunction->setObjectName("comboFunction");
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
        groupBoxInterval->setObjectName("groupBoxInterval");
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
        formLayout->setObjectName("formLayout");
        labelA = new QLabel(groupBoxInterval);
        labelA->setObjectName("labelA");

        formLayout->setWidget(0, QFormLayout::LabelRole, labelA);

        editA = new QLineEdit(groupBoxInterval);
        editA->setObjectName("editA");
        editA->setStyleSheet(QString::fromUtf8("QLineEdit {\n"
"    background-color: #3B4252;\n"
"    color: #D8DEE9;\n"
"    border: 1px solid #4C566A;\n"
"    border-radius: 4px;\n"
"    padding: 4px;\n"
"}"));

        formLayout->setWidget(0, QFormLayout::FieldRole, editA);

        labelB = new QLabel(groupBoxInterval);
        labelB->setObjectName("labelB");

        formLayout->setWidget(1, QFormLayout::LabelRole, labelB);

        editB = new QLineEdit(groupBoxInterval);
        editB->setObjectName("editB");
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
        groupBoxParams->setObjectName("groupBoxParams");
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
        formLayout_2->setObjectName("formLayout_2");
        labelEpsilon = new QLabel(groupBoxParams);
        labelEpsilon->setObjectName("labelEpsilon");

        formLayout_2->setWidget(0, QFormLayout::LabelRole, labelEpsilon);

        editEpsilon = new QLineEdit(groupBoxParams);
        editEpsilon->setObjectName("editEpsilon");
        editEpsilon->setStyleSheet(QString::fromUtf8("QLineEdit {\n"
"    background-color: #3B4252;\n"
"    color: #D8DEE9;\n"
"    border: 1px solid #4C566A;\n"
"    border-radius: 4px;\n"
"    padding: 4px;\n"
"}"));

        formLayout_2->setWidget(0, QFormLayout::FieldRole, editEpsilon);

        labelMaxIter = new QLabel(groupBoxParams);
        labelMaxIter->setObjectName("labelMaxIter");

        formLayout_2->setWidget(1, QFormLayout::LabelRole, labelMaxIter);

        editMaxIter = new QLineEdit(groupBoxParams);
        editMaxIter->setObjectName("editMaxIter");
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
        btnSolve->setObjectName("btnSolve");
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
        btnClear->setObjectName("btnClear");
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
        groupBoxResult->setObjectName("groupBoxResult");
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
        formLayout_3 = new QFormLayout(groupBoxResult);
        formLayout_3->setObjectName("formLayout_3");
        labelRootText = new QLabel(groupBoxResult);
        labelRootText->setObjectName("labelRootText");

        formLayout_3->setWidget(0, QFormLayout::LabelRole, labelRootText);

        labelRoot = new QLabel(groupBoxResult);
        labelRoot->setObjectName("labelRoot");
        labelRoot->setStyleSheet(QString::fromUtf8("QLabel {\n"
"    background-color: #3B4252;\n"
"    color: #A3BE8C;\n"
"    border: 1px solid #4C566A;\n"
"    border-radius: 4px;\n"
"    padding: 4px;\n"
"}"));

        formLayout_3->setWidget(0, QFormLayout::FieldRole, labelRoot);

        labelFunctionValueText = new QLabel(groupBoxResult);
        labelFunctionValueText->setObjectName("labelFunctionValueText");

        formLayout_3->setWidget(1, QFormLayout::LabelRole, labelFunctionValueText);

        labelFunctionValue = new QLabel(groupBoxResult);
        labelFunctionValue->setObjectName("labelFunctionValue");
        labelFunctionValue->setStyleSheet(QString::fromUtf8("QLabel {\n"
"    background-color: #3B4252;\n"
"    color: #A3BE8C;\n"
"    border: 1px solid #4C566A;\n"
"    border-radius: 4px;\n"
"    padding: 4px;\n"
"}"));

        formLayout_3->setWidget(1, QFormLayout::FieldRole, labelFunctionValue);

        labelIterationsText = new QLabel(groupBoxResult);
        labelIterationsText->setObjectName("labelIterationsText");

        formLayout_3->setWidget(2, QFormLayout::LabelRole, labelIterationsText);

        labelIterations = new QLabel(groupBoxResult);
        labelIterations->setObjectName("labelIterations");
        labelIterations->setStyleSheet(QString::fromUtf8("QLabel {\n"
"    background-color: #3B4252;\n"
"    color: #A3BE8C;\n"
"    border: 1px solid #4C566A;\n"
"    border-radius: 4px;\n"
"    padding: 4px;\n"
"}"));

        formLayout_3->setWidget(2, QFormLayout::FieldRole, labelIterations);


        verticalLayout_8->addWidget(groupBoxResult);


        horizontalLayout_2->addLayout(verticalLayout_8);

        verticalLayout_10 = new QVBoxLayout();
        verticalLayout_10->setObjectName("verticalLayout_10");
        labelPlot = new QLabel(tabChordMethod);
        labelPlot->setObjectName("labelPlot");
        labelPlot->setMinimumSize(QSize(400, 300));
        labelPlot->setStyleSheet(QString::fromUtf8("QLabel {\n"
"    background-color: #3B4252;\n"
"    border: 1px solid #4C566A;\n"
"    border-radius: 5px;\n"
"}"));
        labelPlot->setAlignment(Qt::AlignCenter);

        verticalLayout_10->addWidget(labelPlot);

        textChordOutput = new QTextEdit(tabChordMethod);
        textChordOutput->setObjectName("textChordOutput");
        textChordOutput->setStyleSheet(QString::fromUtf8("QTextEdit {\n"
"    background-color: #3B4252;\n"
"    color: #D8DEE9;\n"
"    border: 1px solid #4C566A;\n"
"    border-radius: 5px;\n"
"    padding: 5px;\n"
"}"));
        textChordOutput->setReadOnly(true);

        verticalLayout_10->addWidget(textChordOutput);


        horizontalLayout_2->addLayout(verticalLayout_10);


        verticalLayout_7->addLayout(horizontalLayout_2);

        tabWidget->addTab(tabChordMethod, QString());
        tabAES = new QWidget();
        tabAES->setObjectName("tabAES");
        verticalLayout_11 = new QVBoxLayout(tabAES);
        verticalLayout_11->setObjectName("verticalLayout_11");
        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setObjectName("horizontalLayout_3");
        verticalLayout_12 = new QVBoxLayout();
        verticalLayout_12->setObjectName("verticalLayout_12");
        groupBoxAESSettings = new QGroupBox(tabAES);
        groupBoxAESSettings->setObjectName("groupBoxAESSettings");
        groupBoxAESSettings->setStyleSheet(QString::fromUtf8("QGroupBox {\n"
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
        formLayout_4 = new QFormLayout(groupBoxAESSettings);
        formLayout_4->setObjectName("formLayout_4");
        labelKeyAES = new QLabel(groupBoxAESSettings);
        labelKeyAES->setObjectName("labelKeyAES");

        formLayout_4->setWidget(0, QFormLayout::LabelRole, labelKeyAES);

        editKeyAES = new QLineEdit(groupBoxAESSettings);
        editKeyAES->setObjectName("editKeyAES");
        editKeyAES->setStyleSheet(QString::fromUtf8("QLineEdit {\n"
"    background-color: #3B4252;\n"
"    color: #D8DEE9;\n"
"    border: 1px solid #4C566A;\n"
"    border-radius: 4px;\n"
"    padding: 4px;\n"
"}"));
        editKeyAES->setEchoMode(QLineEdit::Password);

        formLayout_4->setWidget(0, QFormLayout::FieldRole, editKeyAES);

        labelKeySizeAES = new QLabel(groupBoxAESSettings);
        labelKeySizeAES->setObjectName("labelKeySizeAES");

        formLayout_4->setWidget(1, QFormLayout::LabelRole, labelKeySizeAES);

        comboKeySizeAES = new QComboBox(groupBoxAESSettings);
        comboKeySizeAES->addItem(QString());
        comboKeySizeAES->addItem(QString());
        comboKeySizeAES->addItem(QString());
        comboKeySizeAES->setObjectName("comboKeySizeAES");
        comboKeySizeAES->setStyleSheet(QString::fromUtf8("QComboBox {\n"
"    background-color: #3B4252;\n"
"    color: #D8DEE9;\n"
"    border: 1px solid #4C566A;\n"
"    border-radius: 4px;\n"
"    padding: 4px;\n"
"}"));

        formLayout_4->setWidget(1, QFormLayout::FieldRole, comboKeySizeAES);

        labelOutputFormatAES = new QLabel(groupBoxAESSettings);
        labelOutputFormatAES->setObjectName("labelOutputFormatAES");

        formLayout_4->setWidget(2, QFormLayout::LabelRole, labelOutputFormatAES);

        comboOutputFormatAES = new QComboBox(groupBoxAESSettings);
        comboOutputFormatAES->addItem(QString());
        comboOutputFormatAES->addItem(QString());
        comboOutputFormatAES->setObjectName("comboOutputFormatAES");
        comboOutputFormatAES->setStyleSheet(QString::fromUtf8("QComboBox {\n"
"    background-color: #3B4252;\n"
"    color: #D8DEE9;\n"
"    border: 1px solid #4C566A;\n"
"    border-radius: 4px;\n"
"    padding: 4px;\n"
"}"));

        formLayout_4->setWidget(2, QFormLayout::FieldRole, comboOutputFormatAES);


        verticalLayout_12->addWidget(groupBoxAESSettings);

        labelKeySize = new QLabel(tabAES);
        labelKeySize->setObjectName("labelKeySize");
        labelKeySize->setStyleSheet(QString::fromUtf8("QLabel {\n"
"    background-color: #3B4252;\n"
"    color: #88C0D0;\n"
"    border: 1px solid #4C566A;\n"
"    border-radius: 4px;\n"
"    padding: 4px;\n"
"}"));

        verticalLayout_12->addWidget(labelKeySize);

        btnEncrypt = new QPushButton(tabAES);
        btnEncrypt->setObjectName("btnEncrypt");
        btnEncrypt->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"    background-color: #A3BE8C;\n"
"    color: white;\n"
"    border-radius: 5px;\n"
"    padding: 5px;\n"
"}\n"
"QPushButton:hover {\n"
"    background-color: #B9D39C;\n"
"}"));

        verticalLayout_12->addWidget(btnEncrypt);

        btnDecrypt = new QPushButton(tabAES);
        btnDecrypt->setObjectName("btnDecrypt");
        btnDecrypt->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"    background-color: #EBCB8B;\n"
"    color: white;\n"
"    border-radius: 5px;\n"
"    padding: 5px;\n"
"}\n"
"QPushButton:hover {\n"
"    background-color: #FBDB9B;\n"
"}"));

        verticalLayout_12->addWidget(btnDecrypt);

        btnClearAES = new QPushButton(tabAES);
        btnClearAES->setObjectName("btnClearAES");
        btnClearAES->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"    background-color: #BF616A;\n"
"    color: white;\n"
"    border-radius: 5px;\n"
"    padding: 5px;\n"
"}\n"
"QPushButton:hover {\n"
"    background-color: #CF717A;\n"
"}"));

        verticalLayout_12->addWidget(btnClearAES);

        btnCopyAESResult = new QPushButton(tabAES);
        btnCopyAESResult->setObjectName("btnCopyAESResult");
        btnCopyAESResult->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"    background-color: #5E81AC;\n"
"    color: white;\n"
"    border-radius: 5px;\n"
"    padding: 5px;\n"
"}\n"
"QPushButton:hover {\n"
"    background-color: #81A1C1;\n"
"}"));

        verticalLayout_12->addWidget(btnCopyAESResult);

        labelAESStatus = new QLabel(tabAES);
        labelAESStatus->setObjectName("labelAESStatus");
        labelAESStatus->setStyleSheet(QString::fromUtf8("QLabel {\n"
"    background-color: #3B4252;\n"
"    color: #88C0D0;\n"
"    border: 1px solid #4C566A;\n"
"    border-radius: 4px;\n"
"    padding: 4px;\n"
"}"));

        verticalLayout_12->addWidget(labelAESStatus);


        horizontalLayout_3->addLayout(verticalLayout_12);

        verticalLayout_13 = new QVBoxLayout();
        verticalLayout_13->setObjectName("verticalLayout_13");
        groupBoxPlainText = new QGroupBox(tabAES);
        groupBoxPlainText->setObjectName("groupBoxPlainText");
        groupBoxPlainText->setStyleSheet(QString::fromUtf8("QGroupBox {\n"
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
        verticalLayout_14 = new QVBoxLayout(groupBoxPlainText);
        verticalLayout_14->setObjectName("verticalLayout_14");
        editPlainTextAES = new QTextEdit(groupBoxPlainText);
        editPlainTextAES->setObjectName("editPlainTextAES");
        editPlainTextAES->setStyleSheet(QString::fromUtf8("QTextEdit {\n"
"    background-color: #3B4252;\n"
"    color: #D8DEE9;\n"
"    border: 1px solid #4C566A;\n"
"    border-radius: 5px;\n"
"    padding: 5px;\n"
"}"));

        verticalLayout_14->addWidget(editPlainTextAES);


        verticalLayout_13->addWidget(groupBoxPlainText);

        groupBoxCipherText = new QGroupBox(tabAES);
        groupBoxCipherText->setObjectName("groupBoxCipherText");
        groupBoxCipherText->setStyleSheet(QString::fromUtf8("QGroupBox {\n"
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
        verticalLayout_15 = new QVBoxLayout(groupBoxCipherText);
        verticalLayout_15->setObjectName("verticalLayout_15");
        editCipherTextAES = new QTextEdit(groupBoxCipherText);
        editCipherTextAES->setObjectName("editCipherTextAES");
        editCipherTextAES->setStyleSheet(QString::fromUtf8("QTextEdit {\n"
"    background-color: #3B4252;\n"
"    color: #D8DEE9;\n"
"    border: 1px solid #4C566A;\n"
"    border-radius: 5px;\n"
"    padding: 5px;\n"
"}"));

        verticalLayout_15->addWidget(editCipherTextAES);


        verticalLayout_13->addWidget(groupBoxCipherText);


        horizontalLayout_3->addLayout(verticalLayout_13);


        verticalLayout_11->addLayout(horizontalLayout_3);

        tabWidget->addTab(tabAES, QString());
        tabSHA384 = new QWidget();
        tabSHA384->setObjectName("tabSHA384");
        verticalLayout_16 = new QVBoxLayout(tabSHA384);
        verticalLayout_16->setObjectName("verticalLayout_16");
        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setObjectName("horizontalLayout_4");
        verticalLayout_17 = new QVBoxLayout();
        verticalLayout_17->setObjectName("verticalLayout_17");
        groupBoxSHA384Settings = new QGroupBox(tabSHA384);
        groupBoxSHA384Settings->setObjectName("groupBoxSHA384Settings");
        groupBoxSHA384Settings->setStyleSheet(QString::fromUtf8("QGroupBox {\n"
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
        formLayout_5 = new QFormLayout(groupBoxSHA384Settings);
        formLayout_5->setObjectName("formLayout_5");
        labelOutputFormatSHA384 = new QLabel(groupBoxSHA384Settings);
        labelOutputFormatSHA384->setObjectName("labelOutputFormatSHA384");

        formLayout_5->setWidget(0, QFormLayout::LabelRole, labelOutputFormatSHA384);

        comboOutputFormatSHA384 = new QComboBox(groupBoxSHA384Settings);
        comboOutputFormatSHA384->addItem(QString());
        comboOutputFormatSHA384->addItem(QString());
        comboOutputFormatSHA384->setObjectName("comboOutputFormatSHA384");
        comboOutputFormatSHA384->setStyleSheet(QString::fromUtf8("QComboBox {\n"
"    background-color: #3B4252;\n"
"    color: #D8DEE9;\n"
"    border: 1px solid #4C566A;\n"
"    border-radius: 4px;\n"
"    padding: 4px;\n"
"}"));

        formLayout_5->setWidget(0, QFormLayout::FieldRole, comboOutputFormatSHA384);


        verticalLayout_17->addWidget(groupBoxSHA384Settings);

        btnCalculateHash = new QPushButton(tabSHA384);
        btnCalculateHash->setObjectName("btnCalculateHash");
        btnCalculateHash->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"    background-color: #A3BE8C;\n"
"    color: white;\n"
"    border-radius: 5px;\n"
"    padding: 5px;\n"
"}\n"
"QPushButton:hover {\n"
"    background-color: #B9D39C;\n"
"}"));

        verticalLayout_17->addWidget(btnCalculateHash);

        btnClearSHA384 = new QPushButton(tabSHA384);
        btnClearSHA384->setObjectName("btnClearSHA384");
        btnClearSHA384->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"    background-color: #BF616A;\n"
"    color: white;\n"
"    border-radius: 5px;\n"
"    padding: 5px;\n"
"}\n"
"QPushButton:hover {\n"
"    background-color: #CF717A;\n"
"}"));

        verticalLayout_17->addWidget(btnClearSHA384);

        btnCopyHash = new QPushButton(tabSHA384);
        btnCopyHash->setObjectName("btnCopyHash");
        btnCopyHash->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"    background-color: #5E81AC;\n"
"    color: white;\n"
"    border-radius: 5px;\n"
"    padding: 5px;\n"
"}\n"
"QPushButton:hover {\n"
"    background-color: #81A1C1;\n"
"}"));

        verticalLayout_17->addWidget(btnCopyHash);

        groupBoxFileHash = new QGroupBox(tabSHA384);
        groupBoxFileHash->setObjectName("groupBoxFileHash");
        groupBoxFileHash->setStyleSheet(QString::fromUtf8("QGroupBox {\n"
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
        verticalLayout_18 = new QVBoxLayout(groupBoxFileHash);
        verticalLayout_18->setObjectName("verticalLayout_18");
        btnSelectFile = new QPushButton(groupBoxFileHash);
        btnSelectFile->setObjectName("btnSelectFile");
        btnSelectFile->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"    background-color: #5E81AC;\n"
"    color: white;\n"
"    border-radius: 5px;\n"
"    padding: 5px;\n"
"}\n"
"QPushButton:hover {\n"
"    background-color: #81A1C1;\n"
"}"));

        verticalLayout_18->addWidget(btnSelectFile);

        labelSelectedFile = new QLabel(groupBoxFileHash);
        labelSelectedFile->setObjectName("labelSelectedFile");
        labelSelectedFile->setStyleSheet(QString::fromUtf8("QLabel {\n"
"    background-color: #3B4252;\n"
"    color: #D8DEE9;\n"
"    border: 1px solid #4C566A;\n"
"    border-radius: 4px;\n"
"    padding: 4px;\n"
"}"));

        verticalLayout_18->addWidget(labelSelectedFile);

        btnCalculateFileHash = new QPushButton(groupBoxFileHash);
        btnCalculateFileHash->setObjectName("btnCalculateFileHash");
        btnCalculateFileHash->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"    background-color: #A3BE8C;\n"
"    color: white;\n"
"    border-radius: 5px;\n"
"    padding: 5px;\n"
"}\n"
"QPushButton:hover {\n"
"    background-color: #B9D39C;\n"
"}"));

        verticalLayout_18->addWidget(btnCalculateFileHash);


        verticalLayout_17->addWidget(groupBoxFileHash);

        groupBoxVerify = new QGroupBox(tabSHA384);
        groupBoxVerify->setObjectName("groupBoxVerify");
        groupBoxVerify->setStyleSheet(QString::fromUtf8("QGroupBox {\n"
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
        verticalLayout_19 = new QVBoxLayout(groupBoxVerify);
        verticalLayout_19->setObjectName("verticalLayout_19");
        editExpectedHash = new QLineEdit(groupBoxVerify);
        editExpectedHash->setObjectName("editExpectedHash");
        editExpectedHash->setStyleSheet(QString::fromUtf8("QLineEdit {\n"
"    background-color: #3B4252;\n"
"    color: #D8DEE9;\n"
"    border: 1px solid #4C566A;\n"
"    border-radius: 4px;\n"
"    padding: 4px;\n"
"}"));

        verticalLayout_19->addWidget(editExpectedHash);

        btnVerifyHash = new QPushButton(groupBoxVerify);
        btnVerifyHash->setObjectName("btnVerifyHash");
        btnVerifyHash->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"    background-color: #EBCB8B;\n"
"    color: white;\n"
"    border-radius: 5px;\n"
"    padding: 5px;\n"
"}\n"
"QPushButton:hover {\n"
"    background-color: #FBDB9B;\n"
"}"));

        verticalLayout_19->addWidget(btnVerifyHash);

        labelVerifyResult = new QLabel(groupBoxVerify);
        labelVerifyResult->setObjectName("labelVerifyResult");
        labelVerifyResult->setStyleSheet(QString::fromUtf8("QLabel {\n"
"    background-color: #3B4252;\n"
"    color: #D8DEE9;\n"
"    border: 1px solid #4C566A;\n"
"    border-radius: 4px;\n"
"    padding: 4px;\n"
"}"));

        verticalLayout_19->addWidget(labelVerifyResult);


        verticalLayout_17->addWidget(groupBoxVerify);

        labelSHA384Status = new QLabel(tabSHA384);
        labelSHA384Status->setObjectName("labelSHA384Status");
        labelSHA384Status->setStyleSheet(QString::fromUtf8("QLabel {\n"
"    background-color: #3B4252;\n"
"    color: #88C0D0;\n"
"    border: 1px solid #4C566A;\n"
"    border-radius: 4px;\n"
"    padding: 4px;\n"
"}"));

        verticalLayout_17->addWidget(labelSHA384Status);


        horizontalLayout_4->addLayout(verticalLayout_17);

        verticalLayout_20 = new QVBoxLayout();
        verticalLayout_20->setObjectName("verticalLayout_20");
        groupBoxInputText = new QGroupBox(tabSHA384);
        groupBoxInputText->setObjectName("groupBoxInputText");
        groupBoxInputText->setStyleSheet(QString::fromUtf8("QGroupBox {\n"
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
        verticalLayout_21 = new QVBoxLayout(groupBoxInputText);
        verticalLayout_21->setObjectName("verticalLayout_21");
        editInputTextSHA384 = new QTextEdit(groupBoxInputText);
        editInputTextSHA384->setObjectName("editInputTextSHA384");
        editInputTextSHA384->setStyleSheet(QString::fromUtf8("QTextEdit {\n"
"    background-color: #3B4252;\n"
"    color: #D8DEE9;\n"
"    border: 1px solid #4C566A;\n"
"    border-radius: 5px;\n"
"    padding: 5px;\n"
"}"));

        verticalLayout_21->addWidget(editInputTextSHA384);


        verticalLayout_20->addWidget(groupBoxInputText);

        groupBoxHashResult = new QGroupBox(tabSHA384);
        groupBoxHashResult->setObjectName("groupBoxHashResult");
        groupBoxHashResult->setStyleSheet(QString::fromUtf8("QGroupBox {\n"
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
        verticalLayout_22 = new QVBoxLayout(groupBoxHashResult);
        verticalLayout_22->setObjectName("verticalLayout_22");
        editHashResult = new QLineEdit(groupBoxHashResult);
        editHashResult->setObjectName("editHashResult");
        editHashResult->setStyleSheet(QString::fromUtf8("QLineEdit {\n"
"    background-color: #3B4252;\n"
"    color: #D8DEE9;\n"
"    border: 1px solid #4C566A;\n"
"    border-radius: 4px;\n"
"    padding: 4px;\n"
"}"));
        editHashResult->setReadOnly(true);

        verticalLayout_22->addWidget(editHashResult);


        verticalLayout_20->addWidget(groupBoxHashResult);

        groupBoxInfo = new QGroupBox(tabSHA384);
        groupBoxInfo->setObjectName("groupBoxInfo");
        groupBoxInfo->setStyleSheet(QString::fromUtf8("QGroupBox {\n"
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
        verticalLayout_23 = new QVBoxLayout(groupBoxInfo);
        verticalLayout_23->setObjectName("verticalLayout_23");
        textBrowserInfo = new QTextBrowser(groupBoxInfo);
        textBrowserInfo->setObjectName("textBrowserInfo");
        textBrowserInfo->setStyleSheet(QString::fromUtf8("QTextBrowser {\n"
"    background-color: #3B4252;\n"
"    color: #D8DEE9;\n"
"    border: 1px solid #4C566A;\n"
"    border-radius: 5px;\n"
"    padding: 5px;\n"
"}"));

        verticalLayout_23->addWidget(textBrowserInfo);


        verticalLayout_20->addWidget(groupBoxInfo);


        horizontalLayout_4->addLayout(verticalLayout_20);


        verticalLayout_16->addLayout(horizontalLayout_4);

        tabWidget->addTab(tabSHA384, QString());

        verticalLayout->addWidget(tabWidget);

        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName("menubar");
        menubar->setGeometry(QRect(0, 0, 800, 25));
        MainWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName("statusbar");
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
        labelRootText->setText(QCoreApplication::translate("MainWindow", "\320\232\320\276\321\200\320\265\320\275\321\214:", nullptr));
        labelRoot->setText(QCoreApplication::translate("MainWindow", "-", nullptr));
        labelFunctionValueText->setText(QCoreApplication::translate("MainWindow", "f(x):", nullptr));
        labelFunctionValue->setText(QCoreApplication::translate("MainWindow", "-", nullptr));
        labelIterationsText->setText(QCoreApplication::translate("MainWindow", "\320\230\321\202\320\265\321\200\320\260\321\206\320\270\320\271:", nullptr));
        labelIterations->setText(QCoreApplication::translate("MainWindow", "-", nullptr));
        labelPlot->setText(QCoreApplication::translate("MainWindow", "\320\223\321\200\320\260\321\204\320\270\320\272 \321\204\321\203\320\275\320\272\321\206\320\270\320\270", nullptr));
        textChordOutput->setPlaceholderText(QCoreApplication::translate("MainWindow", "\320\240\320\265\320\267\321\203\320\273\321\214\321\202\320\260\321\202\321\213 \320\261\321\203\320\264\321\203\321\202 \320\276\321\202\320\276\320\261\321\200\320\260\320\266\320\260\321\202\321\214\321\201\321\217 \320\267\320\264\320\265\321\201\321\214", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(tabChordMethod), QCoreApplication::translate("MainWindow", "\320\234\320\265\321\202\320\276\320\264 \321\205\320\276\321\200\320\264", nullptr));
        groupBoxAESSettings->setTitle(QCoreApplication::translate("MainWindow", "\320\235\320\260\321\201\321\202\321\200\320\276\320\271\320\272\320\270 AES", nullptr));
        labelKeyAES->setText(QCoreApplication::translate("MainWindow", "\320\232\320\273\321\216\321\207:", nullptr));
        editKeyAES->setPlaceholderText(QCoreApplication::translate("MainWindow", "\320\222\320\262\320\265\320\264\320\270\321\202\320\265 \320\272\320\273\321\216\321\207 \321\210\320\270\321\204\321\200\320\276\320\262\320\260\320\275\320\270\321\217", nullptr));
        labelKeySizeAES->setText(QCoreApplication::translate("MainWindow", "\320\240\320\260\320\267\320\274\320\265\321\200 \320\272\320\273\321\216\321\207\320\260:", nullptr));
        comboKeySizeAES->setItemText(0, QCoreApplication::translate("MainWindow", "128 \320\261\320\270\321\202", nullptr));
        comboKeySizeAES->setItemText(1, QCoreApplication::translate("MainWindow", "192 \320\261\320\270\321\202", nullptr));
        comboKeySizeAES->setItemText(2, QCoreApplication::translate("MainWindow", "256 \320\261\320\270\321\202", nullptr));

        labelOutputFormatAES->setText(QCoreApplication::translate("MainWindow", "\320\244\320\276\321\200\320\274\320\260\321\202 \320\262\321\213\320\262\320\276\320\264\320\260:", nullptr));
        comboOutputFormatAES->setItemText(0, QCoreApplication::translate("MainWindow", "Hex", nullptr));
        comboOutputFormatAES->setItemText(1, QCoreApplication::translate("MainWindow", "Base64", nullptr));

        labelKeySize->setText(QCoreApplication::translate("MainWindow", "\320\240\320\260\320\267\320\274\320\265\321\200 \320\272\320\273\321\216\321\207\320\260: 128 \320\261\320\270\321\202 (16 \320\261\320\260\320\271\321\202)", nullptr));
        btnEncrypt->setText(QCoreApplication::translate("MainWindow", "\320\227\320\260\321\210\320\270\321\204\321\200\320\276\320\262\320\260\321\202\321\214", nullptr));
        btnDecrypt->setText(QCoreApplication::translate("MainWindow", "\320\224\320\265\321\210\320\270\321\204\321\200\320\276\320\262\320\260\321\202\321\214", nullptr));
        btnClearAES->setText(QCoreApplication::translate("MainWindow", "\320\236\321\207\320\270\321\201\321\202\320\270\321\202\321\214", nullptr));
        btnCopyAESResult->setText(QCoreApplication::translate("MainWindow", "\320\232\320\276\320\277\320\270\321\200\320\276\320\262\320\260\321\202\321\214 \321\200\320\265\320\267\321\203\320\273\321\214\321\202\320\260\321\202", nullptr));
        labelAESStatus->setText(QCoreApplication::translate("MainWindow", "\320\241\321\202\320\260\321\202\321\203\321\201: \320\223\320\276\321\202\320\276\320\262", nullptr));
        groupBoxPlainText->setTitle(QCoreApplication::translate("MainWindow", "\320\230\321\201\321\205\320\276\320\264\320\275\321\213\320\271 \321\202\320\265\320\272\321\201\321\202", nullptr));
        editPlainTextAES->setPlaceholderText(QCoreApplication::translate("MainWindow", "\320\222\320\262\320\265\320\264\320\270\321\202\320\265 \321\202\320\265\320\272\321\201\321\202 \320\264\320\273\321\217 \321\210\320\270\321\204\321\200\320\276\320\262\320\260\320\275\320\270\321\217", nullptr));
        groupBoxCipherText->setTitle(QCoreApplication::translate("MainWindow", "\320\227\320\260\321\210\320\270\321\204\321\200\320\276\320\262\320\260\320\275\320\275\321\213\320\271 \321\202\320\265\320\272\321\201\321\202", nullptr));
        editCipherTextAES->setPlaceholderText(QCoreApplication::translate("MainWindow", "\320\227\320\260\321\210\320\270\321\204\321\200\320\276\320\262\320\260\320\275\320\275\321\213\320\271 \321\202\320\265\320\272\321\201\321\202 \320\261\321\203\320\264\320\265\321\202 \320\276\321\202\320\276\320\261\321\200\320\260\320\266\320\260\321\202\321\214\321\201\321\217 \320\267\320\264\320\265\321\201\321\214", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(tabAES), QCoreApplication::translate("MainWindow", "AES", nullptr));
        groupBoxSHA384Settings->setTitle(QCoreApplication::translate("MainWindow", "\320\235\320\260\321\201\321\202\321\200\320\276\320\271\320\272\320\270 SHA-384", nullptr));
        labelOutputFormatSHA384->setText(QCoreApplication::translate("MainWindow", "\320\244\320\276\321\200\320\274\320\260\321\202 \320\262\321\213\320\262\320\276\320\264\320\260:", nullptr));
        comboOutputFormatSHA384->setItemText(0, QCoreApplication::translate("MainWindow", "Hex", nullptr));
        comboOutputFormatSHA384->setItemText(1, QCoreApplication::translate("MainWindow", "Base64", nullptr));

        btnCalculateHash->setText(QCoreApplication::translate("MainWindow", "\320\222\321\213\321\207\320\270\321\201\320\273\320\270\321\202\321\214 \321\205\320\265\321\210", nullptr));
        btnClearSHA384->setText(QCoreApplication::translate("MainWindow", "\320\236\321\207\320\270\321\201\321\202\320\270\321\202\321\214", nullptr));
        btnCopyHash->setText(QCoreApplication::translate("MainWindow", "\320\232\320\276\320\277\320\270\321\200\320\276\320\262\320\260\321\202\321\214 \321\205\320\265\321\210", nullptr));
        groupBoxFileHash->setTitle(QCoreApplication::translate("MainWindow", "\320\245\320\265\321\210\320\270\321\200\320\276\320\262\320\260\320\275\320\270\320\265 \321\204\320\260\320\271\320\273\320\260", nullptr));
        btnSelectFile->setText(QCoreApplication::translate("MainWindow", "\320\222\321\213\320\261\321\200\320\260\321\202\321\214 \321\204\320\260\320\271\320\273", nullptr));
        labelSelectedFile->setText(QCoreApplication::translate("MainWindow", "\320\244\320\260\320\271\320\273 \320\275\320\265 \320\262\321\213\320\261\321\200\320\260\320\275", nullptr));
        btnCalculateFileHash->setText(QCoreApplication::translate("MainWindow", "\320\222\321\213\321\207\320\270\321\201\320\273\320\270\321\202\321\214 \321\205\320\265\321\210 \321\204\320\260\320\271\320\273\320\260", nullptr));
        groupBoxVerify->setTitle(QCoreApplication::translate("MainWindow", "\320\237\321\200\320\276\320\262\320\265\321\200\320\272\320\260 \321\205\320\265\321\210\320\260", nullptr));
        editExpectedHash->setPlaceholderText(QCoreApplication::translate("MainWindow", "\320\222\320\262\320\265\320\264\320\270\321\202\320\265 \320\276\320\266\320\270\320\264\320\260\320\265\320\274\321\213\320\271 \321\205\320\265\321\210 \320\264\320\273\321\217 \320\277\321\200\320\276\320\262\320\265\321\200\320\272\320\270", nullptr));
        btnVerifyHash->setText(QCoreApplication::translate("MainWindow", "\320\237\321\200\320\276\320\262\320\265\321\200\320\270\321\202\321\214 \321\205\320\265\321\210", nullptr));
        labelVerifyResult->setText(QCoreApplication::translate("MainWindow", "\320\240\320\265\320\267\321\203\320\273\321\214\321\202\320\260\321\202 \320\277\321\200\320\276\320\262\320\265\321\200\320\272\320\270", nullptr));
        labelSHA384Status->setText(QCoreApplication::translate("MainWindow", "\320\241\321\202\320\260\321\202\321\203\321\201: \320\223\320\276\321\202\320\276\320\262", nullptr));
        groupBoxInputText->setTitle(QCoreApplication::translate("MainWindow", "\320\222\321\205\320\276\320\264\320\275\320\276\320\271 \321\202\320\265\320\272\321\201\321\202", nullptr));
        editInputTextSHA384->setPlaceholderText(QCoreApplication::translate("MainWindow", "\320\222\320\262\320\265\320\264\320\270\321\202\320\265 \321\202\320\265\320\272\321\201\321\202 \320\264\320\273\321\217 \321\205\320\265\321\210\320\270\321\200\320\276\320\262\320\260\320\275\320\270\321\217", nullptr));
        groupBoxHashResult->setTitle(QCoreApplication::translate("MainWindow", "\320\240\320\265\320\267\321\203\320\273\321\214\321\202\320\260\321\202 \321\205\320\265\321\210\320\270\321\200\320\276\320\262\320\260\320\275\320\270\321\217", nullptr));
        editHashResult->setPlaceholderText(QCoreApplication::translate("MainWindow", "\320\240\320\265\320\267\321\203\320\273\321\214\321\202\320\260\321\202 \321\205\320\265\321\210\320\270\321\200\320\276\320\262\320\260\320\275\320\270\321\217 \320\261\321\203\320\264\320\265\321\202 \320\276\321\202\320\276\320\261\321\200\320\260\320\266\320\260\321\202\321\214\321\201\321\217 \320\267\320\264\320\265\321\201\321\214", nullptr));
        groupBoxInfo->setTitle(QCoreApplication::translate("MainWindow", "\320\230\320\275\321\204\320\276\321\200\320\274\320\260\321\206\320\270\321\217 \320\276 SHA-384", nullptr));
        textBrowserInfo->setHtml(QCoreApplication::translate("MainWindow", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"</style></head><body style=\" font-family:'MS Shell Dlg 2'; font-size:8.25pt; font-weight:400; font-style:normal;\">\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-size:10pt; font-weight:600; color:#88c0d0;\">SHA-384</span><span style=\" font-size:10pt;\"> - \321\215\321\202\320\276 \320\272\321\200\320\270\320\277\321\202\320\276\320\263\321\200\320\260\321\204\320\270\321\207\320\265\321\201\320\272\320\260\321\217 \321\205\320\265\321\210-\321\204\321\203\320\275\320\272\321\206\320\270\321\217 \320\270\320\267 \321\201\320\265\320\274\320\265\320\271\321\201\321\202\320\262\320\260 SHA-2, \321\200\320\260\320\267\321\200\320\260\320\261\320\276\321\202\320\260\320\275\320\275\320\260\321\217"
                        " \320\220\320\235\320\221 \320\241\320\250\320\220.</span></p>\n"
"<p style=\"-qt-paragraph-type:empty; margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px; font-size:10pt;\"><br /></p>\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-size:10pt;\">\320\236\321\201\320\275\320\276\320\262\320\275\321\213\320\265 \321\205\320\260\321\200\320\260\320\272\321\202\320\265\321\200\320\270\321\201\321\202\320\270\320\272\320\270:</span></p>\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-size:10pt;\">- \320\240\320\260\320\267\320\274\320\265\321\200 \320\262\321\213\321\205\320\276\320\264\320\275\320\276\320\263\320\276 \321\205\320\265\321\210\320\260: 384 \320\261\320\270\321\202\320\260 (48 \320\261\320\260\320\271\321\202)</span></p>\n"
"<p style=\" margin-top:0px; mar"
                        "gin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-size:10pt;\">- \320\222\320\275\321\203\321\202\321\200\320\265\320\275\320\275\320\270\320\271 \321\200\320\260\320\267\320\274\320\265\321\200 \320\261\320\273\320\276\320\272\320\260: 1024 \320\261\320\270\321\202\320\260</span></p>\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-size:10pt;\">- \320\236\321\201\320\275\320\276\320\262\320\260\320\275 \320\275\320\260 SHA-512 \321\201 \320\264\321\200\321\203\320\263\320\270\320\274\320\270 \320\275\320\260\321\207\320\260\320\273\321\214\320\275\321\213\320\274\320\270 \320\267\320\275\320\260\321\207\320\265\320\275\320\270\321\217\320\274\320\270</span></p>\n"
"<p style=\"-qt-paragraph-type:empty; margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px; font-size:10pt;\"><br /></p>\n"
"<p style=\" margi"
                        "n-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-size:10pt;\">\320\237\321\200\320\270\320\274\320\265\320\275\320\265\320\275\320\270\320\265:</span></p>\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-size:10pt;\">- \320\237\321\200\320\276\320\262\320\265\321\200\320\272\320\260 \321\206\320\265\320\273\320\276\321\201\321\202\320\275\320\276\321\201\321\202\320\270 \320\264\320\260\320\275\320\275\321\213\321\205</span></p>\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-size:10pt;\">- \320\246\320\270\321\204\321\200\320\276\320\262\321\213\320\265 \320\277\320\276\320\264\320\277\320\270\321\201\320\270</span></p>\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><sp"
                        "an style=\" font-size:10pt;\">- \320\220\321\203\321\202\320\265\320\275\321\202\320\270\321\204\320\270\320\272\320\260\321\206\320\270\321\217</span></p>\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-size:10pt;\">- \320\245\321\200\320\260\320\275\320\265\320\275\320\270\320\265 \320\277\320\260\321\200\320\276\320\273\320\265\320\271</span></p></body></html>", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(tabSHA384), QCoreApplication::translate("MainWindow", "SHA-384", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_TABS_H
