#ifndef Traffic_Sign_ImageData
#define Traffic_Sign_ImageData

#include <opencv2/opencv.hpp>

using namespace cv;

class ImageData {
private:
    cv::Mat image;
public:
	cv::Mat * GetImage();
	void SetImage(const cv::Mat & image);
};

#endif


