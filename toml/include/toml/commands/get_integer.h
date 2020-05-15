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
/// Class GetIntegerCommand.
/// </summary>
class GetIntegerCommand final : public ITomlCommand {
public:
	/// <summary>
	/// </summary>
	GetIntegerCommand(cell handle, const char* key);

	/// <summary>
	/// </summary>
	GetIntegerCommand(cell handle, cell index);

	/// <summary>
	/// </summary>
	cell execute() override;

	/// <summary>
	/// </summary>
	~GetIntegerCommand() = default;

	/// <summary>
	/// <para>Move constructor.</para>
	/// </summary>
	GetIntegerCommand(GetIntegerCommand&&) = delete;

	/// <summary>
	/// <para>Copy constructor.</para>
	/// </summary>
	GetIntegerCommand(const GetIntegerCommand&) = delete;

	/// <summary>
	/// <para>Move assignment operator.</para>
	/// </summary>
	GetIntegerCommand& operator=(GetIntegerCommand&&) = delete;

	/// <summary>
	/// <para>Copy assignment operator.</para>
	/// </summary>
	GetIntegerCommand& operator=(const GetIntegerCommand&) = delete;

private:
	/// <summary>
	/// </summary>
	cell handle_;

	/// <summary>
	/// </summary>
	std::function<toml_t&(TomlHolder*)> find_value_{};
};

/// <summary>
/// </summary>
cell AMX_NATIVE_CALL toml_get_int(Amx* amx, cell* params);

/// <summary>
/// </summary>
cell AMX_NATIVE_CALL toml_array_get_int(Amx* amx, cell* params);
