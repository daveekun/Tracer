#include "App.hpp"

App::App(unsigned int _screen_width, unsigned int _screen_height, std::string _w_name) : screen_width(_screen_width), screen_height(_screen_height), window_name(_w_name)
{
    glfwInit();
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
    #ifdef __APPLE__
        glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);
    #endif
    window = glfwCreateWindow(screen_width, screen_height, window_name.c_str(), NULL, NULL);
    if (!window)
    {
        glfwTerminate();
        throw std::runtime_error("Error while opening window");
    }
    glfwMakeContextCurrent(window);
    glfwSetFramebufferSizeCallback(window, framebuffer_size_callback);
    if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress))
    {
        glfwTerminate();
        throw std::runtime_error("Error while initializing GLAD");
    }
}

App::~App()
{
    glfwTerminate();
}

void App::setup(){}

void App::run()
{
    setup();
    while (!glfwWindowShouldClose(window))
    {
        // input
        processInput();
        // render - main content of the App
        render();
        // change to next buffer and gather input
        glfwSwapBuffers(window);
        glfwPollEvents();
    }
    programCleanup();
}

void App::render(){}

void App::programCleanup()
{
    glfwDestroyWindow(window);
}

void App::processInput()
{
    if (glfwGetKey(window, GLFW_KEY_ESCAPE) == GLFW_PRESS)
        glfwSetWindowShouldClose(window, true);
}

void framebuffer_size_callback(GLFWwindow* window, int width, int height)
{
    // make sure the viewport matches the new window dimensions; might fuck retina windows
    glViewport(0, 0, width, height);
}
