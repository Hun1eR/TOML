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
/// Enum TomlType
/// </summary>
enum class TomlType : cell {
	/// <summary>
	/// </summary>
	Empty,

	/// <summary>
	/// </summary>
	Table,

	/// <summary>
	/// </summary>
	Array,

	/// <summary>
	/// </summary>
	String,

	/// <summary>
	/// </summary>
	Integer,

	/// <summary>
	/// </summary>
	Boolean,

	/// <summary>
	/// </summary>
	Floating,

	/// <summary>
	/// </summary>
	LocalDate,

	/// <summary>
	/// </summary>
	LocalTime,

	/// <summary>
	/// </summary>
	LocalDateTime,

	/// <summary>
	/// </summary>
	OffsetDateTime
};
