//
//  OpenCVVideoCapture.hpp
//  LightArtLikeRepresentation
//
//  Created by Shuto Shikama on 2017/03/15.
//
//

#ifndef OpenCVVideoCapture_hpp
#define OpenCVVideoCapture_hpp

#include <opencv2/opencv.hpp>
#include "VideoCapture.hpp"

namespace mmk {
    class OpenCVVideoCapture;
}

class mmk::OpenCVVideoCapture : public mmk::VideoCapture
{
public:
    OpenCVVideoCapture() = default;
    ~OpenCVVideoCapture() = default;
    
    bool initialize()override;
    
    void capture(mmk::Image* image)override;
    
protected:
    cv::VideoCapture*const getVideoCapturePtr();
private:
    std::unique_ptr<cv::VideoCapture> m_videoCapture{new cv::VideoCapture{0}};
};

#endif /* OpenCVVideoCapture_hpp */
