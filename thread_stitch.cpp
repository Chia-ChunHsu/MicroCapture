#include "thread_stitch.h"

Thread_Stitch::Thread_Stitch()
{

}

Thread_Stitch::~Thread_Stitch()
{

}

int Thread_Stitch::Warp(std::vector<cv::Mat> &CalMat,std::vector<cv::Mat> &CalWarp,std::vector<cv::Mat> &nodilate_warp,cv::Mat &Result,std::vector<cv::Point> &ConrnerPoint)
{
    cv::Stitch stitcher = cv::Stitch::createDefault();

    cv::Stitch::Status status;
    status = stitcher.stitch2(CalMat,Result,CalWarp,nodilate_warp,ConrnerPoint,Ks,cameras_s);

    if (cv::Stitch::OK == status)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

int Thread_Stitch::StLike(std::vector<cv::Mat> &CalMat,std::vector<cv::Mat> &CapMat,std::vector<cv::Mat> &img_warp_result,std::vector<cv::Mat> &Ks_,std::vector<cv::detail::CameraParams> &cameras_s_)
{
    cv::Stitch stitcher = cv::Stitch::createDefault();
    cv::Stitch::Status status;
    status = stitcher.stitch3(CalMat,CapMat,img_warp_result,Ks_,cameras_s_);
    //qDebug()<<img_warp_result.size();
    return 1;
}

std::vector<cv::Mat> Thread_Stitch::getK()
{
    return Ks;
}

std::vector<cv::detail::CameraParams> Thread_Stitch::getCam()
{
    return cameras_s;
}

