//
//  VideoCapture.hpp
//  LightArtLikeRepresentation
//
//  Created by Shuto Shikama on 2017/03/15.
//
//

#ifndef VideoCapture_hpp
#define VideoCapture_hpp

namespace mmk {
    class Image;
    class VideoCapture;
}

class mmk::VideoCapture
{
protected:
    VideoCapture() = default;
public:
    virtual~VideoCapture() = default;
    
    virtual bool initialize() = 0;
    
    virtual void capture(mmk::Image* image) = 0;
};

#endif /* VideoCapture_hpp */
