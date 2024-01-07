#pragma once
// MESSAGE SENSOR_CAMERA_DETECTION PACKING

#define MAVLINK_MSG_ID_SENSOR_CAMERA_DETECTION 3


typedef struct __mavlink_sensor_camera_detection_t {
 uint64_t timestamp; /*< [us] Timestamp of the message*/
 uint8_t identified_apriltag; /*<  Apriltag identified*/
} mavlink_sensor_camera_detection_t;

#define MAVLINK_MSG_ID_SENSOR_CAMERA_DETECTION_LEN 9
#define MAVLINK_MSG_ID_SENSOR_CAMERA_DETECTION_MIN_LEN 9
#define MAVLINK_MSG_ID_3_LEN 9
#define MAVLINK_MSG_ID_3_MIN_LEN 9

#define MAVLINK_MSG_ID_SENSOR_CAMERA_DETECTION_CRC 154
#define MAVLINK_MSG_ID_3_CRC 154



#if MAVLINK_COMMAND_24BIT
#define MAVLINK_MESSAGE_INFO_SENSOR_CAMERA_DETECTION { \
    3, \
    "SENSOR_CAMERA_DETECTION", \
    2, \
    {  { "timestamp", NULL, MAVLINK_TYPE_UINT64_T, 0, 0, offsetof(mavlink_sensor_camera_detection_t, timestamp) }, \
         { "identified_apriltag", NULL, MAVLINK_TYPE_UINT8_T, 0, 8, offsetof(mavlink_sensor_camera_detection_t, identified_apriltag) }, \
         } \
}
#else
#define MAVLINK_MESSAGE_INFO_SENSOR_CAMERA_DETECTION { \
    "SENSOR_CAMERA_DETECTION", \
    2, \
    {  { "timestamp", NULL, MAVLINK_TYPE_UINT64_T, 0, 0, offsetof(mavlink_sensor_camera_detection_t, timestamp) }, \
         { "identified_apriltag", NULL, MAVLINK_TYPE_UINT8_T, 0, 8, offsetof(mavlink_sensor_camera_detection_t, identified_apriltag) }, \
         } \
}
#endif

/**
 * @brief Pack a sensor_camera_detection message
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param msg The MAVLink message to compress the data into
 *
 * @param timestamp [us] Timestamp of the message
 * @param identified_apriltag  Apriltag identified
 * @return length of the message in bytes (excluding serial stream start sign)
 */
static inline uint16_t mavlink_msg_sensor_camera_detection_pack(uint8_t system_id, uint8_t component_id, mavlink_message_t* msg,
                               uint64_t timestamp, uint8_t identified_apriltag)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    char buf[MAVLINK_MSG_ID_SENSOR_CAMERA_DETECTION_LEN];
    _mav_put_uint64_t(buf, 0, timestamp);
    _mav_put_uint8_t(buf, 8, identified_apriltag);

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), buf, MAVLINK_MSG_ID_SENSOR_CAMERA_DETECTION_LEN);
#else
    mavlink_sensor_camera_detection_t packet;
    packet.timestamp = timestamp;
    packet.identified_apriltag = identified_apriltag;

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), &packet, MAVLINK_MSG_ID_SENSOR_CAMERA_DETECTION_LEN);
#endif

    msg->msgid = MAVLINK_MSG_ID_SENSOR_CAMERA_DETECTION;
    return mavlink_finalize_message(msg, system_id, component_id, MAVLINK_MSG_ID_SENSOR_CAMERA_DETECTION_MIN_LEN, MAVLINK_MSG_ID_SENSOR_CAMERA_DETECTION_LEN, MAVLINK_MSG_ID_SENSOR_CAMERA_DETECTION_CRC);
}

/**
 * @brief Pack a sensor_camera_detection message on a channel
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param chan The MAVLink channel this message will be sent over
 * @param msg The MAVLink message to compress the data into
 * @param timestamp [us] Timestamp of the message
 * @param identified_apriltag  Apriltag identified
 * @return length of the message in bytes (excluding serial stream start sign)
 */
static inline uint16_t mavlink_msg_sensor_camera_detection_pack_chan(uint8_t system_id, uint8_t component_id, uint8_t chan,
                               mavlink_message_t* msg,
                                   uint64_t timestamp,uint8_t identified_apriltag)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    char buf[MAVLINK_MSG_ID_SENSOR_CAMERA_DETECTION_LEN];
    _mav_put_uint64_t(buf, 0, timestamp);
    _mav_put_uint8_t(buf, 8, identified_apriltag);

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), buf, MAVLINK_MSG_ID_SENSOR_CAMERA_DETECTION_LEN);
#else
    mavlink_sensor_camera_detection_t packet;
    packet.timestamp = timestamp;
    packet.identified_apriltag = identified_apriltag;

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), &packet, MAVLINK_MSG_ID_SENSOR_CAMERA_DETECTION_LEN);
#endif

    msg->msgid = MAVLINK_MSG_ID_SENSOR_CAMERA_DETECTION;
    return mavlink_finalize_message_chan(msg, system_id, component_id, chan, MAVLINK_MSG_ID_SENSOR_CAMERA_DETECTION_MIN_LEN, MAVLINK_MSG_ID_SENSOR_CAMERA_DETECTION_LEN, MAVLINK_MSG_ID_SENSOR_CAMERA_DETECTION_CRC);
}

/**
 * @brief Encode a sensor_camera_detection struct
 *
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param msg The MAVLink message to compress the data into
 * @param sensor_camera_detection C-struct to read the message contents from
 */
static inline uint16_t mavlink_msg_sensor_camera_detection_encode(uint8_t system_id, uint8_t component_id, mavlink_message_t* msg, const mavlink_sensor_camera_detection_t* sensor_camera_detection)
{
    return mavlink_msg_sensor_camera_detection_pack(system_id, component_id, msg, sensor_camera_detection->timestamp, sensor_camera_detection->identified_apriltag);
}

/**
 * @brief Encode a sensor_camera_detection struct on a channel
 *
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param chan The MAVLink channel this message will be sent over
 * @param msg The MAVLink message to compress the data into
 * @param sensor_camera_detection C-struct to read the message contents from
 */
static inline uint16_t mavlink_msg_sensor_camera_detection_encode_chan(uint8_t system_id, uint8_t component_id, uint8_t chan, mavlink_message_t* msg, const mavlink_sensor_camera_detection_t* sensor_camera_detection)
{
    return mavlink_msg_sensor_camera_detection_pack_chan(system_id, component_id, chan, msg, sensor_camera_detection->timestamp, sensor_camera_detection->identified_apriltag);
}

/**
 * @brief Send a sensor_camera_detection message
 * @param chan MAVLink channel to send the message
 *
 * @param timestamp [us] Timestamp of the message
 * @param identified_apriltag  Apriltag identified
 */
#ifdef MAVLINK_USE_CONVENIENCE_FUNCTIONS

static inline void mavlink_msg_sensor_camera_detection_send(mavlink_channel_t chan, uint64_t timestamp, uint8_t identified_apriltag)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    char buf[MAVLINK_MSG_ID_SENSOR_CAMERA_DETECTION_LEN];
    _mav_put_uint64_t(buf, 0, timestamp);
    _mav_put_uint8_t(buf, 8, identified_apriltag);

    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_SENSOR_CAMERA_DETECTION, buf, MAVLINK_MSG_ID_SENSOR_CAMERA_DETECTION_MIN_LEN, MAVLINK_MSG_ID_SENSOR_CAMERA_DETECTION_LEN, MAVLINK_MSG_ID_SENSOR_CAMERA_DETECTION_CRC);
#else
    mavlink_sensor_camera_detection_t packet;
    packet.timestamp = timestamp;
    packet.identified_apriltag = identified_apriltag;

    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_SENSOR_CAMERA_DETECTION, (const char *)&packet, MAVLINK_MSG_ID_SENSOR_CAMERA_DETECTION_MIN_LEN, MAVLINK_MSG_ID_SENSOR_CAMERA_DETECTION_LEN, MAVLINK_MSG_ID_SENSOR_CAMERA_DETECTION_CRC);
#endif
}

/**
 * @brief Send a sensor_camera_detection message
 * @param chan MAVLink channel to send the message
 * @param struct The MAVLink struct to serialize
 */
static inline void mavlink_msg_sensor_camera_detection_send_struct(mavlink_channel_t chan, const mavlink_sensor_camera_detection_t* sensor_camera_detection)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    mavlink_msg_sensor_camera_detection_send(chan, sensor_camera_detection->timestamp, sensor_camera_detection->identified_apriltag);
#else
    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_SENSOR_CAMERA_DETECTION, (const char *)sensor_camera_detection, MAVLINK_MSG_ID_SENSOR_CAMERA_DETECTION_MIN_LEN, MAVLINK_MSG_ID_SENSOR_CAMERA_DETECTION_LEN, MAVLINK_MSG_ID_SENSOR_CAMERA_DETECTION_CRC);
#endif
}

#if MAVLINK_MSG_ID_SENSOR_CAMERA_DETECTION_LEN <= MAVLINK_MAX_PAYLOAD_LEN
/*
  This variant of _send() can be used to save stack space by re-using
  memory from the receive buffer.  The caller provides a
  mavlink_message_t which is the size of a full mavlink message. This
  is usually the receive buffer for the channel, and allows a reply to an
  incoming message with minimum stack space usage.
 */
static inline void mavlink_msg_sensor_camera_detection_send_buf(mavlink_message_t *msgbuf, mavlink_channel_t chan,  uint64_t timestamp, uint8_t identified_apriltag)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    char *buf = (char *)msgbuf;
    _mav_put_uint64_t(buf, 0, timestamp);
    _mav_put_uint8_t(buf, 8, identified_apriltag);

    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_SENSOR_CAMERA_DETECTION, buf, MAVLINK_MSG_ID_SENSOR_CAMERA_DETECTION_MIN_LEN, MAVLINK_MSG_ID_SENSOR_CAMERA_DETECTION_LEN, MAVLINK_MSG_ID_SENSOR_CAMERA_DETECTION_CRC);
#else
    mavlink_sensor_camera_detection_t *packet = (mavlink_sensor_camera_detection_t *)msgbuf;
    packet->timestamp = timestamp;
    packet->identified_apriltag = identified_apriltag;

    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_SENSOR_CAMERA_DETECTION, (const char *)packet, MAVLINK_MSG_ID_SENSOR_CAMERA_DETECTION_MIN_LEN, MAVLINK_MSG_ID_SENSOR_CAMERA_DETECTION_LEN, MAVLINK_MSG_ID_SENSOR_CAMERA_DETECTION_CRC);
#endif
}
#endif

#endif

// MESSAGE SENSOR_CAMERA_DETECTION UNPACKING


/**
 * @brief Get field timestamp from sensor_camera_detection message
 *
 * @return [us] Timestamp of the message
 */
static inline uint64_t mavlink_msg_sensor_camera_detection_get_timestamp(const mavlink_message_t* msg)
{
    return _MAV_RETURN_uint64_t(msg,  0);
}

/**
 * @brief Get field identified_apriltag from sensor_camera_detection message
 *
 * @return  Apriltag identified
 */
static inline uint8_t mavlink_msg_sensor_camera_detection_get_identified_apriltag(const mavlink_message_t* msg)
{
    return _MAV_RETURN_uint8_t(msg,  8);
}

/**
 * @brief Decode a sensor_camera_detection message into a struct
 *
 * @param msg The message to decode
 * @param sensor_camera_detection C-struct to decode the message contents into
 */
static inline void mavlink_msg_sensor_camera_detection_decode(const mavlink_message_t* msg, mavlink_sensor_camera_detection_t* sensor_camera_detection)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    sensor_camera_detection->timestamp = mavlink_msg_sensor_camera_detection_get_timestamp(msg);
    sensor_camera_detection->identified_apriltag = mavlink_msg_sensor_camera_detection_get_identified_apriltag(msg);
#else
        uint8_t len = msg->len < MAVLINK_MSG_ID_SENSOR_CAMERA_DETECTION_LEN? msg->len : MAVLINK_MSG_ID_SENSOR_CAMERA_DETECTION_LEN;
        memset(sensor_camera_detection, 0, MAVLINK_MSG_ID_SENSOR_CAMERA_DETECTION_LEN);
    memcpy(sensor_camera_detection, _MAV_PAYLOAD(msg), len);
#endif
}
