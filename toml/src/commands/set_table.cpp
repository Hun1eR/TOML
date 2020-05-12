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
SetTableCommand::SetTableCommand(const cell handle, const char* key, const cell value) : handle_(handle), value_(value)
{
	find_value_ = [key](TomlHolder*& holder) -> toml_t&
	{
		return toml_find(holder, key);
	};
}

/// <summary>
/// </summary>
SetTableCommand::SetTableCommand(const cell handle, cell index, const cell value) : handle_(handle), value_(value)
{
	find_value_ = [index](TomlHolder*& holder) -> toml_t&
	{
		return toml::find(*holder->toml(), index);
	};
}

/// <summary>
/// </summary>
cell SetTableCommand::execute()
{
	auto* holder = Storage::get(handle_);
	auto& cur_value = find_value_(holder);

	const auto& new_value = *Storage::get(value_)->toml();
	check_toml_type<toml::value_t::table>(new_value);
	cur_value = new_value;

	return holder->add(cur_value)->handle();
}

/// <summary>
/// </summary>
cell AMX_NATIVE_CALL toml_set_table(Amx* amx, cell* params)
{
	enum Args { Count, Handle, Key, Value };

	const auto handle = params[Handle];
	auto* const key = AmxxApi::get_amx_string(amx, params[Key]);
	const auto value = params[Value];
	SetTableCommand command(handle, key, value);

	return execute(command, amx, TOML_INVALID_HANDLE, 1, __func__);
}

/// <summary>
/// </summary>
cell AMX_NATIVE_CALL toml_array_set_table(Amx* amx, cell* params)
{
	enum Args { Count, Handle, Index, Value };

	const auto handle = params[Handle];
	const auto index = params[Index];
	const auto value = params[Value];
	SetTableCommand command(handle, index, value);

	return execute(command, amx, TOML_INVALID_HANDLE, 1, __func__);
}
