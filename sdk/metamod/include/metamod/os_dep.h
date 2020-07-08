// ***********************************************************************
// Author           : the_hunter
// Created          : 04-01-2020
//
// Last Modified By : the_hunter
// Last Modified On : 04-01-2020
// ***********************************************************************

#pragma once

#ifdef _WIN32
#define WIN32_LEAN_AND_MEAN
#include <Windows.h>
#elif !defined(WINAPI)
#define WINAPI
#endif

#undef DLLEXPORT
#undef NOINLINE
#undef FASTCALL
#undef FORCEINLINE_STATIC

#ifdef _WIN32
#define DLLEXPORT __declspec(dllexport)  // NOLINT(cppcoreguidelines-macro-usage)
#elif defined __clang__
#define DLLEXPORT __attribute__((visibility ("default")))  // NOLINT(cppcoreguidelines-macro-usage)
#else
#define DLLEXPORT __attribute__((visibility ("default"), externally_visible))  // NOLINT(cppcoreguidelines-macro-usage)
#endif

#ifdef _WIN32
#define NOINLINE __declspec(noinline)  // NOLINT(cppcoreguidelines-macro-usage)
#else
#define NOINLINE __attribute__((noinline))  // NOLINT(cppcoreguidelines-macro-usage)
#endif

#ifdef _WIN32
#define FASTCALL __fastcall  // NOLINT(cppcoreguidelines-macro-usage)
#else
#define FASTCALL  // NOLINT(cppcoreguidelines-macro-usage)
#endif

#ifdef _WIN32
#define FORCEINLINE_STATIC FORCEINLINE static  // NOLINT(cppcoreguidelines-macro-usage)
#else
#undef FORCEINLINE
#define FORCEINLINE __attribute__((always_inline)) inline  // NOLINT(cppcoreguidelines-macro-usage)
#define FORCEINLINE_STATIC __attribute__((always_inline)) static inline  // NOLINT(cppcoreguidelines-macro-usage)
#endif
