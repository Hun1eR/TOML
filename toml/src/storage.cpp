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
static std::list<TomlHolder> g_holders;

/// <summary>
/// </summary>
cell Storage::add(toml_t&& toml)
{
	auto* const root = new toml_t(toml);
	g_holders.emplace_back(root);

	return g_holders.back().handle();
}

/// <summary>
/// </summary>
TomlHolder* Storage::get(const cell handle, const bool throw_error)
{
	for (auto& toml_holder : g_holders) {
		auto* holder = toml_holder.find(handle);

		if (holder)
			return holder;
	}

	if (!throw_error)
		return nullptr;

	throw std::invalid_argument("Invalid TOML handle provided (" + std::to_string(handle) + ").");
}

/// <summary>
/// </summary>
void Storage::remove(const cell handle)
{
	if (handle == TOML_INVALID_HANDLE)
		return;

	const auto& it = std::find(g_holders.begin(), g_holders.end(), handle);

	if (it != g_holders.end()) {
		auto* toml = it->toml();
		g_holders.erase(it);
		delete toml;

		return;
	}

	for (auto& holder : g_holders) {
		if (holder.remove(handle))
			break;
	}
}

/// <summary>
/// </summary>
void Storage::clear()
{
	for (const auto& holder : g_holders)
		delete holder.toml();

	g_holders.clear();
}
