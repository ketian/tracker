#ifndef traffic_sign_Model_h
#define traffic_sign_Model_h

#include <boost/shared_ptr.hpp>
#include <string>
#include <list>
#include "Utility/ImageData.hpp"
#include "Utility/VideoData.hpp"
#include "Utility/MarkData.hpp"

typedef std::list<MarkData> MarksData;

class TrafficSignModel {
private:
    boost::shared_ptr<ImageData> sp_image;
    boost::shared_ptr<VideoData> sp_video;
    boost::shared_ptr<MarksData> sp_result;
    
public:
    TrafficSignModel();
    ~TrafficSignModel();

    void OpenVideo(const std::string &filename);
    void NextFrame();
    boost::shared_ptr<ImageData> GetImage();
    void Compute();
    void Draw();
};

#endif
