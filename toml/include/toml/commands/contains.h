// ***********************************************************************
// Author           : the_hunter
// Created          : 04-01-2020
//
// Last Modified By : the_hunter
// Last Modified On : 04-01-2020
// ***********************************************************************

#pragma once

#include <toml/commands/command.h>

/// <summary>
/// Class ContainsCommand.
/// </summary>
class ContainsCommand final : public ITomlCommand {
public:
	/// <summary>
	/// </summary>
	ContainsCommand(cell handle, const char* key);

	/// <summary>
	/// </summary>
	cell execute() override;

private:
	/// <summary>
	/// </summary>
	cell handle_;

	/// <summary>
	/// </summary>
	const char* key_;
};

/// <summary>
/// </summary>
cell AMX_NATIVE_CALL toml_contains(Amx* amx, cell* params);
