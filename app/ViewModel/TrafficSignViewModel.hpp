#ifndef Traffic_Sign_ViewModel_h
#define Traffic_Sign_ViewModel_h

#include <boost/shared_ptr.hpp>
#include <boost/make_shared.hpp>
#include <string>
#include <vector>
#include <opencv2/opencv.hpp>
#include "Common/ICommand.hpp"
#include "Common/INotification.hpp"
#include "Model/TrafficSignModel.hpp"
#include <QMainWindow>

class TrafficSignViewModel {
private:
    boost::shared_ptr<ICommand> sp_OpenCommand;
    boost::shared_ptr<TrafficSignModel> sp_Model;
    //std::vector< boost::shared_ptr<INotification> > events;
    boost::shared_ptr<INotification> event;
    boost::shared_ptr<QImage> sp_image_view;
    
    void fireEvent(const std::string &property);

public:
    TrafficSignViewModel();
    boost::shared_ptr<ICommand> GetOpenCommand();
    boost::shared_ptr<QImage> GetImagePtr();
    void SetEvent(const boost::shared_ptr<INotification> &e);
    void SetModel(boost::shared_ptr<TrafficSignModel> &model);
    void OpenVideo(const std::string& filename);
};

#endif
