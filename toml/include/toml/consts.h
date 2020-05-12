// ***********************************************************************
// Author           : the_hunter
// Created          : 04-01-2020
//
// Last Modified By : the_hunter
// Last Modified On : 04-01-2020
// ***********************************************************************

#pragma once

#include <amxx/amx.h>

#ifdef _WIN32
/// <summary>
/// </summary>
constexpr auto MAX_PATH_LENGTH = MAX_PATH;
#else
#include <limits.h>
/// <summary>
/// </summary>
constexpr auto MAX_PATH_LENGTH = PATH_MAX;
#endif

/// <summary>
/// </summary>
constexpr cell TOML_INVALID_HANDLE = 0;

/// <summary>
/// <para>Internal AMXX buffer size for string retrieval.</para>
/// </summary>
constexpr auto AMXX_MAX_STRING_LENGTH = 16384;
