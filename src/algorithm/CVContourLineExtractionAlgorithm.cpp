//
//  CVContourLineExtractionAlgorithm.cpp
//  LightArtLikeRepresentation
//
//  Created by Shuto Shikama on 2017/03/15.
//
//

#include <opencv2/opencv.hpp>
#include <opencv2/highgui.hpp>
#include <vector>
#include "CVContourLineExtractionAlgorithm.hpp"

void mmk::CVContourLineExtractionAlgorithm::execute(const mmk::Image& input, mmk::Image*const output)
{
    const mmk::OpenCVImage& cvImage = static_cast<const mmk::OpenCVImage&>(input);
    mmk::OpenCVImage*const cvOutputImage = static_cast<mmk::OpenCVImage*const>(output);
    cv::Mat grayImage, cannyImage;
    cvtColor(cvImage, grayImage, cv::COLOR_RGB2GRAY);
    cv::Canny(grayImage, cannyImage, 90, 110);
    cvtColor(cannyImage, *cvOutputImage, cv::COLOR_GRAY2RGB);
}
