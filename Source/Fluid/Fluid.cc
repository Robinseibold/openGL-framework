
#include "Fluid.h"

Fluid::Fluid(int xSize, int ySize, int zSize) : xSize(xSize - 1), ySize(ySize - 1), zSize(zSize - 1), volume(xSize * ySize * zSize) {
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

void Fluid::diffuse(float *current, float *previous, float propertyValue) {
    float rate = deltaTime * propertyValue * xSize * ySize * zSize;
    float reciprocalMultipliedRate = 1 / (1 + (6 * rate));
    
    for (int iteration = 0; iteration != numberOfIterations; ++iteration) {
        for (int x = 1; x != xSize; ++x) {
            for (int y = 1; y != ySize; ++y) {
                for (int z = 1; z != zSize; ++z) {
                    float neighbourValues = current[INDEX(x - 1, y, z)] + current[INDEX(x + 1, y, z)] +
                                            current[INDEX(x, y - 1, z)] + current[INDEX(x, y + 1, z)] +
                                            current[INDEX(x, y, z - 1)] + current[INDEX(x, y, z - 1)];
                    current[INDEX(x, y, z)] = reciprocalMultipliedRate * (previous[INDEX(x, y, z)] + (rate * neighbourValues));
                }
            }
        }
    }
}

void Fluid::advect(float *current, float *previous, float *xDirection, float *yDirection, float *zDirection) {
    float xDeltaTimeRate = xSize * deltaTime;
    float yDeltaTimeRate = ySize * deltaTime;
    float zDeltaTimeRate = zSize * deltaTime;
    
    for (int x = 1; x != xSize; ++x) {
        for (int y = 1; y != ySize; ++y) {
            for (int z = 1; z != zSize; ++z) {
                float xPosition = constrainValue((x - (xDeltaTimeRate * xDirection[INDEX(x, y, z)])), xSize);
                float yPosition = constrainValue((y - (yDeltaTimeRate * yDirection[INDEX(x, y, z)])), ySize);
                float zPosition = constrainValue((z - (zDeltaTimeRate * zDirection[INDEX(x, y, z)])), zSize);
                
                int fromX = int (xPosition);
                int fromY = int (yPosition);
                int fromZ = int (zPosition);
                
                float deltaX = xPosition - fromX;
                float deltaY = yPosition - fromY;
                float deltaZ = zPosition - fromZ;

                current[INDEX(x, y, z)] = (1 - deltaX) * (((1 - deltaY) * (1 - deltaZ) * previous[INDEX(fromX, fromY, fromZ)]) +
                                                          (deltaY * (1 - deltaZ) * previous[INDEX(fromX, (fromY + 1), fromZ)]) +
                                                          ((1 - deltaY) * deltaZ * previous[INDEX(fromX, fromY, (fromZ + 1))]) +
                                                          (deltaY * deltaZ * previous[INDEX(fromX, (fromY + 1), (fromZ + 1))])) +
                                                deltaX * (((1 - deltaY) * (1 - deltaZ) * previous[INDEX((fromX + 1), fromY, fromZ)]) +
                                                          (deltaY * (1 - deltaZ) * previous[INDEX((fromX + 1), (fromY + 1), fromZ)]) +
                                                          ((1 - deltaY) * deltaZ * previous[INDEX((fromX + 1), fromY, (fromZ + 1))]) +
                                                          (deltaY * deltaZ * previous[INDEX((fromX + 1), (fromY + 1), (fromZ + 1))]));
            }
        }
    }
}

void Fluid::checkBounds(float *current, int bound) {
    int x, y, z;
    
    z = zSize + 1;
    for (x = 1; x != xSize; ++x) {
        for (y = 1; y != ySize; ++y) {
            current[INDEX(x, y, 0)] = (bound == 3) ? (-current[INDEX(x, y, 1)]) : (current[INDEX(x, y, 1)]);
            current[INDEX(x, y, z)] = (bound == 3) ? (-current[INDEX(x, y, z)]) : (current[INDEX(x, y, z)]);
        }
    }
    
    y = ySize + 1;
    for (x = 1; x != xSize; ++x) {
        for (z = 1; z != zSize; ++z) {
            current[INDEX(x, 0, z)] = (bound == 2) ? (-current[INDEX(x, 1, z)]) : (current[INDEX(x, 1, z)]);
            current[INDEX(x, y, z)] = (bound == 2) ? (-current[INDEX(x, y, z)]) : (current[INDEX(x, y, z)]);
        }
    }
    
    x = xSize + 1;
    for (y = 1; y != ySize; ++y) {
        for (z = 1; z != zSize; ++z) {
            current[INDEX(0, y, z)] = (bound == 1) ? (-current[INDEX(1, y, z)]) : (current[INDEX(1, y, z)]);
            current[INDEX(x, y, z)] = (bound == 1) ? (-current[INDEX(x, y, z)]) : (current[INDEX(x, y, z)]);
        }
    }
    
    y = ySize + 1;
    z = zSize + 1;
    float rate = (1.0 / 3.0);
    current[INDEX(0, 0, 0)] = rate * (current[INDEX(1, 0, 0)] + current[INDEX(0, 1, 0)] + current[INDEX(0, 0, 1)]);
    current[INDEX(x, 0, 0)] = rate * (current[INDEX(x, 0, 0)] + current[INDEX(x, 1, 0)] + current[INDEX(x, 0, 1)]);
    current[INDEX(0, y, 0)] = rate * (current[INDEX(0, y, 0)] + current[INDEX(1, y, 0)] + current[INDEX(0, y, 1)]);
    current[INDEX(0, 0, z)] = rate * (current[INDEX(0, 0, z)] + current[INDEX(1, 0, z)] + current[INDEX(0, 1, z)]);
    current[INDEX(x, y, 0)] = rate * (current[INDEX(xSize, y, 0)] + current[INDEX(x, ySize, 0)] + current[INDEX(x, y, 1)]);
    current[INDEX(x, 0, z)] = rate * (current[INDEX(xSize, 0, z)] + current[INDEX(x, 0, zSize)] + current[INDEX(x, 1, z)]);
    current[INDEX(0, y, z)] = rate * (current[INDEX(0, ySize, z)] + current[INDEX(0, y, zSize)] + current[INDEX(1, y, z)]);
    current[INDEX(x, y, z)] = rate * (current[INDEX(xSize, y, z)] + current[INDEX(x, ySize, z)] + current[INDEX(x, y, zSize)]);
}

float Fluid::constrainValue(float value, int size) {
    if (value < 0.5) {
        return value;
    } else if (value > (size - 0.5)) {
        return (size - 0.5);
    }
    return value;
}

















