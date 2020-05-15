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
/// Class SetBooleanCommand.
/// </summary>
class SetBooleanCommand final : public ITomlCommand {
public:
	/// <summary>
	/// </summary>
	SetBooleanCommand(cell handle, const char* key, cell value);

	/// <summary>
	/// </summary>
	SetBooleanCommand(cell handle, cell index, cell value);

	/// <summary>
	/// </summary>
	cell execute() override;

	/// <summary>
	/// </summary>
	~SetBooleanCommand() = default;

	/// <summary>
	/// <para>Move constructor.</para>
	/// </summary>
	SetBooleanCommand(SetBooleanCommand&&) = delete;

	/// <summary>
	/// <para>Copy constructor.</para>
	/// </summary>
	SetBooleanCommand(const SetBooleanCommand&) = delete;

	/// <summary>
	/// <para>Move assignment operator.</para>
	/// </summary>
	SetBooleanCommand& operator=(SetBooleanCommand&&) = delete;

	/// <summary>
	/// <para>Copy assignment operator.</para>
	/// </summary>
	SetBooleanCommand& operator=(const SetBooleanCommand&) = delete;

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
cell AMX_NATIVE_CALL toml_set_bool(Amx* amx, cell* params);

/// <summary>
/// </summary>
cell AMX_NATIVE_CALL toml_array_set_bool(Amx* amx, cell* params);
