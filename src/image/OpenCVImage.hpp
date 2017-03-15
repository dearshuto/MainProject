//
//  OpenCVImage.hpp
//  LightArtLikeRepresentation
//
//  Created by Shuto Shikama on 2017/03/15.
//
//

#ifndef OpenCVImage_hpp
#define OpenCVImage_hpp

#include <opencv2/opencv.hpp>
#include "Image.h"

namespace mmk {
    class OpenCVImage;
}

class mmk::OpenCVImage : public cv::Mat, public mmk::Image
{
public:
    OpenCVImage() = delete;
    OpenCVImage(const std::uint32_t width, const std::uint32_t height);
    OpenCVImage(const cv::Mat& mat);
    ~OpenCVImage() = default;
    
    void blend(const mmk::Image& other, const float alpha, const float selfAlpha = 1.0)override;
    void clear()override;
    void copyTo(mmk::Image*const image)const override;
    void show()const override;
    std::uint32_t getWidth()const override;
    std::uint32_t getHeight()const override;
};

#endif /* OpenCVImage_hpp */
