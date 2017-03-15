//
//  AfterImageEffect.hpp
//  LightArtLikeRepresentation
//
//  Created by Shuto Shikama on 2017/03/15.
//
//

#ifndef AfterImageEffect_hpp
#define AfterImageEffect_hpp

#include <cstdint>
#include <memory>
#include <vector>
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
    AfterImageEffect(std::unique_ptr<mmk::EffectComponent> effect, const std::uint32_t bufferSize = 3);
    ~AfterImageEffect() = default;
    
    void execute(const mmk::Image& input, mmk::Image*const output)override;
    
private:
    std::vector<std::unique_ptr<mmk::Image>> m_previousFrames;
    std::uint8_t m_index = 0;
};

#endif /* AfterImageEffect_hpp */
