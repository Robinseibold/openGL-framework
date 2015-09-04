
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

float Fluid::constrainValue(float value, int size) {
    if (value < 0.5) {
        return value;
    } else if (value > (size - 0.5)) {
        return (size - 0.5);
    }
    return value;
}

















