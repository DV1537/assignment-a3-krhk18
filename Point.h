#ifndef POINT_H
#define POINT_H
#include <string>
#include "Shape.h"

class Point : public Shape
{
    private:
    public:
        Point(Position *pPos, int numPositions, std::string type);     //Point constructor

        ~Point();                                  //Point destructor

        double area()           
        {
            return -1;
        }

        double circumreference()       //returns circumreference of the object
        {
            return -1;
        }
};

#endif