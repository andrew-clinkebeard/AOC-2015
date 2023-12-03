// AOC-2015-D4.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <numeric>
#include <string>
#include "md5.h"

int main()
{
    std::string secretKey = "ckczppom";
    bool found = false;

    //secretKey += std::to_string(609043);
    //std::cout << secretKey << std::endl;
    //std::cout << std::hex << md5(secretKey) << std::endl;
    
    //number to append to test
    uint32_t testNum = 0;

    std::string testString{};
    std::string md5Result{};
    do
    {
        //combine secret key with current number to check
        testString = secretKey + std::to_string(testNum);

        //do md5 hash calc
        md5Result = MD5(testString).hexdigest();
        
        if (testNum == 1000000000000)
        {
            std::cout << "ERROR: too high" << std::endl;
            found = true;
        }
        else if (md5Result.find("000000") == 0)//(md5Result.substr(0, 5) == "000000")
        {
            found = true;
            std::cout << testNum << std::endl;
        }
        else
            testNum++;


    } while (!found);
}
