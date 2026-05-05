#include <iostream>
#include "vector_utils.hpp"

int main(int argc, char** argv) {
    std::cout << "Hello from " << argv[0] << std::endl;
    int *p = new int(42);
    std::cout << "Current value of p: " << *p << std::endl;
    *p = -10;
    std::cout << "Value of p after change: " << *p << std::endl;
    delete p;
    p = nullptr;

    // Create array of square numbers on the heap
    int* arr = new int[5];
    for(size_t i=0;i<5;i++) {
        arr[i] = i * i;
    };

    // Print out the array values
    std::cout << "Content of arr:";
    for(size_t i = 0;i<5;i++) {
        std::cout << " " << arr[i];
    }
    std::cout << std::endl;

    // Delete the array and free memory
    delete[] arr;
    
    Vector3<float>* v = allocateVector3();
    std::cout << "Here is the allocated vector " << *v << std::endl;
    freeVector3(&v);
    return 0;
}