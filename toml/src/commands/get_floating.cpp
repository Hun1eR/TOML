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
GetFloatingCommand::GetFloatingCommand(const cell handle, const char* key) : handle_(handle)
{
	find_value_ = [key](TomlHolder* holder) -> toml_t&
	{
		return toml_find(holder, key);
	};
}

/// <summary>
/// </summary>
GetFloatingCommand::GetFloatingCommand(const cell handle, cell index) : handle_(handle)
{
	find_value_ = [index](TomlHolder* holder) -> toml_t&
	{
		return toml::find(*holder->toml(), index);
	};
}

/// <summary>
/// </summary>
cell GetFloatingCommand::execute()
{
	auto* const holder = Storage::get(handle_);
	const auto& value = find_value_(holder);

	switch (value.type()) {
	case toml::value_t::integer:
		return amx_ftoc(real(value.as_integer()));

	case toml::value_t::boolean:
		return amx_ftoc(real(value.as_boolean()));

	default:
		return amx_ftoc(real(value.as_floating()));
	}
}

/// <summary>
/// </summary>
cell AMX_NATIVE_CALL toml_get_float(Amx* amx, cell* params)
{
	enum Args { Count, Handle, Key, DefaultValue, ThrowError };

	const auto handle = params[Handle];
	auto* const key = AmxxApi::get_amx_string(amx, params[Key]);
	const auto default_value = params[DefaultValue];
	GetFloatingCommand command(handle, key);

	return execute(command, amx, default_value, params[ThrowError], __func__);
}

/// <summary>
/// </summary>
cell AMX_NATIVE_CALL toml_array_get_float(Amx* amx, cell* params)
{
	enum Args { Count, Handle, Index, DefaultValue, ThrowError };

	const auto handle = params[Handle];
	const auto index = params[Index];
	const auto default_value = params[DefaultValue];
	GetFloatingCommand command(handle, index);

	return execute(command, amx, default_value, params[ThrowError], __func__);
}
