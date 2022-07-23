/**
 * @file Result.hpp
 * @author UnknownRori
 * @brief A very simple container that hold a result and an error code
 * @version 0.1
 * @date 2022-07-23
 *
 * @copyright Copyright (c) 2022
 *
 */

#pragma once

#ifndef UNKNOWNRORI_RESULT_HPP
#define UNKNOWNRORI_RESULT_HPP

#include "../Types/Error.hpp"

namespace Rori
{
    /**
     * @brief A very simple container that hold a result and an error code
     *
     * @tparam T
     */
    template <typename T, typename S = Rori::Err>
    class Result
    {
        typedef S ErrorCodeType;
        typedef T ResultType;

    private:
        T m_result;
        S m_err;

    public:
        Result() {}
        Result(ResultType result) : m_result(result) {}
        Result(ErrorCodeType err) : m_err(m_err) {}
        Result(ResultType result, ErrorCodeType err) : m_result(result), m_err(err) {}

        bool isErr()
        {
            return m_err != 0;
        }

        ResultType getResult()
        {
            return m_result;
        }

        ErrorCodeType getErr()
        {
            return m_err;
        }
    };
}

#endif
