// ***********************************************************************
// Author           : the_hunter
// Created          : 04-01-2020
//
// Last Modified By : the_hunter
// Last Modified On : 04-01-2020
// ***********************************************************************

#pragma once

#include <toml/commands/command.h>
#include <functional>

/// <summary>
/// Class SetTableCommand.
/// </summary>
class SetTableCommand final : public ITomlCommand {
public:
	/// <summary>
	/// </summary>
	SetTableCommand(cell handle, const char* key, cell value);

	/// <summary>
	/// </summary>
	SetTableCommand(cell handle, cell index, cell value);

	/// <summary>
	/// </summary>
	cell execute() override;

	/// <summary>
	/// </summary>
	~SetTableCommand() = default;

	/// <summary>
	/// <para>Move constructor.</para>
	/// </summary>
	SetTableCommand(SetTableCommand&&) = delete;

	/// <summary>
	/// <para>Copy constructor.</para>
	/// </summary>
	SetTableCommand(const SetTableCommand&) = delete;

	/// <summary>
	/// <para>Move assignment operator.</para>
	/// </summary>
	SetTableCommand& operator=(SetTableCommand&&) = delete;

	/// <summary>
	/// <para>Copy assignment operator.</para>
	/// </summary>
	SetTableCommand& operator=(const SetTableCommand&) = delete;

private:
	/// <summary>
	/// </summary>
	cell handle_;

	/// <summary>
	/// </summary>
	cell value_;

	/// <summary>
	/// </summary>
	std::function<toml_t&(TomlHolder*&)> find_value_{};
};

/// <summary>
/// </summary>
cell AMX_NATIVE_CALL toml_set_table(Amx* amx, cell* params);

/// <summary>
/// </summary>
cell AMX_NATIVE_CALL toml_array_set_table(Amx* amx, cell* params);
