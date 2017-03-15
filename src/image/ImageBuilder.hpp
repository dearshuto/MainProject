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
public:
    ImageBuilder() = delete;
    ImageBuilder(const std::uint32_t width = 640, const std::uint32_t height = 480);
    virtual~ImageBuilder() = default;
    
    virtual std::unique_ptr<mmk::Image> createInstance()const = 0;
    
    std::uint32_t getWidth()const;
    std::uint32_t getHeight()const;

private:
    std::uint32_t m_width;
    std::uint32_t m_height;
};

#endif /* ImageBuilder_hpp */
