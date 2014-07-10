#ifndef Traffic_Sign_MainWindowSink_h
#define Traffic_Sign_MainWindowSink_h

#include <string>
#include "Common/INotification.hpp"

class MainWindowSink: public INotification {
private:
    Traffic_SignMainWindow *p_MainWindow;

public:
    MainWindowSink(Traffic_SignMainWindow *p) {
        p_MainWindow = p;
    }
    void OnPropertyChanged(const std::string &property);
};
