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
/// Class SetFloatingCommand.
/// </summary>
class SetFloatingCommand final : public ITomlCommand {
public:
	/// <summary>
	/// </summary>
	SetFloatingCommand(cell handle, const char* key, cell value);

	/// <summary>
	/// </summary>
	SetFloatingCommand(cell handle, cell index, cell value);

	/// <summary>
	/// </summary>
	cell execute() override;

	/// <summary>
	/// </summary>
	~SetFloatingCommand() = default;

	/// <summary>
	/// <para>Move constructor.</para>
	/// </summary>
	SetFloatingCommand(SetFloatingCommand&&) = delete;

	/// <summary>
	/// <para>Copy constructor.</para>
	/// </summary>
	SetFloatingCommand(const SetFloatingCommand&) = delete;

	/// <summary>
	/// <para>Move assignment operator.</para>
	/// </summary>
	SetFloatingCommand& operator=(SetFloatingCommand&&) = delete;

	/// <summary>
	/// <para>Copy assignment operator.</para>
	/// </summary>
	SetFloatingCommand& operator=(const SetFloatingCommand&) = delete;

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
cell AMX_NATIVE_CALL toml_set_float(Amx* amx, cell* params);

/// <summary>
/// </summary>
cell AMX_NATIVE_CALL toml_array_set_float(Amx* amx, cell* params);
