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
/// Class CloseCommand.
/// </summary>
class CloseCommand final : public ITomlCommand {
public:
	/// <summary>
	/// </summary>
	explicit CloseCommand(cell handle);

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
cell AMX_NATIVE_CALL toml_close(Amx* amx, cell* params);
