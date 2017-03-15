//
//  ContourLineExtractionAlgorithm.h
//  LightArtLikeRepresentation
//
//  Created by Shuto Shikama on 2017/03/15.
//
//

#ifndef ContourLineExtractionAlgorithm_h
#define ContourLineExtractionAlgorithm_h

#include "effect/EffectComponent.hpp"

namespace mmk {
    class Image;
    class ContourLineExtractionAlgorithm;
}

class mmk::ContourLineExtractionAlgorithm : public mmk::EffectComponent
{
protected:
    ContourLineExtractionAlgorithm() = default;
public:
    virtual~ContourLineExtractionAlgorithm() = default;
};

#endif /* ContourLineExtractionAlgorithm_h */