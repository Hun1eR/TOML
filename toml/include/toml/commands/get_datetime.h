// ***********************************************************************
// Author           : the_hunter
// Created          : 04-01-2020
//
// Last Modified By : the_hunter
// Last Modified On : 04-01-2020
// ***********************************************************************

#pragma once

#include <toml/commands/command.h>
#include <toml/datetime.h>

/// <summary>
/// Class GetDateTimeCommand.
/// </summary>
class GetDateTimeCommand final : public ITomlCommand {
public:
	/// <summary>
	/// </summary>
	GetDateTimeCommand(cell handle, const char* key, TomlDateTime* datetime);

	/// <summary>
	/// </summary>
	GetDateTimeCommand(cell handle, cell index, TomlDateTime* datetime);

	/// <summary>
	/// </summary>
	GetDateTimeCommand(cell handle, const char* key, cell* offset_hour, cell* offset_minute);

	/// <summary>
	/// </summary>
	GetDateTimeCommand(cell handle, cell index, cell* offset_hour, cell* offset_minute);

	/// <summary>
	/// </summary>
	cell execute() override;

private:
	/// <summary>
	/// </summary>
	cell handle_;

	/// <summary>
	/// </summary>
	std::function<toml_t&(TomlHolder*)> find_value_{};

	/// <summary>
	/// </summary>
	std::function<cell(const toml_t&)> to_datetime_{};
};

/// <summary>
/// </summary>
cell AMX_NATIVE_CALL toml_get_datetime(Amx* amx, cell* params);

/// <summary>
/// </summary>
cell AMX_NATIVE_CALL toml_array_get_datetime(Amx* amx, cell* params);

/// <summary>
/// </summary>
cell AMX_NATIVE_CALL toml_get_datetime_ex(Amx* amx, cell* params);

/// <summary>
/// </summary>
cell AMX_NATIVE_CALL toml_array_get_datetime_ex(Amx* amx, cell* params);
