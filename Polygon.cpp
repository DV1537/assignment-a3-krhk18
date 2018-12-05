#include "Polygon.h"
#include "Triangle.h"

Polygon::Polygon()
{
    type = "Polygon";
    nrOfPositions = 0;
    posPtr = new Position[nrOfPositions];
}

Polygon::Polygon(Position *pPos, int numPositions)
{
    if(numPositions == 1)
    {
        type = "Point";
    }
    else if(numPositions == 2)
    {
        type = "Line";
    }
    else if(numPositions == 3)
    {
        type = "Triangle";
    }
    else if(numPositions >= 4)
    {
        type = "Polygon (with coordinates >3)";
    }

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

Polygon &Polygon::operator=(const Polygon &polygon)
{
    if(this == &polygon)
    {
        return *this;
    }
    else
    {
        this->type = polygon.type;
        this->nrOfPositions = polygon.nrOfPositions;
        delete[] posPtr;
        posPtr = new Position[polygon.nrOfPositions];
        for(int i = 0; i < polygon.nrOfPositions; i++)
        {
            posPtr[i] = polygon.posPtr[i];
        }
        return *this;
    }
}

Polygon operator+(const Polygon &polygonOne, const Polygon &polygonTwo)
{
    int numPos = polygonOne.nrOfPositions + polygonTwo.nrOfPositions;       //Add number of positions
    Position *ptr = new Position[numPos];                                   //Create new allocated memory for added polygon objects.
    for(int i = 0; i < polygonOne.nrOfPositions; i++)                       
    {
        ptr[i] = polygonOne.posPtr[i];                      //Copy positions from first polygon
    }
    for(int i = 0; i < polygonTwo.nrOfPositions; i++)
    {
        ptr[i + polygonOne.nrOfPositions] = polygonTwo.posPtr[i];   //Copy positions from second polygon
    }
    Polygon addedPolygon(ptr, numPos);      //Create new polygon of the two added ones

    delete[] ptr;
    ptr = nullptr;

    return addedPolygon;             
}

std::ostream &operator<<(std::ostream &out, const Polygon &polygon)
{
    out << polygon.type << "\n";
    for(int i = 0; i < polygon.nrOfPositions; i++)
    {
       out << "X: " << polygon.posPtr[i].xCoord << ", Y: " << polygon.posPtr[i].yCoord << std::endl;
    }
    
    return out;   
}

double Polygon::area()
{
    double area = 0.0;
    if(nrOfPositions <= 2 || this->isConvex() == false)
    {
        area = -1;
    }
    else
    {
        Position trianglePositions[3];
        trianglePositions[0] = posPtr[0];
        for(int i = 0; i < nrOfPositions - 2; i++)
        {
            for(int j = 1; j < 3; j++)
            {
                trianglePositions[j] = posPtr[j + i];
            }
            Triangle trianglePartOfPolygon(trianglePositions, 3);

            area += trianglePartOfPolygon.area();
        }
    }
    if(area == 0)
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