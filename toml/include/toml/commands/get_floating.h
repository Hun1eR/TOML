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
/// Class GetFloatingCommand.
/// </summary>
class GetFloatingCommand final : public ITomlCommand {
public:
	/// <summary>
	/// </summary>
	GetFloatingCommand(cell handle, const char* key);

	/// <summary>
	/// </summary>
	GetFloatingCommand(cell handle, cell index);

	/// <summary>
	/// </summary>
	cell execute() override;

	/// <summary>
	/// </summary>
	~GetFloatingCommand() = default;

	/// <summary>
	/// <para>Move constructor.</para>
	/// </summary>
	GetFloatingCommand(GetFloatingCommand&&) = delete;

	/// <summary>
	/// <para>Copy constructor.</para>
	/// </summary>
	GetFloatingCommand(const GetFloatingCommand&) = delete;

	/// <summary>
	/// <para>Move assignment operator.</para>
	/// </summary>
	GetFloatingCommand& operator=(GetFloatingCommand&&) = delete;

	/// <summary>
	/// <para>Copy assignment operator.</para>
	/// </summary>
	GetFloatingCommand& operator=(const GetFloatingCommand&) = delete;

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
cell AMX_NATIVE_CALL toml_get_float(Amx* amx, cell* params);

/// <summary>
/// </summary>
cell AMX_NATIVE_CALL toml_array_get_float(Amx* amx, cell* params);
