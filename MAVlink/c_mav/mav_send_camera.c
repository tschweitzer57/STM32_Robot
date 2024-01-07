#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>
#include "mavlink.h"

#define SERVER_IP "127.0.0.1"
#define SERVER_PORT 8080

#define MAVLINK_MSG_HEARTBEAT_LEN (MAVLINK_MSG_ID_HEARTBEAT_VCI_LEN + MAVLINK_NUM_NON_PAYLOAD_BYTES)
#define MAVLINK_MSG_CAMERA_LEN (MAVLINK_MSG_ID_SENSOR_CAMERA_DETECTION_LEN + MAVLINK_NUM_NON_PAYLOAD_BYTES)
#define MAVLINK_MSG_COMMAND_LEN (MAVLINK_MSG_ID_VEHICLE_COMMAND_ACTION_LEN + MAVLINK_NUM_NON_PAYLOAD_BYTES)

int main() {
    int sockfd;
    struct sockaddr_in server_addr;
    
    // Create a MAVLink message buffer
    uint8_t buf[MAVLINK_MAX_PACKET_LEN];
    
    // Create a MAVLink heartbeat message
    mavlink_message_t msg;
    mavlink_heartbeat_vci_t heartbeat;
    mavlink_sensor_camera_detection_t camera;
    mavlink_vehicle_command_action_t command;
    
    // Initialize the system and component IDs
    uint8_t system_id = 1;      // Your system ID
    uint8_t component_id = 1;   // Your component ID
    uint64_t timestamp = 11234;
    uint8_t device_id = 1;
    uint8_t id_apriltag = 1;
    uint8_t vh_action = 1;

    // Create a UDP socket
    if ((sockfd = socket(AF_INET, SOCK_DGRAM, 0)) == -1) {
        perror("socket");
        exit(EXIT_FAILURE);
    }

    // Initialize server address structure
    memset(&server_addr, 0, sizeof(server_addr));
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(SERVER_PORT);
    if (inet_pton(AF_INET, SERVER_IP, &server_addr.sin_addr) <= 0) {
        perror("inet_pton");
        exit(EXIT_FAILURE);
    }

    // Data to be sent
    //Camera detection message
    mavlink_msg_sensor_camera_detection_pack(system_id, component_id, &msg, timestamp, id_apriltag);
    uint16_t len = mavlink_msg_to_send_buffer(buf, &msg);
    
    printf("MAVLink Camera Message (Raw Bytes): ");
    for (uint16_t i = 0; i < len; ++i) { //len
        printf("%02X ", buf[i]);
    }
    printf("\n");
    
    // Send data to the server
    if (sendto(sockfd, buf, len, 0, (struct sockaddr*)&server_addr, sizeof(server_addr)) == -1) {
        perror("sendto");
        exit(EXIT_FAILURE);
    }

    // Close the socket
    close(sockfd);

    return 0;
}

