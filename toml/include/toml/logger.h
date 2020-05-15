// ***********************************************************************
// Author           : the_hunter
// Created          : 04-01-2020
//
// Last Modified By : the_hunter
// Last Modified On : 04-01-2020
// ***********************************************************************

#pragma once

#include <amxx/api.h>
#include <chrono>

#ifdef __INTEL_COMPILER
	#pragma warning(push)
	#pragma warning(disable: 2017)
#endif

/// <summary>
/// Class Logger.
/// </summary>
class Logger {
public:
	/// <summary>
	/// </summary>
	Logger(Amx* amx, const char* func) : func_(func), start_(std::chrono::steady_clock::now())
	{
		AmxxApi::log("[%s] Function \"%s\" is running. Initiated by %s.",
		             AMXX_MODULE_LOG_TAG, func_, get_plugin_name(amx));
	}

	/// <summary>
	/// </summary>
	~Logger()
	{
		const auto finish = std::chrono::steady_clock::now();
		const auto elapsed = std::chrono::duration_cast<std::chrono::nanoseconds>(finish - start_).count();

		AmxxApi::log("[%s] Function \"%s\" is complete. Elapsed time: %u nanoseconds.",
		             AMXX_MODULE_LOG_TAG, func_, elapsed);
	}

	/// <summary>
	/// <para>Move constructor.</para>
	/// </summary>
	Logger(Logger&&) = delete;

	/// <summary>
	/// <para>Copy constructor.</para>
	/// </summary>
	Logger(const Logger&) = delete;

	/// <summary>
	/// <para>Move assignment operator.</para>
	/// </summary>
	Logger& operator=(Logger&&) = delete;

	/// <summary>
	/// <para>Copy assignment operator.</para>
	/// </summary>
	Logger& operator=(const Logger&) = delete;

private:
	/// <summary>
	/// </summary>
	const char* func_;

	/// <summary>
	/// </summary>
	std::chrono::time_point<std::chrono::steady_clock> start_;

	/// <summary>
	/// </summary>
	static const char* get_plugin_name(Amx* amx)
	{
		static const auto* empty = "";
		const auto plugin_id = AmxxApi::find_amx_script_by_amx(amx);

		return plugin_id == -1 ? empty : AmxxApi::get_amx_script_name(plugin_id, true);
	}
};

#ifdef __INTEL_COMPILER
	#pragma warning(pop)
#endif
