#ifndef Traffic_Sign_VideoData
#define Traffic_Sign_VideoData

#include <iostream>
#include "opencv2/opencv.hpp"

class VideoData {
private:
    cv::VideoCapture cap;
    cv::Mat frame;
    int currentFrame, totFrame;
public:
    VideoData();
    virtual ~VideoData();
    void OpenVideo(const std::string &);
    cv::Mat *GetFrame();
    cv::Mat *GetFrame(int);
};

#endif
