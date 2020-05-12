// ***********************************************************************
// Author           : the_hunter
// Created          : 04-01-2020
//
// Last Modified By : the_hunter
// Last Modified On : 04-01-2020
// ***********************************************************************

#pragma once

#include <amxx/amx.h>
#include <toml/holder.h>
#include <toml11/toml.hpp>

/// <summary>
/// </summary>
class Storage {
public:
	/// <summary>
	/// </summary>
	static cell add(toml_t&& toml);

	/// <summary>
	/// </summary>
	static TomlHolder* get(cell handle, bool throw_error = true);

	/// <summary>
	/// </summary>
	static void remove(cell handle);

	/// <summary>
	/// </summary>
	static void clear();
};
