// ***********************************************************************
// Author           : the_hunter
// Created          : 04-01-2020
//
// Last Modified By : the_hunter
// Last Modified On : 04-01-2020
// ***********************************************************************

#include <toml/pch.h>

using namespace std;
using namespace std::chrono;

/// <summary>
/// </summary>
inline cell to_seconds(const system_clock::time_point& time_point)
{
	return static_cast<cell>(time_point.time_since_epoch().count() / 10000000);
}

/// <summary>
/// </summary>
inline cell to_seconds(const toml::local_date& date)
{
	const system_clock::time_point time_point = date;
	return to_seconds(time_point);
}

/// <summary>
/// </summary>
inline cell to_seconds(const toml::local_time& time)
{
	return time.hour * 3600 + time.minute * 60 + time.second;
}

/// <summary>
/// </summary>
inline cell to_seconds(const toml::local_datetime& datetime)
{
	const system_clock::time_point time_point = datetime;
	return to_seconds(time_point);
}

/// <summary>
/// </summary>
inline cell to_seconds(const toml::offset_datetime& datetime)
{
	const system_clock::time_point time_point = datetime;
	return to_seconds(time_point);
}

/// <summary>
/// </summary>
static cell to_datetime(const toml_t& value, TomlDateTime* datetime)
{
	switch (value.type()) {
	case toml::value_t::local_date: {
		const auto& date = value.as_local_date();
		datetime->year = date.year;
		datetime->month = date.month + 1;
		datetime->day = date.day;
		datetime->unix_timestamp = to_seconds(date);
		break;
	}
	case toml::value_t::local_time: {
		const auto& time = value.as_local_time();
		datetime->hour = time.hour;
		datetime->minute = time.minute;
		datetime->second = time.second;
		datetime->millisecond = time.millisecond;
		datetime->unix_timestamp = to_seconds(time);
		break;
	}
	case toml::value_t::local_datetime: {
		const auto& local_datetime = value.as_local_datetime();
		datetime->year = local_datetime.date.year;
		datetime->month = local_datetime.date.month + 1;
		datetime->day = local_datetime.date.day;
		datetime->hour = local_datetime.time.hour;
		datetime->minute = local_datetime.time.minute;
		datetime->second = local_datetime.time.second;
		datetime->millisecond = local_datetime.time.millisecond;
		datetime->unix_timestamp = to_seconds(local_datetime);
		break;
	}
	default: {
		const auto& offset_datetime = value.as_offset_datetime();
		datetime->year = offset_datetime.date.year;
		datetime->month = offset_datetime.date.month + 1;
		datetime->day = offset_datetime.date.day;
		datetime->hour = offset_datetime.time.hour;
		datetime->minute = offset_datetime.time.minute;
		datetime->second = offset_datetime.time.second;
		datetime->millisecond = offset_datetime.time.millisecond;
		datetime->offset_hour = offset_datetime.offset.hour; // NOLINT
		datetime->offset_minute = offset_datetime.offset.minute; // NOLINT
		datetime->unix_timestamp = to_seconds(offset_datetime);
		break;
	}
	}

	return datetime->unix_timestamp;
}

/// <summary>
/// </summary>
static cell to_datetime(const toml_t& value, cell* offset_hour, cell* offset_minute)
{
	if (value.type() == toml::value_t::local_time) {
		return to_seconds(value.as_local_time());
	}

	if (value.type() != toml::value_t::offset_datetime) {
		return to_seconds(toml::get<system_clock::time_point>(value));
	}

	const auto& datetime = value.as_offset_datetime();
	*offset_hour = datetime.offset.hour; // NOLINT
	*offset_minute = datetime.offset.minute; // NOLINT

	return to_seconds(datetime);
}

/// <summary>
/// </summary>
GetDateTimeCommand::GetDateTimeCommand(const cell handle, const char* key, TomlDateTime* datetime) : handle_(handle)
{
	find_value_ = [key](TomlHolder* holder) -> toml_t&
	{
		return toml_find(holder, key);
	};

	to_datetime_ = [datetime](const toml_t& value)
	{
		return to_datetime(value, datetime);
	};
}

/// <summary>
/// </summary>
GetDateTimeCommand::GetDateTimeCommand(const cell handle, const cell index, TomlDateTime* datetime) : handle_(handle)
{
	find_value_ = [index](TomlHolder* holder) -> toml_t&
	{
		return toml::find(*holder->toml(), index);
	};

	to_datetime_ = [datetime](const toml_t& value)
	{
		return to_datetime(value, datetime);
	};
}

/// <summary>
/// </summary>
GetDateTimeCommand::GetDateTimeCommand(const cell handle, const char* key, cell* offset_hour, cell* offset_minute) : handle_(handle)
{
	find_value_ = [key](TomlHolder* holder) -> toml_t&
	{
		return toml_find(holder, key);
	};

	to_datetime_ = [offset_hour, offset_minute](const toml_t& value)
	{
		return to_datetime(value, offset_hour, offset_minute);
	};
}

/// <summary>
/// </summary>
GetDateTimeCommand::GetDateTimeCommand(const cell handle, const cell index, cell* offset_hour, cell* offset_minute) : handle_(handle)
{
	find_value_ = [index](TomlHolder* holder) -> toml_t&
	{
		return toml::find(*holder->toml(), index);
	};

	to_datetime_ = [offset_hour, offset_minute](const toml_t& value)
	{
		return to_datetime(value, offset_hour, offset_minute);
	};
}

/// <summary>
/// </summary>
cell GetDateTimeCommand::execute()
{
	auto* const holder = Storage::get(handle_);
	const auto& value = find_value_(holder);

	return to_datetime_(value);
}

/// <summary>
/// </summary>
cell AMX_NATIVE_CALL toml_get_datetime(Amx* amx, cell* params)
{
	enum Args { Count, Handle, Key, DefaultValue, OffsetHour, OffsetMinute, ThrowError };

	const auto handle = params[Handle];
	auto* const key = AmxxApi::get_amx_string(amx, params[Key]);
	const auto default_value = params[DefaultValue];
	auto* const offset_hour = amx_address(amx, params[OffsetHour]);
	auto* const offset_minute = amx_address(amx, params[OffsetMinute]);
	GetDateTimeCommand command(handle, key, offset_hour, offset_minute);

	return execute(command, amx, default_value, params[ThrowError], __func__);
}

/// <summary>
/// </summary>
cell AMX_NATIVE_CALL toml_array_get_datetime(Amx* amx, cell* params)
{
	enum Args { Count, Handle, Index, DefaultValue, OffsetHour, OffsetMinute, ThrowError };

	const auto handle = params[Handle];
	const auto index = params[Index];
	const auto default_value = params[DefaultValue];
	auto* const offset_hour = amx_address(amx, params[OffsetHour]);
	auto* const offset_minute = amx_address(amx, params[OffsetMinute]);
	GetDateTimeCommand command(handle, index, offset_hour, offset_minute);

	return execute(command, amx, default_value, params[ThrowError], __func__);
}

/// <summary>
/// </summary>
cell AMX_NATIVE_CALL toml_get_datetime_ex(Amx* amx, cell* params)
{
	enum Args { Count, Handle, Key, DateTime, ThrowError };

	const auto handle = params[Handle];
	auto* const key = AmxxApi::get_amx_string(amx, params[Key]);
	auto* const datetime = reinterpret_cast<TomlDateTime*>(amx_address(amx, params[DateTime]));
	GetDateTimeCommand command(handle, key, datetime);

	return execute(command, amx, -1, params[ThrowError], __func__);
}

/// <summary>
/// </summary>
cell AMX_NATIVE_CALL toml_array_get_datetime_ex(Amx* amx, cell* params)
{
	enum Args { Count, Handle, Index, DateTime, ThrowError };

	const auto handle = params[Handle];
	const auto index = params[Index];
	auto* const datetime = reinterpret_cast<TomlDateTime*>(amx_address(amx, params[DateTime]));
	GetDateTimeCommand command(handle, index, datetime);

	return execute(command, amx, -1, params[ThrowError], __func__);
}
