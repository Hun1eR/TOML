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
SetFloatingCommand::SetFloatingCommand(const cell handle, const char* key, const cell value)
	: handle_(handle), value_(value)
{
	find_value_ = [key](TomlHolder*& holder) -> toml_t&
	{
		return toml_find(holder, key);
	};
}

/// <summary>
/// </summary>
SetFloatingCommand::SetFloatingCommand(const cell handle, cell index, const cell value)
	: handle_(handle), value_(value)
{
	find_value_ = [index](TomlHolder*& holder) -> toml_t&
	{
		return toml::find(*holder->toml(), index);
	};
}

/// <summary>
/// </summary>
cell SetFloatingCommand::execute()
{
	auto* holder = Storage::get(handle_);
	auto& value = find_value_(holder);

	value = amx_ctof(value_);
	holder->remove(value);

	return 1;
}

/// <summary>
/// </summary>
cell AMX_NATIVE_CALL toml_set_float(Amx* amx, cell* params)
{
	enum Args { Count, Handle, Key, Value };

	const auto handle = params[Handle];
	auto* const key = AmxxApi::get_amx_string(amx, params[Key]);
	const auto value = params[Value];
	SetFloatingCommand command(handle, key, value);

	return execute(command, amx, 0, 1, __func__);
}

/// <summary>
/// </summary>
cell AMX_NATIVE_CALL toml_array_set_float(Amx* amx, cell* params)  // NOLINT(readability-non-const-parameter)
{
	enum Args { Count, Handle, Index, Value };

	const auto handle = params[Handle];
	const auto index = params[Index];
	const auto value = params[Value];
	SetFloatingCommand command(handle, index, value);

	return execute(command, amx, 0, 1, __func__);
}
