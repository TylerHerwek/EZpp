#pragma once

namespace EZ {
// Point class contains 2 intagers X, Y
//---Able to do mathematical operations
class Point {
public:
    int X, Y;

    Point();
    Point(int x, int y);
    Point(int p);

    Point operator+(const Point& other) const;
    Point operator-(const Point& other) const;
    Point operator*(const Point& other) const;
    Point operator/(const Point& other) const;

    void operator+=(const Point& other);
    void operator-=(const Point& other);
    void operator*=(const Point& other);
    void operator/=(const Point& other);

    bool operator!=(const Point& other) const;
};

}
