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
RemoveCommand::RemoveCommand(const cell handle, const char* composite_key) : handle_(handle)
{
	remove_toml_ = [composite_key](TomlHolder*& holder)
	{
		auto& toml = toml_find(holder, composite_key, false);
		auto& table = toml.as_table();

		const auto* const key = get_key_from_composite(composite_key);
		holder->remove(toml::find(toml, key));
		table.erase(key);

		return 1;
	};
}

/// <summary>
/// </summary>
RemoveCommand::RemoveCommand(const cell handle, cell index) : handle_(handle)
{
	remove_toml_ = [index](TomlHolder*& holder)
	{
		auto* toml = holder->toml();
		auto& array = toml->as_array();

		holder->remove(toml::find(*toml, index));
		array.erase(array.begin() + index);

		return static_cast<cell>(array.size());
	};
}

/// <summary>
/// </summary>
cell RemoveCommand::execute()
{
	auto* holder = Storage::get(handle_);
	return remove_toml_(holder);
}

/// <summary>
/// </summary>
cell AMX_NATIVE_CALL toml_remove(Amx* amx, cell* params)
{
	enum Args { Count, Handle, Key };

	const auto handle = params[Handle];
	auto* const key = AmxxApi::get_amx_string(amx, params[Key]);
	RemoveCommand command(handle, key);

	return execute(command, amx, 0, 1, __func__);
}

/// <summary>
/// </summary>
cell AMX_NATIVE_CALL toml_array_remove(Amx* amx, cell* params)  // NOLINT(readability-non-const-parameter)
{
	enum Args { Count, Handle, Index };

	const auto handle = params[Handle];
	const auto index = params[Index];
	RemoveCommand command(handle, index);

	return execute(command, amx, 0, 1, __func__);
}
