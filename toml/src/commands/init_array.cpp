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
InitArrayCommand::InitArrayCommand(const cell handle, const char* key) : handle_(handle)
{
	toml_init_ = [key](TomlHolder*& holder) -> toml_t&
	{
		auto& toml = toml_find(holder, key, false);
		auto& table = toml.as_table();

		return table[get_key_from_composite(key)] = toml::array{};
	};
}

/// <summary>
/// </summary>
InitArrayCommand::InitArrayCommand(const cell handle) : handle_(handle)
{
	toml_init_ = [](TomlHolder*& holder) -> toml_t&
	{
		auto& array = holder->toml()->as_array();
		array.emplace_back(toml::array{});
		holder->clear();

		return array.back();
	};
}

/// <summary>
/// </summary>
cell InitArrayCommand::execute()
{
	auto* holder = Storage::get(handle_);
	auto& toml = toml_init_(holder);

	return holder->add(toml)->handle();
}

/// <summary>
/// </summary>
cell AMX_NATIVE_CALL toml_init_array(Amx* amx, cell* params)
{
	enum Args { Count, Handle, Key };

	const auto handle = params[Handle];
	auto* const key = AmxxApi::get_amx_string(amx, params[Key]);
	InitArrayCommand command(handle, key);

	return execute(command, amx, TOML_INVALID_HANDLE, 1, __func__);
}

/// <summary>
/// </summary>
cell AMX_NATIVE_CALL toml_array_init_array(Amx* amx, cell* params)
{
	enum Args { Count, Handle };

	const auto handle = params[Handle];
	InitArrayCommand command(handle);

	return execute(command, amx, TOML_INVALID_HANDLE, 1, __func__);
}
