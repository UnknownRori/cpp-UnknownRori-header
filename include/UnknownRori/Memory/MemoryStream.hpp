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
        MemoryStream()
        {
            this->m_Allocate();
        }

        MemoryStream(char *ptr)
        {
            this->m_Allocate();
            memcpy(this->m_ptr, ptr, sizeof(T));
        }

        const std::size_t size()
        {
            return sizeof(T);
        }

        void set(char *ptr)
        {
            if (this->m_ptr != nullptr)
                delete[] this->m_ptr;

            this->m_ptr = ptr;
        }

        const char *get() const
        {
            return this->m_ptr;
        }

        char *get()
        {
            return this->m_ptr;
        }

        void *getVoidPtr()
        {
            return (void *)this->m_ptr;
        }

        ~MemoryStream()
        {
            delete[] this->m_ptr;
        }

    private:
        void m_Allocate()
        {
            this->m_ptr = new char[sizeof(T)];
        }
    };
}

#endif