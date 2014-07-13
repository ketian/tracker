#include "TrafficSignViewModel.hpp"
#include "OpenCommand.hpp"
#include "RunCommand.hpp"
#include "ReadCommand.hpp"
#include "Utility/MarkData.hpp"

#include "Algorithm/Tracker.h"
#include "Algorithm/Config.h"
#include <fstream>

#define SPEED 5

using namespace std;
using namespace cv;

TrafficSignViewModel::TrafficSignViewModel() {
    sp_OpenCommand = boost::static_pointer_cast<ICommand, OpenCommand>(
            boost::make_shared<OpenCommand>(this));
    sp_RunCommand = boost::static_pointer_cast<ICommand, RunCommand>(
            boost::make_shared<RunCommand>(this));
    sp_ReadCommand = boost::static_pointer_cast<ICommand, ReadCommand>(
            boost::make_shared<ReadCommand>(this));
    sp_image_view = boost::make_shared<QImage>();
}

void TrafficSignViewModel::SetEvent(const boost::shared_ptr<INotification> &e) {
    event = e;
}

void TrafficSignViewModel::fireEvent(const string &property) {
    event->OnPropertyChanged(property);
}

boost::shared_ptr<QImage> TrafficSignViewModel::GetImagePtr() {
    return sp_image_view;
}

boost::shared_ptr<ICommand> TrafficSignViewModel::GetOpenCommand() {
    return sp_OpenCommand;
}

boost::shared_ptr<ICommand> TrafficSignViewModel::GetReadCommand() {
    return sp_ReadCommand;
}

boost::shared_ptr<ICommand> TrafficSignViewModel::GetRunCommand() {
    return sp_RunCommand;
}

void TrafficSignViewModel::SetModel(boost::shared_ptr<TrafficSignModel> &model) {
    sp_Model = model;
}

void TrafficSignViewModel::OpenVideo(const string &filename) {
    sp_Model->OpenVideo(filename);
    ///DEBUG
    //cout<<"ViewModel opened video!"<<endl;
    RefreshImage();
    
}

void TrafficSignViewModel::ReadMark(const string &filename) {
    sp_Model->ReadMark(filename);
}

void rectangle(Mat& rMat, const FloatRect& rRect, const Scalar& rColour)
{
	IntRect r(rRect);
	rectangle(rMat, Point(r.XMin(), r.YMin()), Point(r.XMax(), r.YMax()), rColour, 3);
}

void TrafficSignViewModel::TrackSign(const string &mode) {

    //cout << sMark.frame << endl;
    
    static Config conf(*sp_Model->GetConfig());
    static Tracker tracker(conf);
    static FloatRect initBB;
    static int frameInd;
    static MarkData sMark, tMark;
    if (mode=="init")
    {
        sMark = *sp_Model->GetMark(0);
        tMark = *sp_Model->GetMark(1);
        frameInd = sMark.frame;
               
        initBB = IntRect(sMark.lx, sMark.ly, sMark.rx-sMark.lx, sMark.ry-sMark.ly);
    }
    Mat result(conf.frameHeight, conf.frameWidth, CV_8UC3);
    Mat frame;
    Mat frameOrig(*sp_Model->GetFrame(frameInd));
    if (frameOrig.empty())
    {
        cout << "error: could not read frame" << endl;
        exit(-1);
    }
    resize(frameOrig, frame, Size(conf.frameWidth, conf.frameHeight));
    frame.copyTo(result);
    if (frameInd == sMark.frame)
    {
        tracker.Initialise(frame, initBB);
    }
    if (tracker.IsInitialised())
    {
        tracker.Track(frame);
        //TODO
        if (true)   //(outFile)
        {
            const IntRect& bb = tracker.GetBB();
            Mat image(result, cv::Rect(bb.XMin(), bb.YMin(), bb.Width(), bb.Height()));
            char outImage[128];
            sprintf(outImage, "image/%d.jpg", frameInd/SPEED);
            //cout << "Write to: " << outImage << endl;
            imwrite(outImage, image);
        }
        rectangle(result, tracker.GetBB(), CV_RGB(0, 255, 0));
    }
    sp_Model->SetImage(result);
    RefreshImage();
    if (frameInd >= tMark.frame) fireEvent("TrackDone");
    frameInd += SPEED;
}

void TrafficSignViewModel::RefreshImage() {
    cv::Mat image = *sp_Model->GetImage()->GetImage();
    cv::Mat rgb;
    if(image.channels()==3)
    {
        //cvt Mat BGR 2 QImage RGB
        cvtColor(image,rgb,CV_BGR2RGB);
        *sp_image_view = QImage((const unsigned char*)(rgb.data),
                                rgb.cols,rgb.rows,
                                rgb.cols*rgb.channels(),
                                QImage::Format_RGB888);
    }
    else
    {
        *sp_image_view = QImage((const unsigned char*)(image.data),
                                image.cols,image.rows,
                                image.cols*image.channels(),
                                QImage::Format_RGB888);
    }
    
    fireEvent("ImageData");
}
