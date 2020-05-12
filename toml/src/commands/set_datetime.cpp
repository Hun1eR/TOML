// ***********************************************************************
// Author           : the_hunter
// Created          : 04-01-2020
//
// Last Modified By : the_hunter
// Last Modified On : 04-01-2020
// ***********************************************************************

#include <toml/pch.h>

/// <summary>
/// </summary>
inline void set_datetime(toml_t& toml, const cell year, const cell month, const cell day)
{
	const auto date = toml::local_date{year, static_cast<toml::month_t>(month - 1), day};
	toml = date;
}

/// <summary>
/// </summary>
inline void set_datetime(toml_t& toml, const cell hour, const cell minute, const cell second, const cell millisecond)
{
	const auto time = toml::local_time{hour, minute, second, millisecond};
	toml = time;
}

/// <summary>
/// </summary>
inline void set_datetime(toml_t& toml, const TomlDateTime* const datetime)
{
	const auto date = toml::local_date{datetime->year, static_cast<toml::month_t>(datetime->month - 1), datetime->day};
	const auto time = toml::local_time{datetime->hour, datetime->minute, datetime->second, datetime->millisecond};
	const auto local_datetime = toml::local_datetime{date, time};
	toml = local_datetime;
}

/// <summary>
/// </summary>
inline void set_datetime_offset(toml_t& toml, const TomlDateTime* const datetime)
{
	const auto date = toml::local_date{datetime->year, static_cast<toml::month_t>(datetime->month - 1), datetime->day};
	const auto time = toml::local_time{datetime->hour, datetime->minute, datetime->second, datetime->millisecond};
	const auto time_offset = toml::time_offset{datetime->offset_hour, datetime->offset_minute};
	const auto offset_datetime = toml::offset_datetime{date, time, time_offset};
	toml = offset_datetime;
}

/// <summary>
/// </summary>
SetDateTimeCommand::SetDateTimeCommand(const cell handle, const char* key, cell year, cell month, cell day)
	: handle_(handle)
{
	find_value_ = [key](TomlHolder*& holder) -> toml_t&
	{
		return toml_find(holder, key);
	};

	set_datetime_ = [year, month, day](toml_t& toml)
	{
		set_datetime(toml, year, month, day);
	};
}

/// <summary>
/// </summary>
SetDateTimeCommand::SetDateTimeCommand(const cell handle, cell index, cell year, cell month, cell day)
	: handle_(handle)
{
	find_value_ = [index](TomlHolder*& holder) -> toml_t&
	{
		return toml::find(*holder->toml(), index);
	};

	set_datetime_ = [year, month, day](toml_t& toml)
	{
		set_datetime(toml, year, month, day);
	};
}

/// <summary>
/// </summary>
SetDateTimeCommand::SetDateTimeCommand(const cell handle, const char* key, cell hour, cell minute, cell second, cell millisecond)
	: handle_(handle)
{
	find_value_ = [key](TomlHolder*& holder) -> toml_t&
	{
		return toml_find(holder, key);
	};

	set_datetime_ = [hour, minute, second, millisecond](toml_t& toml)
	{
		set_datetime(toml, hour, minute, second, millisecond);
	};
}

/// <summary>
/// </summary>
SetDateTimeCommand::SetDateTimeCommand(const cell handle, cell index, cell hour, cell minute, cell second, cell millisecond)
	: handle_(handle)
{
	find_value_ = [index](TomlHolder*& holder) -> toml_t&
	{
		return toml::find(*holder->toml(), index);
	};

	set_datetime_ = [hour, minute, second, millisecond](toml_t& toml)
	{
		set_datetime(toml, hour, minute, second, millisecond);
	};
}

/// <summary>
/// </summary>
SetDateTimeCommand::SetDateTimeCommand(const cell handle, const char* key, const TomlDateTime* datetime, const bool offset)
	: handle_(handle)
{
	find_value_ = [key](TomlHolder*& holder) -> toml_t&
	{
		return toml_find(holder, key);
	};

	set_datetime_ = [datetime, offset](toml_t& toml)
	{
		if (offset) set_datetime_offset(toml, datetime);
		else set_datetime(toml, datetime);
	};
}

/// <summary>
/// </summary>
SetDateTimeCommand::SetDateTimeCommand(const cell handle, cell index, const TomlDateTime* datetime, bool offset)
	: handle_(handle)
{
	find_value_ = [index](TomlHolder*& holder) -> toml_t&
	{
		return toml::find(*holder->toml(), index);
	};

	set_datetime_ = [datetime, offset](toml_t& toml)
	{
		if (offset) set_datetime_offset(toml, datetime);
		else set_datetime(toml, datetime);
	};
}

/// <summary>
/// </summary>
cell SetDateTimeCommand::execute()
{
	auto* holder = Storage::get(handle_);
	auto& value = find_value_(holder);

	set_datetime_(value);
	holder->remove(value);

	return 1;
}

/// <summary>
/// </summary>
cell AMX_NATIVE_CALL toml_set_local_date(Amx* amx, cell* params)
{
	enum Args { Count, Handle, Key, Year, Month, Day };

	const auto handle = params[Handle];
	auto* const key = AmxxApi::get_amx_string(amx, params[Key]);
	const auto year = params[Year];
	const auto month = params[Month];
	const auto day = params[Day];
	SetDateTimeCommand command(handle, key, year, month, day);

	return execute(command, amx, 0, 1, __func__);
}

/// <summary>
/// </summary>
cell AMX_NATIVE_CALL toml_array_set_local_date(Amx* amx, cell* params)
{
	enum Args { Count, Handle, Index, Year, Month, Day };

	const auto handle = params[Handle];
	const auto index = params[Index];
	const auto year = params[Year];
	const auto month = params[Month];
	const auto day = params[Day];
	SetDateTimeCommand command(handle, index, year, month, day);

	return execute(command, amx, 0, 1, __func__);
}

/// <summary>
/// </summary>
cell AMX_NATIVE_CALL toml_set_local_time(Amx* amx, cell* params)
{
	enum Args { Count, Handle, Key, Hour, Minute, Second, Millisecond };

	const auto handle = params[Handle];
	auto* const key = AmxxApi::get_amx_string(amx, params[Key]);
	const auto hour = params[Hour];
	const auto minute = params[Minute];
	const auto second = params[Second];
	const auto millisecond = params[Millisecond];
	SetDateTimeCommand command(handle, key, hour, minute, second, millisecond);

	return execute(command, amx, 0, 1, __func__);
}

/// <summary>
/// </summary>
cell AMX_NATIVE_CALL toml_array_set_local_time(Amx* amx, cell* params)
{
	enum Args { Count, Handle, Index, Hour, Minute, Second, Millisecond };

	const auto handle = params[Handle];
	const auto index = params[Index];
	const auto hour = params[Hour];
	const auto minute = params[Minute];
	const auto second = params[Second];
	const auto millisecond = params[Millisecond];
	SetDateTimeCommand command(handle, index, hour, minute, second, millisecond);

	return execute(command, amx, 0, 1, __func__);
}

/// <summary>
/// </summary>
cell AMX_NATIVE_CALL toml_set_local_datetime(Amx* amx, cell* params)
{
	enum Args { Count, Handle, Key, DateTime };

	const auto handle = params[Handle];
	auto* const key = AmxxApi::get_amx_string(amx, params[Key]);
	auto* const datetime = reinterpret_cast<TomlDateTime*>(amx_address(amx, params[DateTime]));
	SetDateTimeCommand command(handle, key, datetime, false);

	return execute(command, amx, 0, 1, __func__);
}

/// <summary>
/// </summary>
cell AMX_NATIVE_CALL toml_array_set_local_datetime(Amx* amx, cell* params)
{
	enum Args { Count, Handle, Index, DateTime };

	const auto handle = params[Handle];
	const auto index = params[Index];
	auto* const datetime = reinterpret_cast<TomlDateTime*>(amx_address(amx, params[DateTime]));
	SetDateTimeCommand command(handle, index, datetime, false);

	return execute(command, amx, 0, 1, __func__);
}

/// <summary>
/// </summary>
cell AMX_NATIVE_CALL toml_set_offset_datetime(Amx* amx, cell* params)
{
	enum Args { Count, Handle, Key, DateTime };

	const auto handle = params[Handle];
	auto* const key = AmxxApi::get_amx_string(amx, params[Key]);
	auto* const datetime = reinterpret_cast<TomlDateTime*>(amx_address(amx, params[DateTime]));
	SetDateTimeCommand command(handle, key, datetime, true);

	return execute(command, amx, 0, 1, __func__);
}

/// <summary>
/// </summary>
cell AMX_NATIVE_CALL toml_array_set_offset_datetime(Amx* amx, cell* params)
{
	enum Args { Count, Handle, Index, DateTime };

	const auto handle = params[Handle];
	const auto index = params[Index];
	auto* const datetime = reinterpret_cast<TomlDateTime*>(amx_address(amx, params[DateTime]));
	SetDateTimeCommand command(handle, index, datetime, true);

	return execute(command, amx, 0, 1, __func__);
}
