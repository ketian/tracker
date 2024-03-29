#ifndef traffic_sign_ICommand_h
#define traffic_sign_ICommand_h

#include <boost/shared_ptr.hpp>

class ICommandParam {

public:
    ICommandParam() {}
    virtual ~ICommandParam() {}
    virtual int GetParamNum()=0;
    virtual void* GetParam(int index)=0;
};

class ICommand {

public:
    ICommand() {}
    virtual ~ICommand() {}
    virtual void Execute(const boost::shared_ptr<ICommandParam> &param)=0;
};

#endif
