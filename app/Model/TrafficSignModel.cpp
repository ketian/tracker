#include "TrafficSignModel.hpp"

#include <string>
#include <boost/make_shared.hpp>
#include <fstream>

#include "Algorithm/Tracker.h"
#include "Algorithm/Config.h"

using namespace std;
using namespace cv;

TrafficSignModel::TrafficSignModel() {
    sp_image = boost::make_shared<ImageData>();
    sp_mark = boost::make_shared<ImageData>();
    sp_video = boost::make_shared<VideoData>();
    sp_sMark = boost::make_shared<MarkData>();
    sp_tMark = boost::make_shared<MarkData>();
    sp_config = boost::make_shared<Config>("config.txt");
    srand(sp_config->seed);
    //
}

TrafficSignModel::~TrafficSignModel() {}

void TrafficSignModel::OpenVideo(const string &filename) {
    sp_video->OpenVideo(filename);
    sp_image->SetImage(*(sp_video->GetFrame()));
    videoName = filename;
}

void TrafficSignModel::ReadMark(const string &filename) {
    ifstream fin(filename.c_str());
    if (!fin.is_open()) {
        cout << "File is not opened properly!" << endl;
        exit(-1);
    }
    fin >> sp_sMark->frame >> sp_sMark->lx >> sp_sMark->ly >> sp_sMark->rx >> sp_sMark->ry;
    fin >> sp_tMark->frame >> sp_tMark->lx >> sp_tMark->ly >> sp_tMark->rx >> sp_tMark->ry;
    fin.close();
}

boost::shared_ptr<ImageData> TrafficSignModel::GetImage(int x) {
    if (x==0) return sp_image;
    else return sp_mark;
}

boost::shared_ptr<Config> TrafficSignModel::GetConfig() {
    return sp_config;
}

boost::shared_ptr<MarkData> TrafficSignModel::GetMark(int x) {
    if (x==0) return sp_sMark;
    else return sp_tMark;
} 

void TrafficSignModel::SetImage(const cv::Mat &image) {
    sp_image->SetImage(image);
}   

void TrafficSignModel::SetMark(const cv::Mat &image) {
    sp_mark->SetImage(image);
}

cv::Mat *TrafficSignModel::GetFrame() {
    return sp_video->GetFrame();
}

cv::Mat *TrafficSignModel::GetFrame(int frameInd) {
    return sp_video->GetFrame(frameInd);
}

const string &TrafficSignModel::GetVideoName() {
    return videoName;
}


void rectangle(Mat& rMat, const FloatRect& rRect, const Scalar& rColour)
{
	IntRect r(rRect);
	rectangle(rMat, Point(r.XMin(), r.YMin()), Point(r.XMax(), r.YMax()), rColour, 2);
}

bool TrafficSignModel::TrackSign(const string &mode) {

    //cout << "TrackSign" << endl;
    
    static Config conf(*GetConfig());
    static Tracker tracker(conf);
    static FloatRect initBB;
    static int frameInd;
    static MarkData sMark, tMark;
    //static TickMeter timer;
    static Mat frameOrig;

    if (mode=="init")
    {
        sMark = *GetMark(0);
        tMark = *GetMark(1);
        frameInd = sMark.frame;
        float scalex, scaley;
        Mat frame(*GetFrame(0));
        scalex = 1.0*frame.rows/conf.frameHeight;
        scaley = 1.0*frame.cols/conf.frameWidth;
        //cout << scalex << ' ' << scaley << endl;
        initBB = IntRect(sMark.lx/scalex, sMark.ly/scaley, (sMark.rx-sMark.lx)/scalex, (sMark.ry-sMark.ly)/scaley);
        frameOrig=GetFrame(frameInd)->clone();
    }
    else frameOrig=GetFrame()->clone();

    Mat result(conf.frameHeight, conf.frameWidth, CV_8UC3);
    Mat frame;

    if (frameOrig.empty())
    {
        cout << "error: could not read frame" << endl;
        exit(-1);
    }
    resize(frameOrig, frame, Size(conf.frameWidth, conf.frameHeight));
    frame.copyTo(result);
    if (frameInd == sMark.frame)
    {
        tracker.Reset();
        tracker.Initialise(frame, initBB);
    }


    if (tracker.IsInitialised())
    {
        //timer.reset();
        //timer.start();

        tracker.Track(frame);

        //timer.stop();
        //cout << "Tracking: " << timer.getTimeMilli() << endl;

        if (true)   //(outFile)
        {
            const IntRect& bb = tracker.GetBB();
            Mat image(result, cv::Rect(bb.XMin(), bb.YMin(), bb.Width(), bb.Height()));
            char outImage[128];
            sprintf(outImage, "image/%d.jpg", frameInd/SPEED);
            //cout << "Write to: " << outImage << endl;
            imwrite(outImage, image);
            SetMark(image);
        }
        rectangle(result, tracker.GetBB(), CV_RGB(0, 255, 0));
    }
    //else SetMark(result);

    SetImage(result);
    if (frameInd >= tMark.frame) return true;
    frameInd += SPEED;
    
    return false;
}
