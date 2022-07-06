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

namespace Rori
{
    /**
     * @brief Stack based allocation
     *
     * @tparam T
     */
    template <typename T>
    class Stack
    {
    public:
        Stack()
        {
            m_data = new T[2];
            m_stackSize = 2;
        }

        virtual ~Stack()
        {
            delete[] m_data;
        }

        /**
         * @brief Push the value into stack
         *
         * @param value
         */
        void push(const T &value)
        {
            if (m_pointer >= m_stackSize)
            {
                alloc(m_stackSize * 2);
            }

            m_data[m_pointer] = value;
            m_pointer++;
        }

        /**
         * @brief Add a new element at the top of the stack using newly created element using passed args for it's constructor
         *
         * @tparam Args
         * @param args
         */
        template <class... Args>
        void emplace(Args &&...args)
        {
            this->push(T(args...));
        }

        /**
         * @brief Pop the current pointer value
         *
         * @return T
         */
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

        /**
         * @brief Return the stack size
         *
         * @return const size_t
         */
        const size_t size() const
        {
            return m_pointer;
        }

#ifdef UNKNOWNRORI_DEBUG_MODE
        /**
         * @brief This is used for debugging purpose
         * return the current stack size allocation slot
         *
         * @return const size_t
         */
        const size_t getStackSize() const
        {
            return m_stackSize;
        }
#endif

        /**
         * @brief Check if the stack is empty
         *
         * @return true
         * @return false
         */
        bool isEmpty()
        {
            if (m_pointer > 0)
                return false;

            return true;
        }

        /**
         * @brief Get the top value
         *
         * @return T
         */
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

        /**
         * @brief Empty the stack
         *
         */
        void empty()
        {
            while (!this->isEmpty())
            {
                this->pop();
            }
        }

    private:
        /**
         * @brief Dynamically allocate memory for the stack
         *
         * @param newSize
         */
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

        T *m_data = nullptr;    // Main container for storing data in the heap
        size_t m_pointer = 0;   // Main Pointer that always point at the top of the stack (empty slot after the top)
        size_t m_stackSize = 0; // Variable that store the current current heap allocation
    };
}

#endif