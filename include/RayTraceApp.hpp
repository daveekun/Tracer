#ifndef RAYTRACEAPP_HPP
#define RAYTRACEAPP_HPP

#include "App.hpp"
// #include "Camera.hpp"
#include <list>
#include <sstream>
#include <string>
#include <fstream>

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

        const std::string vertex_path = "./resources/basic.vert";
        const std::string fragment_path = "./resources/basic.frag";

    public:
        RayTraceApp() : App(SCR_WIDTH, SCR_HEIGHT, "rt"){};
        void setup() override;
        void processInput() override;
        void render() override;
        void programCleanup() override;

        struct ShaderSource { 
            std::string vertshader;
            std::string fragshader;
        };
        ShaderSource readShaders();
        unsigned int compileShader(GLenum type, std::string source);
};

#endif