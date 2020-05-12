// ***********************************************************************
// Author           : the_hunter
// Created          : 04-01-2020
//
// Last Modified By : the_hunter
// Last Modified On : 04-01-2020
// ***********************************************************************

#include <toml/pch.h>

/// <summary>
/// </summary>
AmxxStatus on_amxx_attach()
{
	if (!register_cvars())
		return AmxxStatus::InterfaceMismatch;

	Storage::clear();

	extern void add_natives();
	add_natives();

	return AmxxStatus::Ok;
}

/// <summary>
/// </summary>
void on_amxx_detach()
{
	Storage::clear();
}

/// <summary>
/// </summary>
void on_amxx_plugins_unloaded()
{
	Storage::clear();
}
