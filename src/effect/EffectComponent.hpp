//
//  EffectComponent.hpp
//  LightArtLikeRepresentation
//
//  Created by Shuto Shikama on 2017/03/15.
//
//

#ifndef EffectComponent_hpp
#define EffectComponent_hpp

namespace mmk {
    class Image;
    class EffectComponent;
}

/// ペンライトアート風のエッフェクトをデコレータパターンで実行するためのコンポーネント
class mmk::EffectComponent
{
protected:
    EffectComponent() = default;
public:
    virtual~EffectComponent() = default;
    
    virtual void execute(const mmk::Image& input, mmk::Image*const output) = 0;
};

#endif /* EffectComponent_hpp */
