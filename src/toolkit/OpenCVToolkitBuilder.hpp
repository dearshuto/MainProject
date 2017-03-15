//
//  OpenCVToolkitBuilder.hpp
//  LightArtLikeRepresentation
//
//  Created by Shuto Shikama on 2017/03/15.
//
//

#ifndef OpenCVToolkitBuilder_hpp
#define OpenCVToolkitBuilder_hpp

#include "ToolkitBuilder.hpp"

namespace mmk {
    class OpenCVToolkitBuilder;
}

class mmk::OpenCVToolkitBuilder : public mmk::ToolkitBuilder
{
public:
    OpenCVToolkitBuilder() = default;
    ~OpenCVToolkitBuilder() = default;
    
    std::unique_ptr<mmk::VideoCapture> buildVideoCapture()const override;
    std::unique_ptr<mmk::ImageBuilder> buildImageBuilder()const override;
};

#endif /* OpenCVToolkitBuilder_hpp */
