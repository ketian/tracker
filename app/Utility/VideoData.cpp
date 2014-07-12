#include <iostream>
#include "opencv2/opencv.hpp"
#include "VideoData.hpp"

using namespace std;
using namespace cv;

VideoData::VideoData()
{
    currentFrame = 1;
    totFrame = 0;
}

VideoData::~VideoData()
{

}

void VideoData::OpenVideo(const string &FileName)
{
    cout << "File name is : " << FileName << endl;
    cap.open(FileName);
    if(!cap.isOpened()) { // check if we succeeded
        cout << "Fail to open!" << endl;
        exit(0);
    }
    totFrame = cap.get(CV_CAP_PROP_FRAME_COUNT);
}

Mat * VideoData::GetFrame()
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
///DEBUG
//cout<<"Success to read"<<endl;
//namedWindow("Display Image", CV_WINDOW_AUTOSIZE );
//imshow("Display Image", frame);
//waitKey(0);
//int x;
//cin>>x;

    return & frame;
}

Mat * VideoData::GetFrame(int givenFrame)
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
