#pragma once
// MESSAGE VEHICLE_COMMAND_ACTION PACKING

#define MAVLINK_MSG_ID_VEHICLE_COMMAND_ACTION 2


typedef struct __mavlink_vehicle_command_action_t {
 uint64_t timestamp; /*< [us] Timestamp of the message*/
 uint8_t vehicle_action; /*<  Vehicle action requested*/
} mavlink_vehicle_command_action_t;

#define MAVLINK_MSG_ID_VEHICLE_COMMAND_ACTION_LEN 9
#define MAVLINK_MSG_ID_VEHICLE_COMMAND_ACTION_MIN_LEN 9
#define MAVLINK_MSG_ID_2_LEN 9
#define MAVLINK_MSG_ID_2_MIN_LEN 9

#define MAVLINK_MSG_ID_VEHICLE_COMMAND_ACTION_CRC 145
#define MAVLINK_MSG_ID_2_CRC 145



#if MAVLINK_COMMAND_24BIT
#define MAVLINK_MESSAGE_INFO_VEHICLE_COMMAND_ACTION { \
    2, \
    "VEHICLE_COMMAND_ACTION", \
    2, \
    {  { "timestamp", NULL, MAVLINK_TYPE_UINT64_T, 0, 0, offsetof(mavlink_vehicle_command_action_t, timestamp) }, \
         { "vehicle_action", NULL, MAVLINK_TYPE_UINT8_T, 0, 8, offsetof(mavlink_vehicle_command_action_t, vehicle_action) }, \
         } \
}
#else
#define MAVLINK_MESSAGE_INFO_VEHICLE_COMMAND_ACTION { \
    "VEHICLE_COMMAND_ACTION", \
    2, \
    {  { "timestamp", NULL, MAVLINK_TYPE_UINT64_T, 0, 0, offsetof(mavlink_vehicle_command_action_t, timestamp) }, \
         { "vehicle_action", NULL, MAVLINK_TYPE_UINT8_T, 0, 8, offsetof(mavlink_vehicle_command_action_t, vehicle_action) }, \
         } \
}
#endif

/**
 * @brief Pack a vehicle_command_action message
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param msg The MAVLink message to compress the data into
 *
 * @param timestamp [us] Timestamp of the message
 * @param vehicle_action  Vehicle action requested
 * @return length of the message in bytes (excluding serial stream start sign)
 */
static inline uint16_t mavlink_msg_vehicle_command_action_pack(uint8_t system_id, uint8_t component_id, mavlink_message_t* msg,
                               uint64_t timestamp, uint8_t vehicle_action)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    char buf[MAVLINK_MSG_ID_VEHICLE_COMMAND_ACTION_LEN];
    _mav_put_uint64_t(buf, 0, timestamp);
    _mav_put_uint8_t(buf, 8, vehicle_action);

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), buf, MAVLINK_MSG_ID_VEHICLE_COMMAND_ACTION_LEN);
#else
    mavlink_vehicle_command_action_t packet;
    packet.timestamp = timestamp;
    packet.vehicle_action = vehicle_action;

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), &packet, MAVLINK_MSG_ID_VEHICLE_COMMAND_ACTION_LEN);
#endif

    msg->msgid = MAVLINK_MSG_ID_VEHICLE_COMMAND_ACTION;
    return mavlink_finalize_message(msg, system_id, component_id, MAVLINK_MSG_ID_VEHICLE_COMMAND_ACTION_MIN_LEN, MAVLINK_MSG_ID_VEHICLE_COMMAND_ACTION_LEN, MAVLINK_MSG_ID_VEHICLE_COMMAND_ACTION_CRC);
}

/**
 * @brief Pack a vehicle_command_action message on a channel
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param chan The MAVLink channel this message will be sent over
 * @param msg The MAVLink message to compress the data into
 * @param timestamp [us] Timestamp of the message
 * @param vehicle_action  Vehicle action requested
 * @return length of the message in bytes (excluding serial stream start sign)
 */
static inline uint16_t mavlink_msg_vehicle_command_action_pack_chan(uint8_t system_id, uint8_t component_id, uint8_t chan,
                               mavlink_message_t* msg,
                                   uint64_t timestamp,uint8_t vehicle_action)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    char buf[MAVLINK_MSG_ID_VEHICLE_COMMAND_ACTION_LEN];
    _mav_put_uint64_t(buf, 0, timestamp);
    _mav_put_uint8_t(buf, 8, vehicle_action);

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), buf, MAVLINK_MSG_ID_VEHICLE_COMMAND_ACTION_LEN);
#else
    mavlink_vehicle_command_action_t packet;
    packet.timestamp = timestamp;
    packet.vehicle_action = vehicle_action;

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), &packet, MAVLINK_MSG_ID_VEHICLE_COMMAND_ACTION_LEN);
#endif

    msg->msgid = MAVLINK_MSG_ID_VEHICLE_COMMAND_ACTION;
    return mavlink_finalize_message_chan(msg, system_id, component_id, chan, MAVLINK_MSG_ID_VEHICLE_COMMAND_ACTION_MIN_LEN, MAVLINK_MSG_ID_VEHICLE_COMMAND_ACTION_LEN, MAVLINK_MSG_ID_VEHICLE_COMMAND_ACTION_CRC);
}

/**
 * @brief Encode a vehicle_command_action struct
 *
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param msg The MAVLink message to compress the data into
 * @param vehicle_command_action C-struct to read the message contents from
 */
static inline uint16_t mavlink_msg_vehicle_command_action_encode(uint8_t system_id, uint8_t component_id, mavlink_message_t* msg, const mavlink_vehicle_command_action_t* vehicle_command_action)
{
    return mavlink_msg_vehicle_command_action_pack(system_id, component_id, msg, vehicle_command_action->timestamp, vehicle_command_action->vehicle_action);
}

/**
 * @brief Encode a vehicle_command_action struct on a channel
 *
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param chan The MAVLink channel this message will be sent over
 * @param msg The MAVLink message to compress the data into
 * @param vehicle_command_action C-struct to read the message contents from
 */
static inline uint16_t mavlink_msg_vehicle_command_action_encode_chan(uint8_t system_id, uint8_t component_id, uint8_t chan, mavlink_message_t* msg, const mavlink_vehicle_command_action_t* vehicle_command_action)
{
    return mavlink_msg_vehicle_command_action_pack_chan(system_id, component_id, chan, msg, vehicle_command_action->timestamp, vehicle_command_action->vehicle_action);
}

/**
 * @brief Send a vehicle_command_action message
 * @param chan MAVLink channel to send the message
 *
 * @param timestamp [us] Timestamp of the message
 * @param vehicle_action  Vehicle action requested
 */
#ifdef MAVLINK_USE_CONVENIENCE_FUNCTIONS

static inline void mavlink_msg_vehicle_command_action_send(mavlink_channel_t chan, uint64_t timestamp, uint8_t vehicle_action)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    char buf[MAVLINK_MSG_ID_VEHICLE_COMMAND_ACTION_LEN];
    _mav_put_uint64_t(buf, 0, timestamp);
    _mav_put_uint8_t(buf, 8, vehicle_action);

    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_VEHICLE_COMMAND_ACTION, buf, MAVLINK_MSG_ID_VEHICLE_COMMAND_ACTION_MIN_LEN, MAVLINK_MSG_ID_VEHICLE_COMMAND_ACTION_LEN, MAVLINK_MSG_ID_VEHICLE_COMMAND_ACTION_CRC);
#else
    mavlink_vehicle_command_action_t packet;
    packet.timestamp = timestamp;
    packet.vehicle_action = vehicle_action;

    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_VEHICLE_COMMAND_ACTION, (const char *)&packet, MAVLINK_MSG_ID_VEHICLE_COMMAND_ACTION_MIN_LEN, MAVLINK_MSG_ID_VEHICLE_COMMAND_ACTION_LEN, MAVLINK_MSG_ID_VEHICLE_COMMAND_ACTION_CRC);
#endif
}

/**
 * @brief Send a vehicle_command_action message
 * @param chan MAVLink channel to send the message
 * @param struct The MAVLink struct to serialize
 */
static inline void mavlink_msg_vehicle_command_action_send_struct(mavlink_channel_t chan, const mavlink_vehicle_command_action_t* vehicle_command_action)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    mavlink_msg_vehicle_command_action_send(chan, vehicle_command_action->timestamp, vehicle_command_action->vehicle_action);
#else
    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_VEHICLE_COMMAND_ACTION, (const char *)vehicle_command_action, MAVLINK_MSG_ID_VEHICLE_COMMAND_ACTION_MIN_LEN, MAVLINK_MSG_ID_VEHICLE_COMMAND_ACTION_LEN, MAVLINK_MSG_ID_VEHICLE_COMMAND_ACTION_CRC);
#endif
}

#if MAVLINK_MSG_ID_VEHICLE_COMMAND_ACTION_LEN <= MAVLINK_MAX_PAYLOAD_LEN
/*
  This variant of _send() can be used to save stack space by re-using
  memory from the receive buffer.  The caller provides a
  mavlink_message_t which is the size of a full mavlink message. This
  is usually the receive buffer for the channel, and allows a reply to an
  incoming message with minimum stack space usage.
 */
static inline void mavlink_msg_vehicle_command_action_send_buf(mavlink_message_t *msgbuf, mavlink_channel_t chan,  uint64_t timestamp, uint8_t vehicle_action)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    char *buf = (char *)msgbuf;
    _mav_put_uint64_t(buf, 0, timestamp);
    _mav_put_uint8_t(buf, 8, vehicle_action);

    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_VEHICLE_COMMAND_ACTION, buf, MAVLINK_MSG_ID_VEHICLE_COMMAND_ACTION_MIN_LEN, MAVLINK_MSG_ID_VEHICLE_COMMAND_ACTION_LEN, MAVLINK_MSG_ID_VEHICLE_COMMAND_ACTION_CRC);
#else
    mavlink_vehicle_command_action_t *packet = (mavlink_vehicle_command_action_t *)msgbuf;
    packet->timestamp = timestamp;
    packet->vehicle_action = vehicle_action;

    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_VEHICLE_COMMAND_ACTION, (const char *)packet, MAVLINK_MSG_ID_VEHICLE_COMMAND_ACTION_MIN_LEN, MAVLINK_MSG_ID_VEHICLE_COMMAND_ACTION_LEN, MAVLINK_MSG_ID_VEHICLE_COMMAND_ACTION_CRC);
#endif
}
#endif

#endif

// MESSAGE VEHICLE_COMMAND_ACTION UNPACKING


/**
 * @brief Get field timestamp from vehicle_command_action message
 *
 * @return [us] Timestamp of the message
 */
static inline uint64_t mavlink_msg_vehicle_command_action_get_timestamp(const mavlink_message_t* msg)
{
    return _MAV_RETURN_uint64_t(msg,  0);
}

/**
 * @brief Get field vehicle_action from vehicle_command_action message
 *
 * @return  Vehicle action requested
 */
static inline uint8_t mavlink_msg_vehicle_command_action_get_vehicle_action(const mavlink_message_t* msg)
{
    return _MAV_RETURN_uint8_t(msg,  8);
}

/**
 * @brief Decode a vehicle_command_action message into a struct
 *
 * @param msg The message to decode
 * @param vehicle_command_action C-struct to decode the message contents into
 */
static inline void mavlink_msg_vehicle_command_action_decode(const mavlink_message_t* msg, mavlink_vehicle_command_action_t* vehicle_command_action)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    vehicle_command_action->timestamp = mavlink_msg_vehicle_command_action_get_timestamp(msg);
    vehicle_command_action->vehicle_action = mavlink_msg_vehicle_command_action_get_vehicle_action(msg);
#else
        uint8_t len = msg->len < MAVLINK_MSG_ID_VEHICLE_COMMAND_ACTION_LEN? msg->len : MAVLINK_MSG_ID_VEHICLE_COMMAND_ACTION_LEN;
        memset(vehicle_command_action, 0, MAVLINK_MSG_ID_VEHICLE_COMMAND_ACTION_LEN);
    memcpy(vehicle_command_action, _MAV_PAYLOAD(msg), len);
#endif
}
