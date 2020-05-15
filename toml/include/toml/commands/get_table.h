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
/// Class GetTableCommand.
/// </summary>
class GetTableCommand final : public ITomlCommand {
public:
	/// <summary>
	/// </summary>
	GetTableCommand(cell handle, const char* key);

	/// <summary>
	/// </summary>
	GetTableCommand(cell handle, cell index);

	/// <summary>
	/// </summary>
	cell execute() override;

	/// <summary>
	/// </summary>
	~GetTableCommand() = default;

	/// <summary>
	/// <para>Move constructor.</para>
	/// </summary>
	GetTableCommand(GetTableCommand&&) = delete;

	/// <summary>
	/// <para>Copy constructor.</para>
	/// </summary>
	GetTableCommand(const GetTableCommand&) = delete;

	/// <summary>
	/// <para>Move assignment operator.</para>
	/// </summary>
	GetTableCommand& operator=(GetTableCommand&&) = delete;

	/// <summary>
	/// <para>Copy assignment operator.</para>
	/// </summary>
	GetTableCommand& operator=(const GetTableCommand&) = delete;

private:
	/// <summary>
	/// </summary>
	cell handle_;

	/// <summary>
	/// </summary>
	std::function<toml_t&(TomlHolder*&)> find_table_{};
};

/// <summary>
/// </summary>
cell AMX_NATIVE_CALL toml_get_table(Amx* amx, cell* params);

/// <summary>
/// </summary>
cell AMX_NATIVE_CALL toml_array_get_table(Amx* amx, cell* params);
