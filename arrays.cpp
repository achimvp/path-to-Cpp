#include <iostream>
#include "vector_utils.hpp"

int main() {
    Vector3<int> numbers1(1, 3, 4);
    Vector3<int> numbers2(1, 2, 3);
    std::cout << "Numbers: ";
    std::cout << numbers1 << std::endl;

    float dotProd = dot(numbers1, numbers2);
    std::cout << "Dot product is: " << dotProd << std::endl;

    float length1 = length(numbers1);
    std::cout << "Length of numbers1: " << length1 << std::endl;

    Vector3 a(1.0l, 2.0l, 3.0l);
    Vector3 b(4.0l, 5.0l, 6.0l);
    std::cout << a + b << std::endl;
    std::cout << a - b << std::endl;
    std::cout << a * 2.0l << std::endl;
    std::cout << 2.0l * a << std::endl;

}