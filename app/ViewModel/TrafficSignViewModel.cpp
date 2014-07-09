#include "TrafficSignViewModel.hpp"
#include "OpenCommand.hpp"

TrafficSignViewModel::TrafficSignViewModel() {
    sp_OpenCommand = boost::static_pointer_cast<ICommand, OpenCommand>(
            boost::make_shared<OpenCommand>(this));
};

QImage *TrafficSignViewModel::GetImage() {
    cv::Mat image = *sp_Model->GetImage()->GetImage();
    cv::Mat rgb;
    if(image.channels()==3)
    {
        //cvt Mat BGR 2 QImage RGB
        cvtColor(image,rgb,CV_BGR2RGB);
        image_view =QImage((const unsigned char*)(rgb.data),
                            rgb.cols,rgb.rows,
                            rgb.cols*rgb.channels(),
                            QImage::Format_RGB888);
    }
    else
    {
        image_view =QImage((const unsigned char*)(image.data),
                            image.cols,image.rows,
                            image.cols*image.channels(),
                            QImage::Format_RGB888);
    }
    return &image_view;
};

boost::shared_ptr<ICommand> TrafficSignViewModel::GetOpenCommand() {
    return sp_OpenCommand;
};

void TrafficSignViewModel::SetModel(boost::shared_ptr<TrafficSignModel> &model) {
    sp_Model = model;
};

void TrafficSignViewModel::OpenVideo(const std::string& filename) {
    sp_Model->OpenVideo(filename);
};

