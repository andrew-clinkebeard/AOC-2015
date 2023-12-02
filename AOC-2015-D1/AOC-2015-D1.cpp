// AOC-2015-D1.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <fstream>

int main()
{
    std::cout << "Hello World!\n";

    //open file
    std::fstream inFile;
    
    inFile.open("C:\\Users\\Andrew Clinkenbeard\\Documents\\Advent of Code\\2015_day1.txt");

    if (inFile.is_open())
    {
        //get data
        std::string line;
        inFile >> line;

        int floor = 0;

        //parse data
        for (int i = 0; i < line.size(); ++i)
        {
            if (line[i] == '(')
                floor++;
            else if (line[i] == ')')
                floor--;

            if (floor == -1)
                std::cout << i << std::endl;
        }
        
        std::cout << floor << std::endl;
    }
    else
    {
        std::cout << "File is not open" << std::endl;
    }

    return 0;
}

