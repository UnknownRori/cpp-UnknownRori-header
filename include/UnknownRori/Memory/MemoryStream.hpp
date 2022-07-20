/**
 * @file MemoryStream.hpp
 * @author UnknownRori
 * @brief
 * @version 0.1
 * @date 2022-07-21
 *
 * @copyright Copyright (c) 2022
 *
 */

#pragma once

#ifndef UNKNOWNRORI_MEMORYSTREAM_HPP
#define UNKNOWNRORI_MEMORYSTREAM_HPP

namespace Rori
{
    /**
     * @brief A class that hold a converted pointer from <T> to char it's still affected by reference change
     *
     * @tparam T
     */
    template <typename T>
    class MemoryStream
    {
    protected:
        char *m_ptr = nullptr;

    public:
        MemoryStream();
        MemoryStream(char *ptr) : m_ptr(ptr) {}

        void set(char *ptr)
        {
            this->m_ptr = ptr;
        }

        char *get()
        {
            return this->m_ptr;
        }

        ~MemoryStream()
        {
            delete this->m_ptr;
        }
    };
}

#endif