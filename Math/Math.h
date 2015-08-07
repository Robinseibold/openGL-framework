#ifndef MATH_H
#define MATH_H

#include <openGL/gl3.h>

#include <iostream>
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
    
    vec2<T>& operator += (const vec2<T> &v) {
        x += v.x;
        y += v.y;
        return *this;
    }
    
    vec2<T> operator - () const {
        return vec2(-x, -y);
    }
    
    vec2<T> operator - (const vec2<T> &v) const {
        return vec2(x - v.x, y - v.y);
    }
    
    vec2<T>& operator -= (const vec2<T> &v) {
        x -= v.x;
        y -= v.y;
        return *this;
    }
    
    vec2<T> operator * (T scalar) const {
        return vec2(x * scalar, y * scalar);
    }
    
    T dotProduct(const vec2<T> &v) const {
        return (x * v.x) + (y * v.y);
    }
    
    vec2<T>& normalize() {
        T norm = sqrt((x * x) + (y * y));
        if (norm != 0) {
            x = x / norm;
            y = y / norm;
        }
        return *this;
    }
    
    T* array() {
        return &x;
    }
    
};

template <typename T>
struct vec3 {
    
    T x, y, z;
    
    vec3(T x = 0, T y = 0, T z = 0) : x(x), y(y), z(z) { }
    
    vec3<T>& operator = (const vec3<T> &v) {
        x = v.x;
        y = v.y;
        z = v.z;
        return *this;
    }
    
    vec3<T> operator + (const vec3<T> &v) const {
        return vec3(x + v.x, y + v.y, z + v.z);
    }
    
    vec3<T>& operator += (const vec3<T> &v) {
        x += v.x;
        y += v.y;
        z += v.z;
        return *this;
    }
    
    vec3<T> operator - () const {
        return vec3(-x, -y, -z);
    }
    
    vec3<T> operator - (const vec3<T> &v) const {
        return vec3(x - v.x, y - v.y, z - v.z);
    }
    
    vec3<T>& operator -= (const vec3<T> &v) {
        x -= v.x;
        y -= v.y;
        z -= v.z;
        return *this;
    }
    
    vec3<T> operator * (T scalar) const {
        return vec3(x * scalar, y * scalar, z * scalar);
    }
    
    T dotProduct(const vec3<T> &v) const {
        return (x * v.x) + (y * v.y) + (z * v.z);
    }
    
    vec3<T>& normalize() {
        T norm = sqrt((x * x) + (y * y) + (z * z));
        if (norm != 0) {
            x = x / norm;
            y = y / norm;
            z = z / norm;
        }
        return *this;
    }
    
    vec3<T> crossProduct(const vec3<T> &v) const {
        return vec3(((y * v.z) - (z * v.y)),
                    ((z * v.x) - (x * v.z)),
                    ((x * v.y) - (y * v.x)));
    }
    
    T* array() {
        return &x;
    }
    
};

template <typename T>
struct vec4 {
    
    T x, y, z, w;
    
    vec4(T x = 0, T y = 0, T z = 0, T w = 0) : x(x), y(y), z(z), w(w) { }
    
    vec4<T>& operator = (const vec4<T> &v) {
        x = v.x;
        y = v.y;
        z = v.z;
        w = v.w;
        return *this;
    }
    
    vec4<T> operator + (const vec4<T> &v) const {
        return vec4(x + v.x, y + v.y, z + v.z, w + v.w);
    }
    
    vec4<T>& operator += (const vec4<T> &v) {
        x += v.x;
        y += v.y;
        z += v.z;
        w += v.w;
        return *this;
    }
    
    vec4<T> operator - () const {
        return vec4(-x, -y, -z, -w);
    }
    
    vec4<T> operator - (const vec4<T> &v) const {
        return vec4(x - v.x, y - v.y, z - v.z, w - v.w);
    }
    
    vec4<T>& operator -= (const vec4<T> &v) {
        x -= v.x;
        y -= v.y;
        z -= v.z;
        w -= v.w;
        return *this;
    }
    
    vec4<T> operator * (T scalar) const {
        return vec4(x * scalar, y * scalar, z * scalar, w * scalar);
    }
    
    T dotProduct(const vec3<T> &v) const {
        return (x * v.x) + (y * v.y) + (z * v.z) + (w * v.w);
    }
    
    vec4<T>& normalize() {
        T norm = sqrt((x * x) + (y * y) + (z * z) + (w * w));
        if (norm != 0) {
            x = x / norm;
            y = y / norm;
            z = z / norm;
            w = w / norm;
        }
        return *this;
    }
    
    T* array() {
        return &x;
    }
    
};

template <typename T>
struct mat2 {
    
    T x1, x2;
    T y1, y2;
    
    mat2(T x1 = 1, T y1 = 0,
         T x2 = 0, T y2 = 1) :
         x1(x1), x2(x2),
         y1(y1), y2(y2) { }
    
    T* array() {
        return &x1;
    }
    
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
    
    T* array() {
        return &x1;
    }
    
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
    
    mat4<T>& operator = (const mat4<T> &m) {
        x1 = m.x1; x2 = m.x2; x3 = m.x3; x4 = m.x4;
        y1 = m.y1; y2 = m.y2; y3 = m.y3; y4 = m.y4;
        z1 = m.z1; z2 = m.z2; z3 = m.z3; z4 = m.z4;
        w1 = m.w1; w2 = m.w2; w3 = m.w3; w4 = m.w4;
        return *this;
    }
    
    mat4<T> operator * (T scalar) const {
        return mat4(x1 * scalar, y1 * scalar, z1 * scalar, w1 * scalar,
                    x2 * scalar, y2 * scalar, z2 * scalar, w2 * scalar,
                    x3 * scalar, y3 * scalar, z3 * scalar, w3 * scalar,
                    x4 * scalar, y4 * scalar, z4 * scalar, w4 * scalar);
    }
    
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
    
    mat4<T>& scale(T xScale, T yScale, T zScale) {
        x1 = xScale;
        y2 = yScale;
        z3 = zScale;
        return *this;
    }
    
    mat4<T>& translate(T xTranslation, T yTranslation, T zTranslation) {
        w1 = xTranslation;
        w2 = yTranslation;
        w3 = zTranslation;
        return *this;
    }
    
    mat4<T>& rotateX(T radians) {
        T cosValue = cos(radians);
        T sinValue = sin(radians);
        y2 = cosValue;
        z2 = -sinValue;
        y3 = sinValue;
        z3 = cosValue;
        return *this;
    }
    
    mat4<T>& rotateY(T radians) {
        T cosValue = cos(radians);
        T sinValue = sin(radians);
        x1 = cosValue;
        z1 = sinValue;
        x3 = -sinValue;
        z3 = cosValue;
        return *this;
    }
    
    mat4<T>& rotateZ(T radians) {
        T cosValue = cos(radians);
        T sinValue = sin(radians);
        x1 = cosValue;
        y1 = -sinValue;
        x2 = sinValue;
        y2 = cosValue;
        return *this;
    }
    
    mat4<T>& inverse() {
        T inverseValues[16];
        inverseValues[0] =   (y2 * z3 * w4) - (y2 * z4 * w3) - (z2 * y3 * w4) + (z2 * y4 * w3) + (w2 * y3 * z4) - (w2 * y4 * z3);
        inverseValues[1] =  -(x2 * z3 * w4) + (x2 * z4 * w3) + (z2 * x3 * w4) - (z2 * x4 * w3) - (w2 * x3 * z4) + (w2 * x4 * z3);
        inverseValues[2] =   (x2 * y3 * w4) - (x2 * y4 * w3) - (y2 * x3 * w4) + (y2 * x4 * w3) + (w2 * x3 * y4) - (w2 * x4 * y3);
        inverseValues[3] =  -(x2 * y3 * z4) + (x2 * y4 * z3) + (y2 * x3 * z4) - (y2 * x4 * z3) - (z2 * x3 * y4) + (z2 * x4 * y3);
        inverseValues[4] =  -(y1 * z3 * w4) + (y1 * z4 * w3) + (z1 * y3 * w4) - (z1 * y4 * w3) - (w1 * y3 * z4) + (w1 * y4 * z3);
        inverseValues[5] =   (x1 * z3 * w4) - (x1 * z4 * w3) - (z1 * x3 * w4) + (z1 * x4 * w3) + (w1 * x3 * z4) - (w1 * x4 * z3);
        inverseValues[6] =  -(x1 * y3 * w4) + (x1 * y4 * w3) + (y1 * x3 * w4) - (y1 * x4 * w3) - (w1 * x3 * y4) + (w1 * x4 * y3);
        inverseValues[7] =   (x1 * y3 * z4) - (x1 * y4 * z3) - (y1 * x3 * z4) + (y1 * x4 * z3) + (z1 * x3 * y4) - (z1 * x4 * y3);
        inverseValues[8] =   (y1 * z2 * w4) - (y1 * z4 * w2) - (z1 * y2 * w4) + (z1 * y4 * w2) + (w1 * y2 * z4) - (w1 * y4 * z2);
        inverseValues[9] =  -(x1 * z2 * w4) + (x1 * z4 * w2) + (z1 * x2 * w4) - (z1 * x4 * w2) - (w1 * x2 * z4) + (w1 * x4 * z2);
        inverseValues[10] =  (x1 * y2 * w4) - (x1 * y4 * w2) - (y1 * x2 * w4) + (y1 * x4 * w2) + (w1 * x2 * y4) - (w1 * x4 * y2);
        inverseValues[11] = -(x1 * y2 * z4) + (x1 * y4 * z2) + (y1 * x2 * z4) - (y1 * x4 * z2) - (z1 * x2 * y4) + (z1 * x4 * y2);
        inverseValues[12] = -(y1 * z2 * w3) + (y1 * z3 * w2) + (z1 * y2 * w3) - (z1 * y3 * w2) - (w1 * y2 * z3) + (w1 * y3 * z2);
        inverseValues[13] =  (x1 * z2 * w3) - (x1 * z3 * w2) - (z1 * x2 * w3) + (z1 * x3 * w2) + (w1 * x2 * z3) - (w1 * x3 * z2);
        inverseValues[14] = -(x1 * y2 * w3) + (x1 * y3 * w2) + (y1 * x2 * w3) - (y1 * x3 * w2) - (w1 * x2 * y3) + (w1 * x3 * y2);
        inverseValues[15] =  (x1 * y2 * z3) - (x1 * y3 * z2) - (y1 * x2 * z3) + (y1 * x3 * z2) + (z1 * x2 * y3) - (z1 * x3 * y2);
        
        T determenant = (x1 * inverseValues[0]) + (x2 * inverseValues[4]) + (x3 * inverseValues[8]) + x4 * inverseValues[12];
        if (determenant == 0)
            return *this;
        
        determenant = 1 / determenant;
        for(int i = 0; i != 16; ++i) {
            (&x1)[i] = inverseValues[i] * determenant;
        }
        return *this;
    }
    
    mat4<T>& transpose() {
        std::swap(x2, y1);
        std::swap(x3, z1);
        std::swap(x4, w1);
        std::swap(y3, z2);
        std::swap(y4, w2);
        std::swap(z4, w3);
        return *this;
    }
    
    mat4<T>& orthographicProjection(T left, T right, T bottom, T top, T near, T far) {
        x1 = (T (2)) / (right - left);
        w1 = -((right + left) / (right - left));
        y2 = (T (2)) / (top - bottom);
        w2 = -((top + bottom) / (top - bottom));
        z3 = (T (-2)) / (far - near);
        w3 = -((far + near) / (far - near));
        return *this;
    }
    
    mat4<T>& perspectiveProjection(T fieldOfView, T aspect, T near, T far) {
        T tanValue = tan(fieldOfView / (T (2)));
        x1 = (T (1)) / (aspect * tanValue);
        y2 = (T (1)) / (tanValue);
        z3 = - (far + near) / (far - near);
        z4 = - (T (1));
        w3 = - ((T (2)) * far * near) / (far - near);
        w4 = T (0);
        return *this;
    }
    
    mat4<T>& lookAt(const vec3<T> &right, const vec3<T> &up, const vec3<T> &direction, const vec3<T> &position) {
        vec3<T> negativePosition = -position;
        x1 = right.x;
        y1 = right.y;
        z1 = right.z;
        w1 = right.dotProduct(negativePosition);
        x2 = up.x;
        y2 = up.y;
        z2 = up.z;
        w2 = up.dotProduct(negativePosition);
        x3 = direction.x;
        y3 = direction.y;
        z3 = direction.z;
        w3 = direction.dotProduct(negativePosition);
        return *this;
    }
    
    mat4<T>& lookAt(const vec3<T> &up, const vec3<T> &center, const vec3<T> &position) {
        vec3<T> direction = (position - center).normalize();
        vec3<T> right = up.crossProduct(direction).normalize();
        vec3<T> upNew = direction.crossProduct(right).normalize();
        lookAt(right, upNew, direction, position);
        return *this;
    }
    
    T* array() {
        return &x1;
    }
    
};

struct Vertex {
    
    vec3<GLfloat> position;
    vec3<GLfloat> normal;
    vec2<GLfloat> texCoord;
    
    Vertex() {
        position = vec3<GLfloat>();
        normal = vec3<GLfloat>();
        texCoord = vec2<GLfloat>();
    }
    
    Vertex(GLfloat px, GLfloat py, GLfloat pz, GLfloat nx, GLfloat ny, GLfloat nz, GLfloat tx, GLfloat ty) {
        position = vec3<GLfloat>(px, py, pz);
        normal = vec3<GLfloat>(nx, ny, nz);
        texCoord = vec2<GLfloat>(tx, ty);
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

template <typename T>
vec2<T> operator * (T scalar, const vec2<T> &v) {
    return v * scalar;
}

template <typename T>
vec3<T> operator * (T scalar, const vec3<T> &v) {
    return v * scalar;
}

template <typename T>
vec4<T> operator * (T scalar, const vec4<T> &v) {
    return v * scalar;
}

template <typename T>
mat4<T> operator * (T scalar, const mat4<T> &m) {
    return m * scalar;
}

#endif