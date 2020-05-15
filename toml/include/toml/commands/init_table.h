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
class InitTableCommand final : public ITomlCommand {
public:
	/// <summary>
	/// </summary>
	InitTableCommand(cell handle, const char* key);

	/// <summary>
	/// </summary>
	explicit InitTableCommand(cell handle);

	/// <summary>
	/// </summary>
	cell execute() override;

	/// <summary>
	/// </summary>
	~InitTableCommand() = default;

	/// <summary>
	/// <para>Move constructor.</para>
	/// </summary>
	InitTableCommand(InitTableCommand&&) = delete;

	/// <summary>
	/// <para>Copy constructor.</para>
	/// </summary>
	InitTableCommand(const InitTableCommand&) = delete;

	/// <summary>
	/// <para>Move assignment operator.</para>
	/// </summary>
	InitTableCommand& operator=(InitTableCommand&&) = delete;

	/// <summary>
	/// <para>Copy assignment operator.</para>
	/// </summary>
	InitTableCommand& operator=(const InitTableCommand&) = delete;

private:
	/// <summary>
	/// </summary>
	cell handle_;

	/// <summary>
	/// </summary>
	std::function<toml_t&(TomlHolder*&)> toml_init_{};
};

/// <summary>
/// </summary>
cell AMX_NATIVE_CALL toml_init_table(Amx* amx, cell* params);

/// <summary>
/// </summary>
cell AMX_NATIVE_CALL toml_array_init_table(Amx* amx, cell* params);
