//
// C++ Utilities - A collection of general-purpose C++ utilities
// Copyright (C) 2022 David Norris <danorris@gmail.com>. All rights reserved.
//

#pragma once

#include <new>

namespace util
{
    /// Asserts that a pointer is non-null and throws std::bad_alloc if not.
    ///
    /// @tparam T The pointed-to type.
    ///
    /// @param ptr the pointer to check.
    ///
    /// @return @p ptr.
    ///
    /// @throws std::bad_alloc @p ptr is null.

    template <typename T>
    T *check_alloc(T *ptr)
    {
        if (!ptr)
            throw std::bad_alloc();
        return ptr;
    }
}
