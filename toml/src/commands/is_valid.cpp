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
IsValidCommand::IsValidCommand(const cell handle) : handle_(handle) {}

/// <summary>
/// </summary>
cell IsValidCommand::execute()
{
	return handle_ != TOML_INVALID_HANDLE && Storage::get(handle_, false);
}

/// <summary>
/// </summary>
cell AMX_NATIVE_CALL toml_is_valid(Amx* amx, cell* params)
{
	enum Args { Count, Handle };

	const auto handle = params[Handle];
	IsValidCommand command(handle);

	return execute(command, amx, 0, 0, __func__);
}
