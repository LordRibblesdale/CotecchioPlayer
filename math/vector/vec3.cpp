#include "vec3.hpp"

#include <cmath>

template <typename V>
Vector3<V, std::enable_if_t<std::is_floating_point<V>::value>>::Vector3() : x(0), y(0), z(0) {}

template <typename V>
Vector3<V, std::enable_if_t<std::is_floating_point<V>::value>>::Vector3(V x, V y, V z) : x(x), y(y), z(z) {}

template <typename V>
Vector3<V, std::enable_if_t<std::is_floating_point<V>::value>>::Vector3(const Vector3<V>& vec):
        x(vec.getX()), y(vec.getY()), z(vec.getZ()) {}

template <typename V>
Vector3<V, std::enable_if_t<std::is_floating_point<V>::value>>::Vector3(Vector3<V>&& vec) :
        x(vec.getX()), y(vec.getY()), z(vec.getZ()) {
   vec.setX(0);
   vec.setY(0);
   vec.setZ(0);
}

template <typename V>
Vector3<V, std::enable_if_t<std::is_floating_point<V>::value>>::~Vector3() {
   x = 0;
   y = 0;
   z = 0;
}

template <typename V>
Vector3<V>& Vector3<V, std::enable_if_t<std::is_floating_point<V>::value>>::operator=(const Vector3<V>& vec) {
   x = vec.getX();
   y = vec.getY();
   z = vec.getZ();

   return *this;
}

template <typename V>
Vector3<V>& Vector3<V, std::enable_if_t<std::is_floating_point<V>::value>>::operator=(Vector3<V>&& vec) {
   x = vec.getX();
   y = vec.getY();
   z = vec.getZ();

   vec.setX(0);
   vec.setY(0);
   vec.setZ(0);

   return *this;
}

template <typename V>
Vector3<V> Vector3<V, std::enable_if_t<std::is_floating_point<V>::value>>::operator+(const Vector3<V>& vec) {
   return Vector3<V>(x + vec.getX(),
                     y + vec.getY(),
                     z + vec.getZ());
}

template <typename V>
Vector3<V>& Vector3<V, std::enable_if_t<std::is_floating_point<V>::value>>::operator+=(const Vector3<V>& vec) {
   x += vec.getX();
   y += vec.getY();
   z += vec.getZ();

   return *this;
}

template <typename V>
Vector3<V> Vector3<V, std::enable_if_t<std::is_floating_point<V>::value>>::operator-(const Vector3<V>& vec) {
   return Vector3<V>(x - vec.getX(),
                     y - vec.getY(),
                     z - vec.getZ());
}

template <typename V>
Vector3<V>& Vector3<V, std::enable_if_t<std::is_floating_point<V>::value>>::operator-=(const Vector3<V>& vec) {
   x -= vec.getX();
   y -= vec.getY();
   z -= vec.getZ();

   return *this;
}

template <typename V>
Vector3<V> Vector3<V, std::enable_if_t<std::is_floating_point<V>::value>>::operator*(V scalar) {
   return Vector3<V>(x * scalar,
                     y * scalar,
                     z * scalar);
}

template <typename V>
Vector3<V>& Vector3<V, std::enable_if_t<std::is_floating_point<V>::value>>::operator*=(V scalar) {
   x *= scalar;
   y *= scalar;
   z *= scalar;

   return *this;
}

template <typename V>
Vector3<V> Vector3<V, std::enable_if_t<std::is_floating_point<V>::value>>::operator/(V scalar) {
   if (scalar == 0) {
      // TODO add logger here
      throw scalar;
   } else {
      V division = 1. / scalar;
      return Vector3<V>(x * division,
                        y * division,
                        z * division);
   }
}

template <typename V>
Vector3<V>& Vector3<V, std::enable_if_t<std::is_floating_point<V>::value>>::operator/=(V scalar) {
   if (scalar == 0) {
      throw scalar;
   } else {
      V division = 1. / scalar;

      x *= division;
      y *= division;
      z *= division;

      return *this;
   }
}

template <typename V>
bool Vector3<V, std::enable_if_t<std::is_floating_point<V>::value>>::isNull() const {
   return (x == 0) && (y == 0) && (z == 0);
}

template <typename V>
double Vector3<V, std::enable_if_t<std::is_floating_point<V>::value>>::getNorm() const {
   return std::sqrt(x*x + y*y + z*z);
}

template <typename V>
V Vector3<V, std::enable_if_t<std::is_floating_point<V>::value>>::getSquaredNorm() const {
   return x*x + y*y + z*z;
}

template <typename V>
Vector3<V> Vector3<V, std::enable_if_t<std::is_floating_point<V>::value>>::getNormalizedVector() const {
   double norm = getNorm();

   if (norm == 0) {
      return *this;
   } else {
      double invNorm = 1. / norm;
      return Vector3<V>(x*invNorm, y*invNorm, z*invNorm);
   }
}

template<typename V>
void Vector3<V, std::enable_if_t<std::is_floating_point<V>::value>>::normalize() {
    double norm = getNorm();

    // TODO change with FLOATING_EPSILON
    if (norm != 0) {
        double invNorm = 1. / norm;
        x *= invNorm;
        y *= invNorm;
        z *= invNorm;
    }
}

template <typename V>
V Vector3<V, std::enable_if_t<std::is_floating_point<V>::value>>::getX() const {
   return x;
}

template <typename V>
void Vector3<V, std::enable_if_t<std::is_floating_point<V>::value>>::setX(V inX) {
   x = inX;
}

template <typename V>
V Vector3<V, std::enable_if_t<std::is_floating_point<V>::value>>::getY() const {
   return y;
}

template <typename V>
void Vector3<V, std::enable_if_t<std::is_floating_point<V>::value>>::setY(V inY) {
   y = inY;
}

template <typename V>
V Vector3<V, std::enable_if_t<std::is_floating_point<V>::value>>::getZ() const {
   return z;
}

template <typename V>
void Vector3<V, std::enable_if_t<std::is_floating_point<V>::value>>::setZ(V inZ) {
   z = inZ;
}

/*
template<typename V>
template<typename T, std::enable_if_t<std::is_floating_point<T>::value>>
Vector3<T> Vector3<V, std::enable_if_t<std::is_floating_point<V>::value>>::castTo() {
   return Vector3<T>(dynamic_cast<T>(x), dynamic_cast<T>(y), dynamic_cast<T>(z));
}
 */

template <typename V>
V Vector3<V, std::enable_if_t<std::is_floating_point<V>::value>>::dotProduct(const Vector3<V>& vec1, 
                                                                             const Vector3<V>& vec2) {
   return vec1.getX()*vec2.getX() + vec1.getY()*vec2.getY() + vec1.getZ()*vec2.getZ();
}

template <typename V>
Vector3<V> Vector3<V, std::enable_if_t<std::is_floating_point<V>::value>>::crossProduct(const Vector3<V>& vec1, 
                                                                                        const Vector3<V>& vec2) {
   V outX = vec1.getY()*vec2.getZ() - vec1.getZ()*vec2.getY();
   V outY = vec1.getZ()*vec2.getX() - vec1.getX()*vec2.getZ();
   V outZ = vec1.getX()*vec2.getY() - vec1.getY()*vec2.getX();

   /*
   V v1X = vec1.getX(), v1Y = vec1.getY(), v1Z = vec1.getZ();
   V v2X = vec2.getX(), v2Y = vec2.getY(), v2Z = vec2.getZ();
   V outX = v1Y*v2Z - v1Z*v2Y;
   V outY = v1Z*v2X - v1X*v2Z;
   V outZ = v1X*v2Y - v1Y*v2X;
   */
  
   return Vector3<V>(outX, outY, outZ);
}


template class Vector3<float>;
template class Vector3<double>;
template class Vector3<long double>;