#ifndef Traffic_Sign_MainWindowSink_h
#define Traffic_Sign_MainWindowSink_h

#include <string>
#include "Common/INotification.hpp"
#include "View/traffic_signmainwindow.h"
class MainWindowSink: public INotification {
private:
    Traffic_signMainWindow *p_Window;

public:
    MainWindowSink(Traffic_signMainWindow *p):p_Window(p)
    {
       
    }
    void OnPropertyChanged(const std::string &property);
};

#endif
