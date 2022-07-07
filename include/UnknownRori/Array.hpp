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
        using ValueType = T;
        using Iterator = ArrayIterator<Array<T, S>>;

        Array() {}

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