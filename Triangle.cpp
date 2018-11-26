#include "Triangle.h"

Triangle::Triangle(Position *pPos, int numPositions)
{
    type = "Triangle";
    nrOfPositions = numPositions;
    posPtr = new Position[numPositions];
    for(int i = 0; i < numPositions; i++)
    {
        posPtr[i] = pPos[i];
    }
}

Triangle::~Triangle()
{
    delete[] posPtr;
    posPtr = nullptr;
}

Triangle& Triangle::operator=(const Triangle &triangle)
{
	if(this == &triangle)       //If same object
    {
        return *this;           //Done
	}
    else
    {
        type = triangle.type;
        nrOfPositions = triangle.nrOfPositions;
        delete [] posPtr;                               //Delete existing
        posPtr = new Position[triangle.nrOfPositions];      //Make new
        for(int i = 0; i < triangle.nrOfPositions; i++)     
        {
            posPtr[i] = triangle.posPtr[i];             //Fill with the one being copied
        }
        
        return *this;
    }
}

double Triangle::area()     
{
    double area = 0.0;

    if(this->isConvex())    
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
        area = -1;      //-1 if the shape is concave
    }
    
    if(area == 0)       // -1 if doesn't have an area
    {
        area = -1;
    }
    return area;
}

double Triangle::circumreference()
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