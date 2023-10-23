#pragma once

namespace EZ {
class Point2;

// Point class contains 2 intagers X, Y
//---Able to do mathematical operations
class Point {
public:
    int X, Y;

    Point();
    Point(int x, int y);
    Point(int p);

    operator Point2() const;

    Point operator+(const Point& other) const;
    Point operator-(const Point& other) const;
    Point operator*(const Point& other) const;
    Point operator/(const Point& other) const;

    void operator+=(const Point& other);
    void operator-=(const Point& other);
    void operator*=(const Point& other);
    void operator/=(const Point& other);

    bool operator!=(const Point& other) const;
	bool operator==(const Point& other) const;
};

class Point2 {
public:
    float X, Y;

    Point2();
    Point2(float x, float y);
    Point2(float p);

    operator Point() const;

    Point2 operator+(const Point2& other) const;
    Point2 operator-(const Point2& other) const;
    Point2 operator*(const Point2& other) const;
    Point2 operator/(const Point2& other) const;

    void operator+=(const Point2& other);
    void operator-=(const Point2& other);
    void operator*=(const Point2& other);
    void operator/=(const Point2& other);

    bool operator!=(const Point2& other) const;
	bool operator==(const Point& other) const
};

};
