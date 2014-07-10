#include "MainWindowSink.hpp"

void OnPropertyChanged(const std::string &property) {
    switch (property) {
        case "ImageData": videoLabel.setPixmap(QPixmap::fromImage(*sp_Image); break;
    }
}
