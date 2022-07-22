/**
 * @file SharedPointer.hpp
 * @author UnknownRori
 * @brief A re-implementation of standard memory library shared pointer
 * @version 0.1
 * @date 2022-07-21
 *
 * @copyright Copyright (c) 2022
 *
 */

#pragma once

#ifndef UNKNOWNRORI_SHAREDPOINTER_HPP
#define UNKNOWNRORI_SHAREDPOINTER_HPP

namespace Rori
{
    template <typename T>
    class SharedPointer
    {
    private:
        T *m_ptr = nullptr;
        int *m_counter = nullptr;

    public:
        SharedPointer(T *ptr) : m_ptr(ptr), m_counter(new int(0)) {}

        SharedPointer(SharedPointer<T> &other)
        {
            this->m_ptr = other.m_ptr;
            this->m_counter = other.m_counter;
            (*this->m_counter)++;
        }

        virtual ~SharedPointer()
        {
            (*this->m_counter)--;
            if ((*this->m_counter) < 0)
            {
                delete m_ptr;
                delete this->m_counter;
            }
        }

        T &operator*()
        {
            return *(this->m_ptr);
        }

        T *operator->()
        {
            return this->m_ptr;
        }

        const T &operator[](const size_t &index) const
        {
            return this->m_ptr[index];
        }

        T &operator[](const size_t &index)
        {
            return this->m_ptr[index];
        }
    };
}

#endif