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
class InitArrayCommand final : public ITomlCommand {
public:
	/// <summary>
	/// </summary>
	InitArrayCommand(cell handle, const char* key);

	/// <summary>
	/// </summary>
	explicit InitArrayCommand(cell handle);

	/// <summary>
	/// </summary>
	cell execute() override;

private:
	/// <summary>
	/// </summary>
	cell handle_;

	/// <summary>
	/// </summary>
	std::function<toml_t&(TomlHolder*&)> toml_init_{};
};

/// <summary>
/// </summary>
cell AMX_NATIVE_CALL toml_init_array(Amx* amx, cell* params);

/// <summary>
/// </summary>
cell AMX_NATIVE_CALL toml_array_init_array(Amx* amx, cell* params);
