/** @file
 *    @brief MAVLink comm protocol testsuite generated from vci_minimal.xml
 *    @see https://mavlink.io/en/
 */
#pragma once
#ifndef VCI_MINIMAL_TESTSUITE_H
#define VCI_MINIMAL_TESTSUITE_H

#ifdef __cplusplus
extern "C" {
#endif

#ifndef MAVLINK_TEST_ALL
#define MAVLINK_TEST_ALL

static void mavlink_test_vci_minimal(uint8_t, uint8_t, mavlink_message_t *last_msg);

static void mavlink_test_all(uint8_t system_id, uint8_t component_id, mavlink_message_t *last_msg)
{

    mavlink_test_vci_minimal(system_id, component_id, last_msg);
}
#endif




static void mavlink_test_heartbeat_vci(uint8_t system_id, uint8_t component_id, mavlink_message_t *last_msg)
{
#ifdef MAVLINK_STATUS_FLAG_OUT_MAVLINK1
    mavlink_status_t *status = mavlink_get_channel_status(MAVLINK_COMM_0);
        if ((status->flags & MAVLINK_STATUS_FLAG_OUT_MAVLINK1) && MAVLINK_MSG_ID_HEARTBEAT_VCI >= 256) {
            return;
        }
#endif
    mavlink_message_t msg;
        uint8_t buffer[MAVLINK_MAX_PACKET_LEN];
        uint16_t i;
    mavlink_heartbeat_vci_t packet_in = {
        93372036854775807ULL,29
    };
    mavlink_heartbeat_vci_t packet1, packet2;
        memset(&packet1, 0, sizeof(packet1));
        packet1.timestamp = packet_in.timestamp;
        packet1.device_id = packet_in.device_id;
        
        
#ifdef MAVLINK_STATUS_FLAG_OUT_MAVLINK1
        if (status->flags & MAVLINK_STATUS_FLAG_OUT_MAVLINK1) {
           // cope with extensions
           memset(MAVLINK_MSG_ID_HEARTBEAT_VCI_MIN_LEN + (char *)&packet1, 0, sizeof(packet1)-MAVLINK_MSG_ID_HEARTBEAT_VCI_MIN_LEN);
        }
#endif
        memset(&packet2, 0, sizeof(packet2));
    mavlink_msg_heartbeat_vci_encode(system_id, component_id, &msg, &packet1);
    mavlink_msg_heartbeat_vci_decode(&msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);

        memset(&packet2, 0, sizeof(packet2));
    mavlink_msg_heartbeat_vci_pack(system_id, component_id, &msg , packet1.timestamp , packet1.device_id );
    mavlink_msg_heartbeat_vci_decode(&msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);

        memset(&packet2, 0, sizeof(packet2));
    mavlink_msg_heartbeat_vci_pack_chan(system_id, component_id, MAVLINK_COMM_0, &msg , packet1.timestamp , packet1.device_id );
    mavlink_msg_heartbeat_vci_decode(&msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);

        memset(&packet2, 0, sizeof(packet2));
        mavlink_msg_to_send_buffer(buffer, &msg);
        for (i=0; i<mavlink_msg_get_send_buffer_length(&msg); i++) {
            comm_send_ch(MAVLINK_COMM_0, buffer[i]);
        }
    mavlink_msg_heartbeat_vci_decode(last_msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);
        
        memset(&packet2, 0, sizeof(packet2));
    mavlink_msg_heartbeat_vci_send(MAVLINK_COMM_1 , packet1.timestamp , packet1.device_id );
    mavlink_msg_heartbeat_vci_decode(last_msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);

#ifdef MAVLINK_HAVE_GET_MESSAGE_INFO
    MAVLINK_ASSERT(mavlink_get_message_info_by_name("HEARTBEAT_VCI") != NULL);
    MAVLINK_ASSERT(mavlink_get_message_info_by_id(MAVLINK_MSG_ID_HEARTBEAT_VCI) != NULL);
#endif
}

static void mavlink_test_vehicle_command_action(uint8_t system_id, uint8_t component_id, mavlink_message_t *last_msg)
{
#ifdef MAVLINK_STATUS_FLAG_OUT_MAVLINK1
    mavlink_status_t *status = mavlink_get_channel_status(MAVLINK_COMM_0);
        if ((status->flags & MAVLINK_STATUS_FLAG_OUT_MAVLINK1) && MAVLINK_MSG_ID_VEHICLE_COMMAND_ACTION >= 256) {
            return;
        }
#endif
    mavlink_message_t msg;
        uint8_t buffer[MAVLINK_MAX_PACKET_LEN];
        uint16_t i;
    mavlink_vehicle_command_action_t packet_in = {
        93372036854775807ULL,29
    };
    mavlink_vehicle_command_action_t packet1, packet2;
        memset(&packet1, 0, sizeof(packet1));
        packet1.timestamp = packet_in.timestamp;
        packet1.vehicle_action = packet_in.vehicle_action;
        
        
#ifdef MAVLINK_STATUS_FLAG_OUT_MAVLINK1
        if (status->flags & MAVLINK_STATUS_FLAG_OUT_MAVLINK1) {
           // cope with extensions
           memset(MAVLINK_MSG_ID_VEHICLE_COMMAND_ACTION_MIN_LEN + (char *)&packet1, 0, sizeof(packet1)-MAVLINK_MSG_ID_VEHICLE_COMMAND_ACTION_MIN_LEN);
        }
#endif
        memset(&packet2, 0, sizeof(packet2));
    mavlink_msg_vehicle_command_action_encode(system_id, component_id, &msg, &packet1);
    mavlink_msg_vehicle_command_action_decode(&msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);

        memset(&packet2, 0, sizeof(packet2));
    mavlink_msg_vehicle_command_action_pack(system_id, component_id, &msg , packet1.timestamp , packet1.vehicle_action );
    mavlink_msg_vehicle_command_action_decode(&msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);

        memset(&packet2, 0, sizeof(packet2));
    mavlink_msg_vehicle_command_action_pack_chan(system_id, component_id, MAVLINK_COMM_0, &msg , packet1.timestamp , packet1.vehicle_action );
    mavlink_msg_vehicle_command_action_decode(&msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);

        memset(&packet2, 0, sizeof(packet2));
        mavlink_msg_to_send_buffer(buffer, &msg);
        for (i=0; i<mavlink_msg_get_send_buffer_length(&msg); i++) {
            comm_send_ch(MAVLINK_COMM_0, buffer[i]);
        }
    mavlink_msg_vehicle_command_action_decode(last_msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);
        
        memset(&packet2, 0, sizeof(packet2));
    mavlink_msg_vehicle_command_action_send(MAVLINK_COMM_1 , packet1.timestamp , packet1.vehicle_action );
    mavlink_msg_vehicle_command_action_decode(last_msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);

#ifdef MAVLINK_HAVE_GET_MESSAGE_INFO
    MAVLINK_ASSERT(mavlink_get_message_info_by_name("VEHICLE_COMMAND_ACTION") != NULL);
    MAVLINK_ASSERT(mavlink_get_message_info_by_id(MAVLINK_MSG_ID_VEHICLE_COMMAND_ACTION) != NULL);
#endif
}

static void mavlink_test_sensor_camera_detection(uint8_t system_id, uint8_t component_id, mavlink_message_t *last_msg)
{
#ifdef MAVLINK_STATUS_FLAG_OUT_MAVLINK1
    mavlink_status_t *status = mavlink_get_channel_status(MAVLINK_COMM_0);
        if ((status->flags & MAVLINK_STATUS_FLAG_OUT_MAVLINK1) && MAVLINK_MSG_ID_SENSOR_CAMERA_DETECTION >= 256) {
            return;
        }
#endif
    mavlink_message_t msg;
        uint8_t buffer[MAVLINK_MAX_PACKET_LEN];
        uint16_t i;
    mavlink_sensor_camera_detection_t packet_in = {
        93372036854775807ULL,29
    };
    mavlink_sensor_camera_detection_t packet1, packet2;
        memset(&packet1, 0, sizeof(packet1));
        packet1.timestamp = packet_in.timestamp;
        packet1.identified_apriltag = packet_in.identified_apriltag;
        
        
#ifdef MAVLINK_STATUS_FLAG_OUT_MAVLINK1
        if (status->flags & MAVLINK_STATUS_FLAG_OUT_MAVLINK1) {
           // cope with extensions
           memset(MAVLINK_MSG_ID_SENSOR_CAMERA_DETECTION_MIN_LEN + (char *)&packet1, 0, sizeof(packet1)-MAVLINK_MSG_ID_SENSOR_CAMERA_DETECTION_MIN_LEN);
        }
#endif
        memset(&packet2, 0, sizeof(packet2));
    mavlink_msg_sensor_camera_detection_encode(system_id, component_id, &msg, &packet1);
    mavlink_msg_sensor_camera_detection_decode(&msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);

        memset(&packet2, 0, sizeof(packet2));
    mavlink_msg_sensor_camera_detection_pack(system_id, component_id, &msg , packet1.timestamp , packet1.identified_apriltag );
    mavlink_msg_sensor_camera_detection_decode(&msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);

        memset(&packet2, 0, sizeof(packet2));
    mavlink_msg_sensor_camera_detection_pack_chan(system_id, component_id, MAVLINK_COMM_0, &msg , packet1.timestamp , packet1.identified_apriltag );
    mavlink_msg_sensor_camera_detection_decode(&msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);

        memset(&packet2, 0, sizeof(packet2));
        mavlink_msg_to_send_buffer(buffer, &msg);
        for (i=0; i<mavlink_msg_get_send_buffer_length(&msg); i++) {
            comm_send_ch(MAVLINK_COMM_0, buffer[i]);
        }
    mavlink_msg_sensor_camera_detection_decode(last_msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);
        
        memset(&packet2, 0, sizeof(packet2));
    mavlink_msg_sensor_camera_detection_send(MAVLINK_COMM_1 , packet1.timestamp , packet1.identified_apriltag );
    mavlink_msg_sensor_camera_detection_decode(last_msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);

#ifdef MAVLINK_HAVE_GET_MESSAGE_INFO
    MAVLINK_ASSERT(mavlink_get_message_info_by_name("SENSOR_CAMERA_DETECTION") != NULL);
    MAVLINK_ASSERT(mavlink_get_message_info_by_id(MAVLINK_MSG_ID_SENSOR_CAMERA_DETECTION) != NULL);
#endif
}

static void mavlink_test_vci_minimal(uint8_t system_id, uint8_t component_id, mavlink_message_t *last_msg)
{
    mavlink_test_heartbeat_vci(system_id, component_id, last_msg);
    mavlink_test_vehicle_command_action(system_id, component_id, last_msg);
    mavlink_test_sensor_camera_detection(system_id, component_id, last_msg);
}

#ifdef __cplusplus
}
#endif // __cplusplus
#endif // VCI_MINIMAL_TESTSUITE_H
