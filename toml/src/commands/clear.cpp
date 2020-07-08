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
ClearCommand::ClearCommand(const cell handle) : handle_(handle) {}

/// <summary>
/// </summary>
cell ClearCommand::execute()
{
	auto* const holder = Storage::get(handle_);
	auto* toml = holder->toml();

	if (toml->is_array()) {
		toml->as_array().clear();
	}
	else {
		toml->as_table().clear();
	}

	holder->clear();

	return 1;
}

/// <summary>
/// </summary>
cell AMX_NATIVE_CALL toml_clear(Amx* amx, cell* params)  // NOLINT(readability-non-const-parameter)
{
	enum Args { Count, Handle };

	const auto handle = params[Handle];
	ClearCommand command(handle);

	return execute(command, amx, 0, 1, __func__);
}
