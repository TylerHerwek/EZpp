#pragma once

namespace EZ {
// Point class contains 2 intagers X, Y
//---Able to do mathematical operations
class Point {
public:
    int x, y;

    Point();
    Point(int x, int y);
    Point(int p);
    Point(const Point& other);

    Point operator+(const Point& other) const;
    Point operator-(const Point& other) const;
    Point operator*(const Point& other) const;
    Point operator/(const Point& other) const;

    void operator+=(const Point& other);
    void operator-=(const Point& other);
    void operator*=(const Point& other);
    void operator/=(const Point& other);

    bool operator==(const Point& other) const;
};

// Point class contains 2 floats X, Y
//---Able to do mathematical operations
class Point2 {
public:
    float x, y;

    Point2();
    Point2(float x, float y);
    Point2(float p);
    Point2(const Point2& other);

    Point ToPoint() const;

    Point2 operator+(const Point2& other) const;
    Point2 operator-(const Point2& other) const;
    Point2 operator*(const Point2& other) const;
    Point2 operator/(const Point2& other) const;

    void operator+=(const Point2& other);
    void operator-=(const Point2& other);
    void operator*=(const Point2& other);
    void operator/=(const Point2& other);

    bool operator==(const Point2& other) const;
};
}
