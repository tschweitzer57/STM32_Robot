/** @file
 *  @brief MAVLink comm protocol generated from vci_minimal.xml
 *  @see http://mavlink.org
 */
#pragma once
#ifndef MAVLINK_VCI_MINIMAL_H
#define MAVLINK_VCI_MINIMAL_H

#ifndef MAVLINK_H
    #error Wrong include order: MAVLINK_VCI_MINIMAL.H MUST NOT BE DIRECTLY USED. Include mavlink.h from the same directory instead or set ALL AND EVERY defines from MAVLINK.H manually accordingly, including the #define MAVLINK_H call.
#endif

#define MAVLINK_VCI_MINIMAL_XML_HASH -7201431283768278570

#ifdef __cplusplus
extern "C" {
#endif

// MESSAGE LENGTHS AND CRCS

#ifndef MAVLINK_MESSAGE_LENGTHS
#define MAVLINK_MESSAGE_LENGTHS {}
#endif

#ifndef MAVLINK_MESSAGE_CRCS
#define MAVLINK_MESSAGE_CRCS {{1, 46, 9, 9, 0, 0, 0}, {2, 145, 9, 9, 0, 0, 0}, {3, 154, 9, 9, 0, 0, 0}}
#endif

#include "../protocol.h"

#define MAVLINK_ENABLED_VCI_MINIMAL

// ENUM DEFINITIONS


/** @brief These values define the type of actions for the vehicle. */
#ifndef HAVE_ENUM_VEHICLE_ACTION
#define HAVE_ENUM_VEHICLE_ACTION
typedef enum VEHICLE_ACTION
{
   VEHICLE_ACTION_STOP=0, /* The vehicle stops | */
   VEHICLE_ACTION_IDLE=1, /* The vehicle do nothing | */
   VEHICLE_ACTION_PAUSE=2, /* The vehicle temporarily stop its actions | */
   VEHICLE_ACTION_RESUME=3, /* The vehicle resume its actions if it was paused | */
   VEHICLE_ACTION_MOVE_FWD=4, /* The vehicle move forward for a certain distance | */
   VEHICLE_ACTION_MOVE_BWD=5, /* The vehicle move backward for a certain distance | */
   VEHICLE_ACTION_ROTATE_R=6, /* The vehicle rotate right of n degrees | */
   VEHICLE_ACTION_ROTATE_L=7, /* The vehicle rotate left of n degrees | */
   VEHICLE_ACTION_CIRCLE=8, /* The vehicle rotate left of n degrees | */
   VEHICLE_ACTION_SQUARE=9, /* The vehicle rotate left of n degrees | */
   VEHICLE_ACTION_ENUM_END=10, /*  | */
} VEHICLE_ACTION;
#endif

/** @brief These values define the type of apriltag detected by the camera. */
#ifndef HAVE_ENUM_CAMERA_DETECTION
#define HAVE_ENUM_CAMERA_DETECTION
typedef enum CAMERA_DETECTION
{
   CAMERA_DETECTION_APRILTAG_0=0, /* The camera detected the apriltag 0 | */
   CAMERA_DETECTION_APRILTAG_1=1, /* The camera detected the apriltag 1 | */
   CAMERA_DETECTION_APRILTAG_2=2, /* The camera detected the apriltag 2 | */
   CAMERA_DETECTION_APRILTAG_3=3, /* The camera detected the apriltag 3 | */
   CAMERA_DETECTION_APRILTAG_4=4, /* The camera detected the apriltag 4 | */
   CAMERA_DETECTION_ENUM_END=5, /*  | */
} CAMERA_DETECTION;
#endif

/** @brief These values define the id of the device. */
#ifndef HAVE_ENUM_DEVICE_ID
#define HAVE_ENUM_DEVICE_ID
typedef enum DEVICE_ID
{
   DEVICE_ID_STM32=0, /* ID of the STM32 card | */
   DEVICE_ID_RASPBERRYPI=1, /* ID of the RASPBERRYPI card | */
   DEVICE_ID_GCS=2, /* ID of the ground control station | */
   DEVICE_ID_ENUM_END=3, /*  | */
} DEVICE_ID;
#endif

// MAVLINK VERSION

#ifndef MAVLINK_VERSION
#define MAVLINK_VERSION 1
#endif

#if (MAVLINK_VERSION == 0)
#undef MAVLINK_VERSION
#define MAVLINK_VERSION 1
#endif

// MESSAGE DEFINITIONS
#include "./mavlink_msg_heartbeat_vci.h"
#include "./mavlink_msg_vehicle_command_action.h"
#include "./mavlink_msg_sensor_camera_detection.h"

// base include



#if MAVLINK_VCI_MINIMAL_XML_HASH == MAVLINK_PRIMARY_XML_HASH
# define MAVLINK_MESSAGE_INFO {MAVLINK_MESSAGE_INFO_HEARTBEAT_VCI, MAVLINK_MESSAGE_INFO_VEHICLE_COMMAND_ACTION, MAVLINK_MESSAGE_INFO_SENSOR_CAMERA_DETECTION}
# define MAVLINK_MESSAGE_NAMES {{ "HEARTBEAT_VCI", 1 }, { "SENSOR_CAMERA_DETECTION", 3 }, { "VEHICLE_COMMAND_ACTION", 2 }}
# if MAVLINK_COMMAND_24BIT
#  include "../mavlink_get_info.h"
# endif
#endif

#ifdef __cplusplus
}
#endif // __cplusplus
#endif // MAVLINK_VCI_MINIMAL_H
