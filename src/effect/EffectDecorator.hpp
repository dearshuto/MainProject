//
//  EffectDecorator.hpp
//  LightArtLikeRepresentation
//
//  Created by Shuto Shikama on 2017/03/15.
//
//

#ifndef EffectDecorator_hpp
#define EffectDecorator_hpp

#include <memory>
#include "EffectComponent.hpp"

namespace mmk {
    class EffectDecorator;
}

class mmk::EffectDecorator : public mmk::EffectComponent
{
public:
    EffectDecorator() = delete;
    EffectDecorator(std::unique_ptr<mmk::EffectComponent> effect);
    virtual~EffectDecorator() = default;
    
    mmk::EffectComponent*const getSuperEffectPtr()const;

private:
    std::unique_ptr<mmk::EffectComponent> m_effect;
};

#endif /* EffectDecorator_hpp */
