/**
 * @file UnknownRori_New.hpp
 * @author UnknownRori
 * @brief A overloaded version of new keyword for debugging purposes
 * @version 0.1
 * @date 2022-07-04
 *
 * @copyright Copyright (c) 2022
 *
 */

#pragma once

#ifndef UNKNOWNRORI_NEW_HPP
#define UNKNOWNRORI_NEW_HPP

#ifdef UNKNOWNRORI_DEBUG_MODE

#include <iostream>

static size_t __ALLOCATED_TIME = 0;

void *operator new(size_t size)
{
    __ALLOCATED_TIME++;
    std::cout << "Allocated!"
              << "\n";
    return malloc(size);
}

void *operator new[](size_t size)
{
    __ALLOCATED_TIME++;
    std::cout << "Allocated!"
              << "\n";
    return malloc(size);
}

#endif

#endif