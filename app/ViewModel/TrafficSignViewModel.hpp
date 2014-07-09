#ifndef Traffic_Sign_ViewModel_h
#define Traffic_Sign_ViewModel_h

#include <memory>
#include <string>
#include <opencv2/opencv.hpp>
#include "Common/ICommand.hpp"
#include "Common/Notification.hpp"
#include "Model/TrafficSignModel.hpp"
#include "ViewModel/OpenCommand.hpp"

using namespace std;

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

    cv::Mat *GetImage() {
        return sp_ImageData->GetImage();
    };

    shared_ptr<ICommand> GetOpenCommand() {
        return sp_OpenCommand;
    };

    void SetModel(shared_ptr<TrafficSignModel> &model) {
        sp_Model = model;
    };

    void OpenVideo(const string& filename) {
        sp_Model->OpenVideo(filename);
    };
};
