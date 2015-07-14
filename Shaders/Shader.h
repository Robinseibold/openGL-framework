
#include <openGL/gl3.h>

#include <fstream>
#include <iostream>
#include <string>

class Shader {
    
public:
    Shader(std::string shaderName);
    void activate();
    void unactivate();
    
private:
    GLuint shaderProgram;
    
    std::string readSourceCode(std::string fileName);
    void checkCompilationSuccess(GLuint shader);
    void checkLinkingSuccess(GLuint program);
    
};
