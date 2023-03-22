#include "Math.hpp"

namespace Utility::Math {

// Vector3 Standard Math operators
Vector3& Vector3::operator=(const Vector3& rhs)
{
    if (this == &rhs)
        return *this;

    x = rhs.x;
    y = rhs.y;
    z = rhs.z;
    return *this;
}

Vector3 Vector3::operator+() const
{
    return *this;
}

Vector3 Vector3::operator-() const
{
    return Vector3(-x, -y, -z);
}

Vector3 Vector3::operator+(const Vector3& v) const
{
    return Vector3(x + v.x, y + v.y, z + v.z);
}

Vector3 Vector3::operator-(const Vector3& v) const
{
    return Vector3(x - v.x, y - v.y, z - v.z);
}

Vector3 Vector3::operator*(float f) const
{
    return Vector3(x * f, y * f, z * f);
}

Vector3 operator*(float f, const Vector3& v)
{
    return v * f;
}

Vector3 Vector3::operator*(const Vector3& v) const
{
    return Vector3(x * v.x, y * v.y, z * v.z);
}

Vector3 Vector3::operator/(float f) const
{
    return (*this) * (1.f / f);
}

// Vector3 Combined Math operators
void Vector3::operator+=(const Vector3& v)
{
    x += v.x;
    y += v.y;
    z += v.z;
}

void Vector3::operator-=(const Vector3& v)
{
    x -= v.x;
    y -= v.y;
    z -= v.z;
}

void Vector3::operator*=(const Vector3& v)
{
    x *= v.x;
    y *= v.y;
    z *= v.z;
}

void Vector3::operator*=(float f)
{
    x *= f;
    y *= f;
    z *= f;
}

void Vector3::operator/=(float f)
{
    (operator*=)(1.f / f);
}

// Vector3 Logic operators
bool Vector3::operator==(const Vector3& v) const
{
    return x == v.x && y == v.y && z == v.z;
}

bool Vector3::operator<(const Vector3& v) const
{
    if (x < v.x)
        return true;
    if (x > v.x)
        return false;
    if (y < v.y)
        return true;
    if (y > v.y)
        return false;
    if (z < v.z)
        return true;
    if (z > v.z)
        return false;

    return false;
}

bool Vector3::operator<=(const Vector3& v) const
{
    return *this < v || *this == v;
}

bool Vector3::operator!=(const Vector3& v) const
{
    return !(*this == v);
}

// Vector3 Array Style access
float& Vector3::operator[](int i)
{
    return (&x)[i];
}

const float& Vector3::operator[](int i) const
{
    return (&x)[i];
}

// Vector3 Math utilities
float Vector3::len() const
{
    return static_cast<float>(sqrtf(lensqr()));
}

float Vector3::lensqr() const
{
    return x * x + y * y + z * z;
}

float Vector3::norm1() const
{
    return fabsf(x) + fabsf(y) + fabsf(z);
}

inline float Vector3::norminf() const
{
    return std::max(std::max(fabsf(x), fabsf(y)), fabsf(z));
}

void Vector3::normalize()
{
    float length = len();
    if (length < 0.0001) {
        zero();
        return;
    }
    *this *= (1.0f / length);
}

Vector3 Vector3::normalized() const
{
    Vector3 v = *this;
    v.normalize();
    return v;
}

void Vector3::zero()
{
    x = y = z = 0.f;
}

bool Vector3::is_zero() const
{
    return x == 0.0f && y == 0.0f && z == 0.0f;
}

double cosine_similarity(const std::vector<double>& first_vector, const std::vector<double>& second_vector)
{
    if (first_vector.size() != second_vector.size() || first_vector.empty() || second_vector.empty()) {
        throw std::invalid_argument("Vectors must have the same length. And must be more than zero");
    }

    const double dot_product = std::inner_product(first_vector.begin(), first_vector.end(), second_vector.begin(), 0.0);
    const double first_vector_lengh = std::sqrt(std::inner_product(first_vector.begin(), first_vector.end(), first_vector.begin(), 0.0));
    const double second_vector_lengh = std::sqrt(std::inner_product(second_vector.begin(), second_vector.end(), second_vector.begin(), 0.0));

    return dot_product / (first_vector_lengh * second_vector_lengh);
}

}
