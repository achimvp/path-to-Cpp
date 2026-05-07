#include "pointers.hpp"
#include <gtest/gtest.h>

TEST(PointersTest, Swap){
    int a = 5, b = 10;
    int sum1 = a + b;
    pointers::swap(&a, &b);
    int sum2 = a + b;
    ASSERT_EQ(a, 10);
    ASSERT_EQ(b, 5);
    ASSERT_EQ(sum1, sum2);
}