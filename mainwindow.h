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
//#include "stitch.h"
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


private slots:
    void on_ProgressList_currentRowChanged(int currentRow);

    void on_LoadCalButtom_clicked();

    void on_LoadCapPic_clicked();

    void on_CapResultSlider_sliderMoved(int position);

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

    void on_hclassslider1_sliderMoved(int position);

    void on_hclassslider3_sliderMoved(int position);

    void on_iclassslider3_sliderMoved(int position);

    void on_trainButton_clicked();

    void on_hSlider_sliderMoved(int position);

    void on_vSlider_sliderMoved(int position);

    void on_SetButtom_clicked();


    void on_getDataButton_clicked();

private:

    Ui::MainWindow *ui;
    std::vector<cv::Mat> CalMat;
    std::vector<cv::Mat> CapMat;
    QProgressBar *statusProgressBar;
    QLabel *statusLabel;
    QLabel *statusGap;
    std::vector<cv::Mat> CapWarp;
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



//    int k();
//    cv::Mat gaussianDistance( cv::vector<cv::Point2f> points, float sigma = 1.0, float division_factor = 1.0 );
//    cv::Mat degreeMatrix( cv::Mat& adjacency );
//    void plot( cv::Mat& img, cv::Mat& points, cv::Mat& labels );
//    void plot( cv::Mat& img, std::vector<cv::Point2f>& points, cv::Scalar color = cv::Scalar(0) );
//    cv::vector<cv::Point2f> createCircles( int center_x, int center_y, float radius, int n_samples );
};

#endif // MAINWINDOW_H
