
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

void Shader::setModelMatrix(mat4<GLfloat> &model) {
    this->activate();
    GLuint modelMatrixLocation = glGetUniformLocation(shaderProgram, "Model");
    if(modelMatrixLocation != -1) {
        glUniformMatrix4fv(modelMatrixLocation, 1, GL_FALSE, model.array());
    }
    GLuint inverseTransposeModelMatrixLocation = glGetUniformLocation(shaderProgram, "InverseTransposeModel");
    if(inverseTransposeModelMatrixLocation != -1) {
        mat4<GLfloat> inverseTransposeModel = model;
        inverseTransposeModel.inverse().transpose();
        glUniformMatrix4fv(inverseTransposeModelMatrixLocation, 1, GL_FALSE, inverseTransposeModel.array());
    }
}

void Shader::setTransformationMatrices(mat4<GLfloat> &model, mat4<GLfloat> *view, mat4<GLfloat> *projection) {
    this->setModelMatrix(model);
    GLuint viewMatrixLocation = glGetUniformLocation(shaderProgram, "View");
    if(viewMatrixLocation != -1) {
        glUniformMatrix4fv(viewMatrixLocation, 1, GL_FALSE, view->array());
    }
    GLuint projectionMatrixLocation = glGetUniformLocation(shaderProgram, "Projection");
    if(projectionMatrixLocation != -1) {
        glUniformMatrix4fv(projectionMatrixLocation, 1, GL_FALSE, projection->array());
    }
}

void Shader::setPropertyMatrix(const char *name, const GLfloat *matrixArray) {
    GLuint matrixLocation = glGetUniformLocation(shaderProgram, name);
    if (matrixLocation == -1) {
        std::cout << "The matrix name '" << name << "' does not correspond to a variable in the shader" << std::endl;
        return;
    }
    this->activate();
    glUniformMatrix4fv(matrixLocation, 1, GL_FALSE, matrixArray);
}

void Shader::setPropertyVector(const char *name, const GLfloat *vectorArray) {
    GLuint vectorLocation = glGetUniformLocation(shaderProgram, name);
    if (vectorLocation == -1) {
        std::cout << "The vector name '" << name << "' does not correspond to a variable in the shader" << std::endl;
        return;
    }
    this->activate();
    glUniform3fv(vectorLocation, 1, vectorArray);
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
















