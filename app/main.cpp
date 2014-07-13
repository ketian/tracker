#include "traffic_signmainwindow.h"
#include <QApplication>
#include "Model/TrafficSignModel.hpp"
#include "ViewModel/TrafficSignViewModel.hpp"
#include <boost/shared_ptr.hpp>
#include <boost/make_shared.hpp>

using namespace std;

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    Traffic_signMainWindow w;
    
    boost::shared_ptr<TrafficSignModel> sp_TrafficSignModel = 
        boost::make_shared<TrafficSignModel>();
    boost::shared_ptr<TrafficSignViewModel> sp_TrafficSignViewModel = 
        boost::make_shared<TrafficSignViewModel>();

    sp_TrafficSignViewModel->SetModel(sp_TrafficSignModel);
    sp_TrafficSignViewModel->SetEvent(w.GetEvent());
    w.SetImage(sp_TrafficSignViewModel->GetImagePtr(0));
    w.SetMark(sp_TrafficSignViewModel->GetImagePtr(1));

    w.SetOpenCommand(sp_TrafficSignViewModel->GetOpenCommand());
    w.SetReadCommand(sp_TrafficSignViewModel->GetReadCommand());
    w.SetRunCommand(sp_TrafficSignViewModel->GetRunCommand());
    w.show();

    return a.exec();
}
