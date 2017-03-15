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

void mmk::CVContourLineExtractionAlgorithm::extract(const mmk::Image& input, mmk::Image*const output)const
{
    std::vector<std::vector<cv::Point> > contours;
    const mmk::OpenCVImage& cvImage = static_cast<const mmk::OpenCVImage&>(input);
    mmk::OpenCVImage*const cvOutputImage = static_cast<mmk::OpenCVImage*const>(output);
    cv::Mat grayImage;
    cvtColor(cvImage, grayImage, CV_BGR2GRAY);

    cv::findContours(grayImage, contours, cv::RetrievalModes::RETR_LIST, cv::ContourApproximationModes::CHAIN_APPROX_NONE);
    
    for (const auto& contour: contours)
    {
        cv::polylines(*cvOutputImage, contour, true, cv::Scalar(255, 255, 255), 2);
    }
}
