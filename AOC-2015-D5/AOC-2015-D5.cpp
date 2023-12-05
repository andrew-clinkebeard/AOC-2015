// AOC-2015-D3.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <fstream>
#include <string>
#include <array>
#include <vector>
#include <tuple>

bool NaughtyOrNice(std::string test);
bool vowelCheck(std::string test);
bool doubleLetter(std::string test);
bool badCombos(std::string test);
bool letterSkip(std::string test);
bool doubleDouble(std::string test);

int checkvowel(std::string str, char c) {
    return std::count(str.begin(), str.end(), c);
}
bool checkvowels(std::string str) {
    return (
        checkvowel(str, 'a') +
        checkvowel(str, 'e') +
        checkvowel(str, 'o') +
        checkvowel(str, 'i') +
        checkvowel(str, 'u')) >= 3;
}

int main()
{
    std::string testString = "ieodomkazucvgmuy";

    if (doubleDouble(testString) && letterSkip(testString))
        std::cout << "Good" << std::endl;
    else 
        std::cout << "bad" << std::endl;

    //open file
    std::ifstream inFile;

    inFile.open("C:\\Users\\Andrew Clinkenbeard\\source\\repos\\AOC-2015\\AOC-2015-D5\\2015_day5.txt");

    if (inFile.is_open())
    {
        //get data
        std::string line;

        int goodCountPart1 = 0;
        int goodCountPart2 = 0;

        while (std::getline(inFile, line))
        {
            if (NaughtyOrNice(line))
            {
                ++goodCountPart1;
            }

            if(doubleDouble(line) && letterSkip(line))
                goodCountPart2++;
 
            
        }

        std::cout << "Part 1: " << goodCountPart1 << std::endl;
        std::cout << "Part 2: " << goodCountPart2 << std::endl;
    }
    else
    {
        std::cout << "File is not open" << std::endl;
    }

    //close file
    inFile.close();

    return 0;
}


//function to check each string
bool NaughtyOrNice(std::string test)
{
    bool result = true;

    //check if it contains 3 or more vowels
    if (!vowelCheck(test))
    //if(!checkvowels(test))
        result = false;

    //check for double letters
    if (!doubleLetter(test))
        result = false;

    //check for invalid combos
    if (!badCombos(test))
        result = false;

    return result;

}

bool vowelCheck(std::string test)
{
    bool flag = false;
    char vowels[5] = { 'a', 'e' , 'i', 'o', 'u' };

    int vowlCount = 0;
    for (int i = 0; i < 5; ++i)
    {
        vowlCount += std::count(test.begin(), test.end(), vowels[i]);
    }
    
    return vowlCount >= 3 ? true : false;
}

bool doubleLetter(std::string test)
{
    bool flag = false;

    for (int i = 0; i < test.length() - 1; ++i)
    {
        if (test[i] == test[i + 1])
            flag = true;
    }

    return flag;
}

bool badCombos(std::string test)
{
    bool flag = true;
    std::string badLetters[4] = { "ab", "cd" , "pq", "xy" };
    
    for (int i = 0; i <4; ++i)
    {
        if (test.find(badLetters[i]) != std::string::npos)
            flag = false;
    }

        return flag;

}

bool letterSkip(std::string test)
{
    bool flag = false;

    for (int i = 0; i < test.length() - 2; ++i)
    {
        if (test[i] == test[i + 2])
            flag = true;
    }

    return flag;
}

bool doubleDouble(std::string test)
{
    //bool flag = false;
    ////vector to hold the pairs and the starting position
    //std::vector < std::tuple<std::string, int>> pairs;
    //std::tuple<std::string, int> temp{};
    //
    ////fill up vector with pairs
    //for (int i = 0; i < test.length() - 1; ++i)
    //{
    //    //put each possible combo of pairs into a vector
    //    temp = std::make_tuple(test.substr(i, 2), i);
    //    pairs.push_back(temp);
    //}

    ////for each pair check others to see if there are possible matches
    //for (int i = 0; i < pairs.size()-1; ++i)
    //{
    //    for (int j = i + 1; j < pairs.size(); ++j)
    //    {
    //        if (std::get<0>(pairs[i]) == std::get<0>(pairs[j]))
    //        {
    //            if ((std::get<1>(pairs[i]) - std::get<1>(pairs[j]) == 1))
    //            {
    //                //these are too close its bad
    //                flag = false;
    //            }
    //            else
    //            {
    //                //they are good
    //                flag = true;
    //            }
    //        }
    //    }
    //}

    bool correct = false;
    std::string pair;
    std::vector<int> pos;

    for (int i = 0; i < test.size() - 1; i++) {
        pair = test.substr(i, 2);
        pos.clear();
        for (int j = 0; j < test.size() - 1; j++) {
            if (pair.compare(test.substr(j, 2)) == 0) {
                pos.push_back(j);
            }
        }

        /*
        std::cout << test << "----------------------------------" << std::endl;
        for (auto p : pos) std::cout << p << std::endl;
        std::cout << "----------------------------------" << std::endl;
        */

        if (pos.size() > 1) {
            for (int j = 0; j < pos.size() - 1; ++j) {
                if (abs(pos[j] - pos[j + 1]) > 1)
                    correct = true;
            }
        }
    }
    return correct;




    //return flag;
}
    
