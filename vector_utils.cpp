#include "vector_utils.hpp"

Vector3<float>* allocateVector3() {
    Vector3<float>* v = new Vector3<float>(0.0f, 0.0f, 0.0f);
    return v;
}

void freeVector3(Vector3<float>** v) {
    delete *v;
    *v = nullptr;
}