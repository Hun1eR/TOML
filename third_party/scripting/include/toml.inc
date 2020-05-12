/*
* AMX Mod X
*	TOML include.
*
* Author: the_hunter
* Version: 1.0.0
*
* MIT License
*
* Permission is hereby granted, free of charge, to any person obtaining a copy
* of this software and associated documentation files (the "Software"), to deal
* in the Software without restriction, including without limitation the rights
* to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
* copies of the Software, and to permit persons to whom the Software is
* furnished to do so, subject to the following conditions:
*
* The above copyright notice and this permission notice shall be included in all
* copies or substantial portions of the Software.
*
* THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
* IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
* FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
* AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
* LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
* OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
* SOFTWARE.
*/

#if defined _toml_included
	#endinput
#endif
#define _toml_included

#pragma reqlib toml
#if !defined AMXMODX_NOAUTOLOAD
	#pragma loadlib toml
#endif

enum _:TomlType {
	toml_empty,
	toml_table,
	toml_array,
	toml_string,
	toml_integer,
	toml_boolean,
	toml_floating,
	toml_local_date,
	toml_local_time,
	toml_local_datetime,
	toml_offset_datetime
};

enum _:TomlDateTime {
	toml_year,
	toml_month,
	toml_day,
	toml_hour,
	toml_minute,
	toml_second,
	toml_millisecond,
	toml_offset_hour,
	toml_offset_minute,
	toml_unix_timestamp
};

#define toml_is_null(%1) (!%1)

/**
 * Helper macros for checking type.
 */
#define toml_is_empty(%1,%2)			(toml_get_type(%1,%2) == toml_empty)
#define toml_is_table(%1,%2)			(toml_get_type(%1,%2) == toml_table)
#define toml_is_array(%1,%2)			(toml_get_type(%1,%2) == toml_array)
#define toml_is_string(%1,%2)			(toml_get_type(%1,%2) == toml_string)
#define toml_is_integer(%1,%2)			(toml_get_type(%1,%2) == toml_integer)
#define toml_is_boolean(%1,%2)			(toml_get_type(%1,%2) == toml_boolean)
#define toml_is_floating(%1,%2)			(toml_get_type(%1,%2) == toml_floating)
#define toml_is_local_date(%1,%2)		(toml_get_type(%1,%2) == toml_local_date)
#define toml_is_local_time(%1,%2)		(toml_get_type(%1,%2) == toml_local_time)
#define toml_is_local_datetime(%1,%2)	(toml_get_type(%1,%2) == toml_local_datetime)
#define toml_is_offset_datetime(%1,%2)	(toml_get_type(%1,%2) == toml_offset_datetime)
#define toml_is_date_or_time(%1,%2)		(toml_get_type(%1,%2) >= toml_local_date)

/**
 * Opens a TOML file.
 *
 * @param szFile		Relative path to a TOML file from the 'cstrike' directory.
 * @param throwError	If true, throws an error if the file could not be opened.
 *
 * @return				The table handle to be used in other natives;
 *						Invalid handle if not successfully opened.
 */
native Toml:toml_open(const szFile[], bool:throwError = true);

/**
 * Checks if the given handle is valid.
 *
 * @param handle		Table or array handle.
 *
 * @return				True if the handle is valid; False otherwise.
 */
native bool:toml_is_valid({Toml, TomlArray}:handle);

/**
 * Checks if a key exists in the table.
 *
 * @param handle		Table handle.
 * @param szKey			Table key.
 * @param throwError	If true, throws an error if the handle is invalid.
 *
 * @note				The key may be composite. For example: Table.SubTable.Key
 *
 * @return				True if the given key exists in the table; False otherwise.
 */
native bool:toml_contains(Toml:handle, const szKey[], bool:throwError = true);

/**
 * Gets the table handle from a table.
 *
 * @param handle		Table handle.
 * @param szKey			Table key.
 * @param throwError	If true, throws an error if the handle is invalid
 *						or if the value type in the table is not a table
 *						or if the key is not found.
 *
 * @note				The key may be composite. For example: Table.SubTable.Key
 *
 * @return				The table handle to be used in other natives;
 *						Invalid handle if table handle cannot be retrieved.
 */
native Toml:toml_get_table(Toml:handle, const szKey[], bool:throwError = true);

/**
 * Gets the table handle from an array.
 *
 * @param handle		Array handle.
 * @param index			Array index.
 * @param throwError	If true, throws an error if the handle is invalid
 *						or if the value type in the array is not a table
 *						or if the index out of range.
 *
 * @return				The table handle to be used in other natives;
 *						Invalid handle if table handle cannot be retrieved.
 */
native Toml:toml_array_get_table(TomlArray:handle, index, bool:throwError = true);

/**
 * Gets the array handle from a table.
 *
 * @param handle		Table handle.
 * @param szKey			Table key.
 * @param throwError	If true, throws an error if the handle is invalid
 *						or if the value type in the table is not an array
 *						or if the key is not found.
 *
 * @note				The key may be composite. For example: Table.SubTable.Key
 *
 * @return				The table handle to be used in other natives;
 *						Invalid handle if array handle cannot be retrieved.
 */
native TomlArray:toml_get_array(Toml:handle, const szKey[], bool:throwError = true);

/**
 * Gets the array handle from another array.
 *
 * @param handle		Array handle.
 * @param index			Array index.
 * @param throwError	If true, throws an error if the handle is invalid
 *						or if the value type in the array is not an array
 *						or if the index out of range.
 *
 * @return				The table handle to be used in other natives;
 *						Invalid handle if array handle cannot be retrieved.
 */
native TomlArray:toml_array_get_array(TomlArray:handle, index, bool:throwError = true);

/**
 * Gets the integer value from a table.
 *
 * @param handle		Table handle.
 * @param szKey			Table key.
 * @param defVal		Default value.
 * @param throwError	If true, throws an error if the handle is invalid
 *						or if the value type in the table cannot be implicitly converted to an integer
 *						or if the key is not found.
 *
 * @note				The key may be composite. For example: Table.SubTable.Key
 *
 * @return				The integer value retrieved from a table;
 *						Default value if the value cannot be retrieved.
 */
native toml_get_int(Toml:handle, const szKey[], defVal = 0, bool:throwError = true);

/**
 * Gets the integer value from an array.
 *
 * @param handle		Array handle.
 * @param index			Array index.
 * @param defVal		Default value.
 * @param throwError	If true, throws an error if the handle is invalid
 *						or if the value type in the array cannot be implicitly converted to an integer
 *						or if the index out of range.
 *
 * @return				The integer value retrieved from an array;
 *						Default value if the value cannot be retrieved.
 */
native toml_array_get_int(TomlArray:handle, index, defVal = 0, bool:throwError = true);

/**
 * Gets the boolean value from a table.
 *
 * @param handle		Table handle.
 * @param szKey			Table key.
 * @param defVal		Default value.
 * @param throwError	If true, throws an error if the handle is invalid
 *						or if the value type in the table cannot be implicitly converted to a boolean
 *						or if the key is not found.
 *
 * @note				The key may be composite. For example: Table.SubTable.Key
 *
 * @return				The boolean value retrieved from a table;
 *						Default value if the value cannot be retrieved.
 */
native bool:toml_get_bool(Toml:handle, const szKey[], bool:defVal = false, bool:throwError = true);

/**
 * Gets the boolean value from an array.
 *
 * @param handle		Array handle.
 * @param index			Array index.
 * @param defVal		Default value.
 * @param throwError	If true, throws an error if the handle is invalid
 *						or if the value type in the array cannot be implicitly converted to a boolean
 *						or if the index out of range.
 *
 * @return				The boolean value retrieved from an array;
 *						Default value if the value cannot be retrieved.
 */
native bool:toml_array_get_bool(TomlArray:handle, index, bool:defVal = false, bool:throwError = true);

/**
 * Gets the floating-point value from a table.
 *
 * @param handle		Table handle.
 * @param szKey			Table key.
 * @param defVal		Default value.
 * @param throwError	If true, throws an error if the handle is invalid
 *						or if the value type in the table cannot be implicitly converted to a floating-point value
 *						or if the key is not found.
 *
 * @note				The key may be composite. For example: Table.SubTable.Key
 *
 * @return				The floating-point value retrieved from a table;
 *						Default value if the value cannot be retrieved.
 */
native Float:toml_get_float(Toml:handle, const szKey[], Float:defVal = 0.0, bool:throwError = true);

/**
 * Gets the floating-point value from an array.
 *
 * @param handle		Array handle.
 * @param index			Array index.
 * @param defVal		Default value.
 * @param throwError	If true, throws an error if the handle is invalid
 *						or if the value type in the array cannot be implicitly converted to a floating-point value
 *						or if the index out of range.
 *
 * @return				The floating-point value retrieved from an array;
 *						Default value if the value cannot be retrieved.
 */
native Float:toml_array_get_float(TomlArray:handle, index, Float:defVal = 0.0, bool:throwError = true);

/**
 * Gets the string value from a table.
 *
 * @param handle		Table handle.
 * @param szKey			Table key.
 * @param szBuffer		Destination string buffer.
 * @param bufSize		Maximum length of the string buffer.
 * @param defVal		Default value.
 * @param throwError	If true, throws an error if the handle is invalid
 *						or if the value type in the table cannot be implicitly converted to a string
 *						or if the key is not found.
 *
 * @note				The key may be composite. For example: Table.SubTable.Key
 *
 * @return				Number of cells written.
 */
native toml_get_string(Toml:handle, const szKey[], szBuffer[], bufSize, const defVal[] = "", bool:throwError = true);

/**
 * Gets the string value from an array.
 *
 * @param handle		Array handle.
 * @param index			Array index.
 * @param szBuffer		Destination string buffer.
 * @param bufSize		Maximum length of the string buffer.
 * @param defVal		Default value.
 * @param throwError	If true, throws an error if the handle is invalid
 *						or if the value type in the array cannot be implicitly converted to a string
 *						or if the index out of range.
 *
 * @return				Number of cells written.
 */
native toml_array_get_string(TomlArray:handle, index, szBuffer[], bufSize, const defVal[] = "", bool:throwError = true);

/**
 * Gets the Unix timestamp value from a table.
 *
 * @param handle		Table handle.
 * @param szKey			Table key.
 * @param defVal		Default value.
 * @param ofsHour		Hour offset (if the value is in offset date-time format (RFC 3339)).
 * @param ofsMinute		Minute offset (if the value is in offset date-time format (RFC 3339)).
 * @param throwError	If true, throws an error if the handle is invalid
 *						or if the value type in the table cannot be implicitly converted to a datetime
 *						or if the key is not found.
 *
 * @note				The key may be composite. For example: Table.SubTable.Key
 *
 * @return				The Unix timestamp value retrieved from a table;
 *						Default value if the value cannot be retrieved.
 */
native toml_get_datetime(Toml:handle, const szKey[], defVal = 0, &ofsHour = 0, &ofsMinute = 0, bool:throwError = true);

/**
 * Gets the Unix timestamp value from an array.
 *
 * @param handle		Array handle.
 * @param index			Array index.
 * @param defVal		Default value.
 * @param ofsHour		Hour offset (if the value is in Offset date-time format (RFC 3339)).
 * @param ofsMinute		Minute offset (if the value is in Offset date-time format (RFC 3339)).
 * @param throwError	If true, throws an error if the handle is invalid
 *						or if the value type in the table cannot be implicitly converted to a datetime
 *						or if the index out of range.
 *
 * @return				The Unix timestamp value retrieved from an array;
 *						Default value if the value cannot be retrieved.
 */
native toml_array_get_datetime(TomlArray:handle, index, defVal = 0, &ofsHour = 0, &ofsMinute = 0, bool:throwError = true);

/**
 * Gets the date-time value from a table.
 *
 * @param handle		Table handle.
 * @param szKey			Table key.
 * @param dateTime		Date-time value.
 * @param throwError	If true, throws an error if the handle is invalid
 *						or if the value type in the table cannot be implicitly converted to a datetime
 *						or if the key is not found.
 *
 * @note				The key may be composite. For example: Table.SubTable.Key
 *
 * @return				The Unix timestamp value retrieved from a table;
 *						-1 if the value cannot be retrieved.
 */
native toml_get_datetime_ex(Toml:handle, const szKey[], dateTime[TomlDateTime], bool:throwError = true);

/**
 * Gets the date-time value from an array.
 *
 * @param handle		Array handle.
 * @param index			Array index.
 * @param dateTime		Date-time value.
 * @param throwError	If true, throws an error if the handle is invalid
 *						or if the value type in the table cannot be implicitly converted to a datetime
 *						or if the index out of range.
 *
 * @return				The Unix timestamp value retrieved from an array;
 *						-1 if the value cannot be retrieved.
 */
native toml_array_get_datetime_ex(TomlArray:handle, index, dateTime[TomlDateTime], bool:throwError = true);

/**
 * Gets the number of elements in the array.
 *
 * @param handle		Array handle.
 * @param throwError	If true, throws an error if the handle is invalid.
 *
 * @return				Number of elements in the array.
 */
native toml_array_get_count(TomlArray:handle, bool:throwError = true);

/**
 * Gets the data type in the table.
 *
 * @param handle		Table handle.
 * @param szKey			Table key.
 * @param throwError	If true, throws an error if the handle is invalid
 *						or if the key is not found.
 *
 * @note				The key may be composite. For example: Table.SubTable.Key
 *
 * @return				Data type.
 */
native TomlType:toml_get_type(Toml:handle, const szKey[], bool:throwError = true);

/**
 * Gets the data type in the array.
 *
 * @param handle		Array handle.
 * @param index			Array index.
 * @param throwError	If true, throws an error if the handle is invalid
 *						or if the index is out of range.
 *
 * @return				Data type.
 */
native TomlType:toml_array_get_type(TomlArray:handle, index, bool:throwError = true);

/**
 * Sets the table value to a table.
 *
 * @param handle		Table handle.
 * @param szKey			Table key.
 * @param value			Table value.
 *
 * @note				The key may be composite. For example: Table.SubTable.Key
 *
 * @return				Table handle.
 */
native Toml:toml_set_table(Toml:handle, const szKey[], Toml:value);

/**
 * Sets the table value to an array.
 *
 * @param handle		Array handle.
 * @param index			Array index.
 * @param value			Table value.
 *
 * @return				Table handle.
 */
native Toml:toml_array_set_table(TomlArray:handle, index, Toml:value);

/**
 * Sets the array value to a table.
 *
 * @param handle		Table handle.
 * @param szKey			Table key.
 * @param value			Array value.
 *
 * @note				The key may be composite. For example: Table.SubTable.Key
 *
 * @return				Array handle.
 */
native TomlArray:toml_set_array(Toml:handle, const szKey[], TomlArray:value);

/**
 * Sets the array value to an array.
 *
 * @param handle		Array handle.
 * @param index			Array index.
 * @param value			Array value.
 *
 * @return				Array handle.
 */
native TomlArray:toml_array_set_array(TomlArray:handle, index, TomlArray:value);

/**
 * Sets the integer value to a table.
 *
 * @param handle		Table handle.
 * @param szKey			Table key.
 * @param value			Integer value.
 *
 * @note				The key may be composite. For example: Table.SubTable.Key
 *
 * @noreturn
 */
native toml_set_int(Toml:handle, const szKey[], value);

/**
 * Sets the integer value to an array.
 *
 * @param handle		Array handle.
 * @param index			Array index.
 * @param value			Integer value.
 *
 * @noreturn
 */
native toml_array_set_int(TomlArray:handle, index, value);

/**
 * Sets the boolean value to a table.
 *
 * @param handle		Table handle.
 * @param szKey			Table key.
 * @param value			Boolean value.
 *
 * @note				The key may be composite. For example: Table.SubTable.Key
 *
 * @noreturn
 */
native toml_set_bool(Toml:handle, const szKey[], bool:value);

/**
 * Sets the boolean value to an array.
 *
 * @param handle		Array handle.
 * @param index			Array index.
 * @param value			Boolean value.
 *
 * @noreturn
 */
native toml_array_set_bool(TomlArray:handle, index, bool:value);

/**
 * Sets the floating-point value to a table.
 *
 * @param handle		Table handle.
 * @param szKey			Table key.
 * @param value			Floating-point value.
 *
 * @note				The key may be composite. For example: Table.SubTable.Key
 *
 * @noreturn
 */
native toml_set_float(Toml:handle, const szKey[], Float:value);

/**
 * Sets the floating-point value to an array.
 *
 * @param handle		Array handle.
 * @param index			Array index.
 * @param value			Floating-point value.
 *
 * @noreturn
 */
native toml_array_set_float(TomlArray:handle, index, Float:value);

/**
 * Sets the string value to a table.
 *
 * @param handle		Table handle.
 * @param szKey			Table key.
 * @param value			String value.
 *
 * @note				The key may be composite. For example: Table.SubTable.Key
 *
 * @noreturn
 */
native toml_set_string(Toml:handle, const szKey[], const szValue[]);

/**
 * Sets the string value to an array.
 *
 * @param handle		Array handle.
 * @param index			Array index.
 * @param value			String value.
 *
 * @noreturn
 */
native toml_array_set_string(TomlArray:handle, index, const szValue[]);

/**
 * Sets the local date value to a table.
 *
 * @param handle		Table handle.
 * @param szKey			Table key.
 * @param year			Year value.
 * @param month			Month value.
 * @param day			Day value.
 *
 * @note				The key may be composite. For example: Table.SubTable.Key
 *
 * @noreturn
 */
native toml_set_local_date(Toml:handle, const szKey[], year, month, day);

/**
 * Sets the local date value to an array.
 *
 * @param handle		Array handle.
 * @param index			Array index.
 * @param year			Year value.
 * @param month			Month value.
 * @param day			Day value.
 *
 * @noreturn
 */
native toml_array_set_local_date(TomlArray:handle, index, year, month, day);

/**
 * Sets the local time value to a table.
 *
 * @param handle		Table handle.
 * @param szKey			Table key.
 * @param hour			Hour value.
 * @param minute		Minute value.
 * @param second		Second value.
 * @param millisecond	Millisecond value.
 *
 * @note				The key may be composite. For example: Table.SubTable.Key
 *
 * @noreturn
 */
native toml_set_local_time(Toml:handle, const szKey[], hour, minute, second = 0, millisecond = 0);

/**
 * Sets the local time value to an array.
 *
 * @param handle		Array handle.
 * @param index			Array index.
 * @param hour			Hour value.
 * @param minute		Minute value.
 * @param second		Second value.
 * @param millisecond	Millisecond value.
 *
 * @noreturn
 */
native toml_array_set_local_time(TomlArray:handle, index, hour, minute, second = 0, millisecond = 0);

/**
 * Sets the local date-time value to a table.
 *
 * @param handle		Table handle.
 * @param szKey			Table key.
 * @param datetime		Date-time value.
 *
 * @note				The key may be composite. For example: Table.SubTable.Key
 *
 * @noreturn
 */
native toml_set_local_datetime(Toml:handle, const szKey[], const datetime[TomlDateTime]);

/**
 * Sets the local date-time value to an array.
 *
 * @param handle		Array handle.
 * @param index			Array index.
 * @param datetime		Date-time value.
 *
 * @noreturn
 */
native toml_array_set_local_datetime(TomlArray:handle, index, const datetime[TomlDateTime]);

/**
 * Sets the offset date-time value to a table.
 *
 * @param handle		Table handle.
 * @param szKey			Table key.
 * @param datetime		Offset date-time value.
 *
 * @note				The key may be composite. For example: Table.SubTable.Key
 *
 * @noreturn
 */
native toml_set_offset_datetime(Toml:handle, const szKey[], const datetime[TomlDateTime]);

/**
 * Sets the offset date-time value to an array.
 *
 * @param handle		Array handle.
 * @param index			Array index.
 * @param datetime		Offset date-time value.
 *
 * @noreturn
 */
native toml_array_set_offset_datetime(TomlArray:handle, index, const datetime[TomlDateTime]);

/**
 * Inits an empty TOML table.
 *
 * @return				The table handle to be used in other natives.
 */
native Toml:toml_init_root();

/**
 * Inits an empty table inside another table.
 *
 * @param handle		Table handle.
 * @param szKey			Table key.
 *
 * @note				The key may be composite. For example: Table.SubTable.Key
 *
 * @return				The table handle to be used in other natives.
 */
native Toml:toml_init_table(Toml:handle, const szKey[]);

/**
 * Inits an empty table inside array.
 *
 * @param handle		Array handle.
 *
 * @return				The table handle to be used in other natives.
 */
native Toml:toml_array_init_table(TomlArray:handle);

/**
 * Inits an empty array inside table.
 *
 * @param handle		Table handle.
 * @param szKey			Table key.
 *
 * @note				The key may be composite. For example: Table.SubTable.Key
 *
 * @return				The table handle to be used in other natives.
 */
native TomlArray:toml_init_array(Toml:handle, const szKey[]);

/**
 * Inits an empty array inside another array.
 *
 * @param handle		Array handle.
 *
 * @return				The array handle to be used in other natives.
 */
native TomlArray:toml_array_init_array(TomlArray:handle);

/**
 * Inits an integer value inside table.
 *
 * @param handle		Table handle.
 * @param szKey			Table key.
 * @param value			Integer value.
 *
 * @note				The key may be composite. For example: Table.SubTable.Key
 *
 * @noreturn
 */
native toml_init_int(Toml:handle, const szKey[], value);

/**
 * Inits an integer value inside array.
 *
 * @param handle		Array handle.
 * @param value			Integer value.
 *
 * @return				Array index of the value.
 */
native toml_array_init_int(TomlArray:handle, value);

/**
 * Inits a boolean value inside table.
 *
 * @param handle		Table handle.
 * @param szKey			Table key.
 * @param value			Boolean value.
 *
 * @note				The key may be composite. For example: Table.SubTable.Key
 *
 * @noreturn
 */
native toml_init_bool(Toml:handle, const szKey[], bool:value);

/**
 * Inits a boolean value inside array.
 *
 * @param handle		Array handle.
 * @param value			Boolean value.
 *
 * @return				Array index of the value.
 */
native toml_array_init_bool(TomlArray:handle, bool:value);

/**
 * Inits a floating-point value inside table.
 *
 * @param handle		Table handle.
 * @param szKey			Table key.
 * @param value			Floating-point value.
 *
 * @note				The key may be composite. For example: Table.SubTable.Key
 *
 * @noreturn
 */
native toml_init_float(Toml:handle, const szKey[], Float:value);

/**
 * Inits a floating-point value inside array.
 *
 * @param handle		Array handle.
 * @param value			Floating-point value.
 *
 * @return				Array index of the value.
 */
native toml_array_init_float(TomlArray:handle, Float:value);

/**
 * Inits a string value inside table.
 *
 * @param handle		Table handle.
 * @param szKey			Table key.
 * @param value			String value.
 *
 * @note				The key may be composite. For example: Table.SubTable.Key
 *
 * @noreturn
 */
native toml_init_string(Toml:handle, const szKey[], const szValue[]);

/**
 * Inits a string value inside array.
 *
 * @param handle		Array handle.
 * @param value			String value.
 *
 * @return				Array index of the value.
 */
native toml_array_init_string(TomlArray:handle, const szValue[]);

/**
 * Inits a local date value inside table.
 *
 * @param handle		Table handle.
 * @param szKey			Table key.
 * @param year			Year value.
 * @param month			Month value.
 * @param day			Day value.
 *
 * @note				The key may be composite. For example: Table.SubTable.Key
 *
 * @noreturn
 */
native toml_init_local_date(Toml:handle, const szKey[], year, month, day);

/**
 * Inits a local date value inside array.
 *
 * @param handle		Array handle.
 * @param year			Year value.
 * @param month			Month value.
 * @param day			Day value.
 *
 * @return				Array index of the value.
 */
native toml_array_init_local_date(TomlArray:handle, year, month, day);

/**
 * Inits a local time value inside table.
 *
 * @param handle		Table handle.
 * @param szKey			Table key.
 * @param hour			Hour value.
 * @param minute		Minute value.
 * @param second		Second value.
 * @param millisecond	Millisecond value.
 *
 * @note				The key may be composite. For example: Table.SubTable.Key
 *
 * @noreturn
 */
native toml_init_local_time(Toml:handle, const szKey[], hour, minute, second = 0, millisecond = 0);

/**
 * Inits a local time value inside array.
 *
 * @param handle		Array handle.
 * @param hour			Hour value.
 * @param minute		Minute value.
 * @param second		Second value.
 * @param millisecond	Millisecond value.
 *
 * @return				Array index of the value.
 */
native toml_array_init_local_time(TomlArray:handle, hour, minute, second = 0, millisecond = 0);

/**
 * Inits a local date-time value inside table.
 *
 * @param handle		Table handle.
 * @param szKey			Table key.
 * @param datetime		Date-time value.
 *
 * @note				The key may be composite. For example: Table.SubTable.Key
 *
 * @noreturn
 */
native toml_init_local_datetime(Toml:handle, const szKey[], const datetime[TomlDateTime]);

/**
 * Inits a local date-time value inside array.
 *
 * @param handle		Array handle.
 * @param datetime		Date-time value.
 *
 * @return				Array index of the value.
 */
native toml_array_init_local_datetime(TomlArray:handle, const datetime[TomlDateTime]);

/**
 * Inits an offset date-time value inside table.
 *
 * @param handle		Table handle.
 * @param szKey			Table key.
 * @param datetime		Offset date-time value.
 *
 * @note				The key may be composite. For example: Table.SubTable.Key
 *
 * @noreturn
 */
native toml_init_offset_datetime(Toml:handle, const szKey[], const datetime[TomlDateTime]);

/**
 * Inits an offset date-time value inside array.
 *
 * @param handle		Array handle.
 * @param datetime		Offset date-time value.
 *
 * @return				Array index of the value.
 */
native toml_array_init_offset_datetime(TomlArray:handle, const datetime[TomlDateTime]);

/**
 * Removes the key and its value in the table.
 *
 * @param handle		Table handle.
 * @param szKey			Table key.
 *
 * @note				The key may be composite. For example: Table.SubTable.Key
 *
 * @noreturn
 */
native toml_remove(Toml:handle, const szKey[]);

/**
 * Removes an element from an array.
 *
 * @param handle		Array handle.
 * @param index			Position in the array (starting from 0).
 *
 * @return				Size of array.
 */
native toml_array_remove(TomlArray:handle, index);

/**
 * Removes all keys in a table or all elements in an array.
 *
 * @param handle		Table or array handle.
 *
 * @noreturn
 */
native toml_clear({Toml, TomlArray}:handle);

/**
 * Serializes TOML to a file.
 *
 * @param handle		Table or array handle.
 * @param szPath		Relative path to a file from the 'cstrike' directory.
 *
 * @return				Number of chars written.
 */
native toml_save({Toml, TomlArray}:handle, const szPath[]);

/**
 * Closes a TOML handle.
 *
 * @param handle		Table or array handle.
 *
 * @note				You don't need to close every handle.
 *						Just close the main one (which retrieved from toml_open or toml_init_root natives)
 *						and all other handles will also be closed.
 *
 * @note				All handles will be closed at the map change.
 *
 * @return				Invalid handle.
 */
native any:toml_close({Toml, TomlArray}:handle);
