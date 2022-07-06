/**
 * @file Array.hpp
 * @author UnknownRori
 * @brief My own array implementation of standard c++ library
 * @version 0.1
 * @date 2022-07-06
 *
 * @copyright Copyright (c) 2022
 *
 */

#pragma once

#ifndef UNKNOWNRORI_ARRAY_HPP
#define UNKNOWNRORI_ARRAY_HPP

namespace rori
{
    /**
     * @brief Static array allocation, this is nearly identical with the standard library
     *
     * @tparam T
     * @tparam S
     */
    template <typename T, size_t S>
    class array
    {
    public:
        // Get the current size of the array
        size_t size() const
        {
            return S;
        }

        // do some hacky stuff
        T &operator[](int index)
        {
#ifdef UNKNOWNRORI_DEBUG_MODE
            if (S < index)
            {
                std::cout << "Array out of index, index : " << index << " , Array Size : " << S << std::endl;
                exit(1);
            }
#endif
            return m_Data[index];
        }

        // do some hacky stuff but const
        const T &operator[](int index) const
        {
            return *m_Data[index];
        }

    private:
        T m_Data[S];
    };
}

#endif