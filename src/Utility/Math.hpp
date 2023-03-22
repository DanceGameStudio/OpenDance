#include <cmath>
#include <numeric>
#include <stdexcept>
#include <vector>

namespace Utility::Math {

// Implementation of a Vector3 with utility functions
class Vector3 {
public:
    float x;
    float y;
    float z;

    Vector3()
        : x(0.0f)
        , y(0.0f)
        , z(0.0f)
    {
    }
    Vector3(float x, float y, float z)
        : x(x)
        , y(y)
        , z(z)
    {
    }
    Vector3(const double* double_array)
        : x(float(double_array[0]))
        , y(float(double_array[1]))
        , z(float(double_array[2]))
    {
    }
    Vector3(const float* float_array)
        : x(float_array[0])
        , y(float_array[1])
        , z(float_array[2])
    {
    }
    Vector3(const Vector3& rhs)
    {
        x = rhs.x;
        y = rhs.y;
        z = rhs.z;
    }

    Vector3& operator=(const Vector3& v);

    Vector3 operator+() const;
    Vector3 operator-() const;
    Vector3 operator+(const Vector3& v) const;
    Vector3 operator-(const Vector3& v) const;
    Vector3 operator*(const Vector3& v) const;
    Vector3 operator*(float f) const;
    Vector3 operator/(float f) const;

    void operator+=(const Vector3& v);
    void operator-=(const Vector3& v);
    void operator*=(const Vector3& v);
    void operator*=(float f);
    void operator/=(float f);

    bool operator==(const Vector3& v) const;
    bool operator<(const Vector3& v) const;
    bool operator<=(const Vector3& v) const;
    bool operator!=(const Vector3& v) const;

    float& operator[](int i);
    const float& operator[](int i) const;

    float len() const;
    float lensqr() const;

    float norm1() const;
    float norm2() const { return len(); }
    float norminf() const;

    void normalize();
    Vector3 normalized() const;

    void zero();
    bool is_zero() const;

    float dot(const Vector3& v) const;
};

// Generic Math Utilities
float cosine_similarity(const Vector3& v1, const Vector3& v2);
}
