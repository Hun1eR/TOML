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
GetCountCommand::GetCountCommand(const cell handle) : handle_(handle) {}

/// <summary>
/// </summary>
cell GetCountCommand::execute()
{
	auto* const holder = Storage::get(handle_);
	const auto& array = holder->toml()->as_array();

	return cell(array.size());
}

/// <summary>
/// </summary>
cell AMX_NATIVE_CALL toml_array_get_count(Amx* amx, cell* params)
{
	enum Args { Count, Handle, ThrowError };

	const auto handle = params[Handle];
	GetCountCommand command(handle);

	return execute(command, amx, 0, params[ThrowError], __func__);
}
