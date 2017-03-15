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
    
    output->blend(*m_previousFrames[0], 0.3);
    output->blend(*m_previousFrames[1], 0.2);
    output->blend(*m_previousFrames[2], 0.1);
    
    output->copyTo(m_previousFrames[(++m_index)%3].get());
}
