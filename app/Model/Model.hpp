#ifndef traffic_sign_Model_h
#define traffic_sign_Model_h

#include <string>

class TrafficSignModel {
private:
    shared_ptr<ImageData> image;
    shared_ptr<VideoData> video;
    //result;
public:
    TrafficSignModel();
    ~TrafficSignModel();

    void LoadVideo(const string &);
    void NextFrame();
    shared_ptr<ImageData> GetImage();
    void Compute();
    void Draw();
};

#endif
