//
// C++ Utilities - A collection of general-purpose C++ utilities
// Copyright (C) 2022 David Norris <danorris@gmail.com>. All rights reserved.
//

#pragma once

namespace util
{
    /// Returns a wrapper function, which takes a pointer to a function object via an opaque
    /// (`void *`) "user data" pointer and invokes that function object when called. This helper
    /// function is useful when combining C++ function objects with C-style callbacks that offer
    /// user data pointers which can be used to hold a pointer to the function object.
    ///
    /// @tparam Args The type(s) of any arguments passed to @p Func.
    /// @tparam Func The type of the function object.
    ///
    /// @param func A reference to the function object to be called. This argument exists solely
    ///             to facility template parameter deduction. The referenced object is not
    ///             accessed.
    ///
    /// @returns A wrapper function as described above.

    template <typename ... Args, typename Func>
    auto wrap_func_with_user_data(const Func& func) noexcept
    {
        return [](Args... args, void *arg)
        {
            Func *func = reinterpret_cast<Func *>(arg);
            (*func)(args...);
        };
    }
}
