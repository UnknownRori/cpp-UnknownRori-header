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

#include <stdint.h>

/*---------------*\
|      Macro      |
/*---------------*/

#define size(array) (sizeof((array)) / sizeof((array)[0]))

/*------------------------*\
|  Custom Primitive Types  |
/*------------------------*/

#define i8 int8_t
#define i16 int16_t
#define i32 int32_t
#define i64 int64_t
#define i128 __int128_t

#define u8 uint8_t
#define u16 uint16_t
#define u32 uint32_t
#define u64 uint64_t
#define u128 __uint128_t

#define f32 float

#define d32 double
#define d64 long double

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
