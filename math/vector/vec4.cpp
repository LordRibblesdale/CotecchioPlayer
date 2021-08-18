#include "vec4.hpp"

#include <cmath>

template <typename V>
Vector4<V, std::enable_if_t<std::is_floating_point<V>::value>>::Vector4() : w(0), x(0), y(0), z(0) {}

template <typename V>
Vector4<V, std::enable_if_t<std::is_floating_point<V>::value>>::Vector4(V w, V x, V y, V z) : w(w), x(x), y(y), z(z) {}

template <typename V>
Vector4<V, std::enable_if_t<std::is_floating_point<V>::value>>::Vector4(const Vector4<V>& vec):
        w(vec.getW()), x(vec.getX()), y(vec.getY()), z(vec.getZ()) {}

template <typename V>
Vector4<V, std::enable_if_t<std::is_floating_point<V>::value>>::Vector4(Vector4<V>&& vec) :
        w(vec.getW()), x(vec.getX()), y(vec.getY()), z(vec.getZ()) {
    vec.setW(0);
    vec.setX(0);
    vec.setY(0);
    vec.setZ(0);
}

template <typename V>
Vector4<V, std::enable_if_t<std::is_floating_point<V>::value>>::~Vector4() {
    w = 0;
    x = 0;
    y = 0;
    z = 0;
}

template <typename V>
Vector4<V>& Vector4<V, std::enable_if_t<std::is_floating_point<V>::value>>::operator=(const Vector4<V>& vec) {
    w = vec.getW();
    x = vec.getX();
    y = vec.getY();
    z = vec.getZ();

    return *this;
}

template <typename V>
Vector4<V>& Vector4<V, std::enable_if_t<std::is_floating_point<V>::value>>::operator=(Vector4<V>&& vec) {
    w = vec.getW();
    x = vec.getX();
    y = vec.getY();
    z = vec.getZ();

    vec.setW(0);
    vec.setX(0);
    vec.setY(0);
    vec.setZ(0);

    return *this;
}

template <typename V>
Vector4<V> Vector4<V, std::enable_if_t<std::is_floating_point<V>::value>>::operator+(const Vector4<V>& vec) {
    return Vector4<V>(w + vec.getW(),
                      x + vec.getX(),
                      y + vec.getY(),
                      z + vec.getZ());
}

template <typename V>
Vector4<V>& Vector4<V, std::enable_if_t<std::is_floating_point<V>::value>>::operator+=(const Vector4<V>& vec) {
    w += vec.getW();
    x += vec.getX();
    y += vec.getY();
    z += vec.getZ();

    return *this;
}

template <typename V>
Vector4<V> Vector4<V, std::enable_if_t<std::is_floating_point<V>::value>>::operator-(const Vector4<V>& vec) {
    return Vector4<V>(w - vec.getW(),
                      x - vec.getX(),
                      y - vec.getY(),
                      z - vec.getZ());
}

template <typename V>
Vector4<V>& Vector4<V, std::enable_if_t<std::is_floating_point<V>::value>>::operator-=(const Vector4<V>& vec) {
    w -= vec.getW();
    x -= vec.getX();
    y -= vec.getY();
    z -= vec.getZ();

    return *this;
}

template <typename V>
Vector4<V> Vector4<V, std::enable_if_t<std::is_floating_point<V>::value>>::operator*(V scalar) {
    return Vector4<V>(w * scalar,
                      x * scalar,
                      y * scalar,
                      z * scalar);
}

template <typename V>
Vector4<V>& Vector4<V, std::enable_if_t<std::is_floating_point<V>::value>>::operator*=(V scalar) {
    w *= scalar;
    x *= scalar;
    y *= scalar;
    z *= scalar;

    return *this;
}

template <typename V>
Vector4<V> Vector4<V, std::enable_if_t<std::is_floating_point<V>::value>>::operator/(V scalar) {
    if (scalar == 0) {
        // TODO add logger here
        throw scalar;
    } else {
        V division = 1. / scalar;
        return Vector4<V>(w * division,
                          x * division,
                          y * division,
                          z * division);
    }
}

template <typename V>
Vector4<V>& Vector4<V, std::enable_if_t<std::is_floating_point<V>::value>>::operator/=(V scalar) {
    if (scalar == 0) {
        throw scalar;
    } else {
        V division = 1. / scalar;

        w *= division;
        x *= division;
        y *= division;
        z *= division;

        return *this;
    }
}

template <typename V>
bool Vector4<V, std::enable_if_t<std::is_floating_point<V>::value>>::isNull() const {
    return (w == 0) && (x == 0) && (y == 0) && (z == 0);
}

template <typename V>
double Vector4<V, std::enable_if_t<std::is_floating_point<V>::value>>::getNorm() const {
    return std::sqrt(w*w + x*x + y*y + z*z);
}

template <typename V>
V Vector4<V, std::enable_if_t<std::is_floating_point<V>::value>>::getSquaredNorm() const {
    return w*w + x*x + y*y + z*z;
}

template <typename V>
Vector4<V> Vector4<V, std::enable_if_t<std::is_floating_point<V>::value>>::getNormalizedVector() const {
    double norm = getNorm();

    if (norm == 0) {
        return *this;
    } else {
        double invNorm = 1. / norm;
        return Vector4<V>(w*invNorm, x*invNorm, y*invNorm, z*invNorm);
    }
}

template<typename V>
void Vector4<V, std::enable_if_t<std::is_floating_point<V>::value>>::normalize() {
    double norm = getNorm();

    // TODO change with FLOATING_EPSILON
    if (norm != 0) {
        double invNorm = 1. / norm;
        x *= invNorm;
        y *= invNorm;
        z *= invNorm;
        w *= invNorm;
    }
}

template <typename V>
V Vector4<V, std::enable_if_t<std::is_floating_point<V>::value>>::getW() const {
    return w;
}

template <typename V>
void Vector4<V, std::enable_if_t<std::is_floating_point<V>::value>>::setW(V inW) {
    w = inW;
}

template <typename V>
V Vector4<V, std::enable_if_t<std::is_floating_point<V>::value>>::getX() const {
    return x;
}

template <typename V>
void Vector4<V, std::enable_if_t<std::is_floating_point<V>::value>>::setX(V inX) {
    x = inX;
}

template <typename V>
V Vector4<V, std::enable_if_t<std::is_floating_point<V>::value>>::getY() const {
    return y;
}

template <typename V>
void Vector4<V, std::enable_if_t<std::is_floating_point<V>::value>>::setY(V inY) {
    y = inY;
}

template <typename V>
V Vector4<V, std::enable_if_t<std::is_floating_point<V>::value>>::getZ() const {
    return z;
}

template <typename V>
void Vector4<V, std::enable_if_t<std::is_floating_point<V>::value>>::setZ(V inZ) {
    z = inZ;
}

/*
template<typename V>
template<typename T, std::enable_if_t<std::is_floating_point<T>::value>>
Vector4<T> Vector4<V, std::enable_if_t<std::is_floating_point<V>::value>>::castTo() {
   return Vector4<T>(dynamic_cast<T>(x), dynamic_cast<T>(y), dynamic_cast<T>(z));
}
 */

template <typename V>
V Vector4<V, std::enable_if_t<std::is_floating_point<V>::value>>::dotProduct(const Vector4<V>& vec1,
                                                                             const Vector4<V>& vec2) {
    return vec1.getW()* vec2.getW() + vec1.getX()*vec2.getX() + vec1.getY()*vec2.getY() + vec1.getZ()*vec2.getZ();
}

template class Vector4<float>;
template class Vector4<double>;
template class Vector4<long double>;