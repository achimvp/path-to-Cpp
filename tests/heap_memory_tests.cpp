#include "vector_utils.hpp"
#include <gtest/gtest.h>

TEST(HeapTest, IntAllocation) {
    int* p = new int(42);
    EXPECT_EQ(*p, 42);
    *p = 100;
    EXPECT_EQ(*p, 100);
    delete p;
}

TEST(HeapTest, ArrayValues) {
    int* arr = new int[5];
    for(size_t i=0;i<5;i++) arr[i] = i*i;
    EXPECT_EQ(arr[0], 0);
    EXPECT_EQ(arr[2], 4);
    EXPECT_EQ(arr[4], 16);
    delete[] arr;
}

TEST(HeapTest, allocateVector3) {
    Vector3<float> *v = allocateVector3();
    ASSERT_NE(v, nullptr);
    EXPECT_FLOAT_EQ(v->data[0], 0.0f);
    freeVector3(&v);
    EXPECT_EQ(v, nullptr);
}

TEST(HeadTest, makeVector3) {
    auto p1 = makeVector3(1.0f, 3.0f, 6.0f);
    auto p2 = makeVector3(1, -1, 400);
    EXPECT_FLOAT_EQ(p1->data[0], 1.0f);
    EXPECT_EQ(p2->data[0], 1);
}