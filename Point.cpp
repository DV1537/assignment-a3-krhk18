#include "Point.h"

Point::Point(Position *pPos, int numPositions)
{
    type = "Point";
    nrOfPositions = numPositions;
    posPtr = new Position[numPositions];
    for(int i = 0; i < numPositions; i++)
    {
        posPtr[i] = pPos[i];
    }
}

Point::~Point()
{
    delete[] posPtr;
    posPtr = nullptr;
}

Point &Point::operator=(const Point &point)
{
    if(this == &point)
    {
        return *this;
    }
    else
    {
        this->type = point.type;
        this->nrOfPositions = point.nrOfPositions;
        delete[] posPtr;
        posPtr = new Position[point.nrOfPositions];
        for(int i = 0; i < point.nrOfPositions; i++)
        {
            posPtr[i] = point.posPtr[i];
        }
        return *this;
    }
}

double Point::area()
{
    double area = -1;
    return area;
}

double Point::circumreference()
{
    double area = -1;
    return area;
}