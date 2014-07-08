#include "TrafficSignModel.h"

TrafficSignModel::TrafficSignModel() {}

TrafficSignModel::~TrafficSignModel() {}

TrafficSignModel::OpenVideo(const string &filename) {
    sp_video->OpenVideo(filename);
    sp_image->SetImage(*(sp_video->GetFrame()));
}

TrafficSignModel::Compute() {}

TrafficSignModel::Draw() {}
