#ifndef Traffic_Sign_OpenCommandParam
#define Traffic_Sign_OpenCommandParam

class OpenCommandParam: public ICommandParam {
private:
    string video_filename;
    string mark_filename;

public:
    int GetParamNum() { return 1; };
    void SetParam(const string &s) { filename=s; };
    void* GetParam(int index) { 
        if (index==0)
            return video_filename;
        if (index==1)
            return mark_filename;
    };
};

#endif
