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
/// Class SetIntegerCommand.
/// </summary>
class SetIntegerCommand final : public ITomlCommand {
public:
	/// <summary>
	/// </summary>
	SetIntegerCommand(cell handle, const char* key, cell value);

	/// <summary>
	/// </summary>
	SetIntegerCommand(cell handle, cell index, cell value);

	/// <summary>
	/// </summary>
	cell execute() override;

	/// <summary>
	/// </summary>
	~SetIntegerCommand() = default;

	/// <summary>
	/// <para>Move constructor.</para>
	/// </summary>
	SetIntegerCommand(SetIntegerCommand&&) = delete;

	/// <summary>
	/// <para>Copy constructor.</para>
	/// </summary>
	SetIntegerCommand(const SetIntegerCommand&) = delete;

	/// <summary>
	/// <para>Move assignment operator.</para>
	/// </summary>
	SetIntegerCommand& operator=(SetIntegerCommand&&) = delete;

	/// <summary>
	/// <para>Copy assignment operator.</para>
	/// </summary>
	SetIntegerCommand& operator=(const SetIntegerCommand&) = delete;

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
cell AMX_NATIVE_CALL toml_set_int(Amx* amx, cell* params);

/// <summary>
/// </summary>
cell AMX_NATIVE_CALL toml_array_set_int(Amx* amx, cell* params);
