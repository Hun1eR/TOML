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
class GetCountCommand final : public ITomlCommand {
public:
	/// <summary>
	/// </summary>
	explicit GetCountCommand(cell handle);

	/// <summary>
	/// </summary>
	cell execute() override;

	/// <summary>
	/// </summary>
	~GetCountCommand() = default;

	/// <summary>
	/// <para>Move constructor.</para>
	/// </summary>
	GetCountCommand(GetCountCommand&&) = delete;

	/// <summary>
	/// <para>Copy constructor.</para>
	/// </summary>
	GetCountCommand(const GetCountCommand&) = delete;

	/// <summary>
	/// <para>Move assignment operator.</para>
	/// </summary>
	GetCountCommand& operator=(GetCountCommand&&) = delete;

	/// <summary>
	/// <para>Copy assignment operator.</para>
	/// </summary>
	GetCountCommand& operator=(const GetCountCommand&) = delete;

private:
	/// <summary>
	/// </summary>
	cell handle_;
};

/// <summary>
/// </summary>
cell AMX_NATIVE_CALL toml_array_get_count(Amx* amx, cell* params);
