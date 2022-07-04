/**
 * @file UnknownRori_Delete.hpp
 * @author UnknownRori
 * @brief A overloaded version of delete keyword for debugging purposes
 * @version 0.1
 * @date 2022-07-04
 *
 * @copyright Copyright (c) 2022
 *
 */

#pragma once

#ifndef UNKNOWNRORI_DELETE_HPP
#define UNKNOWNRORI_DELETE_HPP

#include <iostream>

static size_t __DEALLOCATED_TIME = 0;

void operator delete(void *ptr)
{
    __DEALLOCATED_TIME++;
    std::cout << "Deallocated!"
              << "\n";
    free(ptr);
}

void operator delete[](void *ptr)
{
    __DEALLOCATED_TIME++;
    std::cout << "Deallocated!"
              << "\n";
    free(ptr);
}

#endif