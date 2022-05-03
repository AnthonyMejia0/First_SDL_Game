#ifndef __VECTOR2D_H__
#define __VECTOR2D_H__

#include "math.h"

class Vector2D {
public:
    Vector2D(float x, float y): m_x(x), m_y(y) {}
    float getX() { return m_x; }
    float getY() { return m_y; }
    void setX(float x) { m_x = x; }
    void setY(float y) { m_y = y; }
    float length() { return sqrt(pow(m_x, 2) + pow(m_y, 2)); }
    
    Vector2D operator+(const Vector2D &v2) const {
        return Vector2D(this->m_x + v2.m_x, this->m_y + v2.m_y);
    }

    friend Vector2D& operator+=(Vector2D &v1, const Vector2D &v2) {
        v1.m_x += v2.m_x;
        v1.m_y += v2.m_y;
        return v1;
    }

    Vector2D operator*(float scalar) {
        return Vector2D(m_x * scalar, m_y * scalar);
    }

    Vector2D& operator*=(float scalar) {
        m_x *= scalar;
        m_y *= scalar;
        return *this;
    }

    Vector2D operator-(const Vector2D &v2) const {
        return Vector2D(this->m_x - v2.m_x, this->m_y - v2.m_y);
    }

    friend Vector2D& operator-=(Vector2D &v1, const Vector2D &v2) {
        v1.m_x -= v2.m_x;
        v1.m_y -= v2.m_y;
        return v1;
    }

    Vector2D operator/(float scalar)
    {
        return Vector2D(m_x / scalar, m_y / scalar);
    }

    Vector2D& operator/=(float scalar)
    {
        m_x /= scalar;
        m_y /= scalar;
        return *this;
    }

    void normalize() {
        float l = length();
        if (l > 0) {
            (*this) *= 1 / l;
        }
    }

private:
    float m_x;
    float m_y;
};

#endif //__VECTOR2D_H__