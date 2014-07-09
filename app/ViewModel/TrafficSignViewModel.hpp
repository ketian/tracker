#ifndef Traffic_Sign_ViewModel_h
#define Traffic_Sign_ViewModel_h

#include <boost/shared_ptr.hpp>
#include <boost/make_shared.hpp>
#include <string>
#include <opencv2/opencv.hpp>
#include "Common/ICommand.hpp"
#include "Common/Notification.hpp"
#include "Model/TrafficSignModel.hpp"
#include <QMainWindow>

class TrafficSignViewModel {
private:
    boost::shared_ptr<ICommand> sp_OpenCommand;
    boost::shared_ptr<TrafficSignModel> sp_Model;
    boost::shared_ptr<INotification> events;
    QImage image_view;
    
public:
    TrafficSignViewModel();
    QImage *GetImage();
    boost::shared_ptr<ICommand> GetOpenCommand();
    void SetModel(boost::shared_ptr<TrafficSignModel> &model);
    void OpenVideo(const std::string& filename);
};

#endif
