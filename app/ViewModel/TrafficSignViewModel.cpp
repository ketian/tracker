#include "TrafficSignViewModel.hpp"
#include "OpenCommand.hpp"
#include "RunCommand.hpp"
#include "ReadCommand.hpp"
#include "Utility/MarkData.hpp"

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
    sp_mark_view = boost::make_shared<QImage>();
}

void TrafficSignViewModel::SetEvent(const boost::shared_ptr<INotification> &e) {
    event = e;
}

void TrafficSignViewModel::fireEvent(const string &property) {
    event->OnPropertyChanged(property);
}

boost::shared_ptr<QImage> TrafficSignViewModel::GetImagePtr(const int &x) {
    if (x==0) return sp_image_view;
    else return sp_mark_view;
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

void TrafficSignViewModel::TrackSign(const string &mode) {
    bool flag;
    flag = sp_Model->TrackSign(mode);
    RefreshImage();
    if (flag) fireEvent("TrackDone");
}

void TrafficSignViewModel::RefreshImage() {
    cv::Mat image = *sp_Model->GetImage(0)->GetImage();
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
    
    image = *sp_Model->GetImage(1)->GetImage();
    if(image.channels()==3)
    {
        //cvt Mat BGR 2 QImage RGB
        cvtColor(image,rgb,CV_BGR2RGB);
        *sp_mark_view = QImage((const unsigned char*)(rgb.data),
                                rgb.cols,rgb.rows,
                                rgb.cols*rgb.channels(),
                                QImage::Format_RGB888);
    }
    else
    {
        *sp_mark_view = QImage((const unsigned char*)(image.data),
                                image.cols,image.rows,
                                image.cols*image.channels(),
                                QImage::Format_RGB888);
    }
    
    fireEvent("ImageData");
}
