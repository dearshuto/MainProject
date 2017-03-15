//
//  OpenCVToolkitBuilder.cpp
//  LightArtLikeRepresentation
//
//  Created by Shuto Shikama on 2017/03/15.
//
//

#include "algorithm/CVContourLineExtractionAlgorithm.hpp"
#include "image/OpenCVImageBuilder.hpp"
#include "ui/OpenCVVideoCapture.hpp"
#include "OpenCVToolkitBuilder.hpp"

std::unique_ptr<mmk::ContourLineExtractionAlgorithm> mmk::OpenCVToolkitBuilder::buildContourExtractionAlgorithm()const
{
    return std::make_unique<mmk::CVContourLineExtractionAlgorithm>();
}

std::unique_ptr<mmk::VideoCapture> mmk::OpenCVToolkitBuilder::buildVideoCapture()const
{
    return std::make_unique<mmk::OpenCVVideoCapture>();
}

std::unique_ptr<mmk::ImageBuilder> mmk::OpenCVToolkitBuilder::buildImageBuilder()const
{
    return std::make_unique<mmk::OpenCVImageBuilder>(640, 480);
}
