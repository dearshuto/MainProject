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
    m_previousFrame.reset(new OpenCVImage{640, 480});
}

void mmk::AfterImageEffect::execute(const mmk::Image &input, mmk::Image *const output)
{
    // まずSuperのエフェクトをかける
    getSuperEffectPtr()->execute(input, output);
    
    const mmk::OpenCVImage& cvPreviousImage = static_cast<const mmk::OpenCVImage&>(*m_previousFrame);
    mmk::OpenCVImage*const cvOutput = static_cast<mmk::OpenCVImage*const>(output);
        
    cv::addWeighted(*cvOutput, 1.0, cvPreviousImage, 0.6, 0.0f/*gamma*/, *cvOutput);
    output->copyTo(m_previousFrame.get());
}
