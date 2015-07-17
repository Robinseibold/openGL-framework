
template <typename T>
struct vec2 {
    
    T x, y;
    
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
    T x, y, z;
};

template <typename T>
struct vec4 {
    T x, y, z, w;
};

template <typename T>
struct mat2 {
    T x1, y1;
    T x2, y2;
};

template <typename T>
struct mat3 {
    T x1, y1, z1;
    T x2, y2, z2;
    T x3, y3, z3;
};

template <typename T>
struct mat4 {
    T x1, y1, z1, w1;
    T x2, y2, z2, w2;
    T x3, y3, z3, w3;
    T x4, y4, z4, w4;
};

template <typename T>
inline std::ostream& operator << (std::ostream &o, const vec2<T> &v) {
    return o << "(" << v.x << ", " << v.y << ")";
}




















