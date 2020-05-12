// ***********************************************************************
// Author           : the_hunter
// Created          : 04-01-2020
//
// Last Modified By : the_hunter
// Last Modified On : 04-01-2020
// ***********************************************************************

#pragma once

#include <toml/commands/command.h>
#include <functional>

/// <summary>
/// Class SetStringCommand.
/// </summary>
class SetStringCommand final : public ITomlCommand {
public:
	/// <summary>
	/// </summary>
	SetStringCommand(cell handle, const char* key, const char* value);

	/// <summary>
	/// </summary>
	SetStringCommand(cell handle, cell index, const char* value);

	/// <summary>
	/// </summary>
	cell execute() override;

private:
	/// <summary>
	/// </summary>
	cell handle_;

	/// <summary>
	/// </summary>
	const char* value_;

	/// <summary>
	/// </summary>
	std::function<toml_t&(TomlHolder*&)> find_value_{};
};

/// <summary>
/// </summary>
cell AMX_NATIVE_CALL toml_set_string(Amx* amx, cell* params);

/// <summary>
/// </summary>
cell AMX_NATIVE_CALL toml_array_set_string(Amx* amx, cell* params);
