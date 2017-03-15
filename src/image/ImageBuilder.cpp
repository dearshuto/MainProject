//
//  ImageBuilder.cpp
//  LightArtLikeRepresentation
//
//  Created by Shuto Shikama on 2017/03/15.
//
//

#include "ImageBuilder.hpp"

mmk::ImageBuilder::ImageBuilder(const std::uint32_t width, const std::uint32_t height)
: m_width(width)
, m_height(height)
{
    
}

std::uint32_t mmk::ImageBuilder::getWidth()const
{
    return m_width;
}

std::uint32_t mmk::ImageBuilder::getHeight()const
{
    return m_height;
}
