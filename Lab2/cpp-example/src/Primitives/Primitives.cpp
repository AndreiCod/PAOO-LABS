#include "Primitives.h"
#include <cmath>

Circle::Circle()
{
    radius = 0.0f;
    nextCircle = nullptr;
}

Circle::Circle(float radius)
{
    this->radius = radius;
    nextCircle = nullptr;
}

Circle::Circle(const Circle &c)
{
    this->radius = c.radius;
    this->nextCircle = nullptr;
}

Circle::~Circle()
{
    if (nextCircle != nullptr)
    {
        delete nextCircle;
    }
}

float Circle::getRadius()
{
    return radius;
}

float Circle::getArea()
{
    return M_PI * radius * radius;
}

float Circle::getCircumference()
{
    return 2.0f * M_PI * radius;
}