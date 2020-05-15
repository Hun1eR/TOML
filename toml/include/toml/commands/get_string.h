// ***********************************************************************
// Author           : the_hunter
// Created          : 04-01-2020
//
// Last Modified By : the_hunter
// Last Modified On : 04-01-2020
// ***********************************************************************

#pragma once

#include <amxx/string.h>
#include <toml/commands/command.h>
#include <functional>

/// <summary>
/// Class GetStringCommand.
/// </summary>
class GetStringCommand final : public ITomlCommand {
public:
	/// <summary>
	/// </summary>
	GetStringCommand(cell handle, const char* key, amx::string& string);

	/// <summary>
	/// </summary>
	GetStringCommand(cell handle, cell index, amx::string& string);

	/// <summary>
	/// </summary>
	cell execute() override;

	/// <summary>
	/// </summary>
	~GetStringCommand() = default;

	/// <summary>
	/// <para>Move constructor.</para>
	/// </summary>
	GetStringCommand(GetStringCommand&&) = delete;

	/// <summary>
	/// <para>Copy constructor.</para>
	/// </summary>
	GetStringCommand(const GetStringCommand&) = delete;

	/// <summary>
	/// <para>Move assignment operator.</para>
	/// </summary>
	GetStringCommand& operator=(GetStringCommand&&) = delete;

	/// <summary>
	/// <para>Copy assignment operator.</para>
	/// </summary>
	GetStringCommand& operator=(const GetStringCommand&) = delete;

private:
	/// <summary>
	/// </summary>
	cell handle_;

	/// <summary>
	/// </summary>
	amx::String& string_;

	/// <summary>
	/// </summary>
	std::function<toml_t&(TomlHolder*)> find_value_{};
};

/// <summary>
/// </summary>
cell AMX_NATIVE_CALL toml_get_string(Amx* amx, cell* params);

/// <summary>
/// </summary>
cell AMX_NATIVE_CALL toml_array_get_string(Amx* amx, cell* params);
