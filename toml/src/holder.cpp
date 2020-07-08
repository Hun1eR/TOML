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
TomlHolder* TomlHolder::find(const cell handle)
{
	if (handle_ == handle) {
		return this;
	}

	for (auto& child : children_) {
		auto* const holder = child.find(handle);

		if (holder) {
			return holder;
		}
	}

	return nullptr;
}

/// <summary>
/// </summary>
TomlHolder* TomlHolder::add(toml_t& toml)
{
	if (std::addressof(toml) == toml_) {
		return this;
	}

	TomlHolder holder(toml);
	const auto& it = std::find(children_.begin(), children_.end(), holder.handle_);

	if (it != children_.end()) {
		return std::addressof(*it);
	}

	children_.push_back(std::move(holder));
	return std::addressof(children_.back());
}

/// <summary>
/// </summary>
bool TomlHolder::remove(const cell handle)
{
	const auto& it = std::find(children_.begin(), children_.end(), handle);

	if (it != children_.end()) {
		children_.erase(it);
		return true;
	}

	for (auto& child : children_) {
		if (child.remove(handle)) {
			return true;
		}
	}

	return false;
}

/// <summary>
/// </summary>
bool TomlHolder::remove(const toml_t& toml)
{
	const auto& it = std::find(children_.begin(), children_.end(), toml);

	if (it != children_.end()) {
		children_.erase(it);
		return true;
	}

	for (auto& child : children_) {
		if (child.remove(toml)) {
			return true;
		}
	}

	return false;
}
