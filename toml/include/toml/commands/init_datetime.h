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
class InitDateTimeCommand final : public ITomlCommand {
public:
	/// <summary>
	/// </summary>
	InitDateTimeCommand(cell handle, const char* key, cell year, cell month, cell day);

	/// <summary>
	/// </summary>
	InitDateTimeCommand(cell handle, cell year, cell month, cell day);

	/// <summary>
	/// </summary>
	InitDateTimeCommand(cell handle, const char* key, cell hour, cell minute, cell second, cell millisecond);

	/// <summary>
	/// </summary>
	InitDateTimeCommand(cell handle, cell hour, cell minute, cell second, cell millisecond);

	/// <summary>
	/// </summary>
	InitDateTimeCommand(cell handle, const char* key, const TomlDateTime* datetime, bool offset);

	/// <summary>
	/// </summary>
	InitDateTimeCommand(cell handle, const TomlDateTime* datetime, bool offset);

	/// <summary>
	/// </summary>
	cell execute() override;

	/// <summary>
	/// </summary>
	~InitDateTimeCommand() = default;

	/// <summary>
	/// <para>Move constructor.</para>
	/// </summary>
	InitDateTimeCommand(InitDateTimeCommand&&) = delete;

	/// <summary>
	/// <para>Copy constructor.</para>
	/// </summary>
	InitDateTimeCommand(const InitDateTimeCommand&) = delete;

	/// <summary>
	/// <para>Move assignment operator.</para>
	/// </summary>
	InitDateTimeCommand& operator=(InitDateTimeCommand&&) = delete;

	/// <summary>
	/// <para>Copy assignment operator.</para>
	/// </summary>
	InitDateTimeCommand& operator=(const InitDateTimeCommand&) = delete;

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
cell AMX_NATIVE_CALL toml_init_local_date(Amx* amx, cell* params);

/// <summary>
/// </summary>
cell AMX_NATIVE_CALL toml_array_init_local_date(Amx* amx, cell* params);

/// <summary>
/// </summary>
cell AMX_NATIVE_CALL toml_init_local_time(Amx* amx, cell* params);

/// <summary>
/// </summary>
cell AMX_NATIVE_CALL toml_array_init_local_time(Amx* amx, cell* params);

/// <summary>
/// </summary>
cell AMX_NATIVE_CALL toml_init_local_datetime(Amx* amx, cell* params);

/// <summary>
/// </summary>
cell AMX_NATIVE_CALL toml_array_init_local_datetime(Amx* amx, cell* params);

/// <summary>
/// </summary>
cell AMX_NATIVE_CALL toml_init_offset_datetime(Amx* amx, cell* params);

/// <summary>
/// </summary>
cell AMX_NATIVE_CALL toml_array_init_offset_datetime(Amx* amx, cell* params);
