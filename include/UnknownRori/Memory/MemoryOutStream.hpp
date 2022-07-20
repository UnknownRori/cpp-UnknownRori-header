/**
 * @file MemoryOutStream.hpp
 * @author UnknownRori
 * @brief
 * @version 0.1
 * @date 2022-07-21
 *
 * @copyright Copyright (c) 2022
 *
 */

#pragma once

#ifndef UNKNOWNRORI_MEMORYOUTSTREAM_HPP
#define UNKNOWNRORI_MEMORYOUTSTREAM_HPP

#include "./MemoryStream.hpp"

namespace Rori
{
    /**
     * @brief A deserializer from Rori::MemoryStream<T>
     *
     * @tparam T
     */
    template <typename T>
    class MemoryOutStream
    {
    protected:
        // Only reference stored in here so no housekeeping needed (probably)
        T *m_output = nullptr;
        Rori::MemoryStream<T> *m_memoryToDeserialize = nullptr;

    public:
        /**
         * @brief Initialize <T>MemoryOutStream object to deserialize Rori::MemoryStream<T>
         *
         * @param objectToSerialize
         */
        MemoryOutStream(Rori::MemoryStream<T> *memoryToDeserialize) : m_memoryToDeserialize(memoryToDeserialize) {}

        /**
         * @brief Deserialize and put the value into heap allocated,
         * if this method called it will detach from Rori::MemoryStream<T> reference
         *
         * @return T*
         */
        T *deserialzieHeap()
        {
            if (m_output == nullptr)
                this->m_output = new T(*((T *)(this->m_memoryToDeserialize->get())));

            return this->m_output;
        }

        /**
         * @brief Deserialize and put the value into stack allocated,
         * the value will reflect on reference in Rori::MemoryStream<T>
         *
         * @return T
         */
        T deserializeStack()
        {
            return *(T *)(this->m_memoryToDeserialize->get());
        }

        virtual ~MemoryOutStream() {}
    };
}

#endif