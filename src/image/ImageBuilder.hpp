//
//  ImageBuilder.hpp
//  LightArtLikeRepresentation
//
//  Created by Shuto Shikama on 2017/03/15.
//
//

#ifndef ImageBuilder_hpp
#define ImageBuilder_hpp

#include <cstdint>
#include <memory>

namespace mmk {
    class Image;
    class ImageBuilder;
}

/// mmk::Image のインスタンスを生成するクラス
class mmk::ImageBuilder
{
protected:
    ImageBuilder() = default;
public:
    virtual~ImageBuilder() = default;
    
    virtual std::unique_ptr<mmk::Image> createInstance(const std::uint32_t width, const std::uint32_t height)const = 0;
};

#endif /* ImageBuilder_hpp */
