#ifndef traffic_sign_Model_h
#define traffic_sign_Model_h

#include <boost/shared_ptr.hpp>
#include <string>
#include <list>
#include "Utility/ImageData.hpp"
#include "Utility/VideoData.hpp"
#include "Utility/MarkData.hpp"
#include "Algorithm/Tracker.h"
#include "Algorithm/Config.h"

#define SPEED 1

typedef std::list<MarkData> MarksData;

class TrafficSignModel {
private:
    boost::shared_ptr<ImageData> sp_image, sp_mark;
    boost::shared_ptr<VideoData> sp_video;
    boost::shared_ptr<MarkData> sp_sMark, sp_tMark;
    boost::shared_ptr<Config> sp_config;
    std::string videoName;
    
public:
    TrafficSignModel();
    ~TrafficSignModel();

    void OpenVideo(const std::string &filename);
    void SetImage(const cv::Mat &image);
    void SetMark(const cv::Mat &image);
    void ReadMark(const std::string &filename);
    bool TrackSign(const std::string &mode);
    boost::shared_ptr<ImageData> GetImage(int);
    boost::shared_ptr<Config> GetConfig();
    boost::shared_ptr<MarkData> GetMark(int);
    cv::Mat *GetFrame();
    cv::Mat *GetFrame(int frameInd);
    const std::string &GetVideoName();
    
};

#endif
