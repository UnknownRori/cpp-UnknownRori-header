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

namespace Rori
{
    /**
     * @brief Static array allocation, this is nearly identical with the standard library
     *
     * @tparam T
     * @tparam S
     */
    template <typename T, size_t S>
    class Array
    {
    public:
#ifdef UNKNOWNRORI_ITERATOR_HPP
        using ValueType = T;
        using Iterator = ArrayIterator<Array<T, S>>;
#endif

        Array()
        {
        }

        /**
         * @brief Construct a new Array object using std::initialzier_list
         *
         * @param list
         */
        Array(std::initializer_list<ValueType> list)
        {
#ifdef UNKNOWNRORI_DEBUG_MODE
            if (list.size() > S)
            {
                std::cout << "Failed to initialize array, too large!" << std::endl;
                exit(1);
            }
#endif
            int i = 0;
            for (const ValueType &value : list)
            {
                m_data[i] = std::move(value);
                i++;
            }
        }

        /**
         * @brief Get the array size
         *
         * @return size_t
         */
        size_t size() const
        {
            return S;
        }

#ifdef UNKNOWNRORI_ITERATOR_HPP
        /**
         * @brief Return an begin Array Iterator
         *
         * @return ArrayIterator
         */
        Iterator begin()
        {
            return Iterator(m_data);
        }

        /**
         * @brief Return an end Array Iterator
         *
         * @return ArrayIterator
         */
        Iterator end()
        {
            return Iterator(m_data + S);
        }
#endif

        /**
         * @brief do some hacky stuff to allow access using array index
         *
         * @param index
         * @return T&
         */
        T &operator[](int index)
        {
#ifdef UNKNOWNRORI_DEBUG_MODE
            if (S <= index)
            {
                std::cout << "Array out of index, index : " << index << " , Array Size : " << S << std::endl;
                exit(1);
            }
#endif
            return m_data[index];
        }

        /**
         * @brief do some hacky stuff to allow access using array index but it's a const
         *
         * @param index
         * @return const T&
         */
        const T &operator[](int index) const
        {
#ifdef UNKNOWNRORI_DEBUG_MODE
            if (S <= index)
            {
                std::cout << "Array out of index, index : " << index << " , Array Size : " << S << std::endl;
                exit(1);
            }
#endif
            return *m_data[index];
        }

    private:
        T m_data[S];
    };
}

#endif