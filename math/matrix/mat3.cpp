#include <algorithm>
#include "mat3.hpp"
#include "../math_consts.hpp"

template <typename V>
Matrix3<V, std::enable_if_t<std::is_floating_point<V>::value>>::Matrix3() {
    for (size_t i = 0; i < SIZE; ++i) {
        m[i] = i % LENGTH == 0;
    }
}

template <typename V>
Matrix3<V, std::enable_if_t<std::is_floating_point<V>::value>>::Matrix3(V m00, V m01, V m02, V m10, V m11, V m12, V m20,
                                                                        V m21, V m22) {
    m[0] = m00; m[1] = m01; m[2] = m02;
    m[3] = m10; m[4] = m11; m[5] = m12;
    m[6] = m20; m[7] = m21; m[8] = m22;
}

template <typename V>
Matrix3<V, std::enable_if_t<std::is_floating_point<V>::value>>::Matrix3(V inM[SIZE]) {
    memcpy(m, inM, SIZE * sizeof(V));
}

template<typename V>
Matrix3<V, std::enable_if_t<std::is_floating_point<V>::value>>::~Matrix3() {
    for (V& i : m) {
        i = 0;
    }
}

template<typename V>
Matrix3<V, std::enable_if_t<std::is_floating_point<V>::value>>::Matrix3(const Matrix3<V>& mat) {
    memcpy(m, mat.constData(), SIZE * sizeof(V));
}

template<typename V>
Matrix3<V, std::enable_if_t<std::is_floating_point<V>::value>>::Matrix3(Matrix3<V> &&mat) {
    memmove(m, mat.data(), SIZE * sizeof(V));
}

template<typename V>
Matrix3<V>& Matrix3<V, std::enable_if_t<std::is_floating_point<V>::value>>::operator=(const Matrix3<V> &mat) {
    memcpy(m, mat.constData(), SIZE * sizeof(V));

    return *this;
}

template<typename V>
Matrix3<V> &Matrix3<V, std::enable_if_t<std::is_floating_point<V>::value>>::operator=(Matrix3<V> &&mat) {
    memmove(m, mat.data(), SIZE * sizeof(V));

    return *this;
}

template<typename V>
Matrix3<V> Matrix3<V, std::enable_if_t<std::is_floating_point<V>::value>>::operator+(const Matrix3<V> &mat) {
    Matrix3<V> tmp(*this);

    for (size_t i = 0; i < SIZE; ++i) {
        tmp[i] += mat[i];
    }
    /*
    if (mat.getMatrixType() == matrixType) {
        ---^---
    } else {
        long double div = 1. / LENGTH;
        for (size_t i = 0; i < SIZE; ++i) {
            tmp[i] += mat[LENGTH * (i % LENGTH) + size_t(i * div)];
        }
    }
     */

    return tmp;
}

template<typename V>
Matrix3<V>& Matrix3<V, std::enable_if_t<std::is_floating_point<V>::value>>::operator+=(const Matrix3<V> &mat) {
    for (size_t i = 0; i < SIZE; ++i) {
        m[i] += mat[i];
    }

    return *this;
}

template<typename V>
Matrix3<V> Matrix3<V, std::enable_if_t<std::is_floating_point<V>::value>>::operator-(const Matrix3<V> &mat) {
    Matrix3<V> tmp(*this);

    for (size_t i = 0; i < SIZE; ++i) {
        tmp[i] -= mat[i];
    }

    return tmp;
}

template<typename V>
Matrix3<V>& Matrix3<V, std::enable_if_t<std::is_floating_point<V>::value>>::operator-=(const Matrix3<V> &mat) {
    for (size_t i = 0; i < SIZE; ++i) {
        m[i] -= mat[i];
    }

    return *this;
}

template<typename V>
Matrix3<V> Matrix3<V, std::enable_if_t<std::is_floating_point<V>::value>>::operator*(V scalar) {
    Matrix3<V> tmp(*this);

    for (size_t i = 0; i < SIZE; ++i) {
        tmp[i] *= scalar;
    }

    return tmp;
}

template<typename V>
Matrix3<V> Matrix3<V, std::enable_if_t<std::is_floating_point<V>::value>>::operator*(const Matrix3<V> &mat) {
    // A * B, with A *this and B mat

    Matrix3<V> tmp;

    for (size_t s = 0; s < LENGTH; ++s) {
        for (size_t i = 0; i < LENGTH; ++i) {
            for (size_t j = 0; j < LENGTH; ++j) {
                tmp[s*LENGTH + i] += m[i*LENGTH + j] * mat[i + j*LENGTH];
            }
        }
    }

    return tmp;
}

template<typename V>
Matrix3<V>& Matrix3<V, std::enable_if_t<std::is_floating_point<V>::value>>::operator*=(V scalar) {
    for (V& i : m) {
        i *= scalar;
    }

    return *this;
}

template<typename V>
Matrix3<V>& Matrix3<V, std::enable_if_t<std::is_floating_point<V>::value>>::operator*=(const Matrix3<V> &mat) {
    // A * B, with A *this and B mat
    V newM[SIZE] = {0};

    for (size_t s = 0; s < LENGTH; ++s) {
        for (size_t i = 0; i < LENGTH; ++i) {
            for (size_t j = 0; j < LENGTH; ++j) {
                newM[s*LENGTH + i] += m[i*LENGTH + j] * mat[i + j*LENGTH];
            }
        }
    }

    memmove(m, newM, SIZE * sizeof(V));

    return *this;
}

template<typename V>
Matrix3<V> Matrix3<V, std::enable_if_t<std::is_floating_point<V>::value>>::operator/(V scalar) {
    if (scalar < -MathConsts::FLOATING_EPSILON || scalar > MathConsts::FLOATING_EPSILON) {
        Matrix3<V> tmp(*this);
        V div = 1./scalar;

        for (size_t i = 0; i < SIZE; ++i) {
            tmp[i] *= div;
        }

        return tmp;
    } else {
        // TODO add logger entry
        return *this;
    }
}

template<typename V>
Matrix3<V>& Matrix3<V, std::enable_if_t<std::is_floating_point<V>::value>>::operator/=(V scalar) {
    if (scalar < -MathConsts::FLOATING_EPSILON || scalar > MathConsts::FLOATING_EPSILON) {
        V div = 1./scalar;

        for (V& i : m) {
            i *= div;
        }

        return *this;
    } else {
        // TODO add logger entry
        return *this;
    }
}

template<typename V>
V& Matrix3<V, std::enable_if_t<std::is_floating_point<V>::value>>::operator[](size_t i) {
    return m[i];
}

template<typename V>
V Matrix3<V, std::enable_if_t<std::is_floating_point<V>::value>>::operator[](size_t i) const {
    return m[i];
}

template<typename V>
V* Matrix3<V, std::enable_if_t<std::is_floating_point<V>::value>>::data() {
    return m;
}

template<typename V>
const V* Matrix3<V, std::enable_if_t<std::is_floating_point<V>::value>>::constData() const {
    return m;
}

template<typename V>
bool Matrix3<V, std::enable_if_t<std::is_floating_point<V>::value>>::isNull() const {
    bool areAllNull = false;

    for (V i : m) {
        if (i < -MathConsts::FLOATING_EPSILON || i > MathConsts::FLOATING_EPSILON) {
            areAllNull = false;
        }
    }

    return areAllNull;
}

template<typename V>
void Matrix3<V, std::enable_if_t<std::is_floating_point<V>::value>>::transpose() {
    V newM[SIZE];
    size_t index = 0;

    for (size_t i = 0; i < LENGTH; ++i) {
        for (size_t j = 0; j < LENGTH; ++j) {
            newM[index++] = m[i + j*LENGTH];
        }
    }

    memmove(m, newM, SIZE * sizeof(V));
}

template<typename V>
Matrix3<V> Matrix3<V, std::enable_if_t<std::is_floating_point<V>::value>>::transpose(const Matrix3<V> &mat) {
    V newM[SIZE];
    size_t index = 0;

    for (size_t i = 0; i < LENGTH; ++i) {
        for (size_t j = 0; j < LENGTH; ++j) {
            newM[index++] = mat[i + j*LENGTH];
        }
    }

    return Matrix3<V>(newM);
}


template class Matrix3<float>;
template class Matrix3<double>;
template class Matrix3<long double>;