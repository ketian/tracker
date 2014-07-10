#ifndef Traffic_Sign_Notification
#define Traffic_Sign_Notification

class INotification {
private:

public:
    INotification(){};
    virtual ~INotification(){};
    virtual void OnPropertyChanged(const char* property)=0;
};

#endif
