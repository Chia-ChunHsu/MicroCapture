/********************************************************************************
** Form generated from reading UI file 'autocameradialog.ui'
**
** Created by: Qt User Interface Compiler version 5.5.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_AUTOCAMERADIALOG_H
#define UI_AUTOCAMERADIALOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDialog>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>

QT_BEGIN_NAMESPACE

class Ui_AutoCameraDialog
{
public:
    QLabel *CameraLabel1;
    QLabel *CameraLabel2;
    QLabel *CameraLabel3;
    QLabel *CameraLabel4;
    QPushButton *saveCameraNameButtom;
    QPushButton *CancelButtom;
    QPushButton *Detect;
    QLabel *label0;
    QLabel *label1;
    QLabel *label2;
    QLabel *label3;
    QPushButton *OKButton;
    QPushButton *LoadButtom;

    void setupUi(QDialog *AutoCameraDialog)
    {
        if (AutoCameraDialog->objectName().isEmpty())
            AutoCameraDialog->setObjectName(QStringLiteral("AutoCameraDialog"));
        AutoCameraDialog->resize(511, 269);
        CameraLabel1 = new QLabel(AutoCameraDialog);
        CameraLabel1->setObjectName(QStringLiteral("CameraLabel1"));
        CameraLabel1->setGeometry(QRect(99, 40, 371, 20));
        CameraLabel1->setStyleSheet(QStringLiteral("background-color: rgb(255, 255, 255);"));
        CameraLabel2 = new QLabel(AutoCameraDialog);
        CameraLabel2->setObjectName(QStringLiteral("CameraLabel2"));
        CameraLabel2->setGeometry(QRect(99, 80, 371, 20));
        CameraLabel2->setStyleSheet(QStringLiteral("background-color: rgb(255, 255, 255);"));
        CameraLabel3 = new QLabel(AutoCameraDialog);
        CameraLabel3->setObjectName(QStringLiteral("CameraLabel3"));
        CameraLabel3->setGeometry(QRect(99, 120, 371, 20));
        CameraLabel3->setStyleSheet(QStringLiteral("background-color: rgb(255, 255, 255);"));
        CameraLabel4 = new QLabel(AutoCameraDialog);
        CameraLabel4->setObjectName(QStringLiteral("CameraLabel4"));
        CameraLabel4->setGeometry(QRect(99, 160, 371, 20));
        CameraLabel4->setStyleSheet(QStringLiteral("background-color: rgb(255, 255, 255);"));
        saveCameraNameButtom = new QPushButton(AutoCameraDialog);
        saveCameraNameButtom->setObjectName(QStringLiteral("saveCameraNameButtom"));
        saveCameraNameButtom->setGeometry(QRect(160, 200, 130, 40));
        QFont font;
        font.setFamily(QStringLiteral("Times New Roman"));
        font.setPointSize(12);
        saveCameraNameButtom->setFont(font);
        CancelButtom = new QPushButton(AutoCameraDialog);
        CancelButtom->setObjectName(QStringLiteral("CancelButtom"));
        CancelButtom->setGeometry(QRect(310, 200, 75, 40));
        QFont font1;
        font1.setFamily(QStringLiteral("Times New Roman"));
        font1.setPointSize(12);
        font1.setBold(false);
        font1.setWeight(50);
        CancelButtom->setFont(font1);
        Detect = new QPushButton(AutoCameraDialog);
        Detect->setObjectName(QStringLiteral("Detect"));
        Detect->setGeometry(QRect(10, 40, 81, 141));
        Detect->setFont(font);
        label0 = new QLabel(AutoCameraDialog);
        label0->setObjectName(QStringLiteral("label0"));
        label0->setGeometry(QRect(490, 40, 50, 20));
        label1 = new QLabel(AutoCameraDialog);
        label1->setObjectName(QStringLiteral("label1"));
        label1->setGeometry(QRect(490, 80, 50, 20));
        label2 = new QLabel(AutoCameraDialog);
        label2->setObjectName(QStringLiteral("label2"));
        label2->setGeometry(QRect(490, 120, 50, 20));
        label3 = new QLabel(AutoCameraDialog);
        label3->setObjectName(QStringLiteral("label3"));
        label3->setGeometry(QRect(490, 160, 50, 20));
        OKButton = new QPushButton(AutoCameraDialog);
        OKButton->setObjectName(QStringLiteral("OKButton"));
        OKButton->setGeometry(QRect(400, 200, 75, 40));
        OKButton->setFont(font);
        LoadButtom = new QPushButton(AutoCameraDialog);
        LoadButtom->setObjectName(QStringLiteral("LoadButtom"));
        LoadButtom->setGeometry(QRect(10, 200, 130, 40));
        LoadButtom->setFont(font);

        retranslateUi(AutoCameraDialog);

        QMetaObject::connectSlotsByName(AutoCameraDialog);
    } // setupUi

    void retranslateUi(QDialog *AutoCameraDialog)
    {
        AutoCameraDialog->setWindowTitle(QApplication::translate("AutoCameraDialog", "Dialog", 0));
        CameraLabel1->setText(QString());
        CameraLabel2->setText(QString());
        CameraLabel3->setText(QString());
        CameraLabel4->setText(QString());
        saveCameraNameButtom->setText(QApplication::translate("AutoCameraDialog", "Save Set Up File", 0));
        CancelButtom->setText(QApplication::translate("AutoCameraDialog", "Clear", 0));
        Detect->setText(QApplication::translate("AutoCameraDialog", "Set Camera", 0));
        label0->setText(QApplication::translate("AutoCameraDialog", "0", 0));
        label1->setText(QApplication::translate("AutoCameraDialog", "1", 0));
        label2->setText(QApplication::translate("AutoCameraDialog", "2", 0));
        label3->setText(QApplication::translate("AutoCameraDialog", "3", 0));
        OKButton->setText(QApplication::translate("AutoCameraDialog", "OK", 0));
        LoadButtom->setText(QApplication::translate("AutoCameraDialog", "Load Set Up File", 0));
    } // retranslateUi

};

namespace Ui {
    class AutoCameraDialog: public Ui_AutoCameraDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_AUTOCAMERADIALOG_H
