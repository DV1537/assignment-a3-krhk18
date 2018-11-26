#include <iostream>
#include <fstream>
#include "Position.h"
#include "Shape.h"
#include "Point.h"
#include "Line.h"
#include "Triangle.h"
#include "Polygon.h"

int main(int argc, const char * argv[])
{
    int size = 1;
    double *numbersPtr = new double[size];
    Position *positionPtr = nullptr;
    Shape *shapePtr = nullptr;
    int numbers = 0;
    int count = 0;
    std::string type = "";
    std::ifstream inputFile;
    inputFile.open("input.in");

    if(!inputFile)      //Checks if read in successfully
    {
        std::cout << "Error opening file\n";
    }
    else
    {
        while(inputFile >> numbersPtr[numbers])           //Read in and store
        {           
            numbers++;
            if(numbers >= size)       //If full: expand
            {
                size += 1;
                double *tempPtr = new double[size];  //Create new, bigger
                for(int i = 0; i < size - 1; i++)      //move
                {
                    tempPtr[i] = numbersPtr[i];
                }
                delete []numbersPtr;                //delete old content
                numbersPtr = tempPtr;               //make pointer point to new array
                tempPtr = nullptr;
            }
        }
        if(numbers == 0 || !inputFile.eof())
        {
            std::cout << "File is empty or contains non-numerical values\n";
        }
        else if(numbers % 2 == 1)
        {
            std::cout << "File contains an odd number of values\n";
        }
        else
        {
            count = numbers / 2;
            positionPtr = new Position[count];
            for(int i = 0; i < count; i++)
            {
                positionPtr[i].xCoord = numbersPtr[2 * i];
                positionPtr[i].yCoord = numbersPtr[2 * i + 1];
            }

            delete []numbersPtr;
            numbersPtr = nullptr;

            if(count == 1)
            {
                type = "Point";
                shapePtr = new Point(positionPtr, count, type);    //Create point object
            }
            else if(count == 2)
            {
                type = "Line";
                shapePtr = new Line(positionPtr, count, type);       //Create line object
            }
            else if(count == 3)
            {
                type = "Triangle";
                shapePtr = new Triangle(positionPtr, count, type);   //Create triangle object
            }
            else if(count >= 4)
            {
                type = "Polygon";
                shapePtr = new Polygon(positionPtr, count, type);    //Create polygon object
            }

            std::cout << "Shape: " << shapePtr->getType() << std::endl;
            std::cout << "Area: " << shapePtr->area() << std::endl;
            std::cout << "Midposition, x: " << shapePtr->position().xCoord << " , y: " << shapePtr->position().yCoord << std::endl;
            std::cout << "Circumference: " << shapePtr->circumreference() << std::endl;
            std::string convex = "";
            if(shapePtr->isConvex())
            {
                convex = "Yes";
            }
            else
            {
                convex = "No";
            }
            std::cout << "Is convex: " << convex << std::endl;

            Shape *anotherShapePtr = nullptr;
            Position anotherPosition[4] = {{5, 5}, {7, 5}, {7, 9}, {5, 9}};
            anotherShapePtr = new Polygon(anotherPosition, 4, "Polygon");
            shapePtr = new Polygon(positionPtr, 4, "Polygon");
            std::cout << "Distance: " << shapePtr->distance(anotherShapePtr) << std::endl;

            for(int i = 0; i < count; i++)
            {
                std::cout << "X: " << positionPtr[i].xCoord << ", Y: " << positionPtr[i].yCoord << std::endl;
            }
        }        
    }

    delete shapePtr;
    shapePtr = nullptr;

    delete []positionPtr;
    positionPtr = nullptr;

    std::getchar();
}