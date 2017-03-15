//
//  CVContourLineExtractionAlgorithm.hpp
//  LightArtLikeRepresentation
//
//  Created by Shuto Shikama on 2017/03/15.
//
//

#ifndef CVContourLineExtractionAlgorithm_hpp
#define CVContourLineExtractionAlgorithm_hpp

#include "image/OpenCVImage.hpp"
#include "ContourLineExtractionAlgorithm.h"

namespace mmk {
    class CVContourLineExtractionAlgorithm;
}

class mmk::CVContourLineExtractionAlgorithm : public mmk::ContourLineExtractionAlgorithm
{
public:
    CVContourLineExtractionAlgorithm() = default;
    ~CVContourLineExtractionAlgorithm() = default;
    
    void extract(const mmk::Image& input, mmk::Image*const output)const override;
};

#endif /* CVContourLineExtractionAlgorithm_hpp */
