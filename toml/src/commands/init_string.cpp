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
InitStringCommand::InitStringCommand(const cell handle, const char* key, const char* value) : handle_(handle)
{
	toml_init_ = [key, value](TomlHolder*& holder)
	{
		auto& toml = toml_find(holder, key, false);
		auto& table = toml.as_table();
		table[get_key_from_composite(key)] = toml::string{value};

		return 1;
	};
}

/// <summary>
/// </summary>
InitStringCommand::InitStringCommand(const cell handle, const char* value) : handle_(handle)
{
	toml_init_ = [value](TomlHolder*& holder)
	{
		auto& array = holder->toml()->as_array();
		array.emplace_back(toml::string{value});
		holder->clear();

		return static_cast<cell>(array.size() - 1);
	};
}

/// <summary>
/// </summary>
cell InitStringCommand::execute()
{
	auto* holder = Storage::get(handle_);
	return toml_init_(holder);
}

/// <summary>
/// </summary>
cell AMX_NATIVE_CALL toml_init_string(Amx* amx, cell* params)
{
	enum Args { Count, Handle, Key, Value };

	const auto handle = params[Handle];
	auto* const key = AmxxApi::get_amx_string(amx, params[Key], 0);
	auto* const value = AmxxApi::get_amx_string(amx, params[Value], 1);
	InitStringCommand command(handle, key, value);

	return execute(command, amx, 0, 1, __func__);
}

/// <summary>
/// </summary>
cell AMX_NATIVE_CALL toml_array_init_string(Amx* amx, cell* params)
{
	enum Args { Count, Handle, Value };

	const auto handle = params[Handle];
	auto* const value = AmxxApi::get_amx_string(amx, params[Value]);
	InitStringCommand command(handle, value);

	return execute(command, amx, -1, 1, __func__);
}
