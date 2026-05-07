#include <iostream>

namespace pointers{
    void swap(int* a, int* b) {
        int tmp = *a;
        *a = *b;
        *b = tmp;
    }
}