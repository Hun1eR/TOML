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
/// Class ClearCommand.
/// </summary>
class ClearCommand final : public ITomlCommand {
public:
	/// <summary>
	/// </summary>
	explicit ClearCommand(cell handle);

	/// <summary>
	/// </summary>
	cell execute() override;

private:
	/// <summary>
	/// </summary>
	cell handle_;
};

/// <summary>
/// </summary>
cell AMX_NATIVE_CALL toml_clear(Amx* amx, cell* params);
