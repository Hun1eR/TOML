// ***********************************************************************
// Author           : the_hunter
// Created          : 04-01-2020
//
// Last Modified By : the_hunter
// Last Modified On : 04-01-2020
// ***********************************************************************

#pragma once

#include <toml/commands/command.h>

/// <summary>
/// Class SaveCommand.
/// </summary>
class SaveCommand final : public ITomlCommand {
public:
	/// <summary>
	/// </summary>
	SaveCommand(cell handle, const char* filepath);

	/// <summary>
	/// </summary>
	cell execute() override;

	/// <summary>
	/// </summary>
	~SaveCommand() = default;

	/// <summary>
	/// <para>Move constructor.</para>
	/// </summary>
	SaveCommand(SaveCommand&&) = delete;

	/// <summary>
	/// <para>Copy constructor.</para>
	/// </summary>
	SaveCommand(const SaveCommand&) = delete;

	/// <summary>
	/// <para>Move assignment operator.</para>
	/// </summary>
	SaveCommand& operator=(SaveCommand&&) = delete;

	/// <summary>
	/// <para>Copy assignment operator.</para>
	/// </summary>
	SaveCommand& operator=(const SaveCommand&) = delete;

private:
	/// <summary>
	/// </summary>
	cell handle_;

	/// <summary>
	/// </summary>
	const char* filepath_;
};

/// <summary>
/// </summary>
cell AMX_NATIVE_CALL toml_save(Amx* amx, cell* params);
