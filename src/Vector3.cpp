#include "Vector3.hpp"

Vector3::Vector3(float _x = 0, float _y = 0, float _z = 0) : x(_x), y(_y), z(_z) {}
Vector3::Vector3(const Vector3& other) : x(other.x), y(other.y), z(other.z) {}

Vector3 Vector3::operator+(const Vector3& other)
{
    return Vector3(this->x + other.x, this->y + other.y, this->z + other.z);
}

Vector3 Vector3::operator-(const Vector3& other)
{
    return Vector3(this->x - other.x, this->y - other.y, this->z - other.z);
}

Vector3 Vector3::operator*(float f)
{
    return Vector3(this->x * f, this->y * f, this->z * f);
}

Vector3 Vector3::operator/(float f)
{
    if (f == 0)
        throw std::overflow_error("Zero division");
    return Vector3(this->x / f, this->y / f, this->z / f);
}

Vector3& Vector3::operator=(const Vector3& other)
{
    this->x = other.x;
    this->y = other.y;
    this->z = other.z;
    return (*this);
}

bool Vector3::operator==(const Vector3& other)
{
    return (this->x == other.x && this->y == other.y && this->z == other.z);
}

float Vector3::length()
{
    return (std::sqrt(x * x + y * y + z * z));
}

Vector3 Vector3::normalised()
{
    return (*this / length());
}

std::ostream& operator<<(std::ostream os, const Vector3& vector)
{
    os << "x:" << vector.x << ",y:" << vector.y << ",z:" << vector.z;
}