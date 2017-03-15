//
//  LightArtSystem.cpp
//  LightArtLikeRepresentation
//
//  Created by Shuto Shikama on 2017/03/15.
//
//

#include "LightArtSystem.hpp"
#include <iostream>
#include <sstream>
#include <time.h>
#include "Depth.h"
#include "Dot.h"
#include "NeonDesign.h"
#include "Log.h"
#include "CatmullSpline.h"
#include "NtKinect.h"
#include "algorithm/CVContourLineExtractionAlgorithm.hpp"
#include "image/OpenCVImage.hpp"
#include "effect/EffectComponent.hpp"
#include "ui/OpenCVVideoCapture.hpp"


bool mmk::LightArtSystem::initialize()
{
    bool result = true;
    
    m_videoCapture.reset(new mmk::OpenCVVideoCapture);
    m_contourLineExtractionAlgorithm.reset(new mmk::CVContourLineExtractionAlgorithm);
    
    result &= m_videoCapture->initialize();
    
    
//    /*	écëúÇ†ÇËversion */
//    //1âÒñ⁄ÇÕdotÇ©ÇÁénÇﬂÇƒÅA2âÒñ⁄à»ç~ÇÕeffectÇ©ÇØÇΩresultÇ™ÇŸÇµÇ¢ÇÃÇ≈ÅAeffectÇ©ÇÁénÇﬂÇÈ
//    if (afterimg_array.size() == 0){
//        //                doDot(depth.contourImage, result_img);
//        //1ñáñ⁄ÇñæÇÈÇ≥â∫Ç∞ÇƒarrayÇ…ï€ë∂
//        addAfterImg(result_img, afterimg_array);
//    }
//    else {
//        //arrayÇ…ì¸Ç¡ÇƒÇ¢ÇÈâÊëúÇorââéZéqÇ≈Ç¬Ç»Ç∞ÇƒîwåiÇ…Ç∑ÇÈ
//        for (int i = 0; i < afterimg_array.size(); i++){
//            bitwise_or(result_img, afterimg_array.at(i), result_img);
//        }
//        
//        //è„Ç≈ìæÇÁÇÍÇΩresult_imgÇîwåiÇ…ÇµÇƒê¸Çè„èëÇ´Ç∑ÇÈ
//        //                doDot(depth.contourImage, result_img);
//        //Ç±ÇÃéûÇÃê¸ÇarrayÇ…í«â¡Ç∑ÇÈ
//        addAfterImg(result_img, afterimg_array);
//    }

    return result;
}

void mmk::LightArtSystem::mainloop()
{
#ifdef KINECT
    runWithKinect();
#else
    runWithoutKinect();
#endif //KINECT
}

void mmk::LightArtSystem::runWithKinect()
{
    
}

void mmk::LightArtSystem::runWithoutKinect()
{
    mmk::OpenCVImage image{640, 480};
    mmk::OpenCVImage contour{640, 480};
    
    while(1)
    {
        contour.clear();
        getVideoCapturePtr()->capture(&image);
        getContourLineExtractionAlgorithm().extract(image, &contour);
        contour.show();
    }
}

void mmk::LightArtSystem::terminate()
{
    
}

const mmk::ContourLineExtractionAlgorithm& mmk::LightArtSystem::getContourLineExtractionAlgorithm()const
{
    return *m_contourLineExtractionAlgorithm;
}

mmk::VideoCapture*const mmk::LightArtSystem::getVideoCapturePtr()
{
    return m_videoCapture.get();
}
