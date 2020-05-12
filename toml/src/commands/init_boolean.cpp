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
InitBooleanCommand::InitBooleanCommand(const cell handle, const char* key, const cell value) : handle_(handle)
{
	toml_init_ = [key, value](TomlHolder*& holder)
	{
		auto& toml = toml_find(holder, key, false);
		auto& table = toml.as_table();
		table[get_key_from_composite(key)] = toml::boolean{static_cast<bool>(value)};

		return 1;
	};
}

/// <summary>
/// </summary>
InitBooleanCommand::InitBooleanCommand(const cell handle, const cell value) : handle_(handle)
{
	toml_init_ = [value](TomlHolder*& holder)
	{
		auto& array = holder->toml()->as_array();
		array.emplace_back(toml::boolean{static_cast<bool>(value)});
		holder->clear();

		return cell(array.size() - 1);
	};
}

/// <summary>
/// </summary>
cell InitBooleanCommand::execute()
{
	auto* holder = Storage::get(handle_);
	return toml_init_(holder);
}

/// <summary>
/// </summary>
cell AMX_NATIVE_CALL toml_init_bool(Amx* amx, cell* params)
{
	enum Args { Count, Handle, Key, Value };

	const auto handle = params[Handle];
	auto* const key = AmxxApi::get_amx_string(amx, params[Key]);
	const auto value = params[Value];
	InitBooleanCommand command(handle, key, value);

	return execute(command, amx, 0, 1, __func__);
}

/// <summary>
/// </summary>
cell AMX_NATIVE_CALL toml_array_init_bool(Amx* amx, cell* params)
{
	enum Args { Count, Handle, Value };

	const auto handle = params[Handle];
	const auto value = params[Value];
	InitBooleanCommand command(handle, value);

	return execute(command, amx, -1, 1, __func__);
}
