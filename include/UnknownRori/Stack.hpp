/**
 * @file Stack.hpp
 * @author UnknownRori
 * @brief My own stack implementation on c++ standard library
 * @version 0.1
 * @date 2022-07-04
 *
 * @copyright Copyright (c) 2022
 *
 */

#pragma once

#ifndef UNKNOWNRORI_STACK_HPP
#define UNKNOWNRORI_STACK_HPP

namespace rori
{
    /**
     * @brief Stack based allocation
     *
     * @tparam T
     */
    template <typename T>
    class stack
    {
    public:
        stack()
        {
            m_data = new T[2];
            m_stackSize = 2;
        }

        virtual ~stack()
        {
            delete[] m_data;
        }

        // Push the value into stack
        void push(const T value)
        {
            if (m_pointer >= m_stackSize)
            {
                alloc(m_stackSize * 2);
            }

            m_data[m_pointer] = value;
            m_pointer++;
        }

        // Pop the current pointer value
        T pop()
        {

#ifdef UNKNOWNRORI_DEBUG_MODE
            if (m_pointer < 0)
            {
                std::cout << "Out of bound" << std::endl;
                exit(1);
            }
#endif
            if (m_pointer <= m_stackSize / 2)
            {
                alloc(m_stackSize / 2);
            }

            m_pointer--;
            return m_data[m_pointer];
        }

        // Return the stack size
        const size_t size() const
        {
            return m_pointer;
        }

        // This is used for debugging purpose
        // return the current stack size allocation slot
        const size_t getStackSize() const
        {
            return m_stackSize;
        }

        // Check if the stack is empty
        bool isEmpty()
        {
            if (m_pointer > 0)
                return true;

            return false;
        }

        // Get the top value
        T top()
        {
#ifdef UNKNOWNRORI_DEBUG_MODE
            if (this->isEmpty())
            {
                std::cout << "Stack is currently empty" << std::endl;
                exit(1);
            }
#endif
            return m_data[m_pointer - 1];
        }

        // Empty the stack
        void empty()
        {
            while (true)
            {
                if (this->isEmpty())
                    this->pop();
                else
                    break;
            }
        }

    private:
        // Dynamically allocate memory
        void alloc(size_t newSize)
        {
            T *newData = new T[newSize];

            for (size_t i = 0; i < m_stackSize; i++)
            {
                if (i >= newSize)
                    break;

                newData[i] = std::move(m_data[i]);
            }

            m_stackSize = newSize;

            delete[] m_data;
            m_data = newData;
        }

        T *m_data = nullptr;
        size_t m_pointer = 0;
        size_t m_stackSize = 0;
    };
}

#endif