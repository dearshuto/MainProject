//
//  OpenCVImage.cpp
//  LightArtLikeRepresentation
//
//  Created by Shuto Shikama on 2017/03/15.
//
//

#include "OpenCVImage.hpp"

mmk::OpenCVImage::OpenCVImage(const std::uint32_t width, const std::uint32_t height)
: cv::Mat(cv::Mat::zeros(cv::Size(width, height), CV_8UC1))
{
    
}

mmk::OpenCVImage::OpenCVImage(const cv::Mat& mat)
: cv::Mat(mat)
{
    
}

void mmk::OpenCVImage::clear()
{
    cv::Mat::operator=(cv::Scalar(0));
}

void mmk::OpenCVImage::show()const
{
    cv::imshow("", *this);
    cv::waitKey(20);
}

std::uint32_t mmk::OpenCVImage::getWidth()const
{
    return static_cast<std::uint32_t>(this->cols);
}

std::uint32_t mmk::OpenCVImage::getHeight()const
{
    return static_cast<std::uint32_t>(this->rows);
}
