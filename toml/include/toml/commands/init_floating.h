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
/// Class InitRootCommand.
/// </summary>
class InitFloatingCommand final : public ITomlCommand {
public:
	/// <summary>
	/// </summary>
	InitFloatingCommand(cell handle, const char* key, cell value);

	/// <summary>
	/// </summary>
	InitFloatingCommand(cell handle, cell value);

	/// <summary>
	/// </summary>
	cell execute() override;

	/// <summary>
	/// </summary>
	~InitFloatingCommand() = default;

	/// <summary>
	/// <para>Move constructor.</para>
	/// </summary>
	InitFloatingCommand(InitFloatingCommand&&) = delete;

	/// <summary>
	/// <para>Copy constructor.</para>
	/// </summary>
	InitFloatingCommand(const InitFloatingCommand&) = delete;

	/// <summary>
	/// <para>Move assignment operator.</para>
	/// </summary>
	InitFloatingCommand& operator=(InitFloatingCommand&&) = delete;

	/// <summary>
	/// <para>Copy assignment operator.</para>
	/// </summary>
	InitFloatingCommand& operator=(const InitFloatingCommand&) = delete;

private:
	/// <summary>
	/// </summary>
	cell handle_;

	/// <summary>
	/// </summary>
	std::function<cell(TomlHolder*&)> toml_init_{};
};

/// <summary>
/// </summary>
cell AMX_NATIVE_CALL toml_init_float(Amx* amx, cell* params);

/// <summary>
/// </summary>
cell AMX_NATIVE_CALL toml_array_init_float(Amx* amx, cell* params);
