
#include <unordered_map>

#include "../Math/Math.h"

class Node {
    
public:
    Node();
    Node(vec3<GLfloat> position);
    Node(mat4<GLfloat> *view, mat4<GLfloat> *projection);
    ~Node();
    void add(std::shared_ptr<Node> node, std::string name);
    virtual void draw();
    virtual void moveBy(GLfloat x, GLfloat y, GLfloat z);
    
protected:
    std::unordered_map<std::string, std::shared_ptr<Node>> subNodes;
    
    mat4<GLfloat> modelMatrix;
    mat4<GLfloat> *viewMatrix;
    mat4<GLfloat> *projectionMatrix;
    
    virtual void setTransformationMatrices(mat4<GLfloat> &model, mat4<GLfloat> *view, mat4<GLfloat> *projection);
    
};
