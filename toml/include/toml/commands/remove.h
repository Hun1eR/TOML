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
/// Class RemoveCommand.
/// </summary>
class RemoveCommand final : public ITomlCommand {
public:
	/// <summary>
	/// </summary>
	RemoveCommand(cell handle, const char* composite_key);

	/// <summary>
	/// </summary>
	RemoveCommand(cell handle, cell index);

	/// <summary>
	/// </summary>
	cell execute() override;

	/// <summary>
	/// </summary>
	~RemoveCommand() = default;

	/// <summary>
	/// <para>Move constructor.</para>
	/// </summary>
	RemoveCommand(RemoveCommand&&) = delete;

	/// <summary>
	/// <para>Copy constructor.</para>
	/// </summary>
	RemoveCommand(const RemoveCommand&) = delete;

	/// <summary>
	/// <para>Move assignment operator.</para>
	/// </summary>
	RemoveCommand& operator=(RemoveCommand&&) = delete;

	/// <summary>
	/// <para>Copy assignment operator.</para>
	/// </summary>
	RemoveCommand& operator=(const RemoveCommand&) = delete;

private:
	/// <summary>
	/// </summary>
	cell handle_;

	/// <summary>
	/// </summary>
	std::function<cell(TomlHolder*&)> remove_toml_{};
};

/// <summary>
/// </summary>
cell AMX_NATIVE_CALL toml_remove(Amx* amx, cell* params);

/// <summary>
/// </summary>
cell AMX_NATIVE_CALL toml_array_remove(Amx* amx, cell* params);
