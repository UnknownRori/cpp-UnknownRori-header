/**
 * @file MemoryInStream.hpp
 * @author UnknownRori
 * @brief
 * @version 0.1
 * @date 2022-07-21
 *
 * @copyright Copyright (c) 2022
 *
 */

#pragma once

#ifndef UNKNOWNRORI_MEMORYINSTREAM_HPP
#define UNKNOWNRORI_MEMORYINSTREAM_HPP

#include "./MemoryStream.hpp"

namespace Rori
{
    /**
     * @brief A serializer for a class or type into MemoryStream<T>
     *
     * @tparam T
     */
    template <typename T>
    class MemoryInStream
    {
    protected:
        // Only reference stored in here so no housekeeping needed (probably)
        T *m_objectToSerialize = nullptr;
        Rori::MemoryStream<T> *m_memoryStream = nullptr;
        bool m_notByReference = false;

    public:
        /**
         * @brief Initialize Rori::MemoryInStream to serialize passed <T*>
         *
         * @param objectToSerialize
         */
        MemoryInStream(T *objectToSerialize) : m_objectToSerialize(objectToSerialize) {}

        /**
         * @brief Initialize Rori::MemoryInStream to serialize passed <T> this will create a copy on the heap
         *
         * @param objectToSerialize
         */
        MemoryInStream(T objectToSerialize)
        {
            this->m_objectToSerialize = new T(objectToSerialize);
            this->m_notByReference = true;
        }

        /**
         * @brief Serialize the passed <T> on initialization and serialize it on the heap
         * and then return a pointer that hold the memory stream
         *
         * @return MemoryStream<T>*
         */
        MemoryStream<T> *serializeHeap()
        {
            if (this->m_memoryStream == nullptr)
                this->m_memoryStream = new Rori::MemoryStream<T>((char *)this->m_objectToSerialize);

            return this->m_memoryStream;
        }

        /**
         * @brief Serialize the passed <T> on initialization and serialize on the stack
         *
         * @return MemoryStream<T>
         */
        MemoryStream<T> serializeStack()
        {
            return MemoryStream<T>((char *)this->m_objectToSerialize);
        }

        virtual ~MemoryInStream()
        {
            if (this->m_notByReference)
                delete m_objectToSerialize;
        }
    };
}

#endif