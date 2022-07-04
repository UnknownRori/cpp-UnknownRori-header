/**
 * @file UnknownRori_Cast.hpp
 * @author UnknownRori
 * @brief My collection of cast
 * @version 0.1
 * @date 2022-07-04
 *
 * @copyright Copyright (c) 2022
 *
 */

#pragma once

#ifndef UNKNOWNRORI_CAST_HPP
#define UNKNOWNRORI_CAST_HPP

namespace rori
{
    /**
     * @brief Primitive data casting
     *
     * @param data
     * @return T
     */
    template <typename T, typename V>
    T cast(V data)
    {
        return (T)data;
    }
}

#endif