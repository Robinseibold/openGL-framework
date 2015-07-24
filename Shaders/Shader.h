
#include <openGL/gl3.h>

#include <fstream>
#include <iostream>
#include <string>

class Shader {
    
public:
    Shader(std::string shaderName);
    GLuint getProgram();
    void activate();
    void unactivate();
    void setShaderMatrix(const char *name, const GLfloat *matrixArray);
    
private:
    GLuint shaderProgram;
    
    std::string readSourceCode(std::string fileName);
    void checkCompilationSuccess(GLuint shader);
    void checkLinkingSuccess(GLuint program);
    
};
