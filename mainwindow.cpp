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

    setWindowTitle("Micro Capture ");
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

void MainWindow::on_cutButton_clicked()
{
    //cv::imshow("MaskResult",MaskResult);
    cv::Point t1(std::numeric_limits<int>::max(), std::numeric_limits<int>::max());
    for(int i=0;i<CorPoint.size();i++)
    {
        t1.x = std::min(t1.x,CorPoint[i].x);
        t1.y = std::min(t1.y,CorPoint[i].y);
    }
    std::vector<cv::Mat> temp;
    temp.clear();
    for(int i=0;i<CapWarp.size();i++)
    {
        cv::Mat tMat = CapWarp[i].clone();
        temp.push_back(tMat);
        //cv::imshow(QString::number(i).toStdString()+"CapWarp",CapWarp[i]);
    }


    for(int i=0;i<temp[0].cols;i++)
    {
        for(int j=0;j<temp[0].rows;j++)
        {
            int x,y;
            if(MaskResult.at<cv::Vec3b>(j+CorPoint[0].y-t1.y-(CorPoint[0].y - t1.y),i-t1.x+CorPoint[0].x-(CorPoint[0].x - t1.x))[0] != 255)
            {
                temp[0].at<cv::Vec3b>(j,i)[0]=0;
                temp[0].at<cv::Vec3b>(j,i)[1]=0;
                temp[0].at<cv::Vec3b>(j,i)[2]=0;
            }
            if(MaskResult.at<cv::Vec3b>(j+CorPoint[1].y-t1.y,i-t1.x+CorPoint[1].x)[0] != 255)
            {
                temp[1].at<cv::Vec3b>(j,i)[0]=0;
                temp[1].at<cv::Vec3b>(j,i)[1]=0;
                temp[1].at<cv::Vec3b>(j,i)[2]=0;
            }
            if(MaskResult.at<cv::Vec3b>(j+CorPoint[2].y-t1.y-(CorPoint[0].y - t1.y),i-t1.x+CorPoint[2].x-(CorPoint[0].x - t1.x))[0] != 255)
            {
                temp[2].at<cv::Vec3b>(j,i)[0]=0;
                temp[2].at<cv::Vec3b>(j,i)[1]=0;
                temp[2].at<cv::Vec3b>(j,i)[2]=0;
            }
            else
            {
                x = (temp[1].at<cv::Vec3b>(j,i)[0]+temp[1].at<cv::Vec3b>(j,i)[1]+temp[1].at<cv::Vec3b>(j,i)[2])/3;
                y = (temp[2].at<cv::Vec3b>(j,i)[0]+temp[2].at<cv::Vec3b>(j,i)[1]+temp[2].at<cv::Vec3b>(j,i)[2])/3;
                cv::Point tmp = cv::Point(x,y);
                tempPoint.push_back(tmp);
            }
            if(MaskResult.at<cv::Vec3b>(j+CorPoint[3].y-t1.y-(CorPoint[1].y - t1.y),i-t1.x+CorPoint[3].x-(CorPoint[2].x - t1.x))[0] != 255)
            {
                temp[3].at<cv::Vec3b>(j,i)[0]=0;
                temp[3].at<cv::Vec3b>(j,i)[1]=0;
                temp[3].at<cv::Vec3b>(j,i)[2]=0;
            }

        }
    }


//    for(int i=0;i<temp[0].cols;i++)
//    {
//        for(int j=0;j<temp[0].rows;j++)
//        {
//            if(MaskResult.at<cv::Vec3b>(j+CorPoint[0].y-t1.y-(CorPoint[0].y - t1.y),i-t1.x+CorPoint[0].x-(CorPoint[0].x - t1.x))[0] != 255)
//            {
//                temp[0].at<cv::Vec3b>(j,i)[0]=0;
//                temp[0].at<cv::Vec3b>(j,i)[1]=0;
//                temp[0].at<cv::Vec3b>(j,i)[2]=0;
//            }
//        }
//    }
//    //cv::imshow("0",temp[0]);

//    for(int i=0;i<temp[1].cols;i++)
//    {
//        for(int j=0;j<temp[1].rows;j++)
//        {
//            if(MaskResult.at<cv::Vec3b>(j+CorPoint[1].y-t1.y,i-t1.x+CorPoint[1].x)[0] != 255)
//            {
//                temp[1].at<cv::Vec3b>(j,i)[0]=0;
//                temp[1].at<cv::Vec3b>(j,i)[1]=0;
//                temp[1].at<cv::Vec3b>(j,i)[2]=0;
//            }
//        }
//    }
//    //cv::imshow("1",temp[1]);

//    for(int i=0;i<temp[2].cols;i++)
//    {
//        for(int j=0;j<temp[2].rows;j++)
//        {
//            if(MaskResult.at<cv::Vec3b>(j+CorPoint[2].y-t1.y-(CorPoint[0].y - t1.y),i-t1.x+CorPoint[2].x-(CorPoint[0].x - t1.x))[0] != 255)
//            {
//                temp[2].at<cv::Vec3b>(j,i)[0]=0;
//                temp[2].at<cv::Vec3b>(j,i)[1]=0;
//                temp[2].at<cv::Vec3b>(j,i)[2]=0;
//            }
//        }
//    }
//    //cv::imshow("2",temp[2]);

//    for(int i=0;i<temp[3].cols;i++)
//    {
//        for(int j=0;j<temp[3].rows;j++)
//        {
//            if(MaskResult.at<cv::Vec3b>(j+CorPoint[3].y-t1.y-(CorPoint[1].y - t1.y),i-t1.x+CorPoint[3].x-(CorPoint[2].x - t1.x))[0] != 255)
//            {
//                temp[3].at<cv::Vec3b>(j,i)[0]=0;
//                temp[3].at<cv::Vec3b>(j,i)[1]=0;
//                temp[3].at<cv::Vec3b>(j,i)[2]=0;
//            }
//        }
//    }
    //cv::imshow("3",temp[3]);

//    ShowOnLabel(temp[0],ui->WarpFilterLabel1);
//    ShowOnLabel(temp[1],ui->WarpFilterLabel2);
//    ShowOnLabel(temp[2],ui->WarpFilterLabel3);
//    ShowOnLabel(temp[3],ui->WarpFilterLabel4);

    ShowOnLabel(temp[0],ui->classlabel1);
    ShowOnLabel(temp[1],ui->classlabel2);
    ShowOnLabel(temp[2],ui->classlabel3);
    ShowOnLabel(temp[3],ui->classlabel4);

    ClassMat.clear();
    for(int i=0;i<temp.size();i++)
    {
        ClassMat.push_back(temp[i]);
    }


}

void MainWindow::on_shadowButton_clicked()
{
    cv::Mat shadow;

    //RCapWarp.clear();
    cv::Point t1(std::numeric_limits<int>::max(), std::numeric_limits<int>::max());
    for(int i=0;i<CorPoint.size();i++)
    {
        t1.x = std::min(t1.x,CorPoint[i].x);
        t1.y = std::min(t1.y,CorPoint[i].y);
    }

    cv::Size size(CalResult.cols,CalResult.rows);
    shadow.create(size,CV_MAKETYPE(CapResult.type(),3));
    shadow = cv::Scalar::all(0);

    std::vector<cv::Mat> tempWarp;
    tempWarp.clear();
    for(int i=0;i<CapWarp.size();i++)
    {
        tempWarp.push_back(CapWarp[i]);
    }

    int x1 = CorPoint[1].x;
    int y1 = CorPoint[1].y;

    int x3 = CorPoint[3].x;
    int y3 = CorPoint[3].y;

    int threv1 = ui->hSlider01->value();
    int threv3 = ui->hSlider03->value();


    for(int i = 0;i<shadow.cols;i++)
    {
        for(int j=0;j<shadow.rows;j++)
        {
            bool bool1 = false;
            bool bool3 = false;
            if(j-y1+t1.y >=0 && i-x1+t1.x >=0 && j-y1+t1.y <tempWarp[1].rows && i-x1+t1.x <tempWarp[1].cols)
            {
                bool1 = ( tempWarp[1].at<cv::Vec3b>(j-y1+t1.y,i-x1+t1.x)[0]+tempWarp[1].at<cv::Vec3b>(j-y1+t1.y,i-x1+t1.x)[1]+tempWarp[1].at<cv::Vec3b>(j-y1+t1.y,i-x1+t1.x)[2])/3 < threv1;
            }
            if(j-y3+t1.y >=0 && i-x3+t1.x >=0 && j-y3+t1.y <tempWarp[3].rows && i-x3+t1.x <tempWarp[3].cols)
            {
                bool3 = ( tempWarp[3].at<cv::Vec3b>(j-y3+t1.y,i-x3+t1.x)[0]+tempWarp[3].at<cv::Vec3b>(j-y3+t1.y,i-x3+t1.x)[1]+tempWarp[3].at<cv::Vec3b>(j-y3+t1.y,i-x3+t1.x)[2])/3 > threv3;
            }
            if(bool1==true && bool3 == true)
            {
                shadow.at<cv::Vec3b>(j,i)[0] = 255;
                shadow.at<cv::Vec3b>(j,i)[1] = 255;
                shadow.at<cv::Vec3b>(j,i)[2] = 255;
            }
            else
            {
                shadow.at<cv::Vec3b>(j,i)[0] = 0;
                shadow.at<cv::Vec3b>(j,i)[1] = 0;
                shadow.at<cv::Vec3b>(j,i)[2] = 0;
            }
        }
    }

    //cv::imshow("shadow",shadow);
    int erosion_elem = 0;
    int erosion_size = 8;
    int dilation_elem = 0;
    int dilation_size = 8;
    int const max_elem = 2;
    int const max_kernel_size = 21;

    int erosion_type;
    if( erosion_elem == 0 ){ erosion_type = cv::MORPH_RECT; }
    else if( erosion_elem == 1 ){ erosion_type = cv::MORPH_CROSS; }
    else if( erosion_elem == 2) { erosion_type = cv::MORPH_ELLIPSE; }

    int dilation_type;
    if( dilation_elem == 0 ){ dilation_type = cv::MORPH_RECT; }
    else if( dilation_elem == 1 ){ dilation_type = cv::MORPH_CROSS; }
    else if( dilation_elem == 2) { dilation_type = cv::MORPH_ELLIPSE; }

    cv::Mat eroMat;
    cv::Mat dilMat;
    cv::Mat eroelement = getStructuringElement( erosion_type,
                                         cv::Size( 2*erosion_size + 1, 2*erosion_size+1 ),
                                         cv::Point( erosion_size, erosion_size ) );
    cv::Mat dilelement = getStructuringElement( dilation_type,
                                           cv::Size( 2*dilation_size + 1, 2*dilation_size+1 ),
                                           cv::Point( dilation_size, dilation_size ) );
    cv::erode(shadow,eroMat,eroelement);
    cv::dilate(eroMat,MaskResult,dilelement);
    cv::imshow("dilate",MaskResult);

//    MaskResult.release();

//    MaskResult = dilMat.clone();

}

void MainWindow::on_TestButton_clicked()
{
    cv::Mat temp;
    temp.create(255,255,CV_MAKETYPE(temp.type(),3));
    temp = cv::Scalar::all(0);
    for(int number=0;number<tempPoint.size();number++)
    {
        cv::circle(temp,tempPoint[number],1,cv::Scalar(255,0,0),1,8,0);
    }
    cv::imshow("temp",temp);

    int clusterCount =2;
    int dimensions = 5;
    int sampleCount = tempPoint.size();
    cv::Mat points(sampleCount,dimensions,CV_32F);
    cv::Mat labels;
    cv::Mat centers(clusterCount,1,points.type());

    for(int i=24;i<points.rows;i++)
    {
        for(int j =0 ;j<points.cols;j++)
        {
            points.at<float>(i,j) = 20;
        }
    }

    cv::kmeans(points,clusterCount,labels,cv::TermCriteria( CV_TERMCRIT_EPS+CV_TERMCRIT_ITER, 10, 1.0), 3, cv::KMEANS_PP_CENTERS, centers);
    cv::imshow("pints",points);
    cv::imshow("Centers",centers);
    cv::imshow("Labels ",labels);


    //k();
}

//===========================================================
cv::vector<cv::Point2f> MainWindow::createCircles( int center_x, int center_y, float radius, int n_samples ){
    cv::vector<cv::Point2f> result;
    cv::Point2f center ( center_x, center_y );

    cv::RNG rng;

    for( int i = 0; i < n_samples; i++ ) {
        float x = rng.gaussian( radius ) *  (rand() % 2 == 0 ? 1.0 : -1.0 );
        float y = rng.gaussian( radius ) *  (rand() % 2 == 0 ? 1.0 : -1.0 );

        result.push_back( center + cv::Point2f(x, y) );
    }

    return result;
}

void MainWindow::plot( cv::Mat& img, cv::vector<cv::Point2f>& points, cv::Scalar color ) {
    for( cv::Point2f point: points)
        cv::circle( img, point, 2, color, 2 );
}

/**
 * Plot points and color it based on the given labels
 **/
void MainWindow::plot( cv::Mat& img, cv::Mat& points, cv::Mat& labels ) {
    int total = points.rows;

    if( total < 1 )
        return;

    static cv::Scalar colors[] = {
        cv::Scalar(255, 0, 0), cv::Scalar(0, 255, 0), cv::Scalar(0, 0, 255),
        cv::Scalar(255, 255, 0), cv::Scalar(255, 0, 255), cv::Scalar(0, 255, 255)
    };

    int * labels_ptr = labels.ptr<int>(0);
    cv::Point2f * points_ptr = points.ptr<cv::Point2f>( 0 );

    for( int i = 0; i < total; i++ )
        cv::circle( img, points_ptr[i], 2, colors[labels_ptr[i]], 2 );
}

/**
 * Create a degree matrix out from the given adjacency matrix
 **/
cv::Mat MainWindow::degreeMatrix( cv::Mat& adjacency ) {
    int cols = adjacency.cols;

    cv::Mat degree( 1, cols, CV_32FC1 );
    for( int col = 0; col < cols; col++ )
        degree.at<float>(0, col) = sum(adjacency.col( col ))[0];

    return degree;
}

/**
 * Create an adjacency matrix based on the gaussian distance between the points
 **/
cv::Mat MainWindow::gaussianDistance( cv::vector<cv::Point2f> points, float sigma, float division_factor) {
    int m = static_cast<int>(points.size());
    cv::Mat adjacency(m, m, CV_32FC1, cv::Scalar(0.0));

    for( int i = 0; i < m; i++ ) {
        float * ptr = adjacency.ptr<float>(i);
        for( int j = 0; j < m; j++ ) {
            if( i >= j )
                continue;
            /* Yeah, this is because when the original coordinates is used, it's bound to overflow in later part */
            cv::Point2f p1(points[i].x / division_factor, points[i].y / division_factor);
            cv::Point2f p2(points[j].x / division_factor, points[j].y / division_factor);
            ptr[j] = (p1 - p2).dot(p1 - p2);
        }
    }

    completeSymm( adjacency );

    adjacency = -adjacency / (2.0 * sigma * sigma);
    cv::exp( adjacency, adjacency );
    adjacency = adjacency - cv::Mat::eye(m, m, CV_32FC1 );

    return adjacency;
}


int MainWindow::k() {
    /* Create 2 blobs of points */
//    std::vector<cv::Point2f> points1 = createCircles( 150, 150, 50.0f, 500 );
//    std::vector<cv::Point2f> points2 = createCircles( 450, 450, 40.0f, 500 );
    std::vector<cv::Point2f> points;
//    points.insert( points.end(), points1.begin(), points1.end() );
//    points.insert( points.end(), points2.begin(), points2.end() );
    points.insert( points.end(),tempPoint.begin(),tempPoint.end());

    /* Create adjacency and degree matrices */
    cv::Mat adjacency = gaussianDistance( points, 0.1f, 500.0f );
    cv::Mat degree = degreeMatrix( adjacency );

    /* Create laplacian matrix */
    cv::Mat L = cv::Mat::diag( degree ) - adjacency;
    cv::Mat degree_05;
    pow( degree, -0.5, degree_05 );
    degree_05 = cv::Mat::diag( degree_05 );
    L = (degree_05 * L) * degree_05;

    /* Perform eigen decompositions */
    cv::Mat eigenvalues, eigenvectors;
    cv::eigen( L, eigenvalues, eigenvectors );

    /* Since it's automatically sorted in descending order, take the last two entries of eigenvectors */
    eigenvectors = eigenvectors.rowRange( eigenvectors.rows - 2, eigenvectors.rows ).t();

    /* Perform K-means on eigenvectors */
    cv::Mat labels;
    cv::kmeans( eigenvectors, 2, labels, cv::TermCriteria(CV_TERMCRIT_EPS + CV_TERMCRIT_ITER, 1000, 1e-5), 2, cv::KMEANS_RANDOM_CENTERS );

    /* Plot it out */
    cv::Mat img(600, 600, CV_8UC3, cv::Scalar(255, 255, 255) );
    plot( img, points );

    cv::Mat points_mat( points );
    plot( img, points_mat, labels );

    cv::namedWindow( "Spectral Clustering on OpenCV" );
    cv::moveWindow( "Spectral Clustering on OpenCV", 0, 0 );
    cv::imshow( "Spectral Clustering on OpenCV", img );
    cv::waitKey();

    return 0;
}

void MainWindow::on_hclassslider1_sliderMoved(int position)
{
    cv::Mat temp;

    //temp.create(ClassMat[0].rows,ClassMat[0].cols,CV_MAKETYPE(ClassMat[0].type(),3));
    temp = ClassMat[0].clone();
    for(int i=0;i<ClassMat[0].cols;i++)
    {
        for(int j=0;j<ClassMat[0].rows;j++)
        {
            if(ClassMat[0].at<cv::Vec3b>(j,i)[0] <position +5  && ClassMat[0].at<cv::Vec3b>(j,i)[0] > position-5)
            {
                temp.at<cv::Vec3b>(j,i)[0] = 0;
                temp.at<cv::Vec3b>(j,i)[1] = 255;
                temp.at<cv::Vec3b>(j,i)[2] = 0;
            }
        }
    }
    ShowOnLabel(temp,ui->classlabel1);
}

void MainWindow::on_hclassslider3_sliderMoved(int position)
{
    cv::Mat temp;

    //temp.create(ClassMat[0].rows,ClassMat[0].cols,CV_MAKETYPE(ClassMat[0].type(),3));
    temp = ClassMat[2].clone();
    int v = ui->iclassslider3->value();
    for(int i=0;i<ClassMat[2].cols;i++)
    {
        for(int j=0;j<ClassMat[2].rows;j++)
        {

            if(ClassMat[2].at<cv::Vec3b>(j,i)[0] <position+10  && ClassMat[2].at<cv::Vec3b>(j,i)[0] > position-10)
            {
                temp.at<cv::Vec3b>(j,i)[0] = 0;
                temp.at<cv::Vec3b>(j,i)[1] = 255;
                temp.at<cv::Vec3b>(j,i)[2] = 0;
            }
            else if(ClassMat[2].at<cv::Vec3b>(j,i)[0] <v+10  && ClassMat[2].at<cv::Vec3b>(j,i)[0] > v-10)
            {
                temp.at<cv::Vec3b>(j,i)[0] = 255;
                temp.at<cv::Vec3b>(j,i)[1] = 0;
                temp.at<cv::Vec3b>(j,i)[2] = 0;
            }
        }
    }
    ShowOnLabel(temp,ui->classlabel3);
    ui->showlabel1->setText(QString::number(position));
    ui->showlabel2->setText(QString::number(v));
}

void MainWindow::on_iclassslider3_sliderMoved(int position)
{
    cv::Mat temp;

    //temp.create(ClassMat[0].rows,ClassMat[0].cols,CV_MAKETYPE(ClassMat[0].type(),3));
    temp = ClassMat[2].clone();
    int v = ui->hclassslider3->value();
    for(int i=0;i<ClassMat[2].cols;i++)
    {
        for(int j=0;j<ClassMat[2].rows;j++)
        {

            if(ClassMat[2].at<cv::Vec3b>(j,i)[0] <position+10  && ClassMat[2].at<cv::Vec3b>(j,i)[0] > position-10)
            {
                temp.at<cv::Vec3b>(j,i)[0] = 255;
                temp.at<cv::Vec3b>(j,i)[1] = 0;
                temp.at<cv::Vec3b>(j,i)[2] = 0;
            }
            else if(ClassMat[2].at<cv::Vec3b>(j,i)[0] <v+10  && ClassMat[2].at<cv::Vec3b>(j,i)[0] > v-10)
            {
                temp.at<cv::Vec3b>(j,i)[0] = 0;
                temp.at<cv::Vec3b>(j,i)[1] = 255;
                temp.at<cv::Vec3b>(j,i)[2] = 0;
            }
        }
    }
    ShowOnLabel(temp,ui->classlabel3);
    ui->showlabel2->setText(QString::number(position));
    ui->showlabel1->setText(QString::number(v));
}
