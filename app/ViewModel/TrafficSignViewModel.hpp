#ifndef Traffic_Sign_ViewModel_h
#define Traffic_Sign_ViewModel_h

class TrafficSignViewModel {
private:
    shared_ptr<ICommand> sp_OpenCommand;
    shared_ptr<VideoData> sp_VideoData;
    shared_ptr<ImageData> sp_ImageData;
    shared_ptr<INotification> events;

public:
    TrafficSignViewModel() {
        sp_OpenCommand = static_pointer_cast<ICommand, OpenCommand>(
                make_shared<OpenCommand>(*(new OpenCommand(*this))));
    };

    shared_ptr<cv::Mat> GetImage() {
        return sp_ImageData->GetImage();
    };

};
