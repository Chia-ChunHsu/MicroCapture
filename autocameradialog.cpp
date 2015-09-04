#include "autocameradialog.h"
#include "ui_autocameradialog.h"

AutoCameraDialog::AutoCameraDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::AutoCameraDialog)
{
    ui->setupUi(this);
}

AutoCameraDialog::~AutoCameraDialog()
{
    delete ui;
}





void AutoCameraDialog::on_saveCameraNameButtom_clicked()
{
    devicename.clear();
    //QFileDialog df;
    QString filename = QFileDialog::getSaveFileName(this,tr("Save The Camera Port"),"D:/Code/FourCapture/utilited",tr("Text File  (*.txt))"));
    QFile cameranametxt(filename);

    if(cameranametxt.open(QFile::WriteOnly))
    {
        QTextStream out(&cameranametxt);

        out <<ui->CameraLabel1->text()<<" ";
        out <<ui->CameraLabel2->text()<<" ";
        out <<ui->CameraLabel3->text()<<" ";
        out <<ui->CameraLabel4->text()<<" ";
    }

    devicename.push_back(ui->CameraLabel1->text());
    devicename.push_back(ui->CameraLabel2->text());
    devicename.push_back(ui->CameraLabel3->text());
    devicename.push_back(ui->CameraLabel4->text());

    cameranametxt.close();

}

void AutoCameraDialog::on_Detect_clicked()
{
    QList<QCameraInfo> cameras = QCameraInfo::availableCameras();

    qDebug()<<cameras[0].deviceName();
    std::vector<QString> name;
    for(int i=0;i<cameras.size();i++)
    {
        if(cameras[i].deviceName().contains("usb#vid_05ac&pid_8507&mi_02"))
        {
            QStringList list1 = cameras[i].deviceName().split("#");
            name.push_back(list1[2]);
        }
    }
    if(ui->CameraLabel1->text()=="")
    {
        ui->CameraLabel1->setText(name[0]);
    }
    else if(ui->CameraLabel2->text()=="")
    {
        ui->CameraLabel2->setText(name[0]);
    }
    else if(ui->CameraLabel3->text()=="")
    {
        ui->CameraLabel3->setText(name[0]);
    }
    else if(ui->CameraLabel4->text()=="")
    {
        ui->CameraLabel4->setText(name[0]);
    }

}

void AutoCameraDialog::on_CancelButtom_clicked()
{
    ui->CameraLabel1->setText("");
    ui->CameraLabel2->setText("");
    ui->CameraLabel3->setText("");
    ui->CameraLabel4->setText("");
    close();
}


void AutoCameraDialog::on_OKButton_clicked()
{
    close();
}

std::vector<int> AutoCameraDialog::getdivice()
{
    return device;
}

std::vector<QString> AutoCameraDialog::getDeiveceName()
{
    return devicename;
}


void AutoCameraDialog::on_LoadButtom_clicked()
{
    QString filename = QFileDialog::getOpenFileName(this,tr("Load The Camera Name"),"D:/Code/FourCapture/",tr("Text File  (*.txt))"));
    QFile cameranametxt(filename);
    if(cameranametxt.open(QFile::ReadOnly ))
    {
        QTextStream in(&cameranametxt);
        QString line = in.readLine();
        qDebug()<<line;
        QStringList list = line.split(" ");
        ui->CameraLabel1->setText(list[0]);
        ui->CameraLabel2->setText(list[1]);
        ui->CameraLabel3->setText(list[2]);
        ui->CameraLabel4->setText(list[3]);

    }
    cameranametxt.close();
    devicename.clear();
    devicename.push_back(ui->CameraLabel1->text());
    devicename.push_back(ui->CameraLabel2->text());
    devicename.push_back(ui->CameraLabel3->text());
    devicename.push_back(ui->CameraLabel4->text());

    //close();
}
