#ifndef Traffic_Sign_OpenCommandParam_h
#define Traffic_Sign_OpenCommandParam_h


class OpenCommandParam: public ICommandParam {
private:
    string video_filename;
    string mark_filename;//标记好的信息

public:
    int GetParamNum() { return 1; }
    void SetParam(const string &s) { video_filename=s; }
    void* GetParam(int index) { 
        switch(index)
        {
        case 0: return &video_filename; break;
        case 1: return &mark_filename; break;
        }
    };
};

#endif
