/**
 * @file Log.hpp
 * @author UnknownRori
 * @brief This is where Logger are defined
 * @version 0.1
 * @date 2022-07-09
 *
 * @copyright Copyright (c) 2022
 *
 */

#ifndef UNKNOWNRORI_LOG_HPP
#define UNKNOWNRORI_LOG_HPP

#ifdef UNKNOWNRORI_DEBUG_MODE

// Get the current filename
#define __FILENAME__ (strrchr(__FILE__, '/') ? strrchr(__FILE__, '/') + 1 : __FILE__)

// Logging with the line and filename that trigger the log

// normal print
#define __LOG(message)           \
    std::cout << "\e[1m[ LOG ] " \
              << "(" << __LINE__ << ") | " << __FILENAME__ << " : " << message << "\e[0m" << std::endl;

// print out the log with yellow color
#define __DEBUG(message)                 \
    std::cout << "\e[1;43m[DEBUG]\e[0m " \
              << "\e[1m(" << __LINE__ << ") | " << __FILENAME__ << " : " << message << "\e[0m" << std::endl;

// print out the log with red color
#define __ERROR(message)                 \
    std::cout << "\e[1;41m[ERROR]\e[0m " \
              << "\e[1m(" << __LINE__ << ") | " << __FILENAME__ << " : " << message << "\e[0m" << std::endl;

#else
#define __LOG(message)
#define __DEBUG(message)
#define __ERROR(message)
#endif

#endif