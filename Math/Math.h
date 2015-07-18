
#include <math.h>

template <typename T>
struct vec2 {
    
    T x = 0, y = 0;
    
    vec2(T x, T y) : x(x), y(y) { }
    
    vec2<T>& operator = (const vec2<T> &v) {
        x = v.x;
        y = v.y;
        return *this;
    }
    
    vec2<T> operator + (const vec2<T> &v) const {
        return vec2(x + v.x, y + v.y);
    }
    
};

template <typename T>
struct vec3 {
    
    T x = 0, y = 0, z = 0;
    
    vec3(T x, T y, T z) : x(x), y(y), z(z) { }
    
};

template <typename T>
struct vec4 {
    
    T x = 0, y = 0, z = 0, w = 0;
    
    vec4(T x, T y, T z, T w) : x(x), y(y), z(z), w(w) { }
    
};

template <typename T>
struct mat2 {
    
    T x1 = 1, y1 = 0;
    T x2 = 0, y2 = 1;
    
};

template <typename T>
struct mat3 {
    
    T x1 = 1, y1 = 0, z1 = 0;
    T x2 = 0, y2 = 1, z2 = 0;
    T x3 = 0, y3 = 0, z3 = 1;
    
};

template <typename T>
struct mat4 {
    
    T x1 = 1, y1 = 0, z1 = 0, w1 = 0;
    T x2 = 0, y2 = 1, z2 = 0, w2 = 0;
    T x3 = 0, y3 = 0, z3 = 1, w3 = 0;
    T x4 = 0, y4 = 0, z4 = 0, w4 = 1;
    
    vec4<T> operator * (const vec4<T> &v) {
        return vec4<T>(((x1 * v.x) + (y1 * v.y) + (z1 * v.z) + (w1 * v.w)),
                       ((x2 * v.x) + (y2 * v.y) + (z2 * v.z) + (w2 * v.w)),
                       ((x3 * v.x) + (y3 * v.y) + (z3 * v.z) + (w3 * v.w)),
                       ((x4 * v.x) + (y4 * v.y) + (z4 * v.z) + (w4 * v.w)));
    }
    
    void scale(T xScale, T yScale, T zScale) {
        x1 = xScale;
        y2 = yScale;
        z3 = zScale;
    }
    
    void translate(T xTranslation, T yTranslation, T zTranslation) {
        w1 = xTranslation;
        w2 = yTranslation;
        w3 = zTranslation;
    }
    
    void rotateX(double radians) {
        double cosValue = cos(radians);
        double sinValue = sin(radians);
        y2 = cosValue;
        z2 = -sinValue;
        y3 = sinValue;
        z3 = cosValue;
    }
    
    void rotateY(double radians) {
        double cosValue = cos(radians);
        double sinValue = sin(radians);
        x1 = cosValue;
        z1 = sinValue;
        x3 = -sinValue;
        z3 = cosValue;
    }
    
    void rotateZ(double radians) {
        double cosValue = cos(radians);
        double sinValue = sin(radians);
        x1 = cosValue;
        y1 = -sinValue;
        x2 = sinValue;
        y2 = cosValue;
    }
    
};

template <typename T>
inline std::ostream& operator << (std::ostream &o, const vec2<T> &v) {
    return o << "(" << v.x << ", " << v.y << ")";
}

template <typename T>
inline std::ostream& operator << (std::ostream &o, const vec3<T> &v) {
    return o << "(" << v.x << ", " << v.y << ", " << v.z << ")";
}

template <typename T>
inline std::ostream& operator << (std::ostream &o, const vec4<T> &v) {
    return o << "(" << v.x << ", " << v.y << ", " << v.z << ", " << v.w << ")";
}



















