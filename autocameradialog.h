#ifndef AUTOCAMERADIALOG_H
#define AUTOCAMERADIALOG_H

#include <QDialog>
#include <QString>
#include <QDebug>
#include <QFileDialog>
#include <QTextStream>
#include <iostream>
#include <QCameraInfo>

namespace Ui {
class AutoCameraDialog;
}

class AutoCameraDialog : public QDialog
{
    Q_OBJECT

public:
    explicit AutoCameraDialog(QWidget *parent = 0);
    ~AutoCameraDialog();
    std::vector<int> getdivice();
    std::vector<QString> getDeiveceName();

private slots:

    void on_saveCameraNameButtom_clicked();

    void on_Detect_clicked();

    void on_CancelButtom_clicked();


    void on_OKButton_clicked();



    void on_LoadButtom_clicked();

private:
    Ui::AutoCameraDialog *ui;
    std::vector<int> device;
    std::vector<QString> devicename;
    QString tempname;
};

#endif // AUTOCAMERADIALOG_H
