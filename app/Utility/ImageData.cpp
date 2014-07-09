#include "ImageData.hpp"
#include <opencv2/opencv.hpp>
#include <iostream>


cv::Mat * ImageData::GetImage()
{
	return &(this->image);
}

void ImageData::SetImage(const cv::Mat &input_image)
{
	image=input_image.clone();
}

