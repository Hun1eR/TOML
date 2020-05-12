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
cell InitRootCommand::execute()
{
	toml_t toml(toml::table{});
	return Storage::add(std::move(toml));
}

/// <summary>
/// </summary>
cell AMX_NATIVE_CALL toml_init_root(Amx* amx, cell*)
{
	InitRootCommand command;
	return execute(command, amx, TOML_INVALID_HANDLE, 1, __func__);
}
