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
GetTableCommand::GetTableCommand(const cell handle, const char* key) : handle_(handle)
{
	find_table_ = [key](TomlHolder*& holder) -> toml_t&
	{
		return toml_find(holder, key);
	};
}

/// <summary>
/// </summary>
GetTableCommand::GetTableCommand(const cell handle, const cell index) : handle_(handle)
{
	find_table_ = [index](TomlHolder*& holder) -> toml_t&
	{
		return toml::find(*holder->toml(), index);
	};
}

/// <summary>
/// </summary>
cell GetTableCommand::execute()
{
	auto* holder = Storage::get(handle_);
	auto& table = find_table_(holder);
	check_toml_type<toml::value_t::table>(table);

	return holder->add(table)->handle();
}

/// <summary>
/// </summary>
cell AMX_NATIVE_CALL toml_get_table(Amx* amx, cell* params)
{
	enum Args { Count, Handle, Key, ThrowError };

	const auto handle = params[Handle];
	auto* const key = AmxxApi::get_amx_string(amx, params[Key]);
	GetTableCommand command(handle, key);

	return execute(command, amx, TOML_INVALID_HANDLE, params[ThrowError], __func__);
}

/// <summary>
/// </summary>
cell AMX_NATIVE_CALL toml_array_get_table(Amx* amx, cell* params)
{
	enum Args { Count, Handle, Index, ThrowError };

	const auto handle = params[Handle];
	const auto index = params[Index];
	GetTableCommand command(handle, index);

	return execute(command, amx, TOML_INVALID_HANDLE, params[ThrowError], __func__);
}
