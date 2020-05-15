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
/// Class SetArrayCommand.
/// </summary>
class SetArrayCommand final : public ITomlCommand {
public:
	/// <summary>
	/// </summary>
	SetArrayCommand(cell handle, const char* key, cell value);

	/// <summary>
	/// </summary>
	SetArrayCommand(cell handle, cell index, cell value);

	/// <summary>
	/// </summary>
	cell execute() override;

	/// <summary>
	/// </summary>
	~SetArrayCommand() = default;

	/// <summary>
	/// <para>Move constructor.</para>
	/// </summary>
	SetArrayCommand(SetArrayCommand&&) = delete;

	/// <summary>
	/// <para>Copy constructor.</para>
	/// </summary>
	SetArrayCommand(const SetArrayCommand&) = delete;

	/// <summary>
	/// <para>Move assignment operator.</para>
	/// </summary>
	SetArrayCommand& operator=(SetArrayCommand&&) = delete;

	/// <summary>
	/// <para>Copy assignment operator.</para>
	/// </summary>
	SetArrayCommand& operator=(const SetArrayCommand&) = delete;

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
cell AMX_NATIVE_CALL toml_set_array(Amx* amx, cell* params);

/// <summary>
/// </summary>
cell AMX_NATIVE_CALL toml_array_set_array(Amx* amx, cell* params);
