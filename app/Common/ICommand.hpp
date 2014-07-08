#ifndef traffic_sign_ICommand_h
#define traffic_sign_Icommand_h

#include <memory>
using namespace std;

class ICommandParam {

public:
    ICommandParam();
    virtual ~ICommandParam();
    virtual int GetParamNum()=0;
    virtual void* GetParam(int index)=0;
};

class ICommand {

public:
    ICommand();
    virtual ~ICommand();
    virtual void Execute(shared_ptr<ICommandParam>& param)=0;
};

#endif
