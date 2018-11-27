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

        Polygon& operator=(const Polygon &polygon);

        double area();

        double circumreference();
};

#endif