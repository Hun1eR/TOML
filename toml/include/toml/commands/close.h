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

	/// <summary>
	/// </summary>
	~CloseCommand() = default;

	/// <summary>
	/// <para>Move constructor.</para>
	/// </summary>
	CloseCommand(CloseCommand&&) = delete;

	/// <summary>
	/// <para>Copy constructor.</para>
	/// </summary>
	CloseCommand(const CloseCommand&) = delete;

	/// <summary>
	/// <para>Move assignment operator.</para>
	/// </summary>
	CloseCommand& operator=(CloseCommand&&) = delete;

	/// <summary>
	/// <para>Copy assignment operator.</para>
	/// </summary>
	CloseCommand& operator=(const CloseCommand&) = delete;

private:
	/// <summary>
	/// </summary>
	cell handle_;
};

/// <summary>
/// </summary>
cell AMX_NATIVE_CALL toml_close(Amx* amx, cell* params);
