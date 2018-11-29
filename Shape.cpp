#include "Shape.h"

Position Shape::position()
{
    Position midPosition;
    midPosition.xCoord = 0.0;
    midPosition.yCoord = 0.0;
    for(int i = 0; i < nrOfPositions ; i++)
    {
        midPosition.xCoord += posPtr[i].xCoord;
        midPosition.yCoord += posPtr[i].yCoord;
    }
    midPosition.xCoord /= nrOfPositions;
    midPosition.yCoord /= nrOfPositions;

    return midPosition;
}


bool Shape::isConvex()
{
    bool isConvex = true;
    bool sign = true;     
    bool first = true;

    for(int i = 0; i < nrOfPositions; i++)
    {
        double v1x = posPtr[i].xCoord - posPtr[(i + 1) % nrOfPositions].xCoord;
        double v1y = posPtr[i].yCoord - posPtr[(i + 1) % nrOfPositions].yCoord;
        double v2x = posPtr[(i + 2) % nrOfPositions].xCoord - posPtr[(i + 1) % nrOfPositions].xCoord;
        double v2y = posPtr[(i + 2) % nrOfPositions].yCoord - posPtr[(i + 1) % nrOfPositions].yCoord;
        double dotProduct = ((v2x * v1y) - v2y * v1x);

        if(dotProduct != 0)
        {
            if(first)
            {
                if(dotProduct > 0)
                {
                    sign = false;
                    first = false;
                }
            }
            else
            {
                if(std::signbit(dotProduct) != sign)
                {
                    isConvex = false;
                }
            }
        }
    }
    return isConvex;
}

double Shape::distance(Shape *s)
{
    double xFirst = this->position().xCoord;
    double yFirst = this->position().yCoord;
    double xSecond = s->position().xCoord;
    double ySecond = s->position().yCoord;

    double distance = sqrt(pow((xFirst - xSecond), 2) + pow((yFirst - ySecond), 2));

    return distance;
}