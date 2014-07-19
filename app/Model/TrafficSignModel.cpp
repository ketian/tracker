#include "TrafficSignModel.hpp"

#include <string>
#include <boost/make_shared.hpp>
#include <fstream>

using namespace std;

TrafficSignModel::TrafficSignModel() {
    sp_image = boost::make_shared<ImageData>();
    sp_mark = boost::make_shared<ImageData>();
    sp_video = boost::make_shared<VideoData>();
    sp_sMark = boost::make_shared<MarkData>();
    sp_tMark = boost::make_shared<MarkData>();
    sp_config = boost::make_shared<Config>("config.txt");
    srand(sp_config->seed);
    //
}

TrafficSignModel::~TrafficSignModel() {}

void TrafficSignModel::OpenVideo(const string &filename) {
    sp_video->OpenVideo(filename);
    sp_image->SetImage(*(sp_video->GetFrame()));
    videoName = filename;
}

void TrafficSignModel::ReadMark(const string &filename) {
    ifstream fin(filename.c_str());
    if (!fin.is_open()) {
        cout << "File is not opened properly!" << endl;
        exit(-1);
    }
    fin >> sp_sMark->frame >> sp_sMark->lx >> sp_sMark->ly >> sp_sMark->rx >> sp_sMark->ry;
    fin >> sp_tMark->frame >> sp_tMark->lx >> sp_tMark->ly >> sp_tMark->rx >> sp_tMark->ry;
    fin.close();
}

boost::shared_ptr<ImageData> TrafficSignModel::GetImage(int x) {
    if (x==0) return sp_image;
    else return sp_mark;
}

boost::shared_ptr<Config> TrafficSignModel::GetConfig() {
    return sp_config;
}

boost::shared_ptr<MarkData> TrafficSignModel::GetMark(int x) {
    if (x==0) return sp_sMark;
    else return sp_tMark;
} 

void TrafficSignModel::SetImage(const cv::Mat &image) {
    sp_image->SetImage(image);
}   

void TrafficSignModel::SetMark(const cv::Mat &image) {
    sp_mark->SetImage(image);
}

cv::Mat *TrafficSignModel::GetFrame() {
    return sp_video->GetFrame();
}

cv::Mat *TrafficSignModel::GetFrame(int frameInd) {
    return sp_video->GetFrame(frameInd);
}

const string &TrafficSignModel::GetVideoName() {
    return videoName;
}
