#include "RayTraceApp.hpp"

void RayTraceApp::setup()
{
    // moved from header
    unsigned int buffer;
    unsigned int program;
    
    int res;
    unsigned int vertex = glCreateShader(GL_VERTEX_SHADER);

    const char *s = "#version 330 core\n"
    "layout (location = 0) in vec4 pos;\n"
    "void main()\n"
    "{\n"
    "   gl_Position = pos;\n"
    "}\n";

    glShaderSource(vertex, 1, &s, nullptr);
    glCompileShader(vertex);
    glGetShaderiv(vertex, GL_COMPILE_STATUS, &res);
    if (res == GL_FALSE)
        std::cerr << "stupid vertex\n";

    unsigned int fragment = glCreateShader(GL_FRAGMENT_SHADER);

    const char *f =  "#version 330 core\n"
    "out vec4 color;\n"
    "void main()\n"
    "{\n"
    "   color = vec4(1.0, 0.0, 1.0, 1.0);\n"
    "}\n";

    glShaderSource(fragment, 1, &f, nullptr);
    glCompileShader(fragment);

    glGetShaderiv(fragment, GL_COMPILE_STATUS, &res);
    if (res == GL_FALSE)
        std::cerr << "stupid fragment\n";

    program = glCreateProgram();
    glAttachShader(program, vertex);
    glAttachShader(program, fragment);
    glLinkProgram(program);
    // glValidateProgram(program);

    glGetProgramiv(program, GL_LINK_STATUS, &res);
    if (res == GL_FALSE)
        std::cerr << "stupid program\n";
    glUseProgram(program);

    glDeleteShader(vertex);
    glDeleteShader(fragment);

    float positions[6] = {
        -0.5f, -0.5f,
        0.5f, -0.5f,
        0.0f,  0.5f
    };

    unsigned int vertArray;

    glGenBuffers(1, &buffer);
    glGenVertexArrays(1, &vertArray);
    glBindVertexArray(vertArray);
    glBindBuffer(GL_ARRAY_BUFFER, buffer);
    glBufferData(GL_ARRAY_BUFFER, sizeof(positions), positions, GL_STATIC_DRAW);

    glVertexAttribPointer(0, 2, GL_FLOAT, GL_FALSE, 2 * sizeof(float), (void *)0);
    glEnableVertexAttribArray(0);

    // glBindBuffer(GL_ARRAY_BUFFER, 0);
}

void RayTraceApp::render()
{
    glClear(GL_COLOR_BUFFER_BIT);
    glDrawArrays(GL_TRIANGLES, 0, 3);
}

void RayTraceApp::processInput(){
    if (glfwGetKey(window, GLFW_KEY_ESCAPE) == GLFW_PRESS)
        glfwSetWindowShouldClose(window, true);
}
void RayTraceApp::programCleanup(){
    glfwDestroyWindow(window);
}