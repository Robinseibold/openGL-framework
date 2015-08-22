
#include <openGL/gl3.h>

#include <fstream>
#include <iostream>
#include <string>

#include "../Math/Math.h"

class Shader {
    
public:
    Shader(std::string shaderName);
    GLuint getProgram();
    void activate();
    void unactivate();
    void setModelMatrix(mat4<GLfloat> &model);
    void setTransformationMatrices(mat4<GLfloat> &model, mat4<GLfloat> *view, mat4<GLfloat> *projection);
    void setPropertyMatrix(const char *name, const GLfloat *matrixArray);
    void setPropertyVector(const char *name, const GLfloat *vectorArray);
    void setSampler(const char *name, const GLint samplerValue);
    
private:
    GLuint shaderProgram;
    
    std::string readSourceCode(std::string fileName);
    void checkCompilationSuccess(GLuint shader);
    void checkLinkingSuccess(GLuint program);
    
};
