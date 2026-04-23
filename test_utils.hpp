#pragma once
#include "vector_utils.hpp"

bool nearlyEqual(float a, float b, float epsilon=1e-5f);

bool nearlyEqualVec(const Vector3<float>& v1, const Vector3<float>& v2, float epsilon=1e-5f);

bool equalVec(const Vector3<int>& v1, const Vector3<int>& v2);