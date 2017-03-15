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

mmk::AfterImageEffect::AfterImageEffect(std::unique_ptr<mmk::EffectComponent> effect, const std::uint32_t bufferSize)
: Super(std::move(effect))
{
    m_previousFrames.resize(bufferSize);
    
    auto& imageBuilder = mmk::LightArtSystem::GetInstance()->getImageBuilder();
    for (auto& previousFrame: m_previousFrames)
    {
        previousFrame = imageBuilder.createInstance();
    }
}

void mmk::AfterImageEffect::execute(const mmk::Image &input, mmk::Image *const output)
{
    // まずSuperのエフェクトをかける
    getSuperEffectPtr()->execute(input, output);


    const float kFrom = 0.2f, kTo = 0.0f;
    const float kReduceDuration = (kFrom - kTo) / m_previousFrames.size();
    const std::uint32_t kBufferSize = static_cast<std::uint32_t>(m_previousFrames.size());
    
    for (int i = 0; i < kBufferSize; ++i)
    {
        const float kAlpha = kFrom - float(i)*kReduceDuration;
        const std::uint32_t kIndex = (m_index+i) % kBufferSize;
        
        output->blend(*m_previousFrames[kIndex], kAlpha);
    }
    
    output->copyTo(m_previousFrames[(++m_index)%kBufferSize].get());
}
