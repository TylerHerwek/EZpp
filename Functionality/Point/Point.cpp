#include "Point.hpp"
#include "math.h"
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

Point::operator Point2() const {
    return Point2(X, Y);
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
    return { (int)floorf((float)X / (float)other.X), (int)floorf((float)Y / (float)other.Y) };
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
    X = (int)floorf((float)X / other.X);
    Y = (int)floorf((float)Y / other.Y);
}

bool Point::operator!=(const Point& other) const
{
    if(X == other.X && Y == other.Y) return false;
    return true;
}

bool Point::operator==(const Point& other) const {
	return X == other.X && Y == other.Y;
}

//Point2

Point2::Point2() {
    X = 0.0f;
    Y = 0.0f;
}

Point2::Point2(float x, float y) {
    X = x;
    Y = y;
}

Point2::Point2(float p) {
    X = p;
    Y = p;
}

Point2::operator Point() const {
    return Point(X, Y);
}

Point2 Point2::operator+(const Point2& other) const {
    return Point2(X + other.X, Y + other.Y);
}

Point2 Point2::operator-(const Point2& other) const {
    return Point2(X - other.X, Y - other.Y);
}

Point2 Point2::operator*(const Point2& other) const {
    return Point2(X * other.X, Y * other.Y);
}

Point2 Point2::operator/(const Point2& other) const {
    return Point2(X / other.X, Y / other.Y);
}

void Point2::operator+=(const Point2& other) {
    X += other.X;
    Y += other.Y;
}

void Point2::operator-=(const Point2& other) {
    X -= other.X;
    Y -= other.Y;
}

void Point2::operator*=(const Point2& other) {
    X *= other.X;
    Y *= other.Y;
}

void Point2::operator/=(const Point2& other) {
    X /= other.X;
    Y /= other.Y;
}

bool Point2::operator!=(const Point2& other) const {
    return (X != other.X) || (Y != other.Y);
}

bool Point2::operator==(const Point& other) const {
	return X == other.X && Y == other.Y;
}
