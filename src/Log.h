#ifndef Log_hpp
#define Log_hpp

#pragma once

#include <string>

class Log
{
public:
    Log() = default;
    Log(const std::string& fileName);
    ~Log() = default;
    
    void Write(const std::string& log)const;

public:
    const std::string& getOutputFileName()const;
    
private:
    std::string m_fileName = "";
};

#endif /* Log_hpp */
