//
//  Log.cpp
//  LightArtLikeRepresentation
//
//  Created by Shuto Shikama on 2017/03/15.
//
//

#include <chrono>
#include <ctime>
#include <fstream>
#include <iomanip>
#include "Log.h"

Log::Log(const std::string& fileName)
: m_fileName(fileName)
{
    
}

void Log::Write(const std::string &log)const
{
    std::chrono::system_clock::time_point now = std::chrono::system_clock::now();
    std::time_t now_c = std::chrono::system_clock::to_time_t(now);
    std::ofstream output(getOutputFileName());
    
    output <<  std::put_time(std::localtime(&now_c), "%F %T") << std::endl;
    output << log << std::endl;
}


const std::string& Log::getOutputFileName()const
{
    return m_fileName;
}
