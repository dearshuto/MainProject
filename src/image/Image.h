//
//  Image.h
//  LightArtLikeRepresentation
//
//  Created by Shuto Shikama on 2017/03/15.
//
//

#ifndef Image_h
#define Image_h

#include <cstdint>
#include <string>

namespace mmk {
    class Image;
}

class mmk::Image
{
protected:
    Image() = default;
public:
    ~Image() = default;
    
    /// 他の画像とアルファブレンドする
    virtual void blend(const mmk::Image& other, const float alpha, const float selfAlpha = 1.0) = 0;
    
    /// すべての画素を0に設定する
    virtual void clear() = 0;
    
    /// 別の画像にデータをコピーする. 自身が保持する値は変化しない.
    virtual void copyTo(mmk::Image*const image)const = 0;
    
    /// ウィンドウに表示する
    virtual void show()const = 0;
    
    virtual bool saveToFile(const std::string& fileName)const = 0;
    
    virtual std::uint32_t getWidth()const = 0;
    virtual std::uint32_t getHeight()const = 0;
};

#endif /* Image_h */
