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

	/// <summary>
	/// </summary>
	~ContainsCommand() = default;

	/// <summary>
	/// <para>Move constructor.</para>
	/// </summary>
	ContainsCommand(ContainsCommand&&) = delete;

	/// <summary>
	/// <para>Copy constructor.</para>
	/// </summary>
	ContainsCommand(const ContainsCommand&) = delete;

	/// <summary>
	/// <para>Move assignment operator.</para>
	/// </summary>
	ContainsCommand& operator=(ContainsCommand&&) = delete;

	/// <summary>
	/// <para>Copy assignment operator.</para>
	/// </summary>
	ContainsCommand& operator=(const ContainsCommand&) = delete;

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
