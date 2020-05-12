// ***********************************************************************
// Author           : the_hunter
// Created          : 04-01-2020
//
// Last Modified By : the_hunter
// Last Modified On : 04-01-2020
// ***********************************************************************

#pragma once

#include <cssdk/common/cvar.h>

/// <summary>
/// </summary>
extern CVar* toml_debug;

/// <summary>
/// </summary>
inline bool enable_debug_cvar()
{
	return static_cast<bool>(toml_debug->value);
}

/// <summary>
/// </summary>
bool register_cvars();
