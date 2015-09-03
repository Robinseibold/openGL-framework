
#define INDEX(x, y, z) ((x) + ((y) * xSize) + ((z) * xSize * ySize))

class Fluid {
    
public:
    Fluid(int xSize, int ySize, int zSize);
    ~Fluid();
    
private:
    float *xVelocity, *xVelocityPrevious;
    float *yVelocity, *yVelocityPrevious;
    float *zVelocity, *zVelocityPrevious;
    
    float *density, *densityPrevious;
    
    int xSize, ySize, zSize;
    int volume;
    
    int numberOfIterations = 20;
    float deltaTime = 0.1;
    float diffusion = 0.0001;
    float viscosity = 0.0001;
    
    
    void addSource(float *destination, float *source);
    void diffuse(float *current, float *previous, float propertyValue);
    
};