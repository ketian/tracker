#ifndef traffic_sign_Model_h
#define traffic_sign_Model_h

#include <memory>
#include <string>

using namespace std;

typedef list<MarkData> MarksData;

class TrafficSignModel {
private:
    shared_ptr<ImageData> sp_image;
    shared_ptr<VideoData> sp_video;
    shared_ptr<MarksData> sp_result;
    
public:
    TrafficSignModel();
    ~TrafficSignModel();

    void OpenVideo(const string &filename);
    void NextFrame();
    ImageData* GetImage();
    void Compute();
    void Draw();
};

#endif
