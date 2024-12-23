#include "Point.h"

Point::Point() : x(0.0), y(0.0) {}


Point::Point(double x, double y) : x(x), y(y) {}


double Point::getX() const
{
    return x;
}

double Point::getY() const
{
    return y;
}


void Point::setX(double x)
{
    this->x = x;
}


void Point::setY(double y)
{
    this->y = y;
}


void Point::getPoint(double& x, double& y) const
{
    x = this->x;
    y = this->y;
}


void Point::setPoint(double x, double y)
{
    this->x = x;
    this->y = y;
}


double Point::findDistanceTo(const Point& other) const
{
    double dx = other.x - this->x;
    double dy = other.y - this->y;
    return std::sqrt(dx * dx + dy * dy);
}


double Point::findAngleTo(const Point& other) const
{
    double dx = other.x - this->x;
    double dy = other.y - this->y;
    return std::atan2(dy, dx); 
}


bool Point::operator==(const Point& other) const
{
    return (this->x == other.x && this->y == other.y);
}


std::ostream& operator<<(std::ostream& out, const Point& point)
{
    out << "(" << point.x << ", " << point.y << ")";
    return out;
}
