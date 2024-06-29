#ifndef VECTOR3_HPP
#define VECTOR3_HPP

#include <stdexcept>
#include <cmath>
class Vector3 {
    public:
        float x, y, z;
        Vector3(float _x = 0, float _y = 0, float _z = 0);
        Vector3(const Vector3& other);
        // operations
        Vector3 operator+(const Vector3& other);
        Vector3 operator-(const Vector3& other);
        Vector3 operator*(float f);
        Vector3 operator/(float f);

        Vector3& operator=(const Vector3& other);

        // comparisons
        bool operator==(const Vector3& other);

        // extra opertations
        float length();
        Vector3 normalised();
};

#endif