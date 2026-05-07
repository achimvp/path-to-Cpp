#include <iostream>
#include <memory>

#include "vector_utils.hpp"

int main(int argc, char** argv) {
    std::cout << "Hello from " << argv[0] << std::endl;
    int* p = new int(42);
    std::cout << "Current value of p: " << *p << std::endl;
    *p = -10;
    std::cout << "Value of p after change: " << *p << std::endl;
    delete p;
    p = nullptr;

    // Create array of square numbers on the heap
    int* arr = new int[5];
    for (size_t i = 0; i < 5; i++) {
        arr[i] = i * i;
    };

    // Print out the array values
    std::cout << "Content of arr:";
    for (size_t i = 0; i < 5; i++) {
        std::cout << " " << arr[i];
    }
    std::cout << std::endl;

    // Delete the array and free memory
    delete[] arr;

    Vector3<float>* v = allocateVector3();
    std::cout << "Here is the allocated vector " << *v << std::endl;
    freeVector3(&v);

    // Smart pointer section
    auto sp = makeVector3(1.0f, 3.0f, 156.0f);
    std::cout << "Here is the smart vector: " << *sp << std::endl;

    auto p1 = std::make_shared<Vector3<float>>(1.0f, 2.0f, 3.0f);
    std::cout << "Count of shared pointer: " << p1.use_count() << std::endl;
    {  // New context
        auto p2 = p1;
        std::cout << "Count of shared pointer in context with additional pointer: "
                  << p1.use_count() << std::endl;
    };  // p2 goes out of context
    std::cout << "Cont of shared pointer out of context: " << p1.use_count() << std::endl;

    // This is not allowed!!!
    // auto p3 = std::make_unique<int>(42);
    // auto p4 = p3;
    return 0;
}