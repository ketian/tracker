#ifndef Traffic_Sign_OpenCommand_h
#define Traffic_Sign_OpenCommand_h

#include <string>
#include <memory>
#include "Common/ICommand.hpp"

using namespace std;

class OpenCommand: public ICommand {
private:
    TrafficSignViewModel *m_ViewModel;

public:
    OpenCommand(TrafficSignViewModel &m) {
        m_ViewModel = &m;
    };

    ~OpenCommand() {};

    void Execute(shared_ptr <ICommandParam>& param) {
        m_ViewModel.OpenVideo(*((string*)param->GetParam(0)));
    };
};

