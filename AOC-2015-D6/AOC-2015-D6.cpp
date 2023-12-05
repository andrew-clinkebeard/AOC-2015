// AOC-2015-D6.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <array>
#include <vector>
#include <new>   

typedef int light_t;

void toggle(std::string instr, std::vector<std::vector<light_t>> &lightGrid);
void on(std::string instr, std::vector<std::vector<light_t>> &lightGrid);
void off(std::string instr, std::vector<std::vector<light_t>> &lightGrid);

void toggle2(std::string instr, std::vector<std::vector<light_t>>& lightGrid);
void on2(std::string instr, std::vector<std::vector<light_t>>& lightGrid);
void off2(std::string instr, std::vector<std::vector<light_t>>& lightGrid);

int main()
{
    //array for points
    std::vector<std::vector<light_t>> lightGrid{};

    for (int i = 0; i < 1000; ++i)
    {
        std::vector<light_t> temp;
        for (int j = 0; j < 1000; ++j)
        {
            temp.push_back(0);
        }
        lightGrid.push_back(temp);
    }
    
    //open file
    std::ifstream inFile;

    inFile.open("C:\\Users\\Andrew Clinkenbeard\\source\\repos\\AOC-2015\\AOC-2015-D6\\2015_day6.txt");
    // inFile.open("C:\\Users\\Andrew Clinkenbeard\\Documents\\Advent of Code\\test_doc.txt");

    if (inFile.is_open())
    {
        std::string line;
        while (std::getline(inFile, line))
        {
            

            if (line.find("turn on") == 0) //bit wise or with 1
            {
                line.erase(0,8);
                on2(line, lightGrid);
            }
            else if (line.find("turn off") == 0) //bit wise and with 0
            {
                line.erase(0, 9);
                off2(line, lightGrid);
            }
            else if (line.find("toggle") == 0) //xor with 1
            {
                line.erase(0, 7);
                toggle2(line, lightGrid);
            }
        }

        int sum = 0;
        for (int i = 0; i < lightGrid.size(); ++i)
        {
            for (int j = 0; j < lightGrid.size(); ++j)
            {
                if (lightGrid[i][j])
                    sum += lightGrid[i][j];
            }
        }
        std::cout << sum << std::endl;
    }
    else
    {
        std::cout << "File is not open" << std::endl;
    }

    return 0;
}



void toggle(std::string instr, std::vector<std::vector<light_t>> &lightGrid)
{
    std::stringstream tokens(instr);
    int x1, x2;
    int y1, y2;
    char buff{};
    std::string temp{};

    tokens >> x1 >> buff >> y1 >> temp >> x2 >> buff >> y2;
    //std::cout << x1 << "," << y1 << "\t" << x2 << "," << y2 << std::endl;
    //std::cout << "toggle" << std::endl;
    for (int i = x1; i <= x2; ++i)
    {
        for (int j = y1; j <= y2; ++j)
        {
            lightGrid[i][j] = !lightGrid[i][j];
            //lightGrid[i][j] = (lightGrid[i][j] ^ 0x01) & 0x01;
            //std::cout << (int)lightGrid[i][j] << std::endl;
        }
    }
}
void on(std::string instr, std::vector<std::vector<light_t>> &lightGrid)
{
    std::stringstream tokens(instr);
    int x1, x2;
    int y1, y2;
    char buff{};
    std::string temp{};

    tokens >> x1 >> buff >> y1 >> temp >> x2 >> buff >> y2;
    //std::cout << x1 << "," << y1 << "\t" << x2 << "," << y2 << std::endl;
    //std::cout << "on" << std::endl;
    for (int i = x1; i <= x2; ++i)
    {
        for (int j = y1; j <= y2; ++j)
        {
            lightGrid[i][j] = true;
            //lightGrid[i][j] = lightGrid[i][j] | 0x01;
            //std::cout << (int)lightGrid[i][j] << std::endl;
        }
    }
}
void off(std::string instr, std::vector<std::vector<light_t>> &lightGrid)
{
    std::stringstream tokens(instr);
    int x1, x2;
    int y1, y2;
    char buff{};
    std::string temp{};

    tokens >> x1 >> buff >> y1 >> temp >> x2 >> buff >> y2;
    //std::cout << x1 << "," << y1 << "\t" << x2 << "," << y2 << std::endl;
    //std::cout << "off" << std::endl;
    for (int i = x1; i <= x2; ++i)
    {
        for (int j = y1; j <= y2; ++j)
        {
            lightGrid[i][j] = false;
            //lightGrid[i][j] = lightGrid[i][j] & 0x01;
            //std::cout << (int)lightGrid[i][j] << std::endl;
        }
    }
}


void toggle2(std::string instr, std::vector<std::vector<light_t>>& lightGrid)
{
    std::stringstream tokens(instr);
    int x1, x2;
    int y1, y2;
    char buff{};
    std::string temp{};

    tokens >> x1 >> buff >> y1 >> temp >> x2 >> buff >> y2;
    for (int i = x1; i <= x2; ++i)
    {
        for (int j = y1; j <= y2; ++j)
        {
            lightGrid[i][j] += 2;
        }
    }
}
void on2(std::string instr, std::vector<std::vector<light_t>>& lightGrid)
{
    std::stringstream tokens(instr);
    int x1, x2;
    int y1, y2;
    char buff{};
    std::string temp{};

    tokens >> x1 >> buff >> y1 >> temp >> x2 >> buff >> y2;

    for (int i = x1; i <= x2; ++i)
    {
        for (int j = y1; j <= y2; ++j)
        {
            lightGrid[i][j]++;
        }
    }
}
void off2(std::string instr, std::vector<std::vector<light_t>>& lightGrid)
{
    std::stringstream tokens(instr);
    int x1, x2;
    int y1, y2;
    char buff{};
    std::string temp{};

    tokens >> x1 >> buff >> y1 >> temp >> x2 >> buff >> y2;
    //std::cout << x1 << "," << y1 << "\t" << x2 << "," << y2 << std::endl;
    //std::cout << "off" << std::endl;
    for (int i = x1; i <= x2; ++i)
    {
        for (int j = y1; j <= y2; ++j)
        {
            lightGrid[i][j]--;
            if (lightGrid[i][j] < 0)
                lightGrid[i][j] = 0;
        }
    }
}