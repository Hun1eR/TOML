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
GetArrayCommand::GetArrayCommand(const cell handle, const char* key) : handle_(handle)
{
	find_array_ = [key](TomlHolder*& holder) -> toml_t&
	{
		return toml_find(holder, key);
	};
}

/// <summary>
/// </summary>
GetArrayCommand::GetArrayCommand(const cell handle, cell index) : handle_(handle)
{
	find_array_ = [index](TomlHolder*& holder) -> toml_t&
	{
		return toml::find(*holder->toml(), index);
	};
}

/// <summary>
/// </summary>
cell GetArrayCommand::execute()
{
	auto* holder = Storage::get(handle_);
	auto& array = find_array_(holder);
	check_toml_type<toml::value_t::array>(array);

	return holder->add(array)->handle();
}

/// <summary>
/// </summary>
cell AMX_NATIVE_CALL toml_get_array(Amx* amx, cell* params)
{
	enum Args { Count, Handle, Key, ThrowError };

	const auto handle = params[Handle];
	auto* const key = AmxxApi::get_amx_string(amx, params[Key]);
	GetArrayCommand command(handle, key);

	return execute(command, amx, TOML_INVALID_HANDLE, params[ThrowError], __func__);
}

/// <summary>
/// </summary>
cell AMX_NATIVE_CALL toml_array_get_array(Amx* amx, cell* params)
{
	enum Args { Count, Handle, Index, ThrowError };

	const auto handle = params[Handle];
	const auto index = params[Index];
	GetArrayCommand command(handle, index);

	return execute(command, amx, TOML_INVALID_HANDLE, params[ThrowError], __func__);
}
