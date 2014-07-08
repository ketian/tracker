#ifndef Traffic_Sign_OpenCommand
#define Traffic_Sign_OpenCommand

class OpenCommand: public ICommand {
private:
    TrafficSignViewModel* m_ViewModel;
public:
    OpenCommand(TrafficSignViewModel & m);
    ~OpenCommand();
    void Execute(shared_ptr <ICommandParam>& param) {
        m_ViewModel.OpenVideo(*((string*)param->GetParam(0)));
    };
};

