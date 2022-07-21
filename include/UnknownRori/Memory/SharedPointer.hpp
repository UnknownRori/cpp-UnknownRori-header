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

    public:
        SharedPointer(T *ptr) : m_ptr(ptr) {}

        virtual ~SharedPointer()
        {
            delete m_ptr;
        }

        T *operator->()
        {
            return this->m_ptr;
        }
    };
}

#endif