//
//  ToolkitBuilder.hpp
//  LightArtLikeRepresentation
//
//  Created by Shuto Shikama on 2017/03/15.
//
//

#ifndef ToolkitBuilder_hpp
#define ToolkitBuilder_hpp

#include <memory>

namespace mmk {
    class ContourLineExtractionAlgorithm;
    class ImageBuilder;
    class VideoCapture;
    class ToolkitBuilder;
}

class mmk::ToolkitBuilder
{
protected:
    ToolkitBuilder() = default;
public:
    virtual~ToolkitBuilder() = default;
    
    virtual std::unique_ptr<mmk::ContourLineExtractionAlgorithm> buildContourExtractionAlgorithm()const = 0;
    virtual std::unique_ptr<mmk::VideoCapture> buildVideoCapture()const = 0;
    virtual std::unique_ptr<mmk::ImageBuilder> buildImageBuilder()const = 0;
};

#endif /* ToolkitBuilder_hpp */
