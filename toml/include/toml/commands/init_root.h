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
/// Class InitRootCommand.
/// </summary>
class InitRootCommand final : public ITomlCommand {
public:
	/// <summary>
	/// </summary>
	cell execute() override;
};

/// <summary>
/// </summary>
cell AMX_NATIVE_CALL toml_init_root(Amx* amx, cell* params);
