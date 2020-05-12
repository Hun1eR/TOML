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
/// Class SaveCommand.
/// </summary>
class SaveCommand final : public ITomlCommand {
public:
	/// <summary>
	/// </summary>
	SaveCommand(cell handle, const char* filepath);

	/// <summary>
	/// </summary>
	cell execute() override;

private:
	/// <summary>
	/// </summary>
	cell handle_;

	/// <summary>
	/// </summary>
	const char* filepath_;
};

/// <summary>
/// </summary>
cell AMX_NATIVE_CALL toml_save(Amx* amx, cell* params);
