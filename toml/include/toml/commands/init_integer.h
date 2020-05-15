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
class InitIntegerCommand final : public ITomlCommand {
public:
	/// <summary>
	/// </summary>
	InitIntegerCommand(cell handle, const char* key, cell value);

	/// <summary>
	/// </summary>
	InitIntegerCommand(cell handle, cell value);

	/// <summary>
	/// </summary>
	cell execute() override;

	/// <summary>
	/// </summary>
	~InitIntegerCommand() = default;

	/// <summary>
	/// <para>Move constructor.</para>
	/// </summary>
	InitIntegerCommand(InitIntegerCommand&&) = delete;

	/// <summary>
	/// <para>Copy constructor.</para>
	/// </summary>
	InitIntegerCommand(const InitIntegerCommand&) = delete;

	/// <summary>
	/// <para>Move assignment operator.</para>
	/// </summary>
	InitIntegerCommand& operator=(InitIntegerCommand&&) = delete;

	/// <summary>
	/// <para>Copy assignment operator.</para>
	/// </summary>
	InitIntegerCommand& operator=(const InitIntegerCommand&) = delete;

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
cell AMX_NATIVE_CALL toml_init_int(Amx* amx, cell* params);

/// <summary>
/// </summary>
cell AMX_NATIVE_CALL toml_array_init_int(Amx* amx, cell* params);
