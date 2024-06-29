#include "DemoApp.hpp"
#include <iostream>

// settings
const unsigned int SCR_WIDTH = 800;
const unsigned int SCR_HEIGHT = 600;

int main()
{
    try
    {
        DemoApp app{SCR_WIDTH, SCR_HEIGHT};    
        app.run();
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
    return 0;
}

