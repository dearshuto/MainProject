//
//  OpenCVImageBuilder.cpp
//  LightArtLikeRepresentation
//
//  Created by Shuto Shikama on 2017/03/15.
//
//

#include "OpenCVImage.hpp"
#include "OpenCVImageBuilder.hpp"

mmk::OpenCVImageBuilder::OpenCVImageBuilder(const std::uint32_t width, const std::uint32_t height)
: Super(width, height)
{
    
}

std::unique_ptr<mmk::Image> mmk::OpenCVImageBuilder::createInstance()const
{
    return std::make_unique<mmk::OpenCVImage>(getWidth(), getHeight());
}
