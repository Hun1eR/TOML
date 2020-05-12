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
inline toml::local_date create_local_date(const cell year, const cell month, const cell day)
{
	return toml::local_date{year, static_cast<toml::month_t>(month - 1), day};
}

/// <summary>
/// </summary>
inline toml::local_time create_local_time(const cell hour, const cell minute, const cell second, const cell millisecond)
{
	return toml::local_time{hour, minute, second, millisecond};
}

/// <summary>
/// </summary>
inline toml::local_datetime create_local_datetime(const TomlDateTime* const datetime)
{
	const auto date = create_local_date(datetime->year, datetime->month, datetime->day);
	const auto time = create_local_time(datetime->hour, datetime->minute, datetime->second, datetime->millisecond);

	return toml::local_datetime{date, time};
}

/// <summary>
/// </summary>
inline toml::offset_datetime create_offset_datetime(const TomlDateTime* const datetime)
{
	const auto date = create_local_date(datetime->year, datetime->month, datetime->day);
	const auto time = create_local_time(datetime->hour, datetime->minute, datetime->second, datetime->millisecond);
	const auto offset = toml::time_offset{datetime->hour, datetime->minute};

	return toml::offset_datetime{date, time, offset};
}

/// <summary>
/// </summary>
InitDateTimeCommand::InitDateTimeCommand(const cell handle, const char* key, cell year, cell month, cell day)
	: handle_(handle)
{
	toml_init_ = [key, year, month, day](TomlHolder*& holder)
	{
		auto& toml = toml_find(holder, key, false);
		auto& table = toml.as_table();
		table[get_key_from_composite(key)] = create_local_date(year, month, day);

		return 1;
	};
}

/// <summary>
/// </summary>
InitDateTimeCommand::InitDateTimeCommand(const cell handle, cell year, cell month, cell day)
	: handle_(handle)
{
	toml_init_ = [year, month, day](TomlHolder*& holder)
	{
		auto& array = holder->toml()->as_array();
		array.emplace_back(create_local_date(year, month, day));
		holder->clear();

		return cell(array.size() - 1);
	};
}

/// <summary>
/// </summary>
InitDateTimeCommand::InitDateTimeCommand(const cell handle, const char* key, cell hour, cell minute, cell second, cell millisecond)
	: handle_(handle)
{
	toml_init_ = [key, hour, minute, second, millisecond](TomlHolder*& holder)
	{
		auto& toml = toml_find(holder, key, false);
		auto& table = toml.as_table();
		table[get_key_from_composite(key)] = create_local_time(hour, minute, second, millisecond);

		return 1;
	};
}

/// <summary>
/// </summary>
InitDateTimeCommand::InitDateTimeCommand(const cell handle, cell hour, cell minute, cell second, cell millisecond)
	: handle_(handle)
{
	toml_init_ = [hour, minute, second, millisecond](TomlHolder*& holder)
	{
		auto& array = holder->toml()->as_array();
		array.emplace_back(create_local_time(hour, minute, second, millisecond));
		holder->clear();

		return cell(array.size() - 1);
	};
}

/// <summary>
/// </summary>
InitDateTimeCommand::InitDateTimeCommand(const cell handle, const char* key, const TomlDateTime* datetime, bool offset)
	: handle_(handle)
{
	toml_init_ = [key, datetime, offset](TomlHolder*& holder)
	{
		auto& toml = toml_find(holder, key, false);
		auto& table = toml.as_table();

		if (offset)
			table[get_key_from_composite(key)] = create_offset_datetime(datetime);
		else
			table[get_key_from_composite(key)] = create_local_datetime(datetime);

		return 1;
	};
}

/// <summary>
/// </summary>
InitDateTimeCommand::InitDateTimeCommand(const cell handle, const TomlDateTime* datetime, bool offset)
	: handle_(handle)
{
	toml_init_ = [datetime, offset](TomlHolder*& holder)
	{
		auto& array = holder->toml()->as_array();

		if (offset)
			array.emplace_back(create_offset_datetime(datetime));
		else
			array.emplace_back(create_local_datetime(datetime));

		holder->clear();

		return cell(array.size() - 1);
	};
}

/// <summary>
/// </summary>
cell InitDateTimeCommand::execute()
{
	auto* holder = Storage::get(handle_);
	return toml_init_(holder);
}

/// <summary>
/// </summary>
cell AMX_NATIVE_CALL toml_init_local_date(Amx* amx, cell* params)
{
	enum Args { Count, Handle, Key, Year, Month, Day };

	const auto handle = params[Handle];
	auto* const key = AmxxApi::get_amx_string(amx, params[Key]);
	const auto year = params[Year];
	const auto month = params[Month];
	const auto day = params[Day];
	InitDateTimeCommand command(handle, key, year, month, day);

	return execute(command, amx, 0, 1, __func__);
}

/// <summary>
/// </summary>
cell AMX_NATIVE_CALL toml_array_init_local_date(Amx* amx, cell* params)
{
	enum Args { Count, Handle, Year, Month, Day };

	const auto handle = params[Handle];
	const auto year = params[Year];
	const auto month = params[Month];
	const auto day = params[Day];
	InitDateTimeCommand command(handle, year, month, day);

	return execute(command, amx, -1, 1, __func__);
}

/// <summary>
/// </summary>
cell AMX_NATIVE_CALL toml_init_local_time(Amx* amx, cell* params)
{
	enum Args { Count, Handle, Key, Hour, Minute, Second, Millisecond };

	const auto handle = params[Handle];
	auto* const key = AmxxApi::get_amx_string(amx, params[Key]);
	const auto hour = params[Hour];
	const auto minute = params[Minute];
	const auto second = params[Second];
	const auto millisecond = params[Millisecond];
	InitDateTimeCommand command(handle, key, hour, minute, second, millisecond);

	return execute(command, amx, 0, 1, __func__);
}

/// <summary>
/// </summary>
cell AMX_NATIVE_CALL toml_array_init_local_time(Amx* amx, cell* params)
{
	enum Args { Count, Handle, Hour, Minute, Second, Millisecond };

	const auto handle = params[Handle];
	const auto hour = params[Hour];
	const auto minute = params[Minute];
	const auto second = params[Second];
	const auto millisecond = params[Millisecond];
	InitDateTimeCommand command(handle, hour, minute, second, millisecond);

	return execute(command, amx, -1, 1, __func__);
}

/// <summary>
/// </summary>
cell AMX_NATIVE_CALL toml_init_local_datetime(Amx* amx, cell* params)
{
	enum Args { Count, Handle, Key, DateTime };

	const auto handle = params[Handle];
	auto* const key = AmxxApi::get_amx_string(amx, params[Key]);
	auto* const datetime = reinterpret_cast<TomlDateTime*>(amx_address(amx, params[DateTime]));
	InitDateTimeCommand command(handle, key, datetime, false);

	return execute(command, amx, 0, 1, __func__);
}

/// <summary>
/// </summary>
cell AMX_NATIVE_CALL toml_array_init_local_datetime(Amx* amx, cell* params)
{
	enum Args { Count, Handle, DateTime };

	const auto handle = params[Handle];
	auto* const datetime = reinterpret_cast<TomlDateTime*>(amx_address(amx, params[DateTime]));
	InitDateTimeCommand command(handle, datetime, false);

	return execute(command, amx, -1, 1, __func__);
}

/// <summary>
/// </summary>
cell AMX_NATIVE_CALL toml_init_offset_datetime(Amx* amx, cell* params)
{
	enum Args { Count, Handle, Key, DateTime };

	const auto handle = params[Handle];
	auto* const key = AmxxApi::get_amx_string(amx, params[Key]);
	auto* const datetime = reinterpret_cast<TomlDateTime*>(amx_address(amx, params[DateTime]));
	InitDateTimeCommand command(handle, key, datetime, true);

	return execute(command, amx, 0, 1, __func__);
}

/// <summary>
/// </summary>
cell AMX_NATIVE_CALL toml_array_init_offset_datetime(Amx* amx, cell* params)
{
	enum Args { Count, Handle, DateTime };

	const auto handle = params[Handle];
	auto* const datetime = reinterpret_cast<TomlDateTime*>(amx_address(amx, params[DateTime]));
	InitDateTimeCommand command(handle, datetime, true);

	return execute(command, amx, -1, 1, __func__);
}
