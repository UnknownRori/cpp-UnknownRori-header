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

    public:
        /**
         * @brief Initialize Rori::MemoryInStream to serialize passed <T*>
         *
         * @param objectToSerialize
         */
        MemoryInStream(T *objectToSerialize) : m_objectToSerialize(objectToSerialize) {}

        /**
         * @brief Serialize the passed <T> and return a Rori::MemoryStream<T>
         *
         * @return MemoryStream<T>
         */
        MemoryStream<T> serialize()
        {
            return MemoryStream<T>((char *)this->m_objectToSerialize);
        }

        virtual ~MemoryInStream() {}
    };
}

#endif