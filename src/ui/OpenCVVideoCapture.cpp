//
//  OpenCVVideoCapture.cpp
//  LightArtLikeRepresentation
//
//  Created by Shuto Shikama on 2017/03/15.
//
//

#include <iostream>
#include "image/OpenCVImage.hpp"
#include "OpenCVVideoCapture.hpp"

bool mmk::OpenCVVideoCapture::initialize()
{
    m_videoCapture->set(CV_CAP_PROP_FPS, 10);
    m_videoCapture->set(CV_CAP_PROP_FRAME_WIDTH, 640);
    m_videoCapture->set(CV_CAP_PROP_FRAME_HEIGHT, 480);
    
    return m_videoCapture->isOpened();
}

void mmk::OpenCVVideoCapture::capture(mmk::Image *image)
{
    mmk::OpenCVImage* cvImage = static_cast<mmk::OpenCVImage*>(image);

    do{
        *getVideoCapturePtr() >> *cvImage;
    }while(cvImage->empty());
}

cv::VideoCapture*const mmk::OpenCVVideoCapture::getVideoCapturePtr()
{
    return m_videoCapture.get();
}
