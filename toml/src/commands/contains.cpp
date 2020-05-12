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
ContainsCommand::ContainsCommand(const cell handle, const char* key) : handle_(handle), key_(key) {}

/// <summary>
/// </summary>
cell ContainsCommand::execute()
{
	auto* holder = Storage::get(handle_);
	const auto& toml = toml_find(holder, key_, false);
	
	return toml.contains(get_key_from_composite(key_));
}

/// <summary>
/// </summary>
cell AMX_NATIVE_CALL toml_contains(Amx* amx, cell* params)
{
	enum Args { Count, Handle, Key, ThrowError };

	const auto handle = params[Handle];
	auto* const key = AmxxApi::get_amx_string(amx, params[Key]);
	ContainsCommand command(handle, key);

	return execute(command, amx, 0, params[ThrowError], __func__);
}
