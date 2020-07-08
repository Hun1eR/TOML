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
SaveCommand::SaveCommand(const cell handle, const char* filepath)
	: handle_(handle), filepath_(filepath) {}

/// <summary>
/// </summary>
cell SaveCommand::execute()
{
	const auto& toml = *Storage::get(handle_)->toml();
	const auto serial = format(toml, 80, std::numeric_limits<float>::max_digits10);

	std::ofstream out(filepath_, std::ios_base::out | std::ios_base::trunc);
	out << serial;
	out.close();

	return static_cast<cell>(serial.length());
}

/// <summary>
/// </summary>
cell AMX_NATIVE_CALL toml_save(Amx* amx, cell* params)
{
	enum Args { Count, Handle, File };

	static char file[MAX_PATH_LENGTH];
	AmxxApi::build_path_name_r(file, sizeof file, "%s", AmxxApi::get_amx_string(amx, params[File]));

	const auto handle = params[Handle];
	SaveCommand command(handle, file);

	return execute(command, amx, 0, 1, __func__);
}
