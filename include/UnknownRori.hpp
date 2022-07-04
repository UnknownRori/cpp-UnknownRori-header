/**
 * @file UnknownRori.hpp
 * @author UnknownRori
 * @brief This file is a collection of standard types and some other stuff on my c++ project
 * @version 0.1
 * @date 2022-07-03
 *
 * @copyright Copyright (c) 2022
 *
 */
#pragma once

#ifndef UNKNOWNRORI_H
#define UNKNOWNRORI_H

/*---------------*\
|      Macro      |
/*---------------*/

#define size(array) (sizeof((array)) / sizeof((array)[0]))

/*------------------------*\
|  Custom Primitive Types  |
/*------------------------*/

#include <cstdint>

typedef int8_t i8;
typedef int16_t i16;
typedef int32_t i32;
typedef int64_t i64;
typedef __int128_t i128;

typedef uint8_t u8;
typedef uint16_t u16;
typedef uint32_t u32;
typedef uint64_t u64;
typedef __uint128_t u128;

typedef float f32;

typedef double d32;
typedef long double d64;

/*---------------*\
|   Custom Cast   |
/*---------------*/

/**
 * @brief Primitive data casting
 *
 * @param data
 * @return T
 */
template <typename T, typename V>
T cast(V data)
{
    return (T)data;
}

#endif
