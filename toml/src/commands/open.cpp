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
OpenCommand::OpenCommand(const char* filepath) : filepath_(filepath) {}

/// <summary>
/// </summary>
cell OpenCommand::execute()
{
	auto&& toml = toml::parse<toml::preserve_comments>(std::string(filepath_));
	return Storage::add(std::move(toml));
}

/// <summary>
/// </summary>
cell AMX_NATIVE_CALL toml_open(Amx* amx, cell* params)
{
	enum Args { Count, File, ThrowError };

	static char file[MAX_PATH_LENGTH];
	AmxxApi::build_path_name_r(file, sizeof file, "%s", AmxxApi::get_amx_string(amx, params[File]));

	OpenCommand command(file);

	return execute(command, amx, TOML_INVALID_HANDLE, params[ThrowError], __func__);
}
