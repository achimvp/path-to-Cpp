#include "test_utils.hpp"
#include <cmath>

bool nearlyEqual(float a, float b, float epsilon) {
    return std::abs(a - b) < epsilon;
}

bool nearlyEqualVec(const Vector3<float>& v1, const Vector3<float>& v2, float epsilon) {
    bool isNearlyEqual = true;
    for(size_t i=0;i<v1.data.size();i++){
        isNearlyEqual &= (nearlyEqual(v1.data[i], v2.data[i], epsilon));
    }
    return isNearlyEqual;
}

bool equalVec(const Vector3<int>& v1, const Vector3<int>& v2) {
    bool isEqual = true;
    for(size_t i=0;i<v1.data.size();i++){
        isEqual &= (v1.data[i] == v2.data[i]);
    }
    return isEqual;
}