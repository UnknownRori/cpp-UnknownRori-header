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

#ifndef UNKNOWNRORI_UNIQUEPOINTER_HPP
#define UNKNOWNRORI_UNIQUEPOINTER_HPP

namespace Rori
{
    template <typename T>
    class UniquePointer
    {
    private:
        T *m_ptr = nullptr;

    public:
        UniquePointer(T *ptr) : m_ptr(ptr) {}

        virtual ~UniquePointer()
        {
            delete m_ptr;
        }

        T *release()
        {
            T *out = this->m_ptr;
            this->m_ptr = nullptr;
            return out;
        }

        void reset(T *ptr)
        {
            delete this->m_ptr;
            this->m_ptr = ptr;
        }

        void swap(UniquePointer<T> &other)
        {
            T *temp = other.m_ptr;
            this->m_ptr = other.m_ptr;
            this->m_ptr = temp;
        }

        T &operator*()
        {
            return *(this->m_ptr);
        }

        T *operator->()
        {
            return this->m_ptr;
        }
    };
}

#endif