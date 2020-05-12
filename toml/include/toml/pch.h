// ***********************************************************************
// Author           : the_hunter
// Created          : 04-01-2020
//
// Last Modified By : the_hunter
// Last Modified On : 04-01-2020
// ***********************************************************************

#pragma once

// STL
#include <algorithm>
#include <chrono>
#include <cstddef>
#include <cstring>
#include <functional>
#include <list>
#include <memory>
#include <stdexcept>
#include <string>
#include <utility>
#include <vector>

// Dependencies
#include <toml11/toml.hpp>

// SDK
#include <amxx/api.h>
#include <amxx/string.h>
#include <cssdk/common/cvar.h>
#include <metamod/engine.h>
#include <metamod/utils.h>

// TOML
#include <toml/commands/clear.h>
#include <toml/commands/close.h>
#include <toml/commands/command.h>
#include <toml/commands/contains.h>
#include <toml/commands/get_array.h>
#include <toml/commands/get_boolean.h>
#include <toml/commands/get_count.h>
#include <toml/commands/get_datetime.h>
#include <toml/commands/get_floating.h>
#include <toml/commands/get_integer.h>
#include <toml/commands/get_string.h>
#include <toml/commands/get_table.h>
#include <toml/commands/get_type.h>
#include <toml/commands/init_array.h>
#include <toml/commands/init_boolean.h>
#include <toml/commands/init_datetime.h>
#include <toml/commands/init_floating.h>
#include <toml/commands/init_integer.h>
#include <toml/commands/init_root.h>
#include <toml/commands/init_string.h>
#include <toml/commands/init_table.h>
#include <toml/commands/is_valid.h>
#include <toml/commands/open.h>
#include <toml/commands/remove.h>
#include <toml/commands/save.h>
#include <toml/commands/set_array.h>
#include <toml/commands/set_boolean.h>
#include <toml/commands/set_datetime.h>
#include <toml/commands/set_floating.h>
#include <toml/commands/set_integer.h>
#include <toml/commands/set_string.h>
#include <toml/commands/set_table.h>
#include <toml/consts.h>
#include <toml/cvars.h>
#include <toml/datetime.h>
#include <toml/holder.h>
#include <toml/logger.h>
#include <toml/storage.h>
#include <toml/type.h>
