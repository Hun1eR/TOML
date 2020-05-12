// ***********************************************************************
// Author           : the_hunter
// Created          : 04-01-2020
//
// Last Modified By : the_hunter
// Last Modified On : 04-01-2020
// ***********************************************************************

#pragma once

#include <amxx/amx.h>
#include <toml11/toml.hpp>

class TomlHolder;
using toml_t = toml::basic_value<toml::preserve_comments>;

/// <summary>
/// Class ITomlCommand.
/// </summary>
class ITomlCommand {
public:
	/// <summary>
	/// <para>Default destructor.</para>
	/// </summary>
	virtual ~ITomlCommand() = default;

	/// <summary>
	/// </summary>
	virtual cell execute() = 0;

	/// <summary>
	/// <para>Move constructor.</para>
	/// </summary>
	ITomlCommand(ITomlCommand&&) = delete;

	/// <summary>
	/// <para>Copy constructor.</para>
	/// </summary>
	ITomlCommand(const ITomlCommand&) = delete;

	/// <summary>
	/// <para>Move assignment operator.</para>
	/// </summary>
	ITomlCommand& operator=(ITomlCommand&&) = delete;

	/// <summary>
	/// <para>Copy assignment operator.</para>
	/// </summary>
	ITomlCommand& operator=(const ITomlCommand&) = delete;

protected:
	/// <summary>
	/// <para>Default constructor.</para>
	/// </summary>
	ITomlCommand() = default;
};

/// <summary>
/// </summary>
template <toml::value_t TExpected>
void check_toml_type(const toml_t& toml)
{
	const auto type = toml.type();

	if (type != TExpected)
		toml::detail::throw_bad_cast<TExpected>("", type, toml);
}

/// <summary>
/// </summary>
bool check_string_buffer_size(Amx* amx, cell size, const char* func);

/// <summary>
/// </summary>
void split_string(const std::string& string, char delimiter, std::vector<std::string>& result);

/// <summary>
/// </summary>
void split_string(const char* string, char delimiter, std::vector<std::string>& result);

/// <summary>
/// </summary>
const char* get_key_from_composite(const char* composite_key);

/// <summary>
/// </summary>
toml_t& toml_find(TomlHolder*& holder, const char* composite_key, bool find_value = true);

/// <summary>
/// </summary>
cell execute(ITomlCommand& command, Amx* amx, cell default_value, cell throw_error, const char* func);
