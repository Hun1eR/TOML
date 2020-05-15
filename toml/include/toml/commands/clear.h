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

	/// <summary>
	/// </summary>
	~ClearCommand() = default;

	/// <summary>
	/// <para>Move constructor.</para>
	/// </summary>
	ClearCommand(ClearCommand&&) = delete;

	/// <summary>
	/// <para>Copy constructor.</para>
	/// </summary>
	ClearCommand(const ClearCommand&) = delete;

	/// <summary>
	/// <para>Move assignment operator.</para>
	/// </summary>
	ClearCommand& operator=(ClearCommand&&) = delete;

	/// <summary>
	/// <para>Copy assignment operator.</para>
	/// </summary>
	ClearCommand& operator=(const ClearCommand&) = delete;

private:
	/// <summary>
	/// </summary>
	cell handle_;
};

/// <summary>
/// </summary>
cell AMX_NATIVE_CALL toml_clear(Amx* amx, cell* params);
