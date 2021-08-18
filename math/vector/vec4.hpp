#ifndef VECTOR4
#define VECTOR4

#include <type_traits>
#include <iostream>

template <typename V, typename Enable = void>
class Vector4;

template <typename V>
class Vector4<V, typename std::enable_if_t<std::is_floating_point<V>::value>> {
protected:
    V w = 0;
    V x = 0;
    V y = 0;
    V z = 0;

public:
    Vector4();
    Vector4(V w, V x, V y, V z);
    Vector4(const Vector4<V>& vec);
    Vector4(Vector4<V>&& vec);
    ~Vector4();

    Vector4<V>& operator=(const Vector4<V>& vec);
    Vector4<V>& operator=(Vector4<V>&& vec);

    Vector4<V> operator+(const Vector4<V>& vec);
    Vector4<V>& operator+=(const Vector4<V>& vec);
    Vector4<V> operator-(const Vector4<V>& vec);
    Vector4<V>& operator-=(const Vector4<V>& vec);
    Vector4<V> operator*(V scalar);
    Vector4<V>& operator*=(V scalar);
    Vector4<V> operator/(V scalar);
    Vector4<V>& operator/=(V scalar);
    /*
    Vector4<V> operator*(V scalar, const Vector4<V>& vec);
    Vector4<V>& operator*=(V scalar, )
    */
    inline friend std::ostream& operator<<(std::ostream& stream, const Vector4<V>& vec) {
        std::cout << typeid(V).name() << std::endl;
        return stream << "Vector4<" << typeid(V).name() << "> {"
                      << vec.getW() << ", "
                      << vec.getX() << ", "
                      << vec.getY() << ", "
                      << vec.getZ() << "}";
    }

    bool isNull() const;
    double getNorm() const;
    V getSquaredNorm() const;

    Vector4<V> getNormalizedVector() const;
    void normalize();

    V getW() const;
    void setW(V inW);
    V getX() const;
    void setX(V inX);
    V getY() const;
    void setY(V inY);
    V getZ() const;
    void setZ(V inZ);

    /*
    template <typename T, typename std::enable_if_t<std::is_floating_point<T>::value>>
    Vector4<T> castTo();
     */

    static V dotProduct(const Vector4<V>& vec1, const Vector4<V>& vec2);

    // Reflect
    // Refract
};

using FVector4 = Vector4<float>;
using DVector4 = Vector4<double>;

#endif // VECTOR4