//
//  LightArtSystem.cpp
//  LightArtLikeRepresentation
//
//  Created by Shuto Shikama on 2017/03/15.
//
//

#include "algorithm/ContourLineExtractionAlgorithm.h"
#include "effect/EffectComponent.hpp"
#include "effect/AfterImageEffect.hpp"
#include "image/ImageBuilder.hpp"
#include "image/OpenCVImage.hpp"
#include "toolkit/OpenCVToolkitBuilder.hpp"
#include "LightArtSystem.hpp"


bool mmk::LightArtSystem::initialize()
{
    bool result = true;
    
    // 生成するToolkitBuilderのインスタンスを変更することで, ベースとなるシステムを変更する事ができます.
    // とりあえずOpenCVをベースにシステムを構築します.
    std::unique_ptr<mmk::ToolkitBuilder> toolkitBuilder(new mmk::OpenCVToolkitBuilder);
   
    // NOTE: この関数でImageの作成を行う箇所があるので, 最初にImageBuilderを登録する必要があります.
    m_imageBuilder = toolkitBuilder->buildImageBuilder();
    m_videoCapture = toolkitBuilder->buildVideoCapture();
    result &= m_videoCapture->initialize();

    // デコレータパターンでエフェクトを追加できるようにしてあります.
    auto contourLineExtraction = toolkitBuilder->buildContourExtractionAlgorithm();
    
    // 残像効果の追加
    const std::uint32_t kBuffer = 5;//残像用のバッファ
    auto withAfterImag = std::make_unique<mmk::AfterImageEffect>(std::move(contourLineExtraction), kBuffer);
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
    std::unique_ptr<mmk::Image> input = getImageBuilder().createInstance();
    std::unique_ptr<mmk::Image> output = getImageBuilder().createInstance();
    
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
