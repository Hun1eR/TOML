// ***********************************************************************
// Created          : 05-25-2020
//
// Last Modified By : the_hunter
// Last Modified On : 05-26-2020
// ***********************************************************************
//     Copyright (c) 1996-2002, Valve LLC. All rights reserved.
// ***********************************************************************

#include <cssdk/public/utils.h>
#include <cssdk/dll/entity_base.h>
#include <climits>
#include <cstdio>
#include <cstring>

/// <summary>
/// </summary>
FORCEINLINE_STATIC void message_begin(const MessageType msg_type, const int msg_id, const vec_t* const origin = nullptr, Edict* const client = nullptr)
{
	g_engine_funcs.message_begin(msg_type, msg_id, origin, client);
}

/// <summary>
/// </summary>
FORCEINLINE_STATIC void write_short(const int value)
{
	g_engine_funcs.write_short(value);
}

/// <summary>
/// </summary>
FORCEINLINE_STATIC void write_byte(const int value)
{
	g_engine_funcs.write_byte(value);
}

/// <summary>
/// </summary>
FORCEINLINE_STATIC void write_string(const char* value)
{
	g_engine_funcs.write_string(value);
}

/// <summary>
/// </summary>
FORCEINLINE_STATIC void message_end()
{
	g_engine_funcs.message_end();
}

/// <summary>
/// </summary>
bool cssdk_is_bot(Edict* client)
{
	if (client->vars.flags & FL_FAKE_CLIENT) {
		return true;
	}

	const auto* auth_id = g_engine_funcs.get_player_auth_id(client);

	return !auth_id || !std::strcmp(auth_id, "BOT");
}

/// <summary>
/// </summary>
short cssdk_fixed_signed16(const float value, const float scale)
{
	auto output = static_cast<int>(value * scale);

	if (output < SHRT_MIN) {
		output = SHRT_MIN;
	}
	else if (output > SHRT_MAX) {
		output = SHRT_MAX;
	}

	return static_cast<short>(output);
}

/// <summary>
/// </summary>
unsigned short cssdk_fixed_unsigned16(const float value, const float scale)
{
	auto output = static_cast<int>(value * scale);

	if (output < 0) {
		output = 0;
	}
	else if (output > USHRT_MAX) {
		output = USHRT_MAX;
	}

	return static_cast<unsigned short>(output);
}

/// <summary>
/// </summary>
void cssdk_hud_message(EntityBase* const entity, const HudTextParams& hud_params, const char* message, Edict* const client)
{
	constexpr auto svc_temp_entity = static_cast<int>(SvcMessage::TempEntity);

	if (entity) {
		if (!entity->is_net_client()) {
			return;
		}

		message_begin(MessageType::OneUnreliable, svc_temp_entity, nullptr, client);
	}
	else {
		message_begin(MessageType::Broadcast, svc_temp_entity);
	}

	write_byte(TE_TEXT_MESSAGE);
	write_byte(hud_params.channel & 0xFF);
	write_short(cssdk_fixed_signed16(hud_params.x, 1 << 13));
	write_short(cssdk_fixed_signed16(hud_params.y, 1 << 13));
	write_byte(hud_params.effect);
	write_byte(hud_params.r1);
	write_byte(hud_params.g1);
	write_byte(hud_params.b1);
	write_byte(hud_params.a1);
	write_byte(hud_params.r2);
	write_byte(hud_params.g2);
	write_byte(hud_params.b2);
	write_byte(hud_params.a2);
	write_short(cssdk_fixed_unsigned16(hud_params.fade_in_time, 1 << 8));
	write_short(cssdk_fixed_unsigned16(hud_params.fade_out_time, 1 << 8));
	write_short(cssdk_fixed_unsigned16(hud_params.hold_time, 1 << 8));

	if (hud_params.effect == 2) {
		write_short(cssdk_fixed_unsigned16(hud_params.fx_time, 1 << 8));
	}

	if (!message) {
		write_string(" ");
	}
	else if (std::strlen(message) > 489) {
		// The maximum net message size is 512. There are only 489 bytes left for the string.
		char string[489];
		std::snprintf(string, sizeof string, "%s", message);
		write_string(string);
	}
	else {
		write_string(message);
	}

	message_end();
}

/// <summary>
/// </summary>
void cssdk_hud_message(Edict* const client, const HudTextParams& hud_params, const char* message)
{
	if (client) {
		auto* entity = cssdk_entity_private_data<EntityBase*>(client);
		cssdk_hud_message(entity, hud_params, message, client);
	}
	else {
		cssdk_hud_message(nullptr, hud_params, message, nullptr);
	}
}

/// <summary>
/// </summary>
void cssdk_hud_message(const int client, const HudTextParams& hud_params, const char* message)
{
	if (client) {
		auto* edict = g_engine_funcs.entity_of_ent_index(client);
		cssdk_hud_message(edict, hud_params, message);
	}
	else {
		cssdk_hud_message(nullptr, hud_params, message, nullptr);
	}
}

/// <summary>
/// </summary>
EntityBase* cssdk_find_entity_in_sphere(Edict* start_entity, const Vector& center, const float radius)
{
	const auto* entity = g_engine_funcs.find_entity_in_sphere(start_entity, center, radius);
	return cssdk_is_valid_entity(entity) ? EntityBase::instance(entity) : nullptr;
}

/// <summary>
/// </summary>
EntityBase* cssdk_find_entity_by_string(Edict* start_entity, const char* field, const char* value)
{
	const auto* entity = g_engine_funcs.find_entity_by_string(start_entity, field, value);
	return cssdk_is_valid_entity(entity) ? EntityBase::instance(entity) : nullptr;
}

/// <summary>
/// </summary>
EntityBase* find_entity_by_class_name(Edict* start_entity, const char* class_name)
{
	return cssdk_find_entity_by_string(start_entity, "classname", class_name);
}

/// <summary>
/// </summary>
EntityBase* find_entity_by_target_name(Edict* start_entity, const char* target_name)
{
	return cssdk_find_entity_by_string(start_entity, "targetname", target_name);
}

/// <summary>
/// </summary>
EntityBase* find_client_in_pvs(Edict* entity)
{
	entity = g_engine_funcs.find_client_in_pvs(entity);
	return cssdk_is_valid_entity(entity) ? EntityBase::instance(entity) : nullptr;
}

/// <summary>
/// </summary>
EntityBase* find_entity_by_vars(EntityVars* vars)
{
	const auto* entity = g_engine_funcs.find_entity_by_vars(vars);
	return cssdk_is_valid_entity(entity) ? EntityBase::instance(entity) : nullptr;
}
