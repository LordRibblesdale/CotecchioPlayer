#ifndef VECTOR3
#define VECTOR3

#include <type_traits>
#include <iostream>

template <typename V, typename Enable = void>
class Vector3;

template <typename V>
class Vector3<V, typename std::enable_if_t<std::is_floating_point<V>::value>> {
protected:
    V x = 0;
    V y = 0;
    V z = 0;

public:
   Vector3();
   Vector3(V x, V y, V z);
   Vector3(const Vector3<V>& vec);
   Vector3(Vector3<V>&& vec);
   ~Vector3();

   Vector3<V>& operator=(const Vector3<V>& vec);
   Vector3<V>& operator=(Vector3<V>&& vec);

   Vector3<V> operator+(const Vector3<V>& vec);
   Vector3<V>& operator+=(const Vector3<V>& vec);
   Vector3<V> operator-(const Vector3<V>& vec);
   Vector3<V>& operator-=(const Vector3<V>& vec);
   Vector3<V> operator*(V scalar);
   Vector3<V>& operator*=(V scalar);
   Vector3<V> operator/(V scalar);
   Vector3<V>& operator/=(V scalar);
   /*
   Vector3<V> operator*(V scalar, const Vector3<V>& vec);
   Vector3<V>& operator*=(V scalar, )
   */
   inline friend std::ostream& operator<<(std::ostream& stream, const Vector3<V>& vec) {
      std::cout << typeid(V).name() << std::endl;
      return stream << "Vector3<" << typeid(V).name() << "> {"
                    << vec.getX() << ", "
                    << vec.getY() << ", "
                    << vec.getZ() << "}";
   }

   bool isNull() const;
   double getNorm() const;
   V getSquaredNorm() const;

   Vector3<V> getNormalizedVector() const;
   void normalize();

   V getX() const;
   void setX(V inX);
   V getY() const;
   void setY(V inY);
   V getZ() const;
   void setZ(V inZ);

   /*
   template <typename T, typename std::enable_if_t<std::is_floating_point<T>::value>>
   Vector3<T> castTo();
    */

   static V dotProduct(const Vector3<V>& vec1, const Vector3<V>& vec2);
   static Vector3<V> crossProduct(const Vector3<V>& vec1, const Vector3<V>& vec2);

   // Reflect
   // Refract
};

using FVector3 = Vector3<float>;
using DVector3 = Vector3<double>;

#endif // VECTOR3