#ifndef Traffic_Sign_ImageData_h
#define Traffic_Sign_ImageData_h

#include <opencv2/opencv.hpp>

class ImageData {
private:
    cv::Mat image;
public:
	cv::Mat * GetImage();
	void SetImage(const cv::Mat & image);
};

#endif


