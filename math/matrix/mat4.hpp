#ifndef MATRIX4
#define MATRIX4

#include <type_traits>
#include <iostream>

/*
    V m00, m01, m02, m03,
      m10, m11, m12, m13,
      m20, m21, m22, m23,
      m30, m31, m32, m33;
 */

// TODO create generic matrix

template <typename V, typename Enable = void>
class Matrix4;

template <typename V>
class Matrix4<V, typename std::enable_if_t<std::is_floating_point<V>::value>> {
private:
    const static size_t LENGTH = 4;
    const static size_t SIZE = 16;

protected:
    V m[SIZE] = {0};
    // MatrixType matrixType;

public:
    Matrix4();
    Matrix4(V m00, V m01, V m02, V m03, V m10, V m11, V m12, V m13, V m20, V m21, V m22, V m23, V m30, V m31, V m32, V m33);
    // Matrix4(V m00, V m01, V m02, V m10, V m11, V m12, V m20, V m21, V m22, MatrixType matrixType);
    Matrix4(V inM[SIZE]);
    // Matrix4(V inM[SIZE], MatrixType matrixType);
    Matrix4(const Matrix4<V>& mat);
    Matrix4(Matrix4<V>&& mat);
    ~Matrix4();

    Matrix4<V>& operator=(const Matrix4<V>& mat);
    Matrix4<V>& operator=(Matrix4<V>&& mat);

    Matrix4<V> operator+(const Matrix4<V>& mat);
    Matrix4<V>& operator+=(const Matrix4<V>& mat);
    Matrix4<V> operator-(const Matrix4<V>& mat);
    Matrix4<V>& operator-=(const Matrix4<V>& mat);
    Matrix4<V> operator*(V scalar);
    Matrix4<V> operator*(const Matrix4<V>& mat);
    Matrix4<V>& operator*=(V scalar);
    Matrix4<V>& operator*=(const Matrix4<V>& mat);
    Matrix4<V> operator/(V scalar);
    Matrix4<V>& operator/=(V scalar);
    inline friend std::ostream& operator<<(std::ostream& stream, const Matrix4<V>& mat) {
        stream << "Matrix4<" << typeid(V).name() << "> {";
        for (size_t i = 0; i < SIZE; ++i) {
            stream << mat[i] << (i != SIZE-1 ? ", " : "}");
        }

        return stream;
    }

    V& operator[](size_t i);
    V operator[](size_t i) const;
    V* data();
    const V* constData() const;

    bool isNull() const;
    void transpose();
    static Matrix4<V> transpose(const Matrix4<V>& mat);
};

using FMatrix4 = Matrix4<float>;
using DMatrix4 = Matrix4<double>;


#endif // MATRIX4