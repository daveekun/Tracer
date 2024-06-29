#ifndef RAYTRACEAPP_HPP
#define RAYTRACEAPP_HPP

#include "App.hpp"
#include "Camera.hpp"

class RayTraceApp : public App
{
    //todo raytrace
    private:
        Camera cam;

    public:
        void setup() override;
        void processInput() override;
        void render() override;
        void programCleanup() override;

};

#endif