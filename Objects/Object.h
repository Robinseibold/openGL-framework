
class Object {
    
public:
    Object() {
        glGenBuffers(1, &vertexBufferObject);
        glGenVertexArrays(1, &vertexArrayObject);
    }
    virtual void draw() = 0;
    
    
protected:
    GLuint vertexBufferObject;
    GLuint vertexArrayObject;
    
};