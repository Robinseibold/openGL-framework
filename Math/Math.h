
#include <math.h>

template <typename T>
struct vec2 {
    
    T x, y;
    
    vec2(T x = 0, T y = 0) : x(x), y(y) { }
    
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
    
    T x, y, z;
    
    vec3(T x = 0, T y = 0, T z = 0) : x(x), y(y), z(z) { }
    
};

template <typename T>
struct vec4 {
    
    T x, y, z, w;
    
    vec4(T x = 0, T y = 0, T z = 0, T w = 0) : x(x), y(y), z(z), w(w) { }
    
};

template <typename T>
struct mat2 {
    
    T x1, x2;
    T y1, y2;
    
    mat2(T x1 = 1, T y1 = 0,
         T x2 = 0, T y2 = 1) :
         x1(x1), x2(x2),
         y1(y1), y2(y2) { }
    
};

template <typename T>
struct mat3 {
    
    T x1, x2, x3;
    T y1, y2, y3;
    T z1, z2, z3;
    
    mat3(T x1 = 1, T y1 = 0, T z1 = 0,
         T x2 = 0, T y2 = 1, T z2 = 0,
         T x3 = 0, T y3 = 0, T z3 = 1) :
         x1(x1), x2(x2), x3(x3),
         y1(y1), y2(y2), y3(y3),
         z1(z1), z2(z2), z3(z3) { }
    
};

template <typename T>
struct mat4 {
    
    T x1, x2, x3, x4;
    T y1, y2, y3, y4;
    T z1, z2, z3, z4;
    T w1, w2, w3, w4;

    mat4(T x1 = 1, T y1 = 0, T z1 = 0, T w1 = 0,
         T x2 = 0, T y2 = 1, T z2 = 0, T w2 = 0,
         T x3 = 0, T y3 = 0, T z3 = 1, T w3 = 0,
         T x4 = 0, T y4 = 0, T z4 = 0, T w4 = 1) :
         x1(x1), x2(x2), x3(x3), x4(x4),
         y1(y1), y2(y2), y3(y3), y4(y4),
         z1(z1), z2(z2), z3(z3), z4(z4),
         w1(w1), w2(w2), w3(w3), w4(w4) { }
    
    vec4<T> operator * (const vec4<T> &v) {
        return vec4<T>(((x1 * v.x) + (y1 * v.y) + (z1 * v.z) + (w1 * v.w)),
                       ((x2 * v.x) + (y2 * v.y) + (z2 * v.z) + (w2 * v.w)),
                       ((x3 * v.x) + (y3 * v.y) + (z3 * v.z) + (w3 * v.w)),
                       ((x4 * v.x) + (y4 * v.y) + (z4 * v.z) + (w4 * v.w)));
    }
    
    mat4<T> operator * (const mat4<T> &m) {
        return mat4<T>(x1 * m.x1 + y1 * m.x2 + z1 * m.x3 + w1 * m.x4,
                       x1 * m.y1 + y1 * m.y2 + z1 * m.y3 + w1 * m.y4,
                       x1 * m.z1 + y1 * m.z2 + z1 * m.z3 + w1 * m.z4,
                       x1 * m.w1 + y1 * m.w2 + z1 * m.w3 + w1 * m.w4,
                       x2 * m.x1 + y2 * m.x2 + z2 * m.x3 + w2 * m.x4,
                       x2 * m.y1 + y2 * m.y2 + z2 * m.y3 + w2 * m.y4,
                       x2 * m.z1 + y2 * m.z2 + z2 * m.z3 + w2 * m.z4,
                       x2 * m.w1 + y2 * m.w2 + z2 * m.w3 + w2 * m.w4,
                       x3 * m.x1 + y3 * m.x2 + z3 * m.x3 + w3 * m.x4,
                       x3 * m.y1 + y3 * m.y2 + z3 * m.y3 + w3 * m.y4,
                       x3 * m.z1 + y3 * m.z2 + z3 * m.z3 + w3 * m.z4,
                       x3 * m.w1 + y3 * m.w2 + z3 * m.w3 + w3 * m.w4,
                       x4 * m.x1 + y4 * m.x2 + z4 * m.x3 + w4 * m.x4,
                       x4 * m.y1 + y4 * m.y2 + z4 * m.y3 + w4 * m.y4,
                       x4 * m.z1 + y4 * m.z2 + z4 * m.z3 + w4 * m.z4,
                       x4 * m.w1 + y4 * m.w2 + z4 * m.w3 + w4 * m.w4);
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
    
    void rotateX(T radians) {
        T cosValue = cos(radians);
        T sinValue = sin(radians);
        y2 = cosValue;
        z2 = -sinValue;
        y3 = sinValue;
        z3 = cosValue;
    }
    
    void rotateY(T radians) {
        T cosValue = cos(radians);
        T sinValue = sin(radians);
        x1 = cosValue;
        z1 = sinValue;
        x3 = -sinValue;
        z3 = cosValue;
    }
    
    void rotateZ(T radians) {
        T cosValue = cos(radians);
        T sinValue = sin(radians);
        x1 = cosValue;
        y1 = -sinValue;
        x2 = sinValue;
        y2 = cosValue;
    }
    
    void orthographicProjection(T left, T right, T bottom, T top, T near, T far) {
        x1 = (T (2)) / (right - left);
        w1 = -((right + left) / (right - left));
        y2 = (T (2)) / (top - bottom);
        w2 = -((top + bottom) / (top - bottom));
        z3 = (T (-2)) / (far - near);
        w3 = -((far + near) / (far - near));
    }
    
    void perspectiveProjection(T fieldOfView, T aspect, T near, T far) {
        T tanValue = tan(fieldOfView / (T (2)));
        x1 = (T (1)) / (aspect * tanValue);
        y2 = (T (1)) / (tanValue);
        z3 = - (far + near) / (far - near);
        z4 = - (T (1));
        w3 = - ((T (2)) * far * near) / (far - near);
        w4 = T (0);
    }
    
    T* array() {
        return &x1;
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

template <typename T>
inline std::ostream& operator << (std::ostream &o, const mat4<T> &m) {
    return o << m.x1 << " " << m.y1 << " " << m.z1 << " " << m.w1 << std::endl
             << m.x2 << " " << m.y2 << " " << m.z2 << " " << m.w2 << std::endl
             << m.x3 << " " << m.y3 << " " << m.z3 << " " << m.w3 << std::endl
             << m.x4 << " " << m.y4 << " " << m.z4 << " " << m.w4 << std::endl;
}

















