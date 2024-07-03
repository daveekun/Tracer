#ifndef RAYTRACEAPP_HPP
#define RAYTRACEAPP_HPP

#include "App.hpp"
// #include "Camera.hpp"
#include <list>

const unsigned int SCR_WIDTH = 800;
const unsigned int SCR_HEIGHT = 600;

// struct triangle {
//     Vector3 a;
//     Vector3 b;
//     Vector3 c;
// };

class RayTraceApp : public App
{
    //todo rasterize
    private:
        // triangle t;
        // Camera cam;
        // in use: 
        unsigned int buffer;
        unsigned int program;

    public:
        RayTraceApp() : App(SCR_WIDTH, SCR_HEIGHT, "rt"){};
        void setup() override;
        void processInput() override;
        void render() override;
        void programCleanup() override;

};

#endif