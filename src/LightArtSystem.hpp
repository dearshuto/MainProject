//
//  LightArtSystem.hpp
//  LightArtLikeRepresentation
//
//  Created by Shuto Shikama on 2017/03/15.
//
//

#ifndef LightArtSystem_hpp
#define LightArtSystem_hpp

#include <memory>
#include "algorithm/ContourLineExtractionAlgorithm.h"
#include "effect/EffectComponent.hpp"
#include "ui/VideoCapture.hpp"

namespace mmk {
    class LightArtSystem;
}

class mmk::LightArtSystem
{
private:
    LightArtSystem() = default;
public:
    ~LightArtSystem() = default;
    
    static LightArtSystem*const GetInstance()
    {
        static mmk::LightArtSystem instance;
        return &instance;
    }
    
    bool initialize();
    
    void mainloop();
    
    void terminate();
    
private:
    void runWithKinect();
    
    void runWithoutKinect();
    
    const mmk::ContourLineExtractionAlgorithm& getContourLineExtractionAlgorithm()const;
    
    const mmk::EffectComponent& getEffectComponent()const;
    
    mmk::VideoCapture*const getVideoCapturePtr();
private:
    std::unique_ptr<mmk::ContourLineExtractionAlgorithm> m_contourLineExtractionAlgorithm;
    
    std::unique_ptr<mmk::VideoCapture> m_videoCapture;
    
    std::unique_ptr<mmk::EffectComponent> m_effectComponent;
};

#endif /* LightArtSystem_hpp */
