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
/// Class GetTypeCommand.
/// </summary>
class GetTypeCommand final : public ITomlCommand {
public:
	/// <summary>
	/// </summary>
	GetTypeCommand(cell handle, const char* key);

	/// <summary>
	/// </summary>
	GetTypeCommand(cell handle, cell index);

	/// <summary>
	/// </summary>
	cell execute() override;

	/// <summary>
	/// </summary>
	~GetTypeCommand() = default;

	/// <summary>
	/// <para>Move constructor.</para>
	/// </summary>
	GetTypeCommand(GetTypeCommand&&) = delete;

	/// <summary>
	/// <para>Copy constructor.</para>
	/// </summary>
	GetTypeCommand(const GetTypeCommand&) = delete;

	/// <summary>
	/// <para>Move assignment operator.</para>
	/// </summary>
	GetTypeCommand& operator=(GetTypeCommand&&) = delete;

	/// <summary>
	/// <para>Copy assignment operator.</para>
	/// </summary>
	GetTypeCommand& operator=(const GetTypeCommand&) = delete;

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
cell AMX_NATIVE_CALL toml_get_type(Amx* amx, cell* params);

/// <summary>
/// </summary>
cell AMX_NATIVE_CALL toml_array_get_type(Amx* amx, cell* params);
