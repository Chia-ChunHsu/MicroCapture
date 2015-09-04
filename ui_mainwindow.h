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
    QTabWidget *tabWidget;
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
    QPushButton *saveResultButtom;
    QSlider *CapResultSlider;
    QPushButton *SaveCap;
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
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QStringLiteral("MainWindow"));
        MainWindow->resize(640, 417);
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        tabWidget = new QTabWidget(centralWidget);
        tabWidget->setObjectName(QStringLiteral("tabWidget"));
        tabWidget->setGeometry(QRect(10, 10, 621, 351));
        DetectTab = new QWidget();
        DetectTab->setObjectName(QStringLiteral("DetectTab"));
        CapturePicture = new QPushButton(DetectTab);
        CapturePicture->setObjectName(QStringLiteral("CapturePicture"));
        CapturePicture->setEnabled(false);
        CapturePicture->setGeometry(QRect(370, 270, 80, 50));
        CapResultLabel = new QLabel(DetectTab);
        CapResultLabel->setObjectName(QStringLiteral("CapResultLabel"));
        CapResultLabel->setGeometry(QRect(370, 10, 240, 180));
        CapResultLabel->setStyleSheet(QStringLiteral("background-color: rgb(233, 255, 255);"));
        LoadCapPic = new QPushButton(DetectTab);
        LoadCapPic->setObjectName(QStringLiteral("LoadCapPic"));
        LoadCapPic->setEnabled(false);
        LoadCapPic->setGeometry(QRect(450, 270, 80, 50));
        tabWidget_2 = new QTabWidget(DetectTab);
        tabWidget_2->setObjectName(QStringLiteral("tabWidget_2"));
        tabWidget_2->setGeometry(QRect(10, 10, 351, 311));
        tab_2 = new QWidget();
        tab_2->setObjectName(QStringLiteral("tab_2"));
        FilterLabel2 = new QLabel(tab_2);
        FilterLabel2->setObjectName(QStringLiteral("FilterLabel2"));
        FilterLabel2->setGeometry(QRect(180, 10, 160, 120));
        FilterLabel2->setStyleSheet(QStringLiteral("background-color: rgb(233, 255, 255);"));
        FilterLabel4 = new QLabel(tab_2);
        FilterLabel4->setObjectName(QStringLiteral("FilterLabel4"));
        FilterLabel4->setGeometry(QRect(180, 150, 160, 120));
        FilterLabel4->setStyleSheet(QStringLiteral("background-color: rgb(233, 255, 255);"));
        FilterLabel1 = new QLabel(tab_2);
        FilterLabel1->setObjectName(QStringLiteral("FilterLabel1"));
        FilterLabel1->setGeometry(QRect(10, 10, 160, 120));
        FilterLabel1->setStyleSheet(QStringLiteral("background-color: rgb(233, 255, 255);"));
        FilterLabel3 = new QLabel(tab_2);
        FilterLabel3->setObjectName(QStringLiteral("FilterLabel3"));
        FilterLabel3->setGeometry(QRect(10, 150, 160, 120));
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
        saveResultButtom = new QPushButton(DetectTab);
        saveResultButtom->setObjectName(QStringLiteral("saveResultButtom"));
        saveResultButtom->setEnabled(false);
        saveResultButtom->setGeometry(QRect(370, 220, 241, 41));
        CapResultSlider = new QSlider(DetectTab);
        CapResultSlider->setObjectName(QStringLiteral("CapResultSlider"));
        CapResultSlider->setEnabled(false);
        CapResultSlider->setGeometry(QRect(370, 200, 241, 19));
        CapResultSlider->setMaximum(255);
        CapResultSlider->setValue(200);
        CapResultSlider->setOrientation(Qt::Horizontal);
        SaveCap = new QPushButton(DetectTab);
        SaveCap->setObjectName(QStringLiteral("SaveCap"));
        SaveCap->setGeometry(QRect(530, 270, 80, 50));
        tabWidget->addTab(DetectTab, QString());
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
        tabWidget->addTab(CalibrationTab, QString());
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
        tabWidget->addTab(tab, QString());
        AutoDetectButtom = new QPushButton(centralWidget);
        AutoDetectButtom->setObjectName(QStringLiteral("AutoDetectButtom"));
        AutoDetectButtom->setGeometry(QRect(420, 0, 111, 23));
        SetUpButton = new QPushButton(centralWidget);
        SetUpButton->setObjectName(QStringLiteral("SetUpButton"));
        SetUpButton->setGeometry(QRect(540, 0, 75, 23));
        MainWindow->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(MainWindow);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 640, 22));
        MainWindow->setMenuBar(menuBar);
        mainToolBar = new QToolBar(MainWindow);
        mainToolBar->setObjectName(QStringLiteral("mainToolBar"));
        MainWindow->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(MainWindow);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        MainWindow->setStatusBar(statusBar);

        retranslateUi(MainWindow);

        tabWidget->setCurrentIndex(0);
        tabWidget_2->setCurrentIndex(1);
        stackedWidget->setCurrentIndex(0);
        ProgressList->setCurrentRow(0);


        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "MainWindow", 0));
        CapturePicture->setText(QApplication::translate("MainWindow", "Capture Picture", 0));
        CapResultLabel->setText(QString());
        LoadCapPic->setText(QApplication::translate("MainWindow", "Load", 0));
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
        saveResultButtom->setText(QApplication::translate("MainWindow", "SaveResult", 0));
        SaveCap->setText(QApplication::translate("MainWindow", "Save", 0));
        tabWidget->setTabText(tabWidget->indexOf(DetectTab), QApplication::translate("MainWindow", "Detect Mode", 0));
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

        tabWidget->setTabText(tabWidget->indexOf(CalibrationTab), QApplication::translate("MainWindow", "Calibration Mode", 0));
        BlackReflabel1->setText(QString());
        BlackReflabel2->setText(QString());
        BlackReflabel3->setText(QString());
        BlackReflabel4->setText(QString());
        LBlackRefButton->setText(QApplication::translate("MainWindow", "Load Black Ref", 0));
        CaptureBLRef->setText(QApplication::translate("MainWindow", "Capture Black Ref", 0));
        SaveBlackRef->setText(QApplication::translate("MainWindow", "Save Black Ref", 0));
        tabWidget->setTabText(tabWidget->indexOf(tab), QApplication::translate("MainWindow", "Black Calibration", 0));
        AutoDetectButtom->setText(QApplication::translate("MainWindow", "Auto Detect Camera", 0));
        SetUpButton->setText(QApplication::translate("MainWindow", "SetUp", 0));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
