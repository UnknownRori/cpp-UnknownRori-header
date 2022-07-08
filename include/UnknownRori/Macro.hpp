/**
 * @file Macro.hpp
 * @author UnknownRori
 * @brief A collection of my macro
 * @version 0.1
 * @date 2022-07-04
 *
 * @copyright Copyright (c) 2022
 *
 */

#pragma once

#ifndef UNKNOWNRORI_MACRO_HPP
#define UNKNOWNRORI_MACRO_HPP

// Check the size of passed array
#define __SIZE(array) (sizeof((array)) / sizeof((array)[0]))

// Get the current filename in relative with project root
#define __FILENAME__ (strrchr(__FILE__, '/') ? strrchr(__FILE__, '/') + 1 : __FILE__)

// Logging
#define __LOG(message) \
    std::cout << "[" << __LINE__ << "] " << __FILENAME__ << " : " << message << std::endl

#endif