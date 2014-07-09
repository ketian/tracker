#ifndef Traffic_Sign_OpenCommandParam_h
#define Traffic_Sign_OpenCommandParam_h

#include <string>
#include "ICommand.hpp"

class OpenCommandParam: public ICommandParam {
private:
    std::string video_filename;
    std::string mark_filename;//标记好的信息

public:
    OpenCommandParam() {};
    ~OpenCommandParam() {};
    int GetParamNum() { return 1; };
    void SetParam(const std::string &s) { video_filename=s; };
    void* GetParam(int index) { 
        switch(index)
        {
            case 0: return &video_filename; break;
            case 1: return &mark_filename; break;
        }
    };
};

#endif
