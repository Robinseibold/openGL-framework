
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
    
    int iterations = 20;
    float deltaTime = 0.1;
    
    
    void addSource(float *destination, float *source);
    
};
