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
/// Class GetCountCommand.
/// </summary>
class IsValidCommand final : public ITomlCommand {
public:
	/// <summary>
	/// </summary>
	explicit IsValidCommand(cell handle);

	/// <summary>
	/// </summary>
	cell execute() override;

	/// <summary>
	/// </summary>
	~IsValidCommand() = default;

	/// <summary>
	/// <para>Move constructor.</para>
	/// </summary>
	IsValidCommand(IsValidCommand&&) = delete;

	/// <summary>
	/// <para>Copy constructor.</para>
	/// </summary>
	IsValidCommand(const IsValidCommand&) = delete;

	/// <summary>
	/// <para>Move assignment operator.</para>
	/// </summary>
	IsValidCommand& operator=(IsValidCommand&&) = delete;

	/// <summary>
	/// <para>Copy assignment operator.</para>
	/// </summary>
	IsValidCommand& operator=(const IsValidCommand&) = delete;

private:
	/// <summary>
	/// </summary>
	cell handle_;
};

/// <summary>
/// </summary>
cell AMX_NATIVE_CALL toml_is_valid(Amx* amx, cell* params);
