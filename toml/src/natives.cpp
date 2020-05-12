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
void add_natives()
{
	static const AmxNativeInfo natives[] =
	{
		{"toml_open", toml_open},
		{"toml_is_valid", toml_is_valid},
		{"toml_contains", toml_contains},

		{"toml_get_table", toml_get_table},
		{"toml_array_get_table", toml_array_get_table},
		{"toml_get_array", toml_get_array},
		{"toml_array_get_array", toml_array_get_array},
		{"toml_get_int", toml_get_int},
		{"toml_array_get_int", toml_array_get_int},
		{"toml_get_bool", toml_get_bool},
		{"toml_array_get_bool", toml_array_get_bool},
		{"toml_get_float", toml_get_float},
		{"toml_array_get_float", toml_array_get_float},
		{"toml_get_string", toml_get_string},
		{"toml_array_get_string", toml_array_get_string},
		{"toml_get_datetime", toml_get_datetime},
		{"toml_array_get_datetime", toml_array_get_datetime},
		{"toml_get_datetime_ex", toml_get_datetime_ex},
		{"toml_array_get_datetime_ex", toml_array_get_datetime_ex},
		{"toml_get_type", toml_get_type},
		{"toml_array_get_type", toml_array_get_type},
		{"toml_array_get_count", toml_array_get_count},

		{"toml_set_table", toml_set_table},
		{"toml_array_set_table", toml_array_set_table},
		{"toml_set_array", toml_set_array},
		{"toml_array_set_array", toml_array_set_array},
		{"toml_set_int", toml_set_int},
		{"toml_array_set_int", toml_array_set_int},
		{"toml_set_bool", toml_set_bool},
		{"toml_array_set_bool", toml_array_set_bool},
		{"toml_set_float", toml_set_float},
		{"toml_array_set_float", toml_array_set_float},
		{"toml_set_string", toml_set_string},
		{"toml_array_set_string", toml_array_set_string},
		{"toml_set_local_date", toml_set_local_date},
		{"toml_array_set_local_date", toml_array_set_local_date},
		{"toml_set_local_time", toml_set_local_time},
		{"toml_array_set_local_time", toml_array_set_local_time},
		{"toml_set_local_datetime", toml_set_local_datetime},
		{"toml_array_set_local_datetime", toml_array_set_local_datetime},
		{"toml_set_offset_datetime", toml_set_offset_datetime},
		{"toml_array_set_offset_datetime", toml_array_set_offset_datetime},

		{"toml_init_root", toml_init_root},
		{"toml_init_table", toml_init_table},
		{"toml_array_init_table", toml_array_init_table},
		{"toml_init_array", toml_init_array},
		{"toml_array_init_array", toml_array_init_array},
		{"toml_init_int", toml_init_int},
		{"toml_array_init_int", toml_array_init_int},
		{"toml_init_bool", toml_init_bool},
		{"toml_array_init_bool", toml_array_init_bool},
		{"toml_init_float", toml_init_float},
		{"toml_array_init_float", toml_array_init_float},
		{"toml_init_string", toml_init_string},
		{"toml_array_init_string", toml_array_init_string},
		{"toml_init_local_date", toml_init_local_date},
		{"toml_array_init_local_date", toml_array_init_local_date},
		{"toml_init_local_time", toml_init_local_time},
		{"toml_array_init_local_time", toml_array_init_local_time},
		{"toml_init_local_datetime", toml_init_local_datetime},
		{"toml_array_init_local_datetime", toml_array_init_local_datetime},
		{"toml_init_offset_datetime", toml_init_offset_datetime},
		{"toml_array_init_offset_datetime", toml_array_init_offset_datetime},

		{"toml_remove", toml_remove},
		{"toml_array_remove", toml_array_remove},
		{"toml_clear", toml_clear},

		{"toml_save", toml_save},
		{"toml_close", toml_close},

		{nullptr, nullptr}
	};

	AmxxApi::add_natives(natives);
}
