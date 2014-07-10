#ifndef Traffic_Sign_Notification
#define Traffic_Sign_Notification
#include <string>

class INotification {
private:

public:
    INotification(){};
    virtual ~INotification(){};
    virtual void OnPropertyChanged(const std::string &property)=0;
};

#endif
