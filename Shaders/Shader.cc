
#include "Shader.h"

Shader::Shader(std::string shaderName) {
    std::string vertexShaderString = readSourceCode("Shaders/" + shaderName + ".vert");
    const char *vertexShaderSourceCode = vertexShaderString.c_str();
    GLuint vertexShader = glCreateShader(GL_VERTEX_SHADER);
    glShaderSource(vertexShader, 1, &vertexShaderSourceCode, NULL);
    glCompileShader(vertexShader);
    checkCompilationSuccess(vertexShader);
    
    std::string fragmentShaderString = readSourceCode("Shaders/" + shaderName + ".frag");
    const char *fragmentShaderSourceCode = fragmentShaderString.c_str();
    GLuint fragmentShader = glCreateShader(GL_FRAGMENT_SHADER);
    glShaderSource(fragmentShader, 1, &fragmentShaderSourceCode, NULL);
    glCompileShader(fragmentShader);
    checkCompilationSuccess(fragmentShader);
    
    shaderProgram = glCreateProgram();
    glAttachShader(shaderProgram, vertexShader);
    glAttachShader(shaderProgram, fragmentShader);
    glLinkProgram(shaderProgram);
    checkLinkingSuccess(shaderProgram);
    
    glDeleteShader(vertexShader);
    glDeleteShader(fragmentShader);
}

GLuint Shader::getProgram() {
    return shaderProgram;
}

void Shader::activate() {
    glUseProgram(shaderProgram);
}

void Shader::unactivate() {
    glUseProgram(0);
}

std::string Shader::readSourceCode(std::string fileName) {
    std::string sourceCode;
    std::ifstream inputFile(fileName);
    if (inputFile) {
        inputFile.seekg(0, std::ios::end);
        sourceCode.reserve(inputFile.tellg());
        inputFile.seekg(0, std::ios::beg);
    
        sourceCode.assign((std::istreambuf_iterator<char>(inputFile)), std::istreambuf_iterator<char>());
    } else {
        std::cout << "Shader file not found" << std::endl;
    }
    return sourceCode;
}

void Shader::checkCompilationSuccess(GLuint shader) {
    GLint success;
    glGetShaderiv(shader, GL_COMPILE_STATUS, &success);
    if (!success) {
        GLchar log[512];
        glGetShaderInfoLog(shader, 512, NULL, log);
        std::cout << "Shader compilation failed: \n" << log << std::endl;
    }
}

void Shader::checkLinkingSuccess(GLuint program) {
    GLint success;
    glGetProgramiv(program, GL_LINK_STATUS, &success);
    if (!success) {
        GLchar log[512];
        glGetProgramInfoLog(program, 512, NULL, log);
        std::cout << "Program linkage failed: \n" << log << std::endl;
    }
}
















