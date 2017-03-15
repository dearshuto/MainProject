//
//  AfterImageEffect.cpp
//  LightArtLikeRepresentation
//
//  Created by Shuto Shikama on 2017/03/15.
//
//

#include <iostream>
#include "image/Image.h"
#include "image/OpenCVImage.hpp"
#include "AfterImageEffect.hpp"

mmk::AfterImageEffect::AfterImageEffect(std::unique_ptr<mmk::EffectComponent> effect)
: Super(std::move(effect))
{
    for (auto& previousFrame : m_previousFrames)
    {
        previousFrame.reset(new OpenCVImage{640, 480});
    }
}

void mmk::AfterImageEffect::execute(const mmk::Image &input, mmk::Image *const output)
{
    // まずSuperのエフェクトをかける
    getSuperEffectPtr()->execute(input, output);
    
    const mmk::OpenCVImage& cvPreviousImage1 = static_cast<const mmk::OpenCVImage&>(*m_previousFrames[0]);
    const mmk::OpenCVImage& cvPreviousImage2 = static_cast<const mmk::OpenCVImage&>(*m_previousFrames[1]);
    const mmk::OpenCVImage& cvPreviousImage3 = static_cast<const mmk::OpenCVImage&>(*m_previousFrames[2]);
    mmk::OpenCVImage*const cvOutput = static_cast<mmk::OpenCVImage*const>(output);
    cv::Mat result;
        
    cv::addWeighted(*cvOutput, 1.0, cvPreviousImage1, 0.1, 0.0f/*gamma*/, *cvOutput);
    cv::addWeighted(*cvOutput, 1.0, cvPreviousImage2, 0.2, 0.0f/*gamma*/, *cvOutput);
    cv::addWeighted(*cvOutput, 1.0, cvPreviousImage3, 0.3, 0.0f/*gamma*/, *cvOutput);
    
    cvOutput->copyTo(m_previousFrames[(++m_index)%3].get());
}
