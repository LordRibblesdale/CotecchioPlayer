#ifndef MATRIX3
#define MATRIX3

#include <type_traits>
#include <iostream>

// TODO check how to manage row-major and column-major
/*
enum MatrixType {
    ROW_MAJOR,
    COLUMN_MAJOR
};
 */

template <typename V, typename Enable = void>
class Matrix3;

template <typename V>
class Matrix3<V, typename std::enable_if_t<std::is_floating_point<V>::value>> {
private:
    const static size_t LENGTH = 3;
    const static size_t SIZE = 9;

protected:
    V m[SIZE] = {0};
    // MatrixType matrixType;

public:
    Matrix3();
    Matrix3(V m00, V m01, V m02, V m10, V m11, V m12, V m20, V m21, V m22);
    // Matrix3(V m00, V m01, V m02, V m10, V m11, V m12, V m20, V m21, V m22, MatrixType matrixType);
    Matrix3(V inM[SIZE]);
    // Matrix3(V inM[SIZE], MatrixType matrixType);
    Matrix3(const Matrix3<V>& mat);
    Matrix3(Matrix3<V>&& mat);
    ~Matrix3();

    Matrix3<V>& operator=(const Matrix3<V>& mat);
    Matrix3<V>& operator=(Matrix3<V>&& mat);

    Matrix3<V> operator+(const Matrix3<V>& mat);
    Matrix3<V>& operator+=(const Matrix3<V>& mat);
    Matrix3<V> operator-(const Matrix3<V>& mat);
    Matrix3<V>& operator-=(const Matrix3<V>& mat);
    Matrix3<V> operator*(V scalar);
    Matrix3<V> operator*(const Matrix3<V>& mat);
    Matrix3<V>& operator*=(V scalar);
    Matrix3<V>& operator*=(const Matrix3<V>& mat);
    Matrix3<V> operator/(V scalar);
    Matrix3<V>& operator/=(V scalar);
    inline friend std::ostream& operator<<(std::ostream& stream, const Matrix3<V>& mat) {
        stream << "Matrix3<" << typeid(V).name() << "> {";
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
    static Matrix3<V> transpose(const Matrix3<V>& mat);
};

using FMatrix3 = Matrix3<float>;
using DMatrix3 = Matrix3<double>;

#endif // MATRIX3