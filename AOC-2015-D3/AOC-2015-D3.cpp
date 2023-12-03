// AOC-2015-D3.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <fstream>
#include <vector>
#include <tuple> 
#include <set>

//north(^), south(v), east(> ), or west(< )
enum directions
{
    north = '^',
    south = 'v',
    east = '>',
    west = '<'
};

int main()
{
    //vector of tuples containg each of the cordinates of a house visited
    std::vector<std::tuple<int, int>>santaHouses{};
    std::vector<std::tuple<int, int>>houses{};

    //create a set to use to place unique houses and then get size to get total number of houses visited.
    std::set<std::tuple<int, int>> uniqueHouses;

    //open file
    std::ifstream inFile;

    inFile.open("C:\\Users\\Andrew Clinkenbeard\\Documents\\Advent of Code\\2015_day3.txt");
   // inFile.open("C:\\Users\\Andrew Clinkenbeard\\Documents\\Advent of Code\\test_doc.txt");

    if (inFile.is_open())
    {
        //get data
        std::string line;
        inFile >> line;

        //starting positions
        std::tuple<int, int>currentPositionSanta = { 0,0 };
        std::tuple<int, int>currentPositionRoboSanta = { 0,0 };

        //insert starting house into list of houses
        santaHouses.push_back(currentPositionSanta);
        uniqueHouses.insert(currentPositionSanta);

        int numHouses = 0;

        for (char c : line)
        {

            switch (c)
            {
            case north:
                //increase Y pos by 1
                if( numHouses%2== 0)
                    std::get<1>(currentPositionSanta) = std::get<1>(currentPositionSanta) + 1;
                else if (numHouses%2 ==1)
                    std::get<1>(currentPositionRoboSanta) = std::get<1>(currentPositionRoboSanta) + 1;
               
                break;
            case south:
                //decrease Y pos by 1
                if (numHouses % 2 == 0)
                    std::get<1>(currentPositionSanta) = std::get<1>(currentPositionSanta) - 1;
                else if (numHouses % 2 == 1)
                    std::get<1>(currentPositionRoboSanta) = std::get<1>(currentPositionRoboSanta) - 1;
                break;
            case east:
                //increase X pos by 1 
                if (numHouses % 2 == 0)
                    std::get<0>(currentPositionSanta) = std::get<0>(currentPositionSanta) + 1;
                else if (numHouses % 2 == 1)
                    std::get<0>(currentPositionRoboSanta) = std::get<0>(currentPositionRoboSanta) + 1;
                break;
            case west:
                //decrease X pos by 1
                if (numHouses % 2 == 0)
                    std::get<0>(currentPositionSanta) = std::get<0>(currentPositionSanta) - 1;
                else if (numHouses % 2 == 1)
                    std::get<0>(currentPositionRoboSanta) = std::get<0>(currentPositionRoboSanta) - 1;
                break;
            default:
                break;
            }

            uniqueHouses.insert(currentPositionSanta);
            uniqueHouses.insert(currentPositionRoboSanta);

            numHouses++;
        }

        //print out total number of unique houses
        std::cout << uniqueHouses.size() << std::endl;
        std::cout << numHouses << std::endl;
    }
    else
    {
        std::cout << "File is not open" << std::endl;
    }

    return 0;
}