#include "TrafficSignModel.hpp"

#include <string>
#include <boost/make_shared.hpp>

TrafficSignModel::TrafficSignModel() {
    sp_image = boost::make_shared<ImageData>();
    sp_video = boost::make_shared<VideoData>();
    //
}

TrafficSignModel::~TrafficSignModel() {}

void TrafficSignModel::OpenVideo(const std::string &filename) {
    sp_video->OpenVideo(filename);
    sp_image->SetImage(*(sp_video->GetFrame()));
}

boost::shared_ptr<ImageData> TrafficSignModel::GetImage() {
    return sp_image;
}    

void TrafficSignModel::Compute() {}

void TrafficSignModel::Draw() {}
