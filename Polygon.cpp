#include "Polygon.h"

Polygon::Polygon(Position *pPos, int numPositions)
{
    type = "Polygon";
    nrOfPositions = numPositions;
    posPtr = new Position[numPositions];
    for(int i = 0; i < numPositions; i++)
    {
        posPtr[i] = pPos[i];
    }
}

Polygon::~Polygon()
{
    delete[] posPtr;
    posPtr = nullptr;
}

Polygon& Polygon::operator=(const Polygon &polygon)
{
	if(this == &polygon)       //If same object
    {
        return *this;           //Done
	}
    else
    {
        type = polygon.type;
        nrOfPositions = polygon.nrOfPositions;
        delete [] posPtr;                               //Delete existing
        posPtr = new Position[polygon.nrOfPositions];      //Make new
        for(int i = 0; i < polygon.nrOfPositions; i++)     
        {
            posPtr[i] = polygon.posPtr[i];             //Fill with the one being copied
        }
        
        return *this;
    }
}

double Polygon::area()
{
    double area = 0.0;
    if(this->isConvex())    //-1 if the shape is concave
    {
        int j = nrOfPositions - 1; 
        for (int i = 0; i < nrOfPositions; i++)
        { 
            area += (posPtr[j].xCoord + posPtr[i].xCoord) * (posPtr[j].yCoord - posPtr[i].yCoord); 
            j = i;
        } 
        area = fabs(area / 2.0);
    }
    else
    {
        area = -1;
    }

    if(area == 0)   //-1 if doesn't have an area
    {
        area = -1;
    }
    return area;
}

double Polygon::circumreference()
{
    double circumference = 0.0;
    int j = nrOfPositions - 1;
    for(int i = 0; i < nrOfPositions; i++)
    {
        circumference += sqrt(pow((posPtr[i].xCoord - posPtr[j].xCoord), 2) + pow((posPtr[i].yCoord - posPtr[j].yCoord), 2));
        j = i;
    }
    return circumference;
}