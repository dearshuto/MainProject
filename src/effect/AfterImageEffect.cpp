//
//  AfterImageEffect.cpp
//  LightArtLikeRepresentation
//
//  Created by Shuto Shikama on 2017/03/15.
//
//

#include "image/Image.h"
#include "LightArtSystem.hpp"
#include "AfterImageEffect.hpp"

mmk::AfterImageEffect::AfterImageEffect(std::unique_ptr<mmk::EffectComponent> effect)
: Super(std::move(effect))
{
    auto& imageBuilder = mmk::LightArtSystem::GetInstance()->getImageBuilder();
    for (auto& previousFrame: m_previousFrames)
    {
        previousFrame = imageBuilder.createInstance(640, 480);
    }
}

void mmk::AfterImageEffect::execute(const mmk::Image &input, mmk::Image *const output)
{
    // まずSuperのエフェクトをかける
    getSuperEffectPtr()->execute(input, output);

    const float kFrom = 0.25f, kTo = 0.0f;
    const float kReduceDuration = (kFrom - kTo) / m_previousFrames.size();
    const std::uint32_t kBufferSize = static_cast<std::uint32_t>(m_previousFrames.size());
    
    output->blend(*m_previousFrames[(m_index+0)%3], 0.3);
    output->blend(*m_previousFrames[(m_index+1)%3], 0.2);
    output->blend(*m_previousFrames[(m_index+2)%3], 0.1);
    
    output->copyTo(m_previousFrames[(++m_index)%3].get());
}
