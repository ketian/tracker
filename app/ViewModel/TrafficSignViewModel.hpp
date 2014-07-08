#ifndef Traffic_Sign_ViewModel_h
#define Traffic_Sign_ViewModel_h

class TrafficSignViewModel {
private:
    shared_ptr<ICommand> sp_OpenCommand;
    shared_ptr<TrafficSignModel> sp_Model;
    shared_ptr<INotification> events;

public:
    TrafficSignViewModel() {
        sp_OpenCommand = static_pointer_cast<ICommand, OpenCommand>(
                make_shared<OpenCommand>(*this));
    };

    shared_ptr<cv::Mat> GetImage() {
        return sp_ImageData->GetImage();
    };

    void OpenVideo(const string& filename) {
        sp_Model->OpenVideo(filename);
    }
};
