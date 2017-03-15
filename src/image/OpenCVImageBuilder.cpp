//
//  OpenCVImageBuilder.cpp
//  LightArtLikeRepresentation
//
//  Created by Shuto Shikama on 2017/03/15.
//
//

#include "OpenCVImage.hpp"
#include "OpenCVImageBuilder.hpp"

std::unique_ptr<mmk::Image> mmk::OpenCVImageBuilder::createInstance(const std::uint32_t width, const std::uint32_t height)const
{
    return std::make_unique<mmk::OpenCVImage>(width, height);
}
