#include "MainWindowSink.hpp"

void MainWindowSink::OnPropertyChanged(const std::string &property) {
    if (property=="ImageData")
    {
        ///DEBUG
        //std::cout << "OnPropertyChanged Called" << std::endl;
    	p_Window->GetLabel("video")->setPixmap(QPixmap::fromImage(*(p_Window->GetImage(0))));
    	p_Window->GetLabel("video")->setScaledContents(true);
        p_Window->GetLabel("video")->update();
        
    	p_Window->GetLabel("mark")->setPixmap(QPixmap::fromImage(*(p_Window->GetImage(1))));
    	p_Window->GetLabel("mark")->setScaledContents(true);
        p_Window->GetLabel("mark")->update();
    }
    if (property=="TrackDone")
    {
        p_Window->running_timer->stop();
    }
}
