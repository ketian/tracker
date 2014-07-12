#ifndef Traffic_Sign_RunCommand_h
#define Traffic_Sign_RunCommand_h

#include <string>
#include <boost/shared_ptr.hpp>
#include "Common/ICommand.hpp"
#include "TrafficSignViewModel.hpp"

class RunCommand: public ICommand {
private:
    TrafficSignViewModel *m_ViewModel;


public:
    RunCommand(TrafficSignViewModel *m) {
        m_ViewModel = m;
    };

    ~RunCommand() {};

    void Execute(const boost::shared_ptr<ICommandParam> &param) {
        //m_ViewModel->flag=true;
        m_ViewModel->TrackSign(*((std::string*)param->GetParam(0)));
    };
};

#endif
