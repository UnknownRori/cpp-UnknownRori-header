/**
 * @file Color.hpp
 * @author UnknownRori
 * @brief This where to color your console
 * @version 0.1
 * @date 2022-07-09
 *
 * @copyright Copyright (c) 2022
 *
 */

#pragma once
#ifndef UNKNOWNRORI_COLOR_HPP
#define UNKNOWNRORI_COLOR_HPP

namespace Rori
{
    /**
     * @brief Use color formatting when using std::cout << "\e[{colorcode}m \e[0m"
     *
     */
    enum Color
    {
        // Formatting
        NORMAL = 0,
        BOLD = 1,
        DIM = 2,
        UNDERLINE = 4,
        BLINK = 5,
        REVERSE = 7,
        HIDDEN = 8,

        // Foreground
        BLACK = 31,
        RED = 31,
        GREEN = 32,
        YELLOW = 33,
        BLUE = 34,
        MAGNETA = 25,
        PURPLE = 35,
        CYAN = 36,
        LIGHT_WHITE = 38,
        GRAY = 90,

        // Background
        BG_BLACK = 40,
        BG_RED = 41,
        BG_GREEN = 42,
        BG_YELLOW = 43,
        BG_BLUE = 44,
        BG_MAGNETA = 45,
        BG_CYAN = 46,
        BG_LIGHT_GRAY = 47,
        BG_DEFAULT = 49,
        BG_DARK_GRAY = 100,
        BG_LIGHT_RED = 101,
        BG_LIGHT_GREEN = 102,
        BG_LIGHT_YELLOW = 103,
        BG_LIGHT_BLUE = 104,
        BG_LIGHT_MAGNETA = 105,
        BG_LIGHT_CYAN = 106,
        BG_WHITE = 107,
    };
}

#endif