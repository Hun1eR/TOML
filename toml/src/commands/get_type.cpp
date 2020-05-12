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
GetTypeCommand::GetTypeCommand(const cell handle, const char* key) : handle_(handle)
{
	find_value_ = [key](TomlHolder* holder) -> toml_t&
	{
		return toml_find(holder, key);
	};
}

/// <summary>
/// </summary>
GetTypeCommand::GetTypeCommand(const cell handle, cell index) : handle_(handle)
{
	find_value_ = [index](TomlHolder* holder) -> toml_t&
	{
		return toml::find(*holder->toml(), index);
	};
}

/// <summary>
/// </summary>
cell GetTypeCommand::execute()
{
	auto* const holder = Storage::get(handle_);
	const auto& value = find_value_(holder);

	switch (value.type()) {
	case toml::value_t::table: return cell(TomlType::Table);
	case toml::value_t::array: return cell(TomlType::Array);
	case toml::value_t::string: return cell(TomlType::String);
	case toml::value_t::integer: return cell(TomlType::Integer);
	case toml::value_t::boolean: return cell(TomlType::Boolean);
	case toml::value_t::floating: return cell(TomlType::Floating);
	case toml::value_t::local_date: return cell(TomlType::LocalDate);
	case toml::value_t::local_time: return cell(TomlType::LocalTime);
	case toml::value_t::local_datetime: return cell(TomlType::LocalDateTime);
	case toml::value_t::offset_datetime: return cell(TomlType::OffsetDateTime);
	default: return cell(TomlType::Empty);
	}
}

/// <summary>
/// </summary>
cell AMX_NATIVE_CALL toml_get_type(Amx* amx, cell* params)
{
	enum Args { Count, Handle, Key, ThrowError };

	const auto handle = params[Handle];
	auto* const key = AmxxApi::get_amx_string(amx, params[Key]);
	GetTypeCommand command(handle, key);

	return execute(command, amx, cell(TomlType::Empty), params[ThrowError], __func__);
}

/// <summary>
/// </summary>
cell AMX_NATIVE_CALL toml_array_get_type(Amx* amx, cell* params)
{
	enum Args { Count, Handle, Index, ThrowError };

	const auto handle = params[Handle];
	const auto index = params[Index];
	GetTypeCommand command(handle, index);

	return execute(command, amx, cell(TomlType::Empty), params[ThrowError], __func__);
}
