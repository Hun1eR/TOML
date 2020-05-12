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
/// Class SetDateTimeCommand.
/// </summary>
class SetDateTimeCommand final : public ITomlCommand {
public:
	/// <summary>
	/// </summary>
	SetDateTimeCommand(cell handle, const char* key, cell year, cell month, cell day);

	/// <summary>
	/// </summary>
	SetDateTimeCommand(cell handle, cell index, cell year, cell month, cell day);

	/// <summary>
	/// </summary>
	SetDateTimeCommand(cell handle, const char* key, cell hour, cell minute, cell second, cell millisecond);

	/// <summary>
	/// </summary>
	SetDateTimeCommand(cell handle, cell index, cell hour, cell minute, cell second, cell millisecond);

	/// <summary>
	/// </summary>
	SetDateTimeCommand(cell handle, const char* key, const TomlDateTime* datetime, bool offset);

	/// <summary>
	/// </summary>
	SetDateTimeCommand(cell handle, cell index, const TomlDateTime* datetime, bool offset);

	/// <summary>
	/// </summary>
	cell execute() override;

private:
	/// <summary>
	/// </summary>
	cell handle_;

	/// <summary>
	/// </summary>
	std::function<toml_t&(TomlHolder*&)> find_value_{};

	/// <summary>
	/// </summary>
	std::function<void(toml_t&)> set_datetime_{};
};

/// <summary>
/// </summary>
cell AMX_NATIVE_CALL toml_set_local_date(Amx* amx, cell* params);

/// <summary>
/// </summary>
cell AMX_NATIVE_CALL toml_array_set_local_date(Amx* amx, cell* params);

/// <summary>
/// </summary>
cell AMX_NATIVE_CALL toml_set_local_time(Amx* amx, cell* params);

/// <summary>
/// </summary>
cell AMX_NATIVE_CALL toml_array_set_local_time(Amx* amx, cell* params);

/// <summary>
/// </summary>
cell AMX_NATIVE_CALL toml_set_local_datetime(Amx* amx, cell* params);

/// <summary>
/// </summary>
cell AMX_NATIVE_CALL toml_array_set_local_datetime(Amx* amx, cell* params);

/// <summary>
/// </summary>
cell AMX_NATIVE_CALL toml_set_offset_datetime(Amx* amx, cell* params);

/// <summary>
/// </summary>
cell AMX_NATIVE_CALL toml_array_set_offset_datetime(Amx* amx, cell* params);
