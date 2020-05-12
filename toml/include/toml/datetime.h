// ***********************************************************************
// Author           : the_hunter
// Created          : 04-01-2020
//
// Last Modified By : the_hunter
// Last Modified On : 04-01-2020
// ***********************************************************************

#pragma once

#include <amxx/amx.h>

/// <summary>
/// Struct TomlDateTime
/// </summary>
struct TomlDateTime {
	/// <summary>
	/// </summary>
	cell year;

	/// <summary>
	/// </summary>
	cell month;

	/// <summary>
	/// </summary>
	cell day;

	/// <summary>
	/// </summary>
	cell hour;

	/// <summary>
	/// </summary>
	cell minute;

	/// <summary>
	/// </summary>
	cell second;

	/// <summary>
	/// </summary>
	cell millisecond;

	/// <summary>
	/// </summary>
	cell offset_hour;

	/// <summary>
	/// </summary>
	cell offset_minute;

	/// <summary>
	/// </summary>
	cell unix_timestamp;
};
