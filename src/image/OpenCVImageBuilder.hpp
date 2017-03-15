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
    typedef mmk::ImageBuilder Super;
public:
    OpenCVImageBuilder() = delete;
    OpenCVImageBuilder(const std::uint32_t width = 640, const std::uint32_t height = 480);
    ~OpenCVImageBuilder() = default;
    
    std::unique_ptr<mmk::Image> createInstance()const override;
};

#endif /* OpenCVImageBuilder_hpp */
