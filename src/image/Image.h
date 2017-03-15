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

namespace mmk {
    class Image;
}

class mmk::Image
{
protected:
    Image() = default;
public:
    ~Image() = default;
    
    virtual void clear() = 0;
    virtual void copyTo(mmk::Image*const image)const = 0;
    virtual void show()const = 0;
    virtual std::uint32_t getWidth()const = 0;
    virtual std::uint32_t getHeight()const = 0;
};

#endif /* Image_h */
