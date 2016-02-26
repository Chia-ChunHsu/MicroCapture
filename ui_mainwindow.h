/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.5.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QListWidget>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSlider>
#include <QtWidgets/QStackedWidget>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTabWidget>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralWidget;
    QTabWidget *tabClassifier;
    QWidget *DetectTab;
    QPushButton *CapturePicture;
    QLabel *CapResultLabel;
    QPushButton *LoadCapPic;
    QTabWidget *tabWidget_2;
    QWidget *tab_2;
    QLabel *FilterLabel2;
    QLabel *FilterLabel4;
    QLabel *FilterLabel1;
    QLabel *FilterLabel3;
    QWidget *tab_3;
    QLabel *WarpFilterLabel1;
    QLabel *WarpFilterLabel2;
    QLabel *WarpFilterLabel3;
    QLabel *WarpFilterLabel4;
    QLabel *label;
    QLabel *label_2;
    QLabel *label_3;
    QWidget *tab_4;
    QLabel *classlabel1;
    QLabel *classlabel2;
    QLabel *classlabel3;
    QLabel *classlabel4;
    QSlider *hSlider;
    QSlider *vSlider;
    QWidget *tab_5;
    QLabel *equalLabel1;
    QLabel *equalLabel2;
    QLabel *equalLabel3;
    QLabel *equalLabel4;
    QPushButton *EqualButton;
    QPushButton *saveResultButtom;
    QSlider *CapResultSlider;
    QPushButton *SaveCap;
    QPushButton *TestButton;
    QWidget *CalibrationTab;
    QStackedWidget *stackedWidget;
    QWidget *page_2;
    QLabel *CalLabel2;
    QLabel *CalLabel4;
    QLabel *CalLabel3;
    QLabel *CalLabel1;
    QPushButton *LoadCalButtom;
    QPushButton *CaptureCalButtom;
    QPushButton *SaveCalButtom;
    QWidget *page;
    QLabel *WarpCalLabel1;
    QLabel *WarpCalLabel2;
    QLabel *WarpCalLabel3;
    QLabel *WarpCalLabel4;
    QWidget *page_3;
    QLabel *CalResultLabel;
    QListWidget *ProgressList;
    QWidget *tab;
    QLabel *BlackReflabel1;
    QLabel *BlackReflabel2;
    QLabel *BlackReflabel3;
    QLabel *BlackReflabel4;
    QPushButton *LBlackRefButton;
    QPushButton *CaptureBLRef;
    QPushButton *SaveBlackRef;
    QPushButton *AutoDetectButtom;
    QPushButton *SetUpButton;
    QPushButton *cutButton;
    QPushButton *shadowButton;
    QCheckBox *checkBox1;
    QCheckBox *checkBox2;
    QCheckBox *checkBox3;
    QCheckBox *checkBox4;
    QSlider *hSlider01;
    QSlider *hSlider03;
    QPushButton *getDataButton;
    QPushButton *SetButtom;
    QPushButton *PredictButton;
    QPushButton *getData3x3Button;
    QLabel *L1;
    QLabel *L2;
    QLabel *L3;
    QLabel *L4;
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QStringLiteral("MainWindow"));
        MainWindow->resize(659, 532);
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        tabClassifier = new QTabWidget(centralWidget);
        tabClassifier->setObjectName(QStringLiteral("tabClassifier"));
        tabClassifier->setGeometry(QRect(10, 10, 621, 371));
        DetectTab = new QWidget();
        DetectTab->setObjectName(QStringLiteral("DetectTab"));
        CapturePicture = new QPushButton(DetectTab);
        CapturePicture->setObjectName(QStringLiteral("CapturePicture"));
        CapturePicture->setEnabled(false);
        CapturePicture->setGeometry(QRect(370, 260, 241, 21));
        CapResultLabel = new QLabel(DetectTab);
        CapResultLabel->setObjectName(QStringLiteral("CapResultLabel"));
        CapResultLabel->setGeometry(QRect(370, 10, 240, 180));
        CapResultLabel->setStyleSheet(QStringLiteral("background-color: rgb(233, 255, 255);"));
        LoadCapPic = new QPushButton(DetectTab);
        LoadCapPic->setObjectName(QStringLiteral("LoadCapPic"));
        LoadCapPic->setEnabled(false);
        LoadCapPic->setGeometry(QRect(370, 290, 241, 21));
        tabWidget_2 = new QTabWidget(DetectTab);
        tabWidget_2->setObjectName(QStringLiteral("tabWidget_2"));
        tabWidget_2->setGeometry(QRect(10, 10, 361, 341));
        tab_2 = new QWidget();
        tab_2->setObjectName(QStringLiteral("tab_2"));
        FilterLabel2 = new QLabel(tab_2);
        FilterLabel2->setObjectName(QStringLiteral("FilterLabel2"));
        FilterLabel2->setGeometry(QRect(180, 10, 160, 120));
        FilterLabel2->setStyleSheet(QStringLiteral("background-color: rgb(233, 255, 255);"));
        FilterLabel4 = new QLabel(tab_2);
        FilterLabel4->setObjectName(QStringLiteral("FilterLabel4"));
        FilterLabel4->setGeometry(QRect(180, 160, 160, 120));
        FilterLabel4->setStyleSheet(QStringLiteral("background-color: rgb(233, 255, 255);"));
        FilterLabel1 = new QLabel(tab_2);
        FilterLabel1->setObjectName(QStringLiteral("FilterLabel1"));
        FilterLabel1->setGeometry(QRect(10, 10, 160, 120));
        FilterLabel1->setStyleSheet(QStringLiteral("background-color: rgb(233, 255, 255);"));
        FilterLabel3 = new QLabel(tab_2);
        FilterLabel3->setObjectName(QStringLiteral("FilterLabel3"));
        FilterLabel3->setGeometry(QRect(10, 160, 160, 120));
        FilterLabel3->setStyleSheet(QStringLiteral("background-color: rgb(233, 255, 255);"));
        tabWidget_2->addTab(tab_2, QString());
        tab_3 = new QWidget();
        tab_3->setObjectName(QStringLiteral("tab_3"));
        WarpFilterLabel1 = new QLabel(tab_3);
        WarpFilterLabel1->setObjectName(QStringLiteral("WarpFilterLabel1"));
        WarpFilterLabel1->setGeometry(QRect(10, 10, 160, 120));
        WarpFilterLabel1->setStyleSheet(QStringLiteral("background-color: rgb(233, 255, 255);"));
        WarpFilterLabel2 = new QLabel(tab_3);
        WarpFilterLabel2->setObjectName(QStringLiteral("WarpFilterLabel2"));
        WarpFilterLabel2->setGeometry(QRect(180, 10, 160, 120));
        WarpFilterLabel2->setStyleSheet(QStringLiteral("background-color: rgb(233, 255, 255);"));
        WarpFilterLabel3 = new QLabel(tab_3);
        WarpFilterLabel3->setObjectName(QStringLiteral("WarpFilterLabel3"));
        WarpFilterLabel3->setGeometry(QRect(10, 150, 160, 120));
        WarpFilterLabel3->setStyleSheet(QStringLiteral("background-color: rgb(233, 255, 255);"));
        WarpFilterLabel4 = new QLabel(tab_3);
        WarpFilterLabel4->setObjectName(QStringLiteral("WarpFilterLabel4"));
        WarpFilterLabel4->setGeometry(QRect(180, 150, 160, 120));
        WarpFilterLabel4->setStyleSheet(QStringLiteral("background-color: rgb(233, 255, 255);"));
        label = new QLabel(tab_3);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(180, 130, 161, 16));
        label->setStyleSheet(QStringLiteral("background-color: rgb(255, 0, 0);"));
        label_2 = new QLabel(tab_3);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setGeometry(QRect(10, 270, 161, 16));
        label_2->setStyleSheet(QStringLiteral("background-color: rgb(0, 255, 0);"));
        label_3 = new QLabel(tab_3);
        label_3->setObjectName(QStringLiteral("label_3"));
        label_3->setGeometry(QRect(180, 270, 161, 16));
        label_3->setStyleSheet(QStringLiteral("background-color: rgb(0, 0, 255);"));
        tabWidget_2->addTab(tab_3, QString());
        tab_4 = new QWidget();
        tab_4->setObjectName(QStringLiteral("tab_4"));
        classlabel1 = new QLabel(tab_4);
        classlabel1->setObjectName(QStringLiteral("classlabel1"));
        classlabel1->setGeometry(QRect(10, 10, 160, 120));
        classlabel1->setStyleSheet(QStringLiteral("background-color: rgb(255, 255, 255);"));
        classlabel2 = new QLabel(tab_4);
        classlabel2->setObjectName(QStringLiteral("classlabel2"));
        classlabel2->setGeometry(QRect(180, 10, 160, 120));
        classlabel2->setStyleSheet(QStringLiteral("background-color: rgb(255, 255, 255);"));
        classlabel3 = new QLabel(tab_4);
        classlabel3->setObjectName(QStringLiteral("classlabel3"));
        classlabel3->setGeometry(QRect(10, 150, 160, 120));
        classlabel3->setStyleSheet(QStringLiteral("background-color: rgb(255, 255, 255);"));
        classlabel4 = new QLabel(tab_4);
        classlabel4->setObjectName(QStringLiteral("classlabel4"));
        classlabel4->setGeometry(QRect(180, 150, 160, 120));
        classlabel4->setStyleSheet(QStringLiteral("background-color: rgb(255, 255, 255);"));
        hSlider = new QSlider(tab_4);
        hSlider->setObjectName(QStringLiteral("hSlider"));
        hSlider->setGeometry(QRect(10, 290, 331, 19));
        hSlider->setPageStep(1);
        hSlider->setValue(10);
        hSlider->setOrientation(Qt::Horizontal);
        vSlider = new QSlider(tab_4);
        vSlider->setObjectName(QStringLiteral("vSlider"));
        vSlider->setGeometry(QRect(340, 10, 19, 291));
        vSlider->setPageStep(1);
        vSlider->setValue(10);
        vSlider->setOrientation(Qt::Vertical);
        tabWidget_2->addTab(tab_4, QString());
        tab_5 = new QWidget();
        tab_5->setObjectName(QStringLiteral("tab_5"));
        equalLabel1 = new QLabel(tab_5);
        equalLabel1->setObjectName(QStringLiteral("equalLabel1"));
        equalLabel1->setGeometry(QRect(10, 10, 160, 120));
        equalLabel1->setStyleSheet(QStringLiteral("background-color: rgb(255, 255, 255);"));
        equalLabel2 = new QLabel(tab_5);
        equalLabel2->setObjectName(QStringLiteral("equalLabel2"));
        equalLabel2->setGeometry(QRect(180, 10, 160, 120));
        equalLabel2->setStyleSheet(QStringLiteral("background-color: rgb(255, 255, 255);"));
        equalLabel3 = new QLabel(tab_5);
        equalLabel3->setObjectName(QStringLiteral("equalLabel3"));
        equalLabel3->setGeometry(QRect(10, 150, 160, 120));
        equalLabel3->setStyleSheet(QStringLiteral("background-color: rgb(255, 255, 255);"));
        equalLabel4 = new QLabel(tab_5);
        equalLabel4->setObjectName(QStringLiteral("equalLabel4"));
        equalLabel4->setGeometry(QRect(180, 150, 160, 120));
        equalLabel4->setStyleSheet(QStringLiteral("background-color: rgb(255, 255, 255);"));
        EqualButton = new QPushButton(tab_5);
        EqualButton->setObjectName(QStringLiteral("EqualButton"));
        EqualButton->setEnabled(false);
        EqualButton->setGeometry(QRect(10, 280, 331, 31));
        tabWidget_2->addTab(tab_5, QString());
        saveResultButtom = new QPushButton(DetectTab);
        saveResultButtom->setObjectName(QStringLiteral("saveResultButtom"));
        saveResultButtom->setEnabled(false);
        saveResultButtom->setGeometry(QRect(370, 230, 241, 21));
        CapResultSlider = new QSlider(DetectTab);
        CapResultSlider->setObjectName(QStringLiteral("CapResultSlider"));
        CapResultSlider->setEnabled(false);
        CapResultSlider->setGeometry(QRect(370, 200, 241, 19));
        CapResultSlider->setMaximum(255);
        CapResultSlider->setValue(200);
        CapResultSlider->setOrientation(Qt::Horizontal);
        SaveCap = new QPushButton(DetectTab);
        SaveCap->setObjectName(QStringLiteral("SaveCap"));
        SaveCap->setGeometry(QRect(369, 319, 241, 21));
        TestButton = new QPushButton(DetectTab);
        TestButton->setObjectName(QStringLiteral("TestButton"));
        TestButton->setGeometry(QRect(280, 0, 75, 23));
        tabClassifier->addTab(DetectTab, QString());
        CalibrationTab = new QWidget();
        CalibrationTab->setObjectName(QStringLiteral("CalibrationTab"));
        stackedWidget = new QStackedWidget(CalibrationTab);
        stackedWidget->setObjectName(QStringLiteral("stackedWidget"));
        stackedWidget->setGeometry(QRect(210, 10, 391, 311));
        page_2 = new QWidget();
        page_2->setObjectName(QStringLiteral("page_2"));
        CalLabel2 = new QLabel(page_2);
        CalLabel2->setObjectName(QStringLiteral("CalLabel2"));
        CalLabel2->setGeometry(QRect(180, 0, 160, 120));
        CalLabel2->setStyleSheet(QStringLiteral("background-color: rgb(233, 255, 255);"));
        CalLabel4 = new QLabel(page_2);
        CalLabel4->setObjectName(QStringLiteral("CalLabel4"));
        CalLabel4->setGeometry(QRect(180, 130, 160, 120));
        CalLabel4->setStyleSheet(QStringLiteral("background-color: rgb(233, 255, 255);"));
        CalLabel3 = new QLabel(page_2);
        CalLabel3->setObjectName(QStringLiteral("CalLabel3"));
        CalLabel3->setGeometry(QRect(10, 130, 160, 120));
        CalLabel3->setStyleSheet(QStringLiteral("background-color: rgb(233, 255, 255);"));
        CalLabel1 = new QLabel(page_2);
        CalLabel1->setObjectName(QStringLiteral("CalLabel1"));
        CalLabel1->setGeometry(QRect(10, 0, 160, 120));
        CalLabel1->setStyleSheet(QStringLiteral("background-color: rgb(233, 255, 255);"));
        CalLabel1->setLineWidth(1);
        LoadCalButtom = new QPushButton(page_2);
        LoadCalButtom->setObjectName(QStringLiteral("LoadCalButtom"));
        LoadCalButtom->setGeometry(QRect(160, 260, 160, 50));
        CaptureCalButtom = new QPushButton(page_2);
        CaptureCalButtom->setObjectName(QStringLiteral("CaptureCalButtom"));
        CaptureCalButtom->setGeometry(QRect(0, 260, 160, 50));
        SaveCalButtom = new QPushButton(page_2);
        SaveCalButtom->setObjectName(QStringLiteral("SaveCalButtom"));
        SaveCalButtom->setGeometry(QRect(320, 260, 71, 50));
        stackedWidget->addWidget(page_2);
        page = new QWidget();
        page->setObjectName(QStringLiteral("page"));
        WarpCalLabel1 = new QLabel(page);
        WarpCalLabel1->setObjectName(QStringLiteral("WarpCalLabel1"));
        WarpCalLabel1->setGeometry(QRect(10, 0, 160, 120));
        WarpCalLabel1->setStyleSheet(QStringLiteral("background-color: rgb(233, 255, 255);"));
        WarpCalLabel2 = new QLabel(page);
        WarpCalLabel2->setObjectName(QStringLiteral("WarpCalLabel2"));
        WarpCalLabel2->setGeometry(QRect(180, 0, 160, 120));
        WarpCalLabel2->setStyleSheet(QStringLiteral("background-color: rgb(233, 255, 255);"));
        WarpCalLabel3 = new QLabel(page);
        WarpCalLabel3->setObjectName(QStringLiteral("WarpCalLabel3"));
        WarpCalLabel3->setGeometry(QRect(10, 130, 160, 120));
        WarpCalLabel3->setStyleSheet(QStringLiteral("background-color: rgb(233, 255, 255);"));
        WarpCalLabel4 = new QLabel(page);
        WarpCalLabel4->setObjectName(QStringLiteral("WarpCalLabel4"));
        WarpCalLabel4->setGeometry(QRect(180, 130, 160, 120));
        WarpCalLabel4->setStyleSheet(QStringLiteral("background-color: rgb(233, 255, 255);"));
        stackedWidget->addWidget(page);
        page_3 = new QWidget();
        page_3->setObjectName(QStringLiteral("page_3"));
        CalResultLabel = new QLabel(page_3);
        CalResultLabel->setObjectName(QStringLiteral("CalResultLabel"));
        CalResultLabel->setGeometry(QRect(10, 0, 320, 240));
        CalResultLabel->setStyleSheet(QStringLiteral("background-color: rgb(233, 255, 255);"));
        stackedWidget->addWidget(page_3);
        ProgressList = new QListWidget(CalibrationTab);
        new QListWidgetItem(ProgressList);
        new QListWidgetItem(ProgressList);
        new QListWidgetItem(ProgressList);
        ProgressList->setObjectName(QStringLiteral("ProgressList"));
        ProgressList->setGeometry(QRect(10, 10, 191, 311));
        tabClassifier->addTab(CalibrationTab, QString());
        tab = new QWidget();
        tab->setObjectName(QStringLiteral("tab"));
        BlackReflabel1 = new QLabel(tab);
        BlackReflabel1->setObjectName(QStringLiteral("BlackReflabel1"));
        BlackReflabel1->setGeometry(QRect(10, 10, 160, 120));
        BlackReflabel1->setStyleSheet(QStringLiteral("background-color: rgb(233, 255, 255);"));
        BlackReflabel2 = new QLabel(tab);
        BlackReflabel2->setObjectName(QStringLiteral("BlackReflabel2"));
        BlackReflabel2->setGeometry(QRect(180, 10, 160, 120));
        BlackReflabel2->setStyleSheet(QStringLiteral("background-color: rgb(233, 255, 255);"));
        BlackReflabel3 = new QLabel(tab);
        BlackReflabel3->setObjectName(QStringLiteral("BlackReflabel3"));
        BlackReflabel3->setGeometry(QRect(10, 140, 160, 120));
        BlackReflabel3->setStyleSheet(QStringLiteral("background-color: rgb(233, 255, 255);"));
        BlackReflabel4 = new QLabel(tab);
        BlackReflabel4->setObjectName(QStringLiteral("BlackReflabel4"));
        BlackReflabel4->setGeometry(QRect(180, 140, 160, 120));
        BlackReflabel4->setStyleSheet(QStringLiteral("background-color: rgb(233, 255, 255);"));
        LBlackRefButton = new QPushButton(tab);
        LBlackRefButton->setObjectName(QStringLiteral("LBlackRefButton"));
        LBlackRefButton->setEnabled(false);
        LBlackRefButton->setGeometry(QRect(10, 270, 161, 41));
        CaptureBLRef = new QPushButton(tab);
        CaptureBLRef->setObjectName(QStringLiteral("CaptureBLRef"));
        CaptureBLRef->setGeometry(QRect(180, 270, 161, 41));
        SaveBlackRef = new QPushButton(tab);
        SaveBlackRef->setObjectName(QStringLiteral("SaveBlackRef"));
        SaveBlackRef->setGeometry(QRect(350, 270, 251, 41));
        tabClassifier->addTab(tab, QString());
        AutoDetectButtom = new QPushButton(centralWidget);
        AutoDetectButtom->setObjectName(QStringLiteral("AutoDetectButtom"));
        AutoDetectButtom->setGeometry(QRect(420, 0, 111, 23));
        SetUpButton = new QPushButton(centralWidget);
        SetUpButton->setObjectName(QStringLiteral("SetUpButton"));
        SetUpButton->setGeometry(QRect(540, 0, 75, 23));
        cutButton = new QPushButton(centralWidget);
        cutButton->setObjectName(QStringLiteral("cutButton"));
        cutButton->setGeometry(QRect(170, 390, 91, 31));
        shadowButton = new QPushButton(centralWidget);
        shadowButton->setObjectName(QStringLiteral("shadowButton"));
        shadowButton->setGeometry(QRect(80, 390, 81, 31));
        checkBox1 = new QCheckBox(centralWidget);
        checkBox1->setObjectName(QStringLiteral("checkBox1"));
        checkBox1->setGeometry(QRect(20, 380, 16, 16));
        checkBox2 = new QCheckBox(centralWidget);
        checkBox2->setObjectName(QStringLiteral("checkBox2"));
        checkBox2->setGeometry(QRect(50, 380, 16, 16));
        checkBox3 = new QCheckBox(centralWidget);
        checkBox3->setObjectName(QStringLiteral("checkBox3"));
        checkBox3->setGeometry(QRect(20, 400, 16, 16));
        checkBox4 = new QCheckBox(centralWidget);
        checkBox4->setObjectName(QStringLiteral("checkBox4"));
        checkBox4->setGeometry(QRect(50, 400, 16, 16));
        hSlider01 = new QSlider(centralWidget);
        hSlider01->setObjectName(QStringLiteral("hSlider01"));
        hSlider01->setGeometry(QRect(290, 390, 160, 22));
        hSlider01->setMaximum(255);
        hSlider01->setValue(125);
        hSlider01->setOrientation(Qt::Horizontal);
        hSlider03 = new QSlider(centralWidget);
        hSlider03->setObjectName(QStringLiteral("hSlider03"));
        hSlider03->setGeometry(QRect(470, 390, 160, 22));
        hSlider03->setMaximum(255);
        hSlider03->setValue(100);
        hSlider03->setOrientation(Qt::Horizontal);
        getDataButton = new QPushButton(centralWidget);
        getDataButton->setObjectName(QStringLiteral("getDataButton"));
        getDataButton->setEnabled(false);
        getDataButton->setGeometry(QRect(370, 420, 75, 23));
        SetButtom = new QPushButton(centralWidget);
        SetButtom->setObjectName(QStringLiteral("SetButtom"));
        SetButtom->setGeometry(QRect(80, 430, 181, 41));
        PredictButton = new QPushButton(centralWidget);
        PredictButton->setObjectName(QStringLiteral("PredictButton"));
        PredictButton->setGeometry(QRect(470, 420, 161, 51));
        QFont font;
        font.setPointSize(15);
        font.setBold(true);
        font.setWeight(75);
        PredictButton->setFont(font);
        getData3x3Button = new QPushButton(centralWidget);
        getData3x3Button->setObjectName(QStringLiteral("getData3x3Button"));
        getData3x3Button->setEnabled(false);
        getData3x3Button->setGeometry(QRect(370, 450, 75, 23));
        L1 = new QLabel(centralWidget);
        L1->setObjectName(QStringLiteral("L1"));
        L1->setGeometry(QRect(270, 420, 47, 12));
        L2 = new QLabel(centralWidget);
        L2->setObjectName(QStringLiteral("L2"));
        L2->setGeometry(QRect(320, 420, 47, 12));
        L3 = new QLabel(centralWidget);
        L3->setObjectName(QStringLiteral("L3"));
        L3->setGeometry(QRect(270, 450, 47, 12));
        L4 = new QLabel(centralWidget);
        L4->setObjectName(QStringLiteral("L4"));
        L4->setGeometry(QRect(320, 450, 47, 12));
        MainWindow->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(MainWindow);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 659, 21));
        MainWindow->setMenuBar(menuBar);
        mainToolBar = new QToolBar(MainWindow);
        mainToolBar->setObjectName(QStringLiteral("mainToolBar"));
        MainWindow->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(MainWindow);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        MainWindow->setStatusBar(statusBar);

        retranslateUi(MainWindow);

        tabClassifier->setCurrentIndex(2);
        tabWidget_2->setCurrentIndex(2);
        stackedWidget->setCurrentIndex(0);
        ProgressList->setCurrentRow(0);


        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "MainWindow", 0));
        CapturePicture->setText(QApplication::translate("MainWindow", "Capture Picture", 0));
        CapResultLabel->setText(QString());
        LoadCapPic->setText(QApplication::translate("MainWindow", "Load Capture Pictures", 0));
        FilterLabel2->setText(QString());
        FilterLabel4->setText(QString());
        FilterLabel1->setText(QString());
        FilterLabel3->setText(QString());
        tabWidget_2->setTabText(tabWidget_2->indexOf(tab_2), QApplication::translate("MainWindow", "Original", 0));
        WarpFilterLabel1->setText(QString());
        WarpFilterLabel2->setText(QString());
        WarpFilterLabel3->setText(QString());
        WarpFilterLabel4->setText(QString());
        label->setText(QString());
        label_2->setText(QString());
        label_3->setText(QString());
        tabWidget_2->setTabText(tabWidget_2->indexOf(tab_3), QApplication::translate("MainWindow", "Warping", 0));
        classlabel1->setText(QApplication::translate("MainWindow", "TextLabel", 0));
        classlabel2->setText(QApplication::translate("MainWindow", "TextLabel", 0));
        classlabel3->setText(QApplication::translate("MainWindow", "TextLabel", 0));
        classlabel4->setText(QApplication::translate("MainWindow", "TextLabel", 0));
        tabWidget_2->setTabText(tabWidget_2->indexOf(tab_4), QApplication::translate("MainWindow", "Classifier", 0));
        equalLabel1->setText(QApplication::translate("MainWindow", "TextLabel", 0));
        equalLabel2->setText(QApplication::translate("MainWindow", "TextLabel", 0));
        equalLabel3->setText(QApplication::translate("MainWindow", "TextLabel", 0));
        equalLabel4->setText(QApplication::translate("MainWindow", "TextLabel", 0));
        EqualButton->setText(QApplication::translate("MainWindow", "Equal", 0));
        tabWidget_2->setTabText(tabWidget_2->indexOf(tab_5), QApplication::translate("MainWindow", "Equalize", 0));
        saveResultButtom->setText(QApplication::translate("MainWindow", "Save Result Picture", 0));
        SaveCap->setText(QApplication::translate("MainWindow", "Save Capture Pictures", 0));
        TestButton->setText(QApplication::translate("MainWindow", "Test", 0));
        tabClassifier->setTabText(tabClassifier->indexOf(DetectTab), QApplication::translate("MainWindow", "Detect Mode", 0));
        CalLabel2->setText(QString());
        CalLabel4->setText(QString());
        CalLabel3->setText(QString());
        CalLabel1->setText(QString());
        LoadCalButtom->setText(QApplication::translate("MainWindow", "Load Calibration Pic From File", 0));
        CaptureCalButtom->setText(QApplication::translate("MainWindow", "Capture the Calibration Pictures", 0));
        SaveCalButtom->setText(QApplication::translate("MainWindow", "Save", 0));
        WarpCalLabel1->setText(QString());
        WarpCalLabel2->setText(QString());
        WarpCalLabel3->setText(QString());
        WarpCalLabel4->setText(QString());
        CalResultLabel->setText(QString());

        const bool __sortingEnabled = ProgressList->isSortingEnabled();
        ProgressList->setSortingEnabled(false);
        QListWidgetItem *___qlistwidgetitem = ProgressList->item(0);
        ___qlistwidgetitem->setText(QApplication::translate("MainWindow", "Capture Calibration Picture", 0));
        QListWidgetItem *___qlistwidgetitem1 = ProgressList->item(1);
        ___qlistwidgetitem1->setText(QApplication::translate("MainWindow", "See The Warping Result", 0));
        QListWidgetItem *___qlistwidgetitem2 = ProgressList->item(2);
        ___qlistwidgetitem2->setText(QApplication::translate("MainWindow", "The Stitching Result of the Calibration Photo", 0));
        ProgressList->setSortingEnabled(__sortingEnabled);

        tabClassifier->setTabText(tabClassifier->indexOf(CalibrationTab), QApplication::translate("MainWindow", "Calibration Mode", 0));
        BlackReflabel1->setText(QString());
        BlackReflabel2->setText(QString());
        BlackReflabel3->setText(QString());
        BlackReflabel4->setText(QString());
        LBlackRefButton->setText(QApplication::translate("MainWindow", "Load Black Ref", 0));
        CaptureBLRef->setText(QApplication::translate("MainWindow", "Capture Black Ref", 0));
        SaveBlackRef->setText(QApplication::translate("MainWindow", "Save Black Ref", 0));
        tabClassifier->setTabText(tabClassifier->indexOf(tab), QApplication::translate("MainWindow", "Black Calibration", 0));
        AutoDetectButtom->setText(QApplication::translate("MainWindow", "Auto Detect Camera", 0));
        SetUpButton->setText(QApplication::translate("MainWindow", "Set Up", 0));
        cutButton->setText(QApplication::translate("MainWindow", "cut", 0));
        shadowButton->setText(QApplication::translate("MainWindow", "Shadow", 0));
        checkBox1->setText(QString());
        checkBox2->setText(QString());
        checkBox3->setText(QString());
        checkBox4->setText(QString());
        getDataButton->setText(QApplication::translate("MainWindow", "GetTrainData", 0));
        SetButtom->setText(QApplication::translate("MainWindow", "Set", 0));
        PredictButton->setText(QApplication::translate("MainWindow", "Predict", 0));
        getData3x3Button->setText(QApplication::translate("MainWindow", "Get Data3*3", 0));
        L1->setText(QApplication::translate("MainWindow", "TextLabel", 0));
        L2->setText(QApplication::translate("MainWindow", "TextLabel", 0));
        L3->setText(QApplication::translate("MainWindow", "TextLabel", 0));
        L4->setText(QApplication::translate("MainWindow", "TextLabel", 0));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
