#include "RayTraceApp.hpp"

RayTraceApp::ShaderSource RayTraceApp::readShaders()
{
    std::ifstream vert(vertex_path);
    std::ifstream frag(fragment_path);
    std::stringstream vertShader;
    std::stringstream fragShader;

    std::string line;
    if (!vert.is_open() || !frag.is_open())
        std::cerr << "failed to open shader file\n";
    while (getline(vert, line))
        vertShader << line << "\n";
    while (getline(frag, line))
        fragShader << line << "\n";

    return (RayTraceApp::ShaderSource){ vertShader.str(), fragShader.str() };
}

unsigned int RayTraceApp::compileShader(GLenum type, std::string source)
{
    unsigned int id = glCreateShader(type);
    const char *s = source.c_str();
    glShaderSource(id, 1, &s, nullptr);
    glCompileShader(id);
    int res;
    char buf[512];
    glGetShaderiv(id, GL_COMPILE_STATUS, &res);
    if (res == GL_FALSE)
    {
        std::cerr << "shader compilation failed: " << (type == GL_VERTEX_SHADER ? "vertex" : "fragment") << std::endl;
        glGetShaderInfoLog(id, 512, NULL, buf);
        std::cerr << buf;
        glDeleteShader(id);
        return 0;
    }
    return id;
}

void RayTraceApp::setup()
{
    // moved from header
    unsigned int buffer;
    unsigned int program;
    
    ShaderSource s = readShaders();
    unsigned int vertex = compileShader(GL_VERTEX_SHADER, s.vertshader);
    unsigned int fragment = compileShader(GL_FRAGMENT_SHADER, s.fragshader);

    program = glCreateProgram();
    glAttachShader(program, vertex);
    glAttachShader(program, fragment);
    glLinkProgram(program);
    // glValidateProgram(program);

    int res;
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