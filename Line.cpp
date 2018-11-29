#include "Line.h"

Line::Line(Position *pPos, int numPositions)      //Line constructor
{
    type = "Line";
    nrOfPositions = numPositions;
    posPtr = new Position[numPositions];
    for(int i = 0; i < numPositions; i++)
    {
        posPtr[i] = pPos[i];
    }
}

Line::~Line()       //Line destructor
{
    delete[] posPtr;
    posPtr = nullptr;
}

Line &Line::operator=(const Line &line)
{
    if(this == &line)
    {
        return *this;
    }
    else
    {
        this->type = line.type;
        nrOfPositions = line.nrOfPositions;
        delete[] posPtr;
        posPtr = new Position[nrOfPositions];
        for(int i = 0; i < nrOfPositions; i++)
        {
            posPtr[i] = line.posPtr[i];
        }
        return *this;
    }
        
}

double Line::area()
{
    double area = -1;
    return area;
}

double Line::circumreference()      //Circumference of a line is interpreted as the length of the line.
{
    double circumference = sqrt(pow((posPtr[0].xCoord - posPtr[1].xCoord), 2) + pow((posPtr[0].yCoord - posPtr[1].yCoord), 2));
    return circumference;
}