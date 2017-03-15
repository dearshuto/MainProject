//
//  OpenCVImageBuilder.hpp
//  LightArtLikeRepresentation
//
//  Created by Shuto Shikama on 2017/03/15.
//
//

#ifndef OpenCVImageBuilder_hpp
#define OpenCVImageBuilder_hpp

#include "ImageBuilder.hpp"

namespace mmk {
    class OpenCVImageBuilder;
}

class mmk::OpenCVImageBuilder : public mmk::ImageBuilder
{
public:
    OpenCVImageBuilder() = default;
    ~OpenCVImageBuilder() = default;
    
    std::unique_ptr<mmk::Image> createInstance(const std::uint32_t width, const std::uint32_t height)const override;
};

#endif /* OpenCVImageBuilder_hpp */
