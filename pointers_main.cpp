#include <iostream>
#include "pointers.hpp"

int main() {
    std::cout << "Hello pointers!" << std::endl;
    int x = 42;
    std::cout << "Address of x is: " << &x << "\n";
    std::cout << "Value of x is: " << x << std::endl;
    int* p = &x;
    std::cout << "Update value via pointer..." << std::endl;
    *p = 100;
    std::cout << "Address of x after update is: " << &x << "\n";
    std::cout << "Updated value of x is: " << x << std::endl;

    int a = 5, b = 10;
    std::cout << "Values of a and b before swap: " << a << ", " << b << std::endl;
    pointers::swap(&a, &b);
    std::cout << "Values of a and b after swap: " << a << ", " << b << std::endl;

    int arr[5] = {3, 5, 10, -42, 66};
    int sum = 0;
    for(size_t i = 0;i<5;i++){
        sum += *(arr + i);
    }
    std::cout << "Sum of values in array is: " << sum << std::endl;
    return 0;
}