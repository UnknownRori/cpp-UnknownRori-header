/**
 * @file main.cpp
 * @author UnknownRori (you@domain.com)
 * @brief This is place for manual testing
 * @version 0.1
 * @date 2022-07-04
 *
 * @copyright Copyright (c) 2022
 *
 */

#include <iostream>
#include "./include/UnknownRori.hpp"
#include "./include/UnknownRori_Stack.hpp"

int main()
{
    rori::Stack<i32> myStack;
    myStack.push(1);
    myStack.push(2);
    myStack.push(3);
    myStack.push(4);
    myStack.push(5);
    myStack.push(6);
    myStack.push(7);
    std::cout << myStack.size() << std::endl;
    return 0;
}