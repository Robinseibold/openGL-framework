
#include "Node.h"

Node::Node() { }

Node::Node(vec3<GLfloat> position) {
    modelMatrix.translate(position);
}

Node::Node(mat4<GLfloat> *view, mat4<GLfloat> *projection) : viewMatrix(view), projectionMatrix(projection) { }

Node::~Node() {
    subNodes.clear();
}

void Node::add(std::shared_ptr<Node> node, std::string name) {
    subNodes[name] = node;
    node->setTransformationMatrices(modelMatrix, viewMatrix, projectionMatrix);
}

void Node::draw() {
    for (auto node : subNodes) {
        node.second->draw();
    }
}

void Node::moveBy(GLfloat x, GLfloat y, GLfloat z) {
    modelMatrix.translate(x, y, z);
    for (auto node : subNodes) {
        node.second->moveBy(x, y, z);
    }
}

void Node::setTransformationMatrices(mat4<GLfloat> &model, mat4<GLfloat> *view, mat4<GLfloat> *projection) {
    modelMatrix.translate(model.getTranslationVector());
    modelMatrix.scale(model.getScaleVector());
    viewMatrix = view;
    projectionMatrix = projection;
    for (auto node : subNodes) {
        node.second->setTransformationMatrices(model, view, projection);
    }
}