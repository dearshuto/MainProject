//
//  AfterImageEffect.hpp
//  LightArtLikeRepresentation
//
//  Created by Shuto Shikama on 2017/03/15.
//
//

#ifndef AfterImageEffect_hpp
#define AfterImageEffect_hpp

#include <memory>
#include "EffectDecorator.hpp"

namespace mmk {
    class AfterImageEffect;
}

class mmk::AfterImageEffect : public mmk::EffectDecorator
{
    typedef mmk::EffectDecorator Super;
public:
    AfterImageEffect() = delete;
    AfterImageEffect(std::unique_ptr<mmk::EffectComponent> effect);
    ~AfterImageEffect() = default;
    
    void execute(const mmk::Image& input, mmk::Image*const output)override;
    
private:
    std::unique_ptr<mmk::Image> m_previousFrame;
};

#endif /* AfterImageEffect_hpp */
