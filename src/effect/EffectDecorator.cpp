//
//  EffectDecorator.cpp
//  LightArtLikeRepresentation
//
//  Created by Shuto Shikama on 2017/03/15.
//
//

#include "EffectDecorator.hpp"

mmk::EffectDecorator::EffectDecorator(std::unique_ptr<mmk::EffectComponent> effect)
: m_effect(std::move(effect))
{
    
}

mmk::EffectComponent*const mmk::EffectDecorator::getSuperEffectPtr()const
{
    return m_effect.get();
}
