/**
 * @file UnknownRori.hpp
 * @author UnknownRori
 * @brief Main Header file of my collection
 * @version 0.1
 * @date 2022-07-03
 *
 * @copyright Copyright (c) 2022
 *
 */

/*

MIT License

Copyright (c) 2022 UnknownRori

Permission is hereby granted, free of charge, to any person obtaining a copy
of this software and associated documentation files (the "Software"), to deal
in the Software without restriction, including without limitation the rights
to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
copies of the Software, and to permit persons to whom the Software is
furnished to do so, subject to the following conditions:

The above copyright notice and this permission notice shall be included in all
copies or substantial portions of the Software.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
SOFTWARE.


*/

//? Some header has it's own configuration but the most important is macro
//! #define UNKNOWNRORI_DEBUG_MODE
//? this macro will enable overloading some of c++ operator keyword and do other hacky stuff

#pragma once

#ifndef UNKNOWNRORI_HPP
#define UNKNOWNRORI_HPP

// Some macro, types and custom exception
#include "Macro.hpp"
#include "Types.hpp"
#include "Exception.hpp"

// Some helper function
#include "Cast.hpp"

// Overloading default operator
#include "New.hpp"
#include "Delete.hpp"

// Reimplementing C++ Standard Library
#include "Array.hpp"
#include "Stack.hpp"
#include "String.hpp"
#include "Vector.hpp"
#include "List.hpp"
#include "Queue.hpp"

#endif
