//
//  ContourLineExtractionAlgorithm.h
//  LightArtLikeRepresentation
//
//  Created by Shuto Shikama on 2017/03/15.
//
//

#ifndef ContourLineExtractionAlgorithm_h
#define ContourLineExtractionAlgorithm_h

namespace mmk {
    class Image;
    class ContourLineExtractionAlgorithm;
}

class mmk::ContourLineExtractionAlgorithm
{
protected:
    ContourLineExtractionAlgorithm() = default;
public:
    virtual~ContourLineExtractionAlgorithm() = default;
    
    virtual void extract(const mmk::Image& input, mmk::Image*const output)const = 0;
};

#endif /* ContourLineExtractionAlgorithm_h */
