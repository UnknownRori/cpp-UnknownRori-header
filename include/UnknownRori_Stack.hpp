/**
 * @file UnknownRori_Stack.hpp
 * @author UnknownRori
 * @brief A brief class template definition on stack allocation
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
    template <typename T>
    class Stack
    {
    public:
        Stack()
        {
            data = new T[2];
            stackSize = 2;
        }

        virtual ~Stack()
        {
            delete[] data;
        }

        // Push the value into stack
        void push(const T value)
        {
            if (pointer >= stackSize)
            {
                Stack::alloc((stackSize * 2));
            }

            data[pointer] = value;
            pointer++;
        }

        // Pop the current pointer value
        T pop()
        {
            pointer--;
            return data[pointer];
        }

        // Return the stack size
        size_t size()
        {
            return pointer;
        }

        // Get the top value
        T top()
        {
            return data[pointer - 1];
        }

    private:
        // Dynamically allocate memory
        void alloc(size_t newSize)
        {
            T *newData = new T[newSize];

            for (size_t i = 0; i < stackSize; i++)
            {
                newData[i] = std::move(data[i]);
            }

            stackSize = newSize;

            delete[] data;
            data = newData;
        }

        T *data = nullptr;
        size_t pointer = 0;
        size_t stackSize = 0;
    };
}

#endif