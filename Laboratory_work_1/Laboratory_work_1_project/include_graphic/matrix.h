// matrix.h
// This file is a header for "matrix.cpp" file

#ifndef MATRIX_H

#define MATRIX_H

#include <iostream>
#include <string>

using namespace std;

// ---------- Matrix ----------

template <typename T>
class Matrix
{
private:
    T **a;
    const size_t n, m;
    string printOutOfBound(string ij, size_t ij_val);

public:
    Matrix(size_t n_row, size_t m_column);
    Matrix(const Matrix& clonner);
    ~Matrix();
    T get(size_t i, size_t j);
    void set(T value, size_t i, size_t j);
    static Matrix multiply(const Matrix& one, const Matrix& two);
    static Matrix add(const Matrix& one, const Matrix& two);
    Matrix multiply(const Matrix& other) const;
    Matrix add(const Matrix& other) const;
    string toString();
    string str();
};

#endif // MATRIX_H