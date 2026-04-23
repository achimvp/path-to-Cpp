#include "vector_utils.hpp"
#include "test_utils.hpp"
#include <cassert>
#include <cmath>

// TODO: write test for operators and functions
void testAddition() {
    Vector3<float> v1(-2.0f, 1.0f, 2.0f);
    Vector3<float> v2(1.0f, 1.0f, 4.5f);
    Vector3<float> sum(-1.0f, 2.0f, 6.5f);
    assert(nearlyEqualVec(v1+v2, sum));
    assert(nearlyEqualVec(v1+v2,v2+v1));
}

void testSubstraction() {
    Vector3<float> v1(-2.0f, 1.0f, 2.0f);
    Vector3<float> v2(1.0f, 1.0f, 4.5f);
    Vector3<float> dif(-3.0f, 0.0f, -2.5f);
    assert(nearlyEqualVec(v1-v2, dif));
    assert(nearlyEqual(length(v1-v2), length(v2-v1)));
}

void testScalarMult() {
    Vector3<float> v1(1.0f, 2.0f, -3.0f);
    Vector3<float> v2(2.0f, 4.0f, -6.0f);
    Vector3<int> v3(1, 2, 3);
    float a = 2.0f;
    int b = -4;
    assert(nearlyEqualVec(a*v1, v2));
    assert(nearlyEqualVec(a*v1, v1*a));
    assert(equalVec(b*v3, v3 * b));
}

void testDot() {
    Vector3<float> a(1.0f, 0.0f, 0.0f);
    Vector3<float> b(0.0f, 1.0f, 0.0f);
    assert(nearlyEqual(dot(a, b), 0.0f)); // dot product of orthogonal vectors is 0

    Vector3<float> c(1.0f, 0.0f, 0.0f);
    assert(nearlyEqual(dot(c, c), 1.0f)); // unit vector
}

void testLength() {
    Vector3<float> a(1.0f, 0.0f, 0.0f);
    Vector3<int> b(1, 1, 1);
    assert(nearlyEqual(length(a), 1.0f)); // length of unit vector is 1.0
    assert(nearlyEqual(length(b), std::sqrt(3.0f)));
}


int main(){
    testDot();
    testScalarMult();
    testAddition();
    testSubstraction();

    std::cout << "All tests passed!" << std::endl;
}