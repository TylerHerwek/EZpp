#include "Point.hpp"
using namespace EZ;

Point::Point()
{
    X = 0;
    Y = 0;
}

Point::Point(int x, int y)
{
    X = x;
    Y = y;
}

Point::Point(int p)
{
    X = p;
    Y = p;
}

Point Point::operator+(const Point& other) const
{
    return { X + other.X, Y + other.Y };
}
Point Point::operator-(const Point& other) const
{
    return { X - other.X, Y - other.Y };
}
Point Point::operator*(const Point& other) const
{
    return { X * other.X, Y * other.Y };
}
Point Point::operator/(const Point& other) const
{
    return { (int)((float)X / (float)other.X), (int)((float)Y / (float)other.Y) };
}

void Point::operator+=(const Point& other)
{
    X += other.X;
    Y += other.Y;
}
void Point::operator-=(const Point& other)
{
    X -= other.X;
    Y -= other.Y;
}
void Point::operator*=(const Point& other)
{
    X *= other.X;
    Y *= other.Y;
}
void Point::operator/=(const Point& other)
{
    X = (int)((float)X / other.X);
    Y = (int)((float)Y / other.Y);
}

bool Point::operator!=(const Point& other) const
{
    if(X == other.X && Y == other.Y) return false;
    return true;
}
