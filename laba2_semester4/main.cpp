#include <iostream>
#include "matrix.h"

int main() {
    srand(time(0));

    Matrix matrix1(2, 3);
    matrix1.fillRandom();
    std::cout << "Matrix 1:" << std::endl;
    std::cout << matrix1 << std::endl;

    Matrix matrix2(2, 3);
    matrix2.fillRandom();
    std::cout << "Matrix 2:" << std::endl;
    std::cout << matrix2 << std::endl;

    std::cout << "Sum of Matrix 1 and Matrix 2:" << std::endl;
    Matrix sum = matrix1 + matrix2;
    std::cout << sum << std::endl;

    std::cout << "Difference of Matrix 1 and Matrix 2:" << std::endl;
    Matrix difference = matrix1 - matrix2;
    std::cout << difference << std::endl;

    std::cout << "Product of Matrix 1 and Matrix 2:" << std::endl;
    Matrix product = matrix1 * matrix2;
    std::cout << product << std::endl;

    return 0;
}