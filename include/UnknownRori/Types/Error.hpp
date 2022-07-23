/**
 * @file Error.hpp
 * @author UnknownRori
 * @brief A enum that stored type of error
 * @version 0.1
 * @date 2022-07-23
 *
 * @copyright Copyright (c) 2022
 *
 */

#pragma once

#ifndef UNKNOWNRORI_TYPES_ERROR_HPP
#define UNKNOWNRORI_TYPES_ERROR_HPP

namespace Rori
{
    /**
     * @brief A enum that stored type of error
     *
     */
    enum Err
    {
        NONE,
        OUT_OF_BOUND,
        LOGIC_ERROR,
        INVALID_OPERATION,
        INVALID_TYPE,
        RUNTIME_ERROR,
        NOT_IMPLEMENTED,
        REFERENCE_NOT_FOUND
    };
}

#endif