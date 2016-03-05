#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QLabel>
#include <QFileDialog>
#include "opencv.hpp"
#include "features2d/features2d.hpp"
#include "core/core.hpp"
#include "nonfree/features2d.hpp"
#include "highgui/highgui.hpp"
#include "nonfree/nonfree.hpp"
#include <QDebug>
#include <string>
#include "opencv2/stitching/detail/blenders.hpp"
#include <QTextCodec>
#include "opencv2/imgproc/imgproc.hpp"
#include "ml/ml.hpp"
#include <QList>
#include <QCameraInfo>
#include <QProgressBar>
#include <QDialog>
#include "thread_stitch.h"
#include "autocameradialog.h"
#include <opencv2/core/core.hpp>
#include <QAxObject>



namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();
    void ShowOnLabel(cv::Mat mat,QLabel *k);
    int Cal();
    void Stitch(int value);
    float predictresult(int y,int x);
    void Equal();


private slots:
    void on_ProgressList_currentRowChanged(int currentRow);

    void on_LoadCalButtom_clicked();

    void on_LoadCapPic_clicked();

    void on_LBlackRefButton_clicked();

    void on_CaptureCalButtom_clicked();

    void on_saveResultButtom_clicked();

    void on_AutoDetectButtom_clicked();

    void on_SetUpButton_clicked();

    void on_CapturePicture_clicked();

    void on_CaptureBLRef_clicked();

    void on_SaveBlackRef_clicked();

    void on_SaveCalButtom_clicked();

    void on_SaveCap_clicked();

    void on_cutButton_clicked();

    void on_shadowButton_clicked();

    void on_TestButton_clicked();

    void on_trainButton_clicked();

    void on_hSlider_sliderMoved(int position);

    void on_vSlider_sliderMoved(int position);

    void on_SetButtom_clicked();


    void on_getDataButton_clicked();

    void on_PredictButton_clicked();

    void on_getData3x3Button_clicked();

    void on_EqualButton_clicked();

    void on_hSlider_valueChanged(int value);

    void on_TestButton_2_clicked();

private:

    Ui::MainWindow *ui;
    std::vector<cv::Mat> CalMat;
    std::vector<cv::Mat> CapMat;
    std::vector<cv::Mat> CapOMat;
    QProgressBar *statusProgressBar;
    QLabel *statusLabel;
    QLabel *statusGap;
    std::vector<cv::Mat> CapWarp;
    std::vector<cv::Mat> CapWEual;
    std::vector<cv::Mat> RCapWarp;

    Thread_Stitch TS;
    Thread_Stitch TS_Detect;

    std::vector<cv::Point> CorPoint;
    cv::Mat CalResult;

    std::vector<cv::Mat> BlackRef;

    cv::Mat CapResult;
    std::vector<QString> VideoName;
    std::vector<int> Device;
    AutoCameraDialog autocamera;
    std::vector<cv::Mat> nonDilateMask;


    cv::Mat MaskResult;

    std::vector<cv::Mat> ClassMat;

    std::vector<cv::Point> tempPoint;


    std::vector<cv::Mat> cutTempMat;

    std::vector<cv::Mat> savetrainMat;

    cv::Mat saveMat;
    cv::Mat saveMat3;

    CvSVM svm;
    cv::Mat predict;

};

#endif // MAINWINDOW_H
