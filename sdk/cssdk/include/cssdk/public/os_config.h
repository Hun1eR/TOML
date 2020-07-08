// ***********************************************************************
// Created          : 04-01-2020
//
// Last Modified By : the_hunter
// Last Modified On : 04-01-2020
// ***********************************************************************
//     Copyright (c) 1996-2002, Valve LLC. All rights reserved.
// ***********************************************************************

#pragma once

#undef FORCE_STACK_ALIGN
#undef FORCEINLINE_STATIC

#if defined(_WIN32)
#define FORCE_STACK_ALIGN
#else
#define FORCE_STACK_ALIGN __attribute__((force_align_arg_pointer))  // NOLINT(cppcoreguidelines-macro-usage)
#endif

#define EXT_FUNC FORCE_STACK_ALIGN  // NOLINT(cppcoreguidelines-macro-usage)

#ifdef _WIN32
#define WIN32_LEAN_AND_MEAN
#include <Windows.h>
#define FORCEINLINE_STATIC FORCEINLINE static  // NOLINT(cppcoreguidelines-macro-usage)
#else
#undef FORCEINLINE
#define FORCEINLINE __attribute__((always_inline)) inline  // NOLINT(cppcoreguidelines-macro-usage)
#define FORCEINLINE_STATIC __attribute__((always_inline)) static inline  // NOLINT(cppcoreguidelines-macro-usage)
#endif
