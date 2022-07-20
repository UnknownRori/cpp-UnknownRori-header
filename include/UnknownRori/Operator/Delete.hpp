/**
 * @file Delete.hpp
 * @author UnknownRori
 * @brief A overloaded version of delete keyword for debugging purposes,
 * this can be inaccurate so use it at your own risk
 *
 * @version 0.1
 * @date 2022-07-04
 *
 * @copyright Copyright (c) 2022
 *
 */

#pragma once

#ifndef UNKNOWNRORI_DELETE_HPP
#define UNKNOWNRORI_DELETE_HPP

#ifdef UNKNOWNRORI_DEBUG_MODE

#include <iostream>

static size_t __DEALLOCATED_TIME = 0;
static size_t __TOTAL_DEALLOCATED_SIZE = 0;

void operator delete(void *ptr, std::size_t size)
{
    __DEALLOCATED_TIME++;
    __TOTAL_DEALLOCATED_SIZE += size;

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

#endif