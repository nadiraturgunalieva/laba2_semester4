#include "matrix.h"
#include <cstdlib>


Matrix::Matrix(unsigned int rows, unsigned int columns) : m(rows), n(columns) {
    data = new int* [m];
    for (unsigned int i = 0; i < m; ++i) {
        data[i] = new int[n];
    }
}

Matrix::~Matrix() {
    for (unsigned int i = 0; i < m; ++i) {
        delete[] data[i];
    }
    delete[] data;
}

int* Matrix::operator[](unsigned int i) {
    return data[i];
}

void Matrix::fillRandom() {
    for (unsigned int i = 0; i < m; ++i) {
        for (unsigned int j = 0; j < n; ++j) {
            data[i][j] = rand() % 10;
        }
    }
}

Matrix Matrix::operator+(const Matrix& other) {
    if (m == other.m || n == other.n) {
        Matrix result(m, n);
        for (unsigned int i = 0; i < m; ++i) {
            for (unsigned int j = 0; j < n; ++j) {
                result[i][j] = data[i][j] + other.data[i][j];
            }
        }
        return result;
    }
    else std::cout << "Matrix dimensions do not match! \n";
}

Matrix Matrix::operator-(const Matrix& other) {
    if (m == other.m || n == other.n) {
        Matrix result(m, n);
        for (unsigned int i = 0; i < m; ++i) {
            for (unsigned int j = 0; j < n; ++j) {
                result[i][j] = data[i][j] - other.data[i][j];
            }
        }
        return result;
    }
    else std::cout << "Matrix dimensions do not match! \n";
}

Matrix Matrix::operator*(const Matrix& other) {
    if (n == other.m) {
        Matrix result(m, other.n);
        for (unsigned int i = 0; i < m; ++i) {
            for (unsigned int j = 0; j < other.n; ++j) {
                result[i][j] = 0;
                for (unsigned int k = 0; k < n; ++k) {
                    result[i][j] += data[i][k] * other.data[k][j];
                }
            }
        }
        return result;
    }
    else std::cout << "The number of columns of Matrix 1 does not match the number of rows of Matrix 2! \n";
    // ��������� ��������, ������ ���� ���������� �������� � ������ ������� ����� ����� ����� �� ������
}

Matrix& Matrix::operator+=(const Matrix& other) {
    if (m == other.m || n == other.n) {
        for (unsigned int i = 0; i < m; ++i) {
            for (unsigned int j = 0; j < n; ++j) {
                data[i][j] += other.data[i][j];
            }
        }
        return *this;
    }
    else std::cout << "Matrix dimensions do not match! \n";
}

Matrix& Matrix::operator-=(const Matrix& other) {
    if (m == other.m || n == other.n) {
        for (unsigned int i = 0; i < m; ++i) {
            for (unsigned int j = 0; j < n; ++j) {
                data[i][j] -= other.data[i][j];
            }
        }
        return *this;
    }
    else std::cout << "Matrix dimensions do not match! \n";
}

bool Matrix::operator==(const Matrix& other) {
    if (m != other.m || n != other.n) {
        return false;
    }

    for (unsigned int i = 0; i < m; ++i) {
        for (unsigned int j = 0; j < n; ++j) {
            if (data[i][j] != other.data[i][j]) {
                return false;
            }
        }
    }
    return true;
}

bool Matrix::operator!=(const Matrix& other) {
    return !(*this == other);
}

std::ostream& operator<<(std::ostream& out, const Matrix& matrix) {
    for (unsigned int i = 0; i < matrix.m; ++i) {
        for (unsigned int j = 0; j < matrix.n; ++j) {
            out << matrix.data[i][j] << " ";
        }
        out << std::endl;
    }
    return out;
}
