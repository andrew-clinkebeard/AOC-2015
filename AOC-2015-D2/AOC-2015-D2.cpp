// AOC-2015-D2.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <fstream>
#include <vector>
#include "utilities.h"
#include <string>
#include <sstream>

int main()
{
    std::cout << "Hello World!\n";

    //open file
    std::ifstream inFile;

    inFile.open("C:\\Users\\Andrew Clinkenbeard\\Documents\\Advent of Code\\2015_day2.txt");

    std::vector<Package>Packages;


    if (inFile.is_open())
    {
        //get data
        std::string line;
        std::stringstream tokens;

        while (std::getline(inFile, line))
        {
            std::stringstream tokens(line);

            Package tempPackage{};
            char buff{};
            
            //get dimensions from string and put into 
            //sa >> ra >> buff >> ia >> buff;
            tokens >> tempPackage.l >> buff >> tempPackage.w >> buff >> tempPackage.h;
            Packages.push_back(tempPackage);
        }

        int area = 0;
        int bowLength = 0;

        for(Package p : Packages)
        {
            //std::cout << "Height: " << p.h << " Width: " << p.w << " Length: " << p.l << std::endl;
            area += p.getTotalArea();
            bowLength += p.getBowLength();
        }

        std::cout << area << std::endl;
        std::cout << bowLength << std::endl;

    }
    else
    {
        std::cout << "File is not open" << std::endl;
    }

    return 0;
}