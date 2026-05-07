#include "vector_utils.hpp"
#include "test_utils.hpp"
#include <gtest/gtest.h>
#include <cassert>
#include <cmath>

// TODO: write test for operators and functions
TEST(Vector3Test, Addition) {
    Vector3<float> v1(-2.0f, 1.0f, 2.0f);
    Vector3<float> v2(1.0f, 1.0f, 4.5f);
    Vector3<float> sum(-1.0f, 2.0f, 6.5f);
    auto result = v1 + v2;
    for(size_t i=0; i<v1.data.size();i++){
        EXPECT_NEAR(result.data[i], sum.data[i], 1e-5f);
    }
}

TEST(Vector3Test, CommutativeAddition) {
    Vector3<float> v1(-2.0f, 1.0f, 2.0f);
    Vector3<float> v2(1.0f, 1.0f, 4.5f);
    auto r1 = v1 + v2;
    auto r2 = v2 + v1;
    for(size_t i=0; i<v1.data.size();i++){
        EXPECT_NEAR(r1.data[i], r2.data[i], 1e-5f);
    }
}

TEST(Vector3Test, Substraction) {
    Vector3<float> v1(-2.0f, 1.0f, 2.0f);
    Vector3<float> v2(1.0f, 1.0f, 4.5f);
    Vector3<float> dif(-3.0f, 0.0f, -2.5f);
    auto result = v1 - v2;
    for(size_t i=0; i<v1.data.size();i++){
        EXPECT_NEAR(result.data[i], dif.data[i], 1e-5f);
    }
}
// assert(nearlyEqual(length(v1-v2), length(v2-v1)));

TEST(Vector3Test, ScalarMultiplication) {
    Vector3<float> v1(1.0f, 2.0f, -3.0f);
    Vector3<float> v2(2.0f, 4.0f, -6.0f);
    Vector3<int> v3(1, 2, 3);
    float a = 2.0f;
    int b = -4;
    auto floatResult1 = a*v1;
    auto floatResult2 = v1*a;
    auto intResult1 = b*v3;
    auto intResult2 = v3*b;
    for(size_t i=0;i<v1.data.size();i++) {
        EXPECT_NEAR(floatResult1.data[i], v2.data[i], 1e-5f);
        EXPECT_NEAR(floatResult1.data[i], floatResult2.data[i], 1e-5f);
        EXPECT_EQ(intResult1.data[i], intResult2.data[i]);
    }
}

TEST(Vector3Test, Dotproduct) {
    Vector3<float> a(1.0f, 0.0f, 0.0f);
    Vector3<float> b(0.0f, 1.0f, 0.0f);
    Vector3<float> c(1.0f, 0.0f, 0.0f);

    EXPECT_NEAR(dot(a, b), 0.0f, 1e-5f); // dot product of orthogonal vectors is 0
    EXPECT_NEAR(dot(c, c), 1.0f, 1e-5f); // unit vector
}

TEST(Vector3Test, Length) {
    Vector3<float> a(1.0f, 0.0f, 0.0f);
    Vector3<int> b(1, 1, 1);
    EXPECT_NEAR(length(a), 1.0f, 1e-5f); // length of unit vector is 1.0
    EXPECT_NEAR(length(b), std::sqrt(3.0f), 1e-5f);
}


// int main(){
//     testDot();
//     testScalarMult();

//     std::cout << "All tests passed!" << std::endl;
// }