/*
 * Deprecated.h
 *
 * Copyright (c) 2015 Lukas Hermanns. All rights reserved.
 * Licensed under the terms of the BSD 3-Clause license (see LICENSE.txt).
 */

#ifndef LLGL_DEPRECATED_H
#define LLGL_DEPRECATED_H


// Macro to support deprecation warnings before C++14

#define LLGL_DEPRECATED_VA_ARGS(...) \
    , ## __VA_ARGS__

#if defined __clang__ // Prefer Clang deprecation attribute as it provides better diagnostics than the C++14 attribute
#   define LLGL_DEPRECATED(MESSAGE, ...) __attribute__((deprecated(MESSAGE LLGL_DEPRECATED_VA_ARGS(__VA_ARGS__))))
#elif __cplusplus >= 201402L // C++14
#   define LLGL_DEPRECATED(MESSAGE, ...) [[deprecated(MESSAGE)]]
#elif defined __GNUC__
#   define LLGL_DEPRECATED(MESSAGE, ...) __attribute__((deprecated(MESSAGE)))
#elif defined _MSC_VER
#   define LLGL_DEPRECATED(MESSAGE, ...) __declspec(deprecated(MESSAGE))
#else
#   define LLGL_DEPRECATED(MESSAGE, ...)
#endif


#endif



// ================================================================================
