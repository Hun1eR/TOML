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
/// Class RemoveCommand.
/// </summary>
class RemoveCommand final : public ITomlCommand {
public:
	/// <summary>
	/// </summary>
	RemoveCommand(cell handle, const char* composite_key);

	/// <summary>
	/// </summary>
	RemoveCommand(cell handle, cell index);

	/// <summary>
	/// </summary>
	cell execute() override;

private:
	/// <summary>
	/// </summary>
	cell handle_;

	/// <summary>
	/// </summary>
	std::function<cell(TomlHolder*&)> remove_toml_{};
};

/// <summary>
/// </summary>
cell AMX_NATIVE_CALL toml_remove(Amx* amx, cell* params);

/// <summary>
/// </summary>
cell AMX_NATIVE_CALL toml_array_remove(Amx* amx, cell* params);
