#include "MainWindowSink.hpp"

void MainWindowSink::OnPropertyChanged(const std::string &property) {
    if (property=="ImageData")
    {
        ///DEBUG
        //std::cout << "OnPropertyChanged Called" << std::endl;
    	p_Window->GetLabel("video")->setPixmap(QPixmap::fromImage(*(p_Window->GetImage())));
    	p_Window->GetLabel("video")->setScaledContents(true);
        p_Window->GetLabel("video")->update();
    }
    if (property=="TrackDone")
    {
        p_Window->running_timer->stop();
    }
}
