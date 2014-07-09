#ifndef Traffic_Sign_VideoData
#define Traffic_Sign_VideoData

#include <iostream>
#include "opencv2/opencv.hpp"

using namespace std;
using namespace cv;

class VideoData {
private:
    VideoCapture cap;
    Mat frame;
    int currentFrame, totFrame;
public:
    VideoData();
    virtual ~VideoData();
    void OpenVideo(const string &);
    Mat * GetFrame();
    Mat * GetFrame(int);
};

#endif
