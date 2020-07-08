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
CloseCommand::CloseCommand(const cell handle) : handle_(handle) {}

/// <summary>
/// </summary>
cell CloseCommand::execute()
{
	Storage::remove(handle_);
	return TOML_INVALID_HANDLE;
}

/// <summary>
/// </summary>
cell AMX_NATIVE_CALL toml_close(Amx* amx, cell* params)  // NOLINT(readability-non-const-parameter)
{
	enum Args { Count, Handle };

	const auto handle = params[Handle];
	CloseCommand command(handle);

	return execute(command, amx, TOML_INVALID_HANDLE, 0, __func__);
}
