/**
 * @file Vector.hpp
 * @author UnknownRori
 * @brief My attempt reimplementing vector standard library
 * @version 0.1
 * @date 2022-07-09
 *
 * @copyright Copyright (c) 2022
 *
 */

#pragma once

#ifndef UNKNOWNRORI_VECTOR_HPP
#define UNKNOWNORORI_VECTOR_HPP

namespace Rori
{
    /**
     * @brief Heap Allocated Dynamic Array
     *
     * @tparam T
     */
    template <typename T>
    class Vector
    {
    public:
        /**
         * @brief If nothing passed allocate 10 slot
         *
         */
        Vector()
        {
            Alloc(10);
        }

        /**
         * @brief Allow initialize Vector class using initializer list
         *
         * @param initializer
         */
        Vector(std::initializer_list<T> &&initializer)
        {
            Alloc(initializer.size() * 2);

            int i = 0;
            for (const T &value : initializer)
            {
                m_data[i] = std::move(value);
                i++;
            }
        }

        /**
         * @brief Allow access using array index
         *
         * @param index
         * @return const T&
         */
        const T &operator[](size_t index) const
        {
            return m_data[index];
        }

        /**
         * @brief Allow access using array index
         *
         * @param index
         * @return T&
         */
        T &operator[](size_t index)
        {
            return m_data[index];
        }

    private:
        /**
         * @brief Allocate memory for vector class
         *
         * @param newSize
         */
        void Alloc(size_t newSize)
        {
            T *new_data_block = new T[newSize];

            for (size_t i = 0; i < m_size; i++)
            {
                if (i >= newSize)
                    break;

                new_data_block[i] = std::move(m_data[i]);
            }

            m_size = newSize;
            delete[] m_data;
            m_data = new_data_block;
        }
        T *m_data = nullptr;
        size_t m_size = 0;
    };
}

#endif