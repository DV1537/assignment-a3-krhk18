#include <iostream>
#include <fstream>
#include <sstream>
#include "Position.h"
#include "Shape.h"
#include "Point.h"
#include "Line.h"
#include "Triangle.h"
#include "Polygon.h"

int main(int argc, const char * argv[])
{
    int capacity = 1;
    double *numbersPtr = new double[capacity];
    Position *positionPtr = nullptr;
    std::string type = "";
    std::ifstream inputFile;
    std::stringstream myStringStream;
    std::string line;
    int numberOfCoordinates = 0;
    int numberOfElements;
    int capacityPolygons = 1;
    Polygon *polygonPtr = new Polygon[capacityPolygons];
    int numberOfShapes;

    inputFile.open("input.in");

    if(!inputFile)      //Checks if read in successfully
    {
        std::cout << "Error opening file\n";
    }
    else
    {
        while(!inputFile.eof())
        {
            myStringStream.clear();
            std::getline(inputFile, line);
            myStringStream << line;

            while(myStringStream >> numbersPtr[numberOfElements])           //Read in and store
            {           
                numberOfElements++;
                if(numberOfElements >= capacity)       //If full: expand
                {
                    capacity += 1;
                    double *tempPtr = new double[capacity];  //Create new, bigger
                    for(int i = 0; i < capacity - 1; i++)      //move
                    {
                        tempPtr[i] = numbersPtr[i];
                    }
                    delete []numbersPtr;                //delete old content
                    numbersPtr = tempPtr;               //make pointer point to new array
                    tempPtr = nullptr;
                }
            }
            if(numberOfElements == 0 || !myStringStream.eof())
            {
                std::cout << "Line number " << numberOfShapes + 1 << " is empty or contains non-numerical values\n";
                exit(EXIT_FAILURE);
            }
            else if(numberOfElements % 2 == 1)
            {
                std::cout << "Line number " << numberOfShapes + 1 << " contains an odd number of values\n";
                exit(EXIT_FAILURE);
            }
            else
            {
                numberOfCoordinates = numberOfElements / 2;
                positionPtr = new Position[numberOfCoordinates];
                for(int i = 0; i < numberOfCoordinates; i++)
                {
                    positionPtr[i].xCoord = numbersPtr[2 * i];
                    positionPtr[i].yCoord = numbersPtr[2 * i + 1];
                }

                Polygon myPolygonObject(positionPtr, numberOfCoordinates);

                if(numberOfShapes >= capacityPolygons)
                {
                    capacityPolygons += 1;
                    Polygon *tempPtr = new Polygon[capacityPolygons];  //Create new, bigger
                    for(int i = 0; i < capacityPolygons - 1; i++)      //move
                    {
                        tempPtr[i] = polygonPtr[i];
                    }
                    delete []polygonPtr;                //delete old content
                    polygonPtr = tempPtr;               //make pointer point to new array
                    tempPtr = nullptr;
                }
                polygonPtr[numberOfShapes] = myPolygonObject;
                numberOfShapes++;

                numberOfElements = 0;
            }
        }

        inputFile.close();

        delete []numbersPtr;
        numbersPtr = nullptr;
        
        delete []positionPtr;
        positionPtr = nullptr;

        for(int i = 0; i < numberOfShapes; i++)
        {
            std::cout << polygonPtr[i] << std::endl;
        }
    
        std::cout << "Shape: " << polygonPtr[1].getType() << std::endl;
        std::cout << "Area: " << polygonPtr[1].area() << std::endl;
        std::cout << "Midposition, x: " << polygonPtr[1].position().xCoord << " , y: " << polygonPtr[1].position().yCoord << std::endl;
        std::cout << "Circumference: " << polygonPtr[1].circumreference() << std::endl;
        std::string convex = "";
        if(polygonPtr[1].isConvex())
        {
            convex = "Yes";
        }
        else
        {
            convex = "No";
        }
        std::cout << "Is convex: " << convex << std::endl;

        Position anotherPosition[2] = {{5, 5}, {7, 5}}; //, {7, 9}, {5, 9}};
        Polygon anotherPolygonObject(anotherPosition, 2);
        std::cout << "Distance: " << polygonPtr[1].distance(&anotherPolygonObject) << std::endl;

        //myPolygonObject = anotherPolygonObject;

        //Polygon addedPolyObj = polygonPtr[1] + anotherPolygonObject;

        //std::cout << polygonPtr[1] << std::endl << anotherPolygonObject << std::endl << addedPolyObj << std::endl;
              
    }
    
    delete []polygonPtr;
    polygonPtr = nullptr;

    std::getchar();

    return 0;
}