#ifndef APP_HPP
#define APP_HPP

#include <string>
#include <exception>
#include <stdexcept>
#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include <iostream>

class App {
    protected:
        unsigned int screen_width;
        unsigned int screen_height;
        std::string window_name;
        GLFWwindow *window;
    public:
        // should be in trycatch as exceptions are thrown on error
        App(unsigned int _screen_width, unsigned int _screen_height, std::string _w_name);
        // glfw cleanup
        ~App();
        // base loop calling the overrideable program and processinput functions
        void run();
        // functions to override in inherited classes
        virtual void setup();
        virtual void processInput();
        virtual void render();
        virtual void programCleanup();
        // disallow Orthodox canonical required functions
        App(const App& other) = delete;
        App& operator=(const App& other) = delete;
};

void framebuffer_size_callback(GLFWwindow* window, int width, int height);

#endif