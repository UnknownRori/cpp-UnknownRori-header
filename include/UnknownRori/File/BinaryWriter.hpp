/**
 * @file BinaryWriter.hpp
 * @author UnknownRori
 * @brief From Rori::MemoryStream<T> to binary file and vice versa
 * @version 0.1
 * @date 2022-07-22
 *
 * @copyright Copyright (c) 2022
 *
 */

#pragma once

#ifndef UNKNOWNRORI_BINARYWRITER_HPP
#define UNKNOWNRORI_BINARYWRITER_HPP

#include <fstream>
#include "../Memory/MemoryStream.hpp"

#ifdef UNKNOWNRORI_DEBUG_MODE

#ifdef UNKNOWNRORI_LOG_HPP

#include "../Utility/Log.hpp"

#endif
#else
#define __ERROR(message)

#endif

namespace Rori
{
    template <typename T>
    class BinaryWriter
    {
    protected:
        // Only hold a reference
        Rori::MemoryStream<T> *m_ptrStream = nullptr;

        // Runtime
        std::fstream *m_file = nullptr;

    public:
        BinaryWriter() {}
        BinaryWriter(const char filename[])
        {
            this->setFile(filename);
        }
        BinaryWriter(const char filename[], Rori::MemoryStream<T> *stream) : m_ptrStream(stream)
        {
            this->setFile(filename);
        }

        virtual ~BinaryWriter()
        {
            this->m_file->close();
            delete this->m_file;
        }

        void setFile(const char filename[])
        {
            if (this->m_file != nullptr)
                delete this->m_file;

            this->m_file = new std::fstream(filename, std::ios::out | std::ios::trunc | std::ios::binary);
        }

        void setMemoryStream(Rori::MemoryStream<T> *stream)
        {
            this->m_ptrStream = stream;
        }

        bool isGood()
        {
#ifdef UNKNOWNRORI_DEBUG_MODE
            if (this->m_file == nullptr || this->m_ptrStream == nullptr)
            {
                __ERROR("std::fstream has not yet initialized, have you run method setFile or maybe you forgot the Rori::MemoryStream<T>")
                exit(1);
            }
#endif
            return this->m_file->good();
        }

        bool isOpen()
        {
#ifdef UNKNOWNRORI_DEBUG_MODE
            if (this->m_file == nullptr || this->m_ptrStream == nullptr)
            {
                __ERROR("std::fstream has not yet initialized, have you run method setFile or maybe you forgot the Rori::MemoryStream<T>")
                exit(1);
            }
#endif
            return this->m_file->is_open();
        }

        void close()
        {
#ifdef UNKNOWNRORI_DEBUG_MODE
            if (this->m_file == nullptr || this->m_ptrStream == nullptr)
            {
                __ERROR("std::fstream has not yet initialized, have you run method setFile or maybe you forgot the Rori::MemoryStream<T>")
                exit(1);
            }
#endif
            this->m_file->close();
        }

        bool write()
        {
#ifdef UNKNOWNRORI_DEBUG_MODE
            if (this->m_file == nullptr)
            {
                __ERROR("std::fstream has not yet initialized, have you run method setFile")
                exit(1);
            }
#endif

            if (this->m_file->is_open())
            {
                char *src = this->m_ptrStream->get();

                this->m_file->write(src, sizeof(T));

                return this->isGood();
            }

            return false;
        }
    };
}

#endif