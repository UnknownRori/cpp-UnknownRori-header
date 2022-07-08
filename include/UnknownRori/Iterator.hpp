/**
 * @file Iterator.hpp
 * @author UnknownRori
 * @brief A place implementation of iteration
 * @version 0.1
 * @date 2022-07-09
 *
 * @copyright Copyright (c) 2022
 *
 */

#pragma once

#ifndef UNKNOWNRORI_ITERATOR_HPP
#define UNKNOWNRORI_ITERATOR_HPP

namespace Rori
{
    /**
     * @brief Array based iterator
     *
     * @tparam Array
     */
    template <typename Array>
    class ArrayIterator
    {
    public:
        using ValueType = typename Array::ValueType;
        using PointerType = ValueType *;
        using ReferenceType = ValueType &;

        /**
         * @brief Construct a new Array Iterator object
         *
         * @param ptr
         */
        ArrayIterator(PointerType ptr)
        {
            m_ptr = ptr;
        }

        /**
         * @brief do some hacky pointer stuff
         *
         * @return ArrayIterator&
         */
        ArrayIterator &operator++()
        {
            m_ptr++;
            return *this;
        }

        /**
         * @brief do some hacky pointer stuff
         *
         * @return ArrayIterator
         */
        ArrayIterator operator++(int)
        {
            ArrayIterator iterator = *this;
            ++(*this);
            return iterator;
        }

        /**
         * @brief do some hacky pointer stuff
         *
         * @return ArrayIterator&
         */
        ArrayIterator &operator--()
        {
            m_ptr--;
            return *this;
        }

        /**
         * @brief do some hacky pointer stuff
         *
         * @return ArrayIterator
         */
        ArrayIterator operator--(int)
        {
            ArrayIterator iterator = *this;
            --(*this);
            return iterator;
        }

        /**
         * @brief do some hacky stuff to allow access using array index
         *
         * @param index
         * @return ReferenceType
         */
        ReferenceType operator[](size_t index)
        {
            return *(m_ptr + index);
        }

        /**
         * @brief To allow use arrow keyword on the iterator
         *
         * @return PointerType
         */
        PointerType operator->()
        {
            return m_ptr;
        }

        /**
         * @brief To allow use arrow keyword on the iterator
         *
         * @return ReferenceType
         */
        ReferenceType operator*()
        {
            return *m_ptr;
        }

        bool operator==(const ArrayIterator &other) const
        {
            return m_ptr == other.m_ptr;
        }

        bool operator!=(const ArrayIterator &other) const
        {
            return !(*this == other);
        }

    private:
        PointerType m_ptr = nullptr;
    };
}

#endif