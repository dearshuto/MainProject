//
//  LightArtSystem.cpp
//  LightArtLikeRepresentation
//
//  Created by Shuto Shikama on 2017/03/15.
//
//

#include "algorithm/CVContourLineExtractionAlgorithm.hpp"
#include "effect/EffectComponent.hpp"
#include "effect/AfterImageEffect.hpp"
#include "image/ImageBuilder.hpp"
#include "image/OpenCVImage.hpp"
#include "toolkit/OpenCVToolkitBuilder.hpp"
#include "ui/OpenCVVideoCapture.hpp"
#include "LightArtSystem.hpp"


bool mmk::LightArtSystem::initialize()
{
    bool result = true;
    
    std::unique_ptr<mmk::ToolkitBuilder> toolkitBuilder(new mmk::OpenCVToolkitBuilder);
    m_imageBuilder = toolkitBuilder->buildImageBuilder();
    m_videoCapture = toolkitBuilder->buildVideoCapture();
    
    result &= m_videoCapture->initialize();
    
    auto contourLineExtraction = std::make_unique<mmk::CVContourLineExtractionAlgorithm>();
    auto withAfterImag = std::make_unique<mmk::AfterImageEffect>(std::move(contourLineExtraction));
    m_effect = std::move(withAfterImag);

    return result;
}

void mmk::LightArtSystem::mainloop()
{
#ifdef KINECT
    runWithKinect();
#else
    runWithoutKinect();
#endif //KINECT
}

void mmk::LightArtSystem::runWithKinect()
{
    // Not Supported
}

void mmk::LightArtSystem::runWithoutKinect()
{
    std::unique_ptr<mmk::Image> input = getImageBuilder().createInstance(640, 480);
    std::unique_ptr<mmk::Image> output = getImageBuilder().createInstance(640, 480);
    
    while(1)
    {
        output->clear();
        getVideoCapturePtr()->capture(input.get());
        m_effect->execute(*input, output.get());
        output->show();
    }
}

void mmk::LightArtSystem::terminate()
{
    
}

const mmk::ImageBuilder& mmk::LightArtSystem::getImageBuilder()const
{
    return *m_imageBuilder;
}

mmk::VideoCapture*const mmk::LightArtSystem::getVideoCapturePtr()
{
    return m_videoCapture.get();
}
