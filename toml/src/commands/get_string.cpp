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
GetStringCommand::GetStringCommand(const cell handle, const char* key, amx::string& string) : handle_(handle), string_(string)
{
	find_value_ = [key](TomlHolder* holder) -> toml_t&
	{
		return toml_find(holder, key);
	};
}

/// <summary>
/// </summary>
GetStringCommand::GetStringCommand(const cell handle, cell index, amx::string& string) : handle_(handle), string_(string)
{
	find_value_ = [index](TomlHolder* holder) -> toml_t&
	{
		return toml::find(*holder->toml(), index);
	};
}

/// <summary>
/// </summary>
cell GetStringCommand::execute()
{
	auto* const holder = Storage::get(handle_);
	const auto& value = find_value_(holder);

	switch (value.type()) {
	case toml::value_t::integer:
		string_ = std::to_string(value.as_integer()).c_str();
		break;

	case toml::value_t::boolean:
		string_ = std::to_string(value.as_boolean()).c_str();
		break;

	case toml::value_t::floating:
		string_ = std::to_string(value.as_floating()).c_str();
		break;

	default:
		string_ = value.as_string().str.c_str();
	}

	return string_.length();
}

/// <summary>
/// </summary>
cell AMX_NATIVE_CALL toml_get_string(Amx* amx, cell* params)
{
	enum Args { Count, Handle, Key, Buffer, BufferSize, DefaultValue, ThrowError };

	const auto buf_size = params[BufferSize];

	if (!check_string_buffer_size(amx, buf_size, __func__))
		return 0;

	const auto handle = params[Handle];
	auto* const key = AmxxApi::get_amx_string(amx, params[Key]);
	auto string = amx::string(amx, params[Buffer], buf_size);
	GetStringCommand command(handle, key, string);

	const auto result = execute(command, amx, -1, params[ThrowError], __func__);

	if (result != -1)
		return result;

	return AmxxApi::set_amx_string(amx, params[Buffer], AmxxApi::get_amx_string(amx, params[DefaultValue]), buf_size);
}

/// <summary>
/// </summary>
cell AMX_NATIVE_CALL toml_array_get_string(Amx* amx, cell* params)
{
	enum Args { Count, Handle, Index, Buffer, BufferSize, DefaultValue, ThrowError };

	const auto buf_size = params[BufferSize];

	if (!check_string_buffer_size(amx, buf_size, __func__))
		return 0;

	const auto handle = params[Handle];
	const auto index = params[Index];
	auto string = amx::string(amx, params[Buffer], buf_size);
	GetStringCommand command(handle, index, string);

	const auto result = execute(command, amx, -1, params[ThrowError], __func__);

	if (result != -1)
		return result;

	return AmxxApi::set_amx_string(amx, params[Buffer], AmxxApi::get_amx_string(amx, params[DefaultValue]), buf_size);
}
