
#include "Fluid.h"

Fluid::Fluid(int xSize, int ySize, int zSize) : xSize(xSize), ySize(ySize), zSize(zSize), volume(xSize * ySize * zSize) {
    xVelocity = new float[volume];
    xVelocityPrevious = new float[volume];
    
    yVelocity = new float[volume];
    yVelocityPrevious = new float[volume];
    
    zVelocity = new float[volume];
    zVelocityPrevious = new float[volume];
    
    density = new float[volume];
    densityPrevious = new float[volume];
}

Fluid::~Fluid() {
    delete [] xVelocity;
    delete [] xVelocityPrevious;
    
    delete [] yVelocity;
    delete [] yVelocityPrevious;
    
    delete [] zVelocity;
    delete [] zVelocityPrevious;
    
    delete [] density;
    delete [] densityPrevious;
}

void Fluid::addSource(float *destination, float *source) {
    for (int i = 0; i != volume; ++i) {
        destination[i] += source[i] * deltaTime;
    }
}