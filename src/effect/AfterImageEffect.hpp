//
//  AfterImageEffect.hpp
//  LightArtLikeRepresentation
//
//  Created by Shuto Shikama on 2017/03/15.
//
//

#ifndef AfterImageEffect_hpp
#define AfterImageEffect_hpp

#include <array>
#include <cstdint>
#include <memory>
#include "EffectDecorator.hpp"

namespace mmk {
    class AfterImageEffect;
}

/// 残像効果
class mmk::AfterImageEffect : public mmk::EffectDecorator
{
    typedef mmk::EffectDecorator Super;
public:
    AfterImageEffect() = delete;
    AfterImageEffect(std::unique_ptr<mmk::EffectComponent> effect);
    ~AfterImageEffect() = default;
    
    void execute(const mmk::Image& input, mmk::Image*const output)override;
    
private:
    std::array<std::unique_ptr<mmk::Image>, 3> m_previousFrames;
    std::uint8_t m_index = 0;
};

#endif /* AfterImageEffect_hpp */
