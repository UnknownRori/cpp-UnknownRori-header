/**
 * @file main.cpp
 * @author UnknownRori
 * @brief This is place for manual testing
 * @version 0.1
 * @date 2022-07-04
 *
 * @copyright Copyright (c) 2022
 *
 */

#define UNKNOWNRORI_DEBUG_MODE

#include <iostream>
#include "./include/UnknownRori/UnknownRori.hpp"

int main()
{
    Rori::Vector<i32> myVec = {1, 2, 3, 4};
    for (size_t i = 0; i < 4; i++)
    {
        std::cout << myVec[i] << std::endl;
    }

    return 0;
}