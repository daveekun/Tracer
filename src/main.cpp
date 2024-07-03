#include "RayTraceApp.hpp"
#include <iostream>

// settings
int main()
{
    try
    {
        RayTraceApp app{};    
        app.run();
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
    return 0;
}

