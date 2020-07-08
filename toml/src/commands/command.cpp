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
bool check_string_buffer_size(Amx* amx, const cell size, const char* func)
{
	if (size < 0 || size > AMXX_MAX_STRING_LENGTH) {
		constexpr auto err = "%s: Unexpected buffer size value provided (%d). Expected value in range of 0 to %d.";
		AmxxApi::log_error(amx, AmxError::Native, err, func, size, AMXX_MAX_STRING_LENGTH);

		return false;
	}

	return true;
}

/// <summary>
/// </summary>
void split_string(const std::string& string, const char delimiter, std::vector<std::string>& result)
{
	std::size_t previous = 0;
	auto current = string.find(delimiter);

	while (current != std::string::npos) {
		result.emplace_back(string.substr(previous, current - previous));
		previous = current + 1;
		current = string.find(delimiter, previous);
	}

	result.emplace_back(string.substr(previous, current - previous));
}

/// <summary>
/// </summary>
void split_string(const char* string, const char delimiter, std::vector<std::string>& result)
{
	split_string(std::string(string), delimiter, result);
}

/// <summary>
/// </summary>
const char* get_key_from_composite(const char* composite_key)
{
	const auto* const ch = std::strrchr(composite_key, '.');
	return ch ? ch + 1 : composite_key;
}

/// <summary>
/// </summary>
toml_t& toml_find(TomlHolder*& holder, const char* composite_key, const bool find_value)
{
	if (!std::strchr(composite_key, '.')) {
		return find_value ? toml::find(*holder->toml(), composite_key) : *holder->toml();
	}

	std::vector<std::string> keys;
	split_string(composite_key, '.', keys);

	auto* table = holder->toml();
	const auto key = keys.back();
	keys.pop_back(); // table.key

	for (const auto& k : keys) {
		holder = holder->add(toml::find(*table, k));
		table = holder->toml();
	}

	return find_value ? toml::find(*holder->toml(), key) : *holder->toml();
}

/// <summary>
/// </summary>
cell execute(ITomlCommand& command, Amx* amx, const cell default_value, const cell throw_error, const char* func)
{
	try {
		if (enable_debug_cvar()) {
			Logger logger{amx, func};
			return command.execute();
		}

		return command.execute();
	}
	catch (const std::exception& ex) {
		if (throw_error) {
			AmxxApi::log_error(amx, AmxError::Native, "%s: %s", func, ex.what());
		}
	}
	catch (...) {
		if (throw_error) {
			AmxxApi::log_error(amx, AmxError::Native, "%s: Unknown error.", func);
		}
	}

	return default_value;
}
