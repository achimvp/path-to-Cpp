#pragma once
#include <iostream>
#include <array>
#include <type_traits>
#include <cmath>

template <typename T>
struct Vector3
{
    std::array<T, 3> data;

    Vector3(T d1, T d2, T d3) : data({d1, d2, d3}) {}
};

template <typename T>
std::ostream& operator<<(std::ostream& os, const Vector3<T>& v) {
    os << "[" << v.data[0] << "," << v.data[1] << "," << v.data[2] << "]";
    return os;
}

template <typename T>
Vector3<T> operator+(const Vector3<T>& v1, const Vector3<T>& v2){
    Vector3<T> result(0.0, 0.0, 0.0);
    for (size_t i=0;i<v1.data.size();i++){
        result.data[i] = v1.data[i] + v2.data[i];
    }
    return result;
}
template <typename T>
Vector3<T> operator-(const Vector3<T>& v1, const Vector3<T>& v2){
    Vector3<T> result(0.0, 0.0, 0.0);
    for (size_t i=0;i<v1.data.size();i++){
        result.data[i] = v1.data[i] - v2.data[i];
    }
    return result;
}
template <typename T>
Vector3<T> operator*(const Vector3<T>& v1, const Vector3<T>& v2){
    Vector3<T> result(0.0, 0.0, 0.0);
    for (size_t i=0;i<v1.data.size();i++){
        result.data[i] = v1.data[i] * v2.data[i];
    }
    return result;
}
template <typename T, typename S>
Vector3<std::common_type_t<T, S>> operator*(const S scalar, const Vector3<T>& v){
    using R = std::common_type_t<T, S>;
    Vector3<R> result(0, 0, 0);
    for (size_t i=0;i<v.data.size();i++){
        result.data[i] = static_cast<R>(v.data[i]) * static_cast<R>(scalar);
    }
    return result;
}
template <typename T, typename S>
Vector3<std::common_type_t<T, S>> operator*(const Vector3<T>& v, const S scalar){
    return scalar * v;
}

template <typename T>
T dot(const Vector3<T>& v1, const Vector3<T>& v2) {
    T result = 0.0;
    for(size_t i=0;i< v1.data.size();i++){
        result += v1.data[i] * v2.data[i];
    }
    return result;
}

template <typename T>
float length(const Vector3<T>& v) {
    return static_cast<float>(std::sqrt(static_cast<float>(dot(v, v))));
}
