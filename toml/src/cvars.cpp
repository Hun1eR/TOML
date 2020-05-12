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
CVar* toml_debug = nullptr;

/// <summary>
/// </summary>
static std::vector<CVar*> g_cvar_cache{};

/// <summary>
/// </summary>
static CVar* cvar_cache_lookup(const char* cvar_name)
{
	for (auto const& cvar : g_cvar_cache) {
		if (!std::strcmp(cvar->name, cvar_name))
			return cvar;
	}

	return nullptr;
}

/// <summary>
/// </summary>
static CVar* register_cvar(CVar* new_cvar)
{
	auto* cvar = cvar_cache_lookup(new_cvar->name);

	if (cvar)
		return cvar;

	cvar = Engine::cvar_get_pointer(new_cvar->name);

	if (!cvar) {
		Engine::cvar_register(new_cvar);
		cvar = Engine::cvar_get_pointer(new_cvar->name);

		if (!cvar) {
			MetaUtils::log_error("Failed to register cvar: \"%s\" already registered as a command.", new_cvar->name);
			return nullptr;
		}

		g_cvar_cache.push_back(cvar);
	}

	Engine::cvar_direct_set(cvar, new_cvar->string);

	return cvar;
}

/// <summary>
/// </summary>
bool register_cvars()
{
	static CVar cvar_toml_debug{"toml_debug", "0", 0, 0.0f, nullptr};
	toml_debug = register_cvar(&cvar_toml_debug);

	return toml_debug;
}
