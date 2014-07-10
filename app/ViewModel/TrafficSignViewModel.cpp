#include "TrafficSignViewModel.hpp"
#include "OpenCommand.hpp"

TrafficSignViewModel::TrafficSignViewModel() {
    sp_OpenCommand = boost::static_pointer_cast<ICommand, OpenCommand>(
            boost::make_shared<OpenCommand>(this));
    sp_image_view = boost::make_shared<QImage>();
}

void TrafficSignViewModel::SetEvent(const boost::shared_ptr<INotification> &e) {
    event = e;
}

void TrafficSignViewModel::fireEvent(const std::string &property) {
    event->OnPropertyChanged(property);
}

boost::shared_ptr<QImage> TrafficSignViewModel::GetImagePtr() {
    return sp_image_view;
}

boost::shared_ptr<ICommand> TrafficSignViewModel::GetOpenCommand() {
    return sp_OpenCommand;
}

void TrafficSignViewModel::SetModel(boost::shared_ptr<TrafficSignModel> &model) {
    sp_Model = model;
}

void TrafficSignViewModel::OpenVideo(const std::string& filename) {
    sp_Model->OpenVideo(filename);
    ///DEBUG
    //std::cout<<"ViewModel opened video!"<<std::endl;
    
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

