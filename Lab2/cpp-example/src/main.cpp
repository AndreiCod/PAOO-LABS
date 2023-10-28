#include <iostream>
#include "Primitives.h"

int main(int argc, char **argv)
{
    std::cout << "Hello, World!" << std::endl;

    Circle *startCircle = new Circle(1);

    for (int i = 2; i <= 10; ++i)
    {
        Circle *c = new Circle(i);
        c->nextCircle = startCircle;
        startCircle = c;
    }

    Circle *c = startCircle;
    do
    {
        std::cout << "Circle with radius " << c->getRadius();
        std::cout << ", circumference " << c->getCircumference();
        std::cout << " and area " << c->getArea() << std::endl;

        c = c->nextCircle;
    } while (c != nullptr);

    c = startCircle;
    for (int i = 1; i <= 3; ++i)
    {
        if (i == 3)
        {
            Circle *tmpC = c;
            c = c->nextCircle;
            tmpC->nextCircle = nullptr;
        }
        else
        {
            c = c->nextCircle;
        }
    }

    delete c;
    c = startCircle;

    do
    {
        std::cout << "Circle with radius " << c->getRadius();
        std::cout << ", circumference " << c->getCircumference();
        std::cout << " and area " << c->getArea() << std::endl;

        c = c->nextCircle;
    } while (c != nullptr);

    return 0;
}