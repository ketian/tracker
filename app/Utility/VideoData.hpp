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


VideoData()
{
    currentFrame = 1;
    totFrame = 0;
}

~VideoData()
{

}

void OpenVideo(const string & FileName)
{
    cout << "File name is : " << FileName << endl;
    cap.open(FileName);
    if(!cap.isOpened()) { // check if we succeeded
        cout << "Fail to open!" << endl;
        exit(0);
    }
    totFrame = cap.get(CV_CAP_PROP_FRAME_COUNT);
}

Mat * GetFrame()
{
    if(currentFrame > totFrame)
    {
        exit(0);
    }

    cap.set(CV_CAP_PROP_POS_FRAMES, currentFrame++);

    if(!cap.read(frame)) // read fail
    {
        cout << "Fail to read the video!" << endl;
        exit(0);
    }

    return & frame;
}

Mat * GetFrame(int givenFrame)
{
    if(givenFrame > totFrame)
    {
        exit(0);
    }

    cap.set( CV_CAP_PROP_POS_FRAMES, givenFrame);

    if(!cap.read(frame)) { // read fail
        cout << "Fail to read the video!" << endl;
        exit(0);
    }

    return &frame;
}
