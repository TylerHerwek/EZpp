#include "Point.hpp"
using namespace EZ;

Point::Point()
{
    x = 0;
    y = 0;
}

Point::Point(const Point& other)
{
    x = other.x;
    y = other.y;
}

Point::Point(int x, int y)
{
    this->x = x;
    this->y = y;
}

Point::Point(int p)
{
    x = p;
    y = p;
}

Point Point::operator+(const Point& other) const
{
    return { x + other.x, y + other.y };
}
Point Point::operator-(const Point& other) const
{
    return { x - other.x, y - other.y };
}
Point Point::operator*(const Point& other) const
{
    return { x * other.x, y * other.y };
}
Point Point::operator/(const Point& other) const
{
    return { (int)((float)x / (float)other.x), (int)((float)y / (float)other.y) };
}

void Point::operator+=(const Point& other)
{
    x += other.x;
    y += other.y;
}
void Point::operator-=(const Point& other)
{
    x -= other.x;
    y -= other.y;
}
void Point::operator*=(const Point& other)
{
    x *= other.x;
    y *= other.y;
}
void Point::operator/=(const Point& other)
{
    x = (int)((float)x / other.x);
    y = (int)((float)y / other.y);
}

bool Point::operator==(const Point& other) const
{
    if (x != other.x)
        return false;
    if (y != other.y)
        return false;
    return true;
}

Point2::Point2()
{
    x = 0;
    y = 0;
}

Point2::Point2(float x, float y)
{
    this->x = x;
    this->y = y;
}

Point2::Point2(float p)
{
    x = p;
    y = p;
}

Point2::Point2(const Point2& other)
{
    x = other.x;
    y = other.y;
}

Point Point2::ToPoint() const
{
    return Point((int)x, (int)y);
}

Point2 Point2::operator+(const Point2& other) const
{
    return { x + other.x, y + other.y };
}
Point2 Point2::operator-(const Point2& other) const
{
    return { x - other.x, y - other.y };
}
Point2 Point2::operator*(const Point2& other) const
{
    return { x * other.x, y * other.y };
}
Point2 Point2::operator/(const Point2& other) const
{
    return { (float)x / (float)other.x, (float)y / (float)other.y };
}

void Point2::operator+=(const Point2& other)
{
    x += other.x;
    y += other.y;
}
void Point2::operator-=(const Point2& other)
{
    x -= other.x;
    y -= other.y;
}
void Point2::operator*=(const Point2& other)
{
    x *= other.x;
    y *= other.y;
}
void Point2::operator/=(const Point2& other)
{
    x = x / other.x;
    y = y / other.y;
}

bool Point2::operator==(const Point2& other) const
{
    if (x != other.x)
        return false;
    if (y != other.y)
        return false;
    return true;
}
