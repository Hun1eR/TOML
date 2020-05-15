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
class InitStringCommand final : public ITomlCommand {
public:
	/// <summary>
	/// </summary>
	InitStringCommand(cell handle, const char* key, const char* value);

	/// <summary>
	/// </summary>
	InitStringCommand(cell handle, const char* value);

	/// <summary>
	/// </summary>
	cell execute() override;

	/// <summary>
	/// </summary>
	~InitStringCommand() = default;

	/// <summary>
	/// <para>Move constructor.</para>
	/// </summary>
	InitStringCommand(InitStringCommand&&) = delete;

	/// <summary>
	/// <para>Copy constructor.</para>
	/// </summary>
	InitStringCommand(const InitStringCommand&) = delete;

	/// <summary>
	/// <para>Move assignment operator.</para>
	/// </summary>
	InitStringCommand& operator=(InitStringCommand&&) = delete;

	/// <summary>
	/// <para>Copy assignment operator.</para>
	/// </summary>
	InitStringCommand& operator=(const InitStringCommand&) = delete;

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
cell AMX_NATIVE_CALL toml_init_string(Amx* amx, cell* params);

/// <summary>
/// </summary>
cell AMX_NATIVE_CALL toml_array_init_string(Amx* amx, cell* params);
