// ***********************************************************************
// Author           : the_hunter
// Created          : 04-01-2020
//
// Last Modified By : the_hunter
// Last Modified On : 04-01-2020
// ***********************************************************************

#pragma once

#include <amxx/amx.h>
#include <list>
#include <memory>

/// <summary>
/// Class TomlHolder.
/// </summary>
class TomlHolder {
public:
	/// <summary>
	/// </summary>
	explicit TomlHolder(toml_t* toml)
		: handle_(reinterpret_cast<cell>(toml)), toml_(toml) {}

	/// <summary>
	/// </summary>
	explicit TomlHolder(toml_t& toml)
		: TomlHolder(std::addressof(toml)) {}

	/// <summary>
	/// </summary>
	[[nodiscard]] cell handle() const
	{
		return handle_;
	}

	/// <summary>
	/// </summary>
	[[nodiscard]] toml_t* toml() const
	{
		return toml_;
	}

	/// <summary>
	/// </summary>
	TomlHolder* find(cell handle);

	/// <summary>
	/// </summary>
	TomlHolder* add(toml_t& toml);

	/// <summary>
	/// </summary>
	bool remove(cell handle);

	/// <summary>
	/// </summary>
	bool remove(const toml_t& toml);

	/// <summary>
	/// </summary>
	void clear()
	{
		children_.clear();
	}

	/// <summary>
	/// </summary>
	bool operator==(const cell rhs) const
	{
		return handle_ == rhs;
	}

	/// <summary>
	/// </summary>
	bool operator!=(const cell rhs) const
	{
		return handle_ != rhs;
	}

	/// <summary>
	/// </summary>
	bool operator==(const toml_t& rhs) const
	{
		return toml_ == std::addressof(rhs);
	}

	/// <summary>
	/// </summary>
	bool operator!=(const toml_t& rhs) const
	{
		return toml_ != std::addressof(rhs);
	}

	/// <summary>
	/// </summary>
	bool operator==(const TomlHolder& rhs) const
	{
		return handle_ == rhs.handle_;
	}

	/// <summary>
	/// </summary>
	bool operator!=(const TomlHolder& rhs) const
	{
		return handle_ != rhs.handle_;
	}

	/// <summary>
	/// </summary>
	~TomlHolder() = default;

	/// <summary>
	/// <para>Move constructor.</para>
	/// </summary>
	TomlHolder(TomlHolder&&) = default;

	/// <summary>
	/// <para>Copy constructor.</para>
	/// </summary>
	TomlHolder(const TomlHolder&) = delete;

	/// <summary>
	/// <para>Move assignment operator.</para>
	/// </summary>
	TomlHolder& operator=(TomlHolder&&) = default;

	/// <summary>
	/// <para>Copy assignment operator.</para>
	/// </summary>
	TomlHolder& operator=(const TomlHolder&) = delete;

private:
	/// <summary>
	/// </summary>
	cell handle_;

	/// <summary>
	/// </summary>
	toml_t* toml_;

	/// <summary>
	/// </summary>
	std::list<TomlHolder> children_{};
};
