#ifndef THREAD_STITCH_H
#define THREAD_STITCH_H
#include <QThread>
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
#include <Qlist>
#include <QCameraInfo>
#include <QProgressBar>
#include "stitch.h"

class Thread_Stitch :public QThread
{
public:
    Thread_Stitch();
    ~Thread_Stitch();
    int Warp(std::vector<cv::Mat> &CalMat,std::vector<cv::Mat> &CalWarp ,std::vector<cv::Mat> &nodilate_warp,cv::Mat &Result,std::vector<cv::Point> &ConrnerPoint);
    int StLike(std::vector<cv::Mat> &CalMat,std::vector<cv::Mat> &CapMat,std::vector<cv::Mat> &img_warp_result,std::vector<cv::Mat> &Ks_,std::vector<cv::detail::CameraParams> &cameras_s_);
    std::vector<cv::Mat> getK();
    std::vector<cv::detail::CameraParams> getCam();

private:
    std::vector<cv::Ptr<cv::detail::Blender>> blender_2;
    std::vector<cv::Mat> img_warp;
    std::vector<cv::Mat> dilate_mask;
    std::vector<cv::Mat> Ks;
    std::vector<cv::detail::CameraParams> cameras_s;


    //std::vector<cv::Mat> nodilate_warp;

};

#endif // THREAD_STITCH_H
