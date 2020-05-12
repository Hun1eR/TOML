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
/// Class GetIntegerCommand.
/// </summary>
class GetBooleanCommand final : public ITomlCommand {
public:
	/// <summary>
	/// </summary>
	GetBooleanCommand(cell handle, const char* key);

	/// <summary>
	/// </summary>
	GetBooleanCommand(cell handle, cell index);

	/// <summary>
	/// </summary>
	cell execute() override;

private:
	/// <summary>
	/// </summary>
	cell handle_;

	/// <summary>
	/// </summary>
	std::function<toml_t&(TomlHolder*)> find_value_{};
};

/// <summary>
/// </summary>
cell AMX_NATIVE_CALL toml_get_bool(Amx* amx, cell* params);

/// <summary>
/// </summary>
cell AMX_NATIVE_CALL toml_array_get_bool(Amx* amx, cell* params);
