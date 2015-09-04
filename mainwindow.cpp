#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    statusLabel = new QLabel(this);
    statusProgressBar = new QProgressBar(this);
    statusGap = new QLabel(this);
    statusGap->setFixedWidth(200);
    statusProgressBar->setTextVisible(false);
    ui->statusBar->addPermanentWidget(statusLabel);
    ui->statusBar->addPermanentWidget(statusProgressBar,1);
    ui->statusBar->addPermanentWidget(statusGap);
    ui->stackedWidget->setCurrentIndex(0);

}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::ShowOnLabel(cv::Mat mat, QLabel *k)
{
    QImage qtemp = QImage((const unsigned char*)(mat.data),mat.cols,mat.rows,mat.step,QImage::Format_RGB888);
    k->clear();
    k->setPixmap(QPixmap::fromImage(qtemp.scaled(k->width(),k->height(),Qt::KeepAspectRatio)));
    k->show();
}

void MainWindow::on_ProgressList_currentRowChanged(int currentRow)
{
    if(currentRow == 0)
    {
        ui->stackedWidget->setCurrentIndex(0);
    }
    else if(currentRow == 1)
    {
        ui->stackedWidget->setCurrentIndex(1);
    }
    else if(currentRow == 2)
    {
        ui->stackedWidget->setCurrentIndex(2);
    }
}

void MainWindow::on_LoadCalButtom_clicked()
{
    CalMat.clear();
    statusProgressBar->setValue(0);
    QStringList fileNames = QFileDialog::getOpenFileNames(this,tr("Open Image"), "D:/Code/FourCapture/", tr("Image Files (*.jpg)"));

    if(fileNames.size()>4)
    {
        statusLabel->setText("Chosse Too Many Pictures!");
        return;
    }
    else if(fileNames.size()<4)
    {
        statusLabel->setText("Not Enough Pictures!");
        return;
    }
    for(int i=0;i<4;i++)
    {
        cv::Mat temp = cv::imread(fileNames[i].toStdString().c_str(),cv::IMREAD_COLOR);
        CalMat.push_back(temp);
    }

    ShowOnLabel(CalMat[0],ui->CalLabel1);
    ShowOnLabel(CalMat[1],ui->CalLabel2);
    ShowOnLabel(CalMat[2],ui->CalLabel3);
    ShowOnLabel(CalMat[3],ui->CalLabel4);
    statusLabel->setText("Load Reference Pictures Success!");
    statusProgressBar->setValue(20);

    std::vector<cv::Mat> WarpMat;
    std::vector<cv::Mat> WarpM;
    qDebug()<<CalMat[0].cols;

    if(TS.Warp(CalMat,WarpMat,nonDilateMask,CalResult,CorPoint)!=1)
    {
        statusLabel->setText("Stitching Fail!");
        return;
    }
    statusLabel->setText("Stitching Success!");

    statusProgressBar->setValue(60);
    ui->stackedWidget->setCurrentIndex(1);

    for(int n=0;n<WarpMat.size();n++)
    {
        cv::Mat resultTemp = WarpMat[n].clone();
        for(int i=0;i<WarpMat[n].cols;i++)
        {
            for(int j=0;j<WarpMat[n].rows;j++)
            {
                if(nonDilateMask[n].at<uchar>(j,i) == 255)
                {
                    resultTemp.at<cv::Vec3b>(j, i)[0] = WarpMat[n].at<cv::Vec3b>(j,i)[0];
                    resultTemp.at<cv::Vec3b>(j, i)[1] = WarpMat[n].at<cv::Vec3b>(j,i)[1];
                    resultTemp.at<cv::Vec3b>(j, i)[2] = WarpMat[n].at<cv::Vec3b>(j,i)[2];
                }
                else
                {
                    resultTemp.at<cv::Vec3b>(j, i)[0] = 0;
                    resultTemp.at<cv::Vec3b>(j, i)[1] = 0;
                    resultTemp.at<cv::Vec3b>(j, i)[2] = 0;
                }
            }
        }
        WarpM.push_back(resultTemp);
    }

    ShowOnLabel(WarpM[0],ui->WarpCalLabel1);
    ShowOnLabel(WarpM[1],ui->WarpCalLabel2);
    ShowOnLabel(WarpM[2],ui->WarpCalLabel3);
    ShowOnLabel(WarpM[3],ui->WarpCalLabel4);
    statusProgressBar->setValue(80);


    ui->stackedWidget->setCurrentIndex(2);
    ShowOnLabel(CalResult,ui->CalResultLabel);

    statusProgressBar->setValue(100);
    ui->LoadCapPic->setEnabled(true);
    ui->CapturePicture->setEnabled(true);


    cv::Mat temp;

    cv::Size size(CalMat[0].cols,CalMat[0].rows);
    temp.create(size,CV_MAKETYPE(temp.type(),3));
    temp = cv::Scalar::all(0);
    for(int i=0;i<4;i++)
    {
        BlackRef.push_back(temp);
    }
    ui->LBlackRefButton->setEnabled(true);
}

void MainWindow::on_LoadCapPic_clicked()
{
    CapMat.clear();
    statusProgressBar->setValue(0);
    QStringList fileNames = QFileDialog::getOpenFileNames(this,tr("Open Image"), "D:/Code/FourCapture/", tr("Image Files (*.jpg)"));

    if(fileNames.size()>4)
    {
        statusLabel->setText("Choose Too Many Pictures!");
        return;
    }
    else if(fileNames.size()<4)
    {
        statusLabel->setText("Not Enough Pictures!");
        return;
    }
    for(int i=0;i<4;i++)
    {
        cv::Mat temp = cv::imread(fileNames[i].toStdString().c_str(),cv::IMREAD_COLOR);
        if(temp.empty())
        {
            statusLabel->setText("Get Null Image!");
            return;
        }
        CapMat.push_back(temp);
    }
    for(int i=0;i<4;i++)
    {
        CapMat[i] = CapMat[i] -BlackRef[i];
    }

    ShowOnLabel(CapMat[0],ui->FilterLabel1);
    ShowOnLabel(CapMat[1],ui->FilterLabel2);
    ShowOnLabel(CapMat[2],ui->FilterLabel3);
    ShowOnLabel(CapMat[3],ui->FilterLabel4);
    statusLabel->setText("Load Capture Pictures Success!");
    statusProgressBar->setValue(20);
    if(Cal()==1)
    {
        statusLabel->setText("Success!");
    }
    else
    {
        statusLabel->setAcceptDrops("Fail!");
    }

    std::vector<cv::Mat> CapWarp2;

    CapWarp2.clear();
    for(int i=0;i<4;i++)
    {
         CapWarp2.push_back(CapWarp[i]);
    }

    cv::Size s = cv::Size(640,480);
    for(int i=0;i<4;i++)
    {
        cv::resize(CapWarp2[i],CapWarp[i],s);
        cv::Mat temp = nonDilateMask[i];
        cv::resize(temp,nonDilateMask[i],s);
    }

    CapWarp2.clear();
    for(int n=0;n<CapWarp.size();n++)
    {
        cv::Mat resultTemp = CapWarp[n].clone();
        //qDebug()<<n<<CapWarp[n].cols<<nonDilateMask[n].cols;
        for(int i=0;i<CapWarp[n].cols;i++)
        {
            for(int j=0;j<CapWarp[n].rows;j++)
            {
                if(nonDilateMask[n].at<uchar>(j,i) == 255)
                {

                }
                else if(nonDilateMask[n].at<uchar>(j,i) != 255)
                {
                    resultTemp.at<cv::Vec3b>(j, i)[0] = 0;
                    resultTemp.at<cv::Vec3b>(j, i)[1] = 0;
                    resultTemp.at<cv::Vec3b>(j, i)[2] = 0;
                }
            }
        }
        CapWarp2.push_back(resultTemp);
    }
    CapWarp.clear();
    for(int i=0;i<CapWarp2.size();i++)
    {
        CapWarp.push_back(CapWarp2[i]);
    }

    ShowOnLabel(CapWarp[0],ui->WarpFilterLabel1);
    ShowOnLabel(CapWarp[1],ui->WarpFilterLabel2);
    ShowOnLabel(CapWarp[2],ui->WarpFilterLabel3);
    ShowOnLabel(CapWarp[3],ui->WarpFilterLabel4);
    statusProgressBar->setValue(40);
    Stitch(200);
    statusProgressBar->setValue(100);
    ui->CapResultSlider->setEnabled(true);
    ui->saveResultButtom->setEnabled(true);
}

int MainWindow::Cal()
{
    CapWarp.clear();
    if(TS_Detect.StLike(CalMat,CapMat,CapWarp,TS.getK(),TS.getCam())!=1)
    {
        return 0;
    }
    return 1;
}

void MainWindow::Stitch(int value)
{
    RCapWarp.clear();
    cv::Point t1(std::numeric_limits<int>::max(), std::numeric_limits<int>::max());
    for(int i=0;i<CorPoint.size();i++)
    {
        t1.x = std::min(t1.x,CorPoint[i].x);
        t1.y = std::min(t1.y,CorPoint[i].y);
    }

    cv::Size size(CalResult.cols,CalResult.rows);
    CapResult.create(size,CV_MAKETYPE(CapResult.type(),3));
    CapResult = cv::Scalar::all(0);

    for(int i=0;i<CapWarp.size();i++)
    {
        RCapWarp.push_back(CapWarp[i]);
    }
    qDebug()<<RCapWarp[0].cols<<RCapWarp[1].cols<<RCapWarp[2].cols<<RCapWarp[3].cols;

    for(int number=0;number<CapWarp.size();number++)
    {
        int x = CorPoint[number].x;
        int y = CorPoint[number].y;

        for(int i = 0;i<RCapWarp[number].cols;i++)
        {
            for(int j=0;j<RCapWarp[number].rows;j++)
            {
                if((RCapWarp[number].at<cv::Vec3b>(j,i)[0]+RCapWarp[number].at<cv::Vec3b>(j,i)[1]+RCapWarp[number].at<cv::Vec3b>(j,i)[2])/3 >value)
                {
                    if(j+y-t1.y<CalResult.rows && i+x-t1.x<CalResult.cols && j+y-t1.y>=0 && i+x-t1.x>=0 && number == 1)
                    {
                        CapResult.at<cv::Vec3b>(j+y-t1.y,i+x-t1.x)[0] = 255;
                    }
                    else if(j+y-t1.y<CalResult.rows && i+x-t1.x<CalResult.cols && j+y-t1.y>=0 && i+x-t1.x>=0 && number == 2)
                    {
                        CapResult.at<cv::Vec3b>(j+y-t1.y,i+x-t1.x)[1] = 255;
                    }
                    else if(j+y-t1.y<CalResult.rows && i+x-t1.x<CalResult.cols && j+y-t1.y>=0 && i+x-t1.x>=0 && number == 3)
                    {
                        CapResult.at<cv::Vec3b>(j+y-t1.y,i+x-t1.x)[2] = 255;
                    }
//                    else if(j+y-t1.y<CalResult.rows && i+x-t1.x<CalResult.cols && j+y-t1.y>=0 && i+x-t1.x>=0 && number == 0)
//                    {
//                        CapResult.at<cv::Vec3b>(j+y-t1.y,i+x-t1.x)[2] = 255;
//                    }
                }
            }
        }
    }
    //qDebug()<<"pano_ "<<CapResult.cols<<CapResult.rows;

    ShowOnLabel(CapResult,ui->CapResultLabel);

}

void MainWindow::on_CapResultSlider_sliderMoved(int position)
{
    Stitch(position);
    ui->CapResultSlider->setValue(position);
}

void MainWindow::on_LBlackRefButton_clicked()
{
    BlackRef.clear();

    QStringList fileNames = QFileDialog::getOpenFileNames(this,tr("Open Image of Black Ref Pic"), "D:/Code/FourCapture/", tr("Image Files (*.jpg)"));

    if(fileNames.size()>4)
    {
        statusLabel->setText("Chosse Too Many Pictures!");
        return;
    }
    else if(fileNames.size()<4)
    {
        statusLabel->setText("Not Enough Pictures!");
        return;
    }
    for(int i=0;i<4;i++)
    {
        cv::Mat temp = cv::imread(fileNames[i].toStdString().c_str(),cv::IMREAD_COLOR);
        BlackRef.push_back(temp);
    }

    ShowOnLabel(BlackRef[0],ui->BlackReflabel1);
    ShowOnLabel(BlackRef[1],ui->BlackReflabel2);
    ShowOnLabel(BlackRef[2],ui->BlackReflabel3);
    ShowOnLabel(BlackRef[3],ui->BlackReflabel4);
}

void MainWindow::on_CaptureCalButtom_clicked()
{
    CalMat.clear();

    statusProgressBar->setValue(0);

    //QStringList fileNames = QFileDialog::getOpenFileNames(this,tr("Open Image"), "D:/Code/FourCapture/", tr("Image Files (*.jpg)"));

    int DeviceID[4]={-1,-1,-1,-1};
    QList<QCameraInfo> cameras = QCameraInfo::availableCameras();

    if(VideoName.size() == 0)
    {
        statusLabel->setText("Please SetUp Camera First!");
        return;
    }

    for(int i=0;i<10;i++)
    {
        if(i>= cameras.size())
        {

        }
        else if(cameras.at(i).deviceName().contains(VideoName[0]))
        {
            DeviceID[0] = i;
        }
        else if(cameras.at(i).deviceName().contains(VideoName[1]))
        {
            DeviceID[1] = i;
        }
        else if(cameras.at(i).deviceName().contains(VideoName[2]))
        {
            DeviceID[2] = i;
        }
        else if(cameras.at(i).deviceName().contains(VideoName[3]))
        {
            DeviceID[3] = i;
        }

    }

    cv::VideoCapture cap1(DeviceID[0]);
    cv::VideoCapture cap2(DeviceID[1]);

    cap1.set(CV_CAP_PROP_BRIGHTNESS,160);
    cap2.set(CV_CAP_PROP_BRIGHTNESS,160);
    cap1.set(CV_CAP_PROP_CONTRAST,165);
    cap2.set(CV_CAP_PROP_CONTRAST,165);
    cap1.set(CV_CAP_PROP_SATURATION,125);
    cap2.set(CV_CAP_PROP_SATURATION,125);

    if(!cap1.isOpened() || !cap2.isOpened())
        return;


    cv::Mat frame0;
    cv::Mat frame1;
    for(int i = 0; i< 100;i++)
    {

        cap1>>frame0;
        cap2>>frame1;
        cv::waitKey(100);
    }
    CalMat.push_back(frame0);
    CalMat.push_back(frame1);
    cap1.release();
    cap2.release();


    cv::VideoCapture cap3(DeviceID[2]);
    cv::VideoCapture cap4(DeviceID[3]);

    cap3.set(CV_CAP_PROP_BRIGHTNESS,160);
    cap4.set(CV_CAP_PROP_BRIGHTNESS,160);
    cap3.set(CV_CAP_PROP_CONTRAST,165);
    cap4.set(CV_CAP_PROP_CONTRAST,165);
    cap3.set(CV_CAP_PROP_SATURATION,125);
    cap4.set(CV_CAP_PROP_SATURATION,125);


    if(!cap3.isOpened() || !cap4.isOpened())
        return;

    cv::Mat frame2;
    cv::Mat frame3;

    for(int i = 0; i< 100;i++)
    {
        cap3>>frame2;
        cap4>>frame3;
        cv::waitKey(100);
    }
    CalMat.push_back(frame2);
    CalMat.push_back(frame3);
    cap3.release();
    cap4.release();


    ShowOnLabel(CalMat[0],ui->CalLabel1);
    ShowOnLabel(CalMat[1],ui->CalLabel2);
    ShowOnLabel(CalMat[2],ui->CalLabel3);
    ShowOnLabel(CalMat[3],ui->CalLabel4);
    statusLabel->setText("Load Reference Pictures Success!");
    statusProgressBar->setValue(20);

    std::vector<cv::Mat> WarpMat;
    std::vector<cv::Mat> nonDilateMask;
    std::vector<cv::Mat> WarpM;

    if(TS.Warp(CalMat,WarpMat,nonDilateMask,CalResult,CorPoint)!=1)
    {
        statusLabel->setText("Stitching Fail!");
        return;
    }
    statusLabel->setText("Stitching Success!");

    statusProgressBar->setValue(60);
    ui->stackedWidget->setCurrentIndex(1);

    for(int n=0;n<WarpMat.size();n++)
    {
        cv::Mat resultTemp = WarpMat[n].clone();
        for(int i=0;i<WarpMat[n].cols;i++)
        {
            for(int j=0;j<WarpMat[n].rows;j++)
            {
                if(nonDilateMask[n].at<uchar>(j,i) == 255)
                {
                    resultTemp.at<cv::Vec3b>(j, i)[0] = WarpMat[n].at<cv::Vec3b>(j,i)[0];
                    resultTemp.at<cv::Vec3b>(j, i)[1] = WarpMat[n].at<cv::Vec3b>(j,i)[1];
                    resultTemp.at<cv::Vec3b>(j, i)[2] = WarpMat[n].at<cv::Vec3b>(j,i)[2];
                }
                else
                {
                    resultTemp.at<cv::Vec3b>(j, i)[0] = 0;
                    resultTemp.at<cv::Vec3b>(j, i)[1] = 0;
                    resultTemp.at<cv::Vec3b>(j, i)[2] = 0;
                }
            }
        }
        WarpM.push_back(resultTemp);
    }

    ShowOnLabel(WarpM[0],ui->WarpCalLabel1);
    ShowOnLabel(WarpM[1],ui->WarpCalLabel2);
    ShowOnLabel(WarpM[2],ui->WarpCalLabel3);
    ShowOnLabel(WarpM[3],ui->WarpCalLabel4);
    statusProgressBar->setValue(80);


    ui->stackedWidget->setCurrentIndex(2);
    ShowOnLabel(CalResult,ui->CalResultLabel);

    statusProgressBar->setValue(100);
    ui->LoadCapPic->setEnabled(true);
    ui->CapturePicture->setEnabled(true);


    cv::Mat temp;

    cv::Size size(CalMat[0].cols,CalMat[0].rows);
    temp.create(size,CV_MAKETYPE(temp.type(),3));
    temp = cv::Scalar::all(0);
    for(int i=0;i<4;i++)
    {
        BlackRef.push_back(temp);
    }
    ui->LBlackRefButton->setEnabled(true);
}

void MainWindow::on_saveResultButtom_clicked()
{
    QString fileName = QFileDialog::getSaveFileName(this, tr("Save File"),
                               "D:/Code/FourCapture/utilited.jpg",
                               tr("Images (*.png *.jpg)"));
    cv::imwrite(fileName.toStdString().c_str(),CapResult);
    cv::imwrite("1.jpg",CapMat[0]);
    cv::imwrite("2.jpg",CapMat[1]);
    cv::imwrite("3.jpg",CapMat[2]);
    cv::imwrite("4.jpg",CapMat[3]);

}

void MainWindow::on_AutoDetectButtom_clicked()
{

    VideoName.clear();
//    QList<QCameraInfo> cameras = QCameraInfo::availableCameras();

//    //std::vector<QString> name;
//    for(int i=0;i<cameras.size();i++)
//    {
//        if(cameras[i].deviceName().contains("usb#vid_05ac&pid_8507&mi_02"))
//            VideoName.push_back(cameras[i].deviceName());
//        //name.push_back(cameras[i].deviceName());
//    }

    autocamera.show();

}

void MainWindow::on_SetUpButton_clicked()
{
    VideoName = autocamera.getDeiveceName();
}

void MainWindow::on_CapturePicture_clicked()
{
    CapMat.clear();

    statusProgressBar->setValue(0);

    //QStringList fileNames = QFileDialog::getOpenFileNames(this,tr("Open Image"), "D:/Code/FourCapture/", tr("Image Files (*.jpg)"));

    int DeviceID[4]={-1,-1,-1,-1};
    QList<QCameraInfo> cameras = QCameraInfo::availableCameras();


    if(VideoName.size() == 0)
    {
        statusLabel->setText("Please SetUp Camera First!");
        return;
    }

    for(int i=0;i<10;i++)
    {
        if(i>= cameras.size())
        {

        }
        else if(cameras.at(i).deviceName().contains(VideoName[0]))
        {
            DeviceID[0] = i;
        }
        else if(cameras.at(i).deviceName().contains(VideoName[1]))
        {
            DeviceID[1] = i;
        }
        else if(cameras.at(i).deviceName().contains(VideoName[2]))
        {
            DeviceID[2] = i;
        }
        else if(cameras.at(i).deviceName().contains(VideoName[3]))
        {
            DeviceID[3] = i;
        }
    }

    cv::VideoCapture cap1(DeviceID[0]);
    cv::VideoCapture cap2(DeviceID[1]);

    cap1.set(CV_CAP_PROP_BRIGHTNESS,160);
    cap2.set(CV_CAP_PROP_BRIGHTNESS,160);
    cap1.set(CV_CAP_PROP_CONTRAST,165);
    cap2.set(CV_CAP_PROP_CONTRAST,165);
    cap1.set(CV_CAP_PROP_SATURATION,125);
    cap2.set(CV_CAP_PROP_SATURATION,125);


    if(!cap1.isOpened() || !cap2.isOpened())
        return;


    cv::Mat frame0;
    cv::Mat frame1;
    for(int i = 0; i< 100;i++)
    {

        cap1>>frame0;
        cap2>>frame1;
        cv::waitKey(100);
    }
    CapMat.push_back(frame0);
    CapMat.push_back(frame1);

    cap1.release();
    cap2.release();


    cv::VideoCapture cap3(DeviceID[2]);
    cv::VideoCapture cap4(DeviceID[3]);

    cap3.set(CV_CAP_PROP_BRIGHTNESS,160);
    cap4.set(CV_CAP_PROP_BRIGHTNESS,160);
    cap3.set(CV_CAP_PROP_CONTRAST,165);
    cap4.set(CV_CAP_PROP_CONTRAST,165);
    cap3.set(CV_CAP_PROP_SATURATION,125);
    cap4.set(CV_CAP_PROP_SATURATION,125);


    if(!cap3.isOpened() || !cap4.isOpened())
        return;

    cv::Mat frame2;
    cv::Mat frame3;

    for(int i = 0; i< 100;i++)
    {
        cap3>>frame2;
        cap4>>frame3;
        cv::waitKey(100);
    }
    CapMat.push_back(frame2);
    CapMat.push_back(frame3);
    cap3.release();
    cap4.release();

    for(int i=0;i<4;i++)
    {
        CapMat[i] = CapMat[i] -BlackRef[i];
    }

    ShowOnLabel(CapMat[0],ui->FilterLabel1);
    ShowOnLabel(CapMat[1],ui->FilterLabel2);
    ShowOnLabel(CapMat[2],ui->FilterLabel3);
    ShowOnLabel(CapMat[3],ui->FilterLabel4);
    statusLabel->setText("Capture Test Pictures Success!");
    statusProgressBar->setValue(20);

    if(Cal()==1)
    {
        statusLabel->setText("Success!");
    }
    else
    {
        statusLabel->setAcceptDrops("Fail!");
    }
    ShowOnLabel(CapWarp[0],ui->WarpFilterLabel1);
    ShowOnLabel(CapWarp[1],ui->WarpFilterLabel2);
    ShowOnLabel(CapWarp[2],ui->WarpFilterLabel3);
    ShowOnLabel(CapWarp[3],ui->WarpFilterLabel4);

    statusProgressBar->setValue(40);
    Stitch(200);
    statusProgressBar->setValue(100);
    ui->CapResultSlider->setEnabled(true);
    ui->saveResultButtom->setEnabled(true);


}



void MainWindow::on_CaptureBLRef_clicked()
{
    BlackRef.clear();

    statusProgressBar->setValue(0);

    //QStringList fileNames = QFileDialog::getOpenFileNames(this,tr("Open Image"), "D:/Code/FourCapture/", tr("Image Files (*.jpg)"));

    int DeviceID[4]={-1,-1,-1,-1};
    QList<QCameraInfo> cameras = QCameraInfo::availableCameras();

    if(VideoName.size() == 0)
    {
        statusLabel->setText("Please SetUp Camera First!");
        return;
    }

    for(int i=0;i<10;i++)
    {
        if(i>= cameras.size())
        {

        }
        else if(cameras.at(i).deviceName().contains(VideoName[0]))
        {
            DeviceID[0] = i;
        }
        else if(cameras.at(i).deviceName().contains(VideoName[1]))
        {
            DeviceID[1] = i;
        }
        else if(cameras.at(i).deviceName().contains(VideoName[2]))
        {
            DeviceID[2] = i;
        }
        else if(cameras.at(i).deviceName().contains(VideoName[3]))
        {
            DeviceID[3] = i;
        }

    }

    cv::VideoCapture cap1(DeviceID[0]);
    cv::VideoCapture cap2(DeviceID[1]);

    cap1.set(CV_CAP_PROP_BRIGHTNESS,160);
    cap2.set(CV_CAP_PROP_BRIGHTNESS,160);
    cap1.set(CV_CAP_PROP_CONTRAST,165);
    cap2.set(CV_CAP_PROP_CONTRAST,165);
    cap1.set(CV_CAP_PROP_SATURATION,125);
    cap2.set(CV_CAP_PROP_SATURATION,125);

    if(!cap1.isOpened() || !cap2.isOpened())
        return;


    cv::Mat frame0;
    cv::Mat frame1;
    for(int i = 0; i< 100;i++)
    {

        cap1>>frame0;
        cap2>>frame1;
        cv::waitKey(100);
    }
    BlackRef.push_back(frame0);
    BlackRef.push_back(frame1);
    cap1.release();
    cap2.release();


    cv::VideoCapture cap3(DeviceID[2]);
    cv::VideoCapture cap4(DeviceID[3]);

    cap3.set(CV_CAP_PROP_BRIGHTNESS,160);
    cap4.set(CV_CAP_PROP_BRIGHTNESS,160);
    cap3.set(CV_CAP_PROP_CONTRAST,165);
    cap4.set(CV_CAP_PROP_CONTRAST,165);
    cap3.set(CV_CAP_PROP_SATURATION,125);
    cap4.set(CV_CAP_PROP_SATURATION,125);


    if(!cap3.isOpened() || !cap4.isOpened())
        return;

    cv::Mat frame2;
    cv::Mat frame3;

    for(int i = 0; i< 100;i++)
    {
        cap3>>frame2;
        cap4>>frame3;
        cv::waitKey(100);
    }
    BlackRef.push_back(frame2);
    BlackRef.push_back(frame3);
    cap3.release();
    cap4.release();


    ShowOnLabel(BlackRef[0],ui->BlackReflabel1);
    ShowOnLabel(BlackRef[1],ui->BlackReflabel2);
    ShowOnLabel(BlackRef[2],ui->BlackReflabel3);
    ShowOnLabel(BlackRef[3],ui->BlackReflabel4);
}

void MainWindow::on_SaveBlackRef_clicked()
{

    QString fileName = QFileDialog::getSaveFileName(this,tr("Save Image of Black Ref Pic"), "D:/Code/FourCapture/", tr("Image Files"));

    cv::imwrite(fileName.toStdString()+std::string("1.jpg"),BlackRef[0]);
    cv::imwrite(fileName.toStdString()+std::string("2.jpg"),BlackRef[1]);
    cv::imwrite(fileName.toStdString()+std::string("3.jpg"),BlackRef[2]);
    cv::imwrite(fileName.toStdString()+std::string("4.jpg"),BlackRef[3]);
}

void MainWindow::on_SaveCalButtom_clicked()
{
    QString fileName = QFileDialog::getSaveFileName(this,tr("Save Image of Calbration Ref Pic"), "D:/Code/FourCapture/", tr("Image Files"));

    cv::imwrite(fileName.toStdString()+std::string("1.jpg"),CalMat[0]);
    cv::imwrite(fileName.toStdString()+std::string("2.jpg"),CalMat[1]);
    cv::imwrite(fileName.toStdString()+std::string("3.jpg"),CalMat[2]);
    cv::imwrite(fileName.toStdString()+std::string("4.jpg"),CalMat[3]);
}

void MainWindow::on_SaveCap_clicked()
{
    QString fileName = QFileDialog::getSaveFileName(this,tr("Save Image of Capturer Pic"), "D:/Code/FourCapture/", tr("Image Files"));

    cv::imwrite(fileName.toStdString()+std::string("1.jpg"),CalMat[0]);
    cv::imwrite(fileName.toStdString()+std::string("2.jpg"),CalMat[1]);
    cv::imwrite(fileName.toStdString()+std::string("3.jpg"),CalMat[2]);
    cv::imwrite(fileName.toStdString()+std::string("4.jpg"),CalMat[3]);
}
