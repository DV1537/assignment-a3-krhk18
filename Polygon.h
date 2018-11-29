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

        friend Polygon operator+(const Polygon &polygonOne, const Polygon &polygonTwo);

/*         Polygon& operator=(const Polygon &polygon);

     //Polygon& operator+(const Polygon &polygon);
        friend Polygon operator+(const Polygon& poly1, const Polygon& poly2); */

        double area();

        double circumreference();
};

#endif