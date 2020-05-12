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
/// Class InitRootCommand.
/// </summary>
class InitBooleanCommand final : public ITomlCommand {
public:
	/// <summary>
	/// </summary>
	InitBooleanCommand(cell handle, const char* key, cell value);

	/// <summary>
	/// </summary>
	InitBooleanCommand(cell handle, cell value);

	/// <summary>
	/// </summary>
	cell execute() override;

private:
	/// <summary>
	/// </summary>
	cell handle_;

	/// <summary>
	/// </summary>
	std::function<cell(TomlHolder*&)> toml_init_{};
};

/// <summary>
/// </summary>
cell AMX_NATIVE_CALL toml_init_bool(Amx* amx, cell* params);

/// <summary>
/// </summary>
cell AMX_NATIVE_CALL toml_array_init_bool(Amx* amx, cell* params);
