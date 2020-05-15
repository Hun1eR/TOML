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
/// Class OpenCommand.
/// </summary>
class OpenCommand final : public ITomlCommand {
public:
	/// <summary>
	/// </summary>
	explicit OpenCommand(const char* filepath);

	/// <summary>
	/// </summary>
	cell execute() override;

	/// <summary>
	/// </summary>
	~OpenCommand() = default;

	/// <summary>
	/// <para>Move constructor.</para>
	/// </summary>
	OpenCommand(OpenCommand&&) = delete;

	/// <summary>
	/// <para>Copy constructor.</para>
	/// </summary>
	OpenCommand(const OpenCommand&) = delete;

	/// <summary>
	/// <para>Move assignment operator.</para>
	/// </summary>
	OpenCommand& operator=(OpenCommand&&) = delete;

	/// <summary>
	/// <para>Copy assignment operator.</para>
	/// </summary>
	OpenCommand& operator=(const OpenCommand&) = delete;

private:
	/// <summary>
	/// </summary>
	const char* filepath_;
};

/// <summary>
/// </summary>
cell AMX_NATIVE_CALL toml_open(Amx* amx, cell* params);
