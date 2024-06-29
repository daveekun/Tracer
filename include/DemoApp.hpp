#ifndef DEMOAPP_HPP
#define DEMOAPP_HPP

#include "App.hpp"

class DemoApp : public App
{
    private:
        unsigned int shaderProgram;
        unsigned int VAO, VBO;
    public:
        DemoApp(unsigned int _screen_width, unsigned int _screen_height) : App(_screen_width, _screen_height, "Demo"){};
        void setup() override;
        void render() override;
        void programCleanup() override;
};

#endif