#ifndef Traffic_Sign_OpenCommand_h
#define Traffic_Sign_OpenCommand_h

#include <string>
#include <boost/shared_ptr.hpp>
#include "Common/ICommand.hpp"
#include "TrafficSignViewModel.hpp"

class OpenCommand: public ICommand {
private:
    TrafficSignViewModel *m_ViewModel;


public:
    OpenCommand(TrafficSignViewModel *m) {
        m_ViewModel = m;
    };

    ~OpenCommand() {};

    void Execute(const boost::shared_ptr<ICommandParam> &param) {
        m_ViewModel->OpenVideo(*((std::string*)param->GetParam(0)));
    };
};

#endif
