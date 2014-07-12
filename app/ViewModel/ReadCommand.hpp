#ifndef Traffic_Sign_ReadCommand_h
#define Traffic_Sign_ReadCommand_h

#include <string>
#include <boost/shared_ptr.hpp>
#include "Common/ICommand.hpp"
#include "TrafficSignViewModel.hpp"

class ReadCommand: public ICommand {
private:
    TrafficSignViewModel *m_ViewModel;


public:
    ReadCommand(TrafficSignViewModel *m) {
        m_ViewModel = m;
    };

    ~ReadCommand() {};

    void Execute(const boost::shared_ptr<ICommandParam> &param) {
        //m_ViewModel->flag=true;
        m_ViewModel->ReadMark(*((std::string*)param->GetParam(0)));
    };
};

#endif
