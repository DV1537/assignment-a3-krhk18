#include <iostream>
#include <fstream>
#include "Position.h"
#include "Shape.h"
#include "Point.h"
#include "Line.h"
#include "Triangle.h"
#include "Polygon.h"
//Comment
int main(int argc, const char * argv[])
{
    int size = 1;
    double *numbersPtr = new double[size];
    Position *positionPtr = nullptr;
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
        /* std::string line[2];
        while(!inputFile.eof())
        {
            for(int i = 0; i < 2; i++)
            {
                getline(inputFile, line[i]);
            }
        }

        std::cout << line[0] << std::endl << line[1] << std::endl;

       std::cout << line[0][0] << std::endl << line[0][1]; */

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

        /* while(!inputFile.eof() && numbers <= size)
        {
            //if(numbers == size)
            //{
                size += 1;
                double *tempPtr = new double [size];
                
                for(int i = 0; i < size - 1; i++)
                {
                    tempPtr[i] = numbersPtr[i];
                }

                delete[] numbersPtr;
                numbersPtr = tempPtr;
                tempPtr = nullptr;
            //}
            if(inputFile >> numbersPtr[size - 1])
            {
                numbers++;
            }
            else
            {
                std::cout << "File contains non-numerical values\n";
            }
        }
        if(numbers == 0)
        {
            std::cout << "File is empty\n";
        }
        else if(numbers % 2 == 1)
        {
            std::cout << "File contains an odd number of values\n";
        } */
        
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

            Polygon myPolygonObject(positionPtr, count);     //Create polygon object

            std::cout << "Shape: " << myPolygonObject.getType() << std::endl;
            std::cout << "Area: " << myPolygonObject.area() << std::endl;
            std::cout << "Midposition, x: " << myPolygonObject.position().xCoord << " , y: " << myPolygonObject.position().yCoord << std::endl;
            std::cout << "Circumference: " << myPolygonObject.circumreference() << std::endl;
            std::string convex = "";
            if(myPolygonObject.isConvex())
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
            std::cout << "Distance: " << myPolygonObject.distance(&anotherPolygonObject) << std::endl;

            //myPolygonObject = anotherPolygonObject;

            Polygon addedPolyObj = myPolygonObject + anotherPolygonObject;

            std::cout << myPolygonObject << std::endl << anotherPolygonObject << std::endl << addedPolyObj << std::endl;
        }        
    }

    delete []positionPtr;
    positionPtr = nullptr;

    std::getchar();

    return 0;
}