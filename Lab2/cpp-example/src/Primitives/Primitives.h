#pragma once

class Circle
{
public:
    Circle();
    Circle(float radius);
    Circle(const Circle &c);
    ~Circle();

    float getRadius();
    float getArea();
    float getCircumference();

    Circle *nextCircle;

private:
    float radius;
};