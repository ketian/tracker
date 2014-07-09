#include "traffic_signmainwindow.h"
#include <QApplication>
#include "Model/TrafficSignModel.hpp"
#include "ViewModel/TrafficSignViewModel.hpp"
#include <memory>

using namespace std;

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    Traffic_signMainWindow w;

    shared_ptr<TrafficSignModel> sp_TrafficSignModel = 
        make_shared<TrafficSignModel>();
    shared_ptr<TrafficSignViewModel> sp_TrafficSignViewModel = 
        make_shared<TrafficSignViewModel>();

    sp_TrafficSignModel->SetModel(sp_TrafficSignModel);

    w.SetOpenCommand(sp_TrafficSignViewModel->GetOpenCommand);
    w.show();

    return a.exec();
}
