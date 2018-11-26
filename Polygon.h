#ifndef POLYGON_H
#define POLYGON_H
#include <string>
#include "Shape.h"

class Polygon : public Shape
{
    private:
    public:
        Polygon(Position *pPos, int numPositions);      //Polygon constructor

        ~Polygon();     //Polygon destructor

        double area();

        double circumreference();
};

#endif