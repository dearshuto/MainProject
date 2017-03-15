
#include <iostream>
#include "LightArtSystem.hpp"

int main()
{
    auto instance = mmk::LightArtSystem::GetInstance();
    
    if(!instance->initialize())
    {
        std::cout << "Error" << std::endl;
    }
    else
    {
        instance->mainloop();
    }
    
    instance->terminate();
    
    return EXIT_SUCCESS;
}
