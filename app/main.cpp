#include "traffic_signmainwindow.h"
#include <QApplication>
#include "Model/TrafficSignModel.hpp"
#include "ViewModel/TrafficSignViewModel.hpp"
#include "View/MainWindowSink.hpp"
#include <boost/shared_ptr.hpp>
#include <boost/make_shared.hpp>

using namespace std;

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    Traffic_signMainWindow w;
    MainWindowSink mainWindowEvent(&w);
    
    boost::shared_ptr<TrafficSignModel> sp_TrafficSignModel = 
        boost::make_shared<TrafficSignModel>();
    boost::shared_ptr<TrafficSignViewModel> sp_TrafficSignViewModel = 
        boost::make_shared<TrafficSignViewModel>();
    boost::shared_ptr<MainWindowSink> sp_MainWindowEvent(
        boost::make_shared<MainWindowSink>(mainWindowEvent));

    sp_TrafficSignViewModel->SetModel(sp_TrafficSignModel);
    sp_TrafficSignViewModel->SetEvent(boost::static_pointer_cast<INotification>(
        sp_MainWindowEvent));
    w.SetImage(sp_TrafficSignViewModel->GetImagePtr());

    w.SetOpenCommand(sp_TrafficSignViewModel->GetOpenCommand());
    w.show();

    return a.exec();
}
