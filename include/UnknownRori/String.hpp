/**
 * @file String.hpp
 * @author UnknownRori
 * @brief A String implementation
 * @version 0.1
 * @date 2022-07-08
 *
 * @copyright Copyright (c) 2022
 *
 */

#pragma once

#ifndef UNKNOWNRORI_STRING_HPP

#include <cstring>

namespace Rori
{
    /**
     * @brief Heap allocated string
     *
     */
    class String
    {
    public:
        /**
         * @brief Construct a new String object
         *
         */
        String()
        {
            //
        }

        /**
         * @brief Construct a new String object
         *
         * @param string_literal
         */
        String(const char string_literal[])
        {
            m_size = strlen(string_literal);
            m_data = new char[m_size];
            // m_data = std::move(string_literal);
            strcpy(m_data, string_literal);
            std::cout << m_data << std::endl;
        }

        void operator=(const char string_literal[])
        {
            if (m_size >= 0)
                delete m_data;

            m_size = strlen(string_literal);
            m_data = new char[m_size];
            strcpy(m_data, string_literal);
            std::cout << m_data << std::endl;
        }

        /**
         * @brief Hacky stuff to allow access using array index
         *
         * @param index
         * @return const char&
         */
        const char &operator[](const int &index) const
        {
#ifdef UNKNOWNRORI_DEBUG_MODE
            if (index >= m_size)
            {
                std::cout << "Out of bound" << std::endl;
                exit(1);
            }
#endif
            return m_data[index];
        }

        /**
         * @brief Hacky stuff to allow access using array index
         *
         * @param index
         * @return const char&
         */
        char &operator[](const int &index)
        {
#ifdef UNKNOWNRORI_DEBUG_MODE
            if (index >= m_size)
            {
                std::cout << "Out of bound" << std::endl;
                exit(1);
            }
#endif
            return m_data[index];
        }

        /**
         * @brief This will allow to print string in std::cout
         *
         * @param os
         * @param string
         * @return std::ostream&
         */
        friend std::ostream &operator<<(std::ostream &os, const String &string)
        {
            os << string.m_data;
            return os;
        }

    private:
        char *m_data = nullptr;
        size_t m_size = -1;
    };
}

#endif