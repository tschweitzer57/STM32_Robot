#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>
#include "mavlink.h"

#define SERVER_PORT 8080

#define MAVLINK_MSG_HEARTBEAT_LEN (MAVLINK_MSG_ID_HEARTBEAT_VCI_LEN + MAVLINK_NUM_NON_PAYLOAD_BYTES)

int main() {
    int sockfd;
    struct sockaddr_in server_addr, client_addr;
    socklen_t client_addr_len = sizeof(client_addr);

    // Create a UDP socket
    if ((sockfd = socket(AF_INET, SOCK_DGRAM, 0)) == -1) {
        perror("socket");
        exit(EXIT_FAILURE);
    }

    // Initialize server address structure
    memset(&server_addr, 0, sizeof(server_addr));
    server_addr.sin_family = AF_INET;
    server_addr.sin_addr.s_addr = INADDR_ANY;
    server_addr.sin_port = htons(SERVER_PORT);

    // Bind the socket to the specified port
    if (bind(sockfd, (struct sockaddr*)&server_addr, sizeof(server_addr)) == -1) {
        perror("bind");
        close(sockfd);
        exit(EXIT_FAILURE);
    }

    // Buffer to store received data
    uint8_t buf[MAVLINK_MSG_HEARTBEAT_LEN];
    mavlink_message_t msg;
    //memset(&msg, 0, sizeof(mavlink_message_t));
    mavlink_status_t status;
    mavlink_heartbeat_vci_t heartbeat;
    mavlink_sensor_camera_detection_t camera;
    mavlink_vehicle_command_action_t command;

    // Receive data from clients
    ssize_t recv_len;
    //while (1) {
    recv_len = recvfrom(sockfd, buf, sizeof(buf), 0, (struct sockaddr*)&client_addr, &client_addr_len);
    if (recv_len == -1) {
        perror("recvfrom");
        close(sockfd);
        exit(EXIT_FAILURE);
    }
    
    printf("MAVLink Message (Raw Bytes): ");
    for (uint16_t i = 0; i < sizeof(buf); ++i) { //len
        printf("%02X ", buf[i]);
    }

    //buf[recv_len] = '\0'; // Null-terminate the received data
    printf("Received data from %s:%d: %s\n", inet_ntoa(client_addr.sin_addr), ntohs(client_addr.sin_port), buf);
        
    //}
    
    // Parse the message
    for (uint16_t i = 0; i < recv_len; ++i)
    {
        if (mavlink_parse_char(MAVLINK_COMM_0, buf[i], &msg, &status))
        {
            // Message successfully parsed
            break;
        }
    }
    
    // Check if the parsed message is a heartbeat message
    if (msg.msgid == MAVLINK_MSG_ID_HEARTBEAT_VCI)
    {
        // Extract information from the heartbeat message
        mavlink_msg_heartbeat_vci_decode(&msg, &heartbeat);

        // Populate the custom structure
        printf("Timestamp: %lu\n", heartbeat.timestamp);
        printf("Device ID: %u\n", heartbeat.device_id);
    }
    else if (msg.msgid == MAVLINK_MSG_ID_VEHICLE_COMMAND_ACTION)
    {
        // Extract information from the heartbeat message
        mavlink_msg_vehicle_command_action_decode(&msg, &command);

        // Populate the custom structure
        printf("Timestamp: %lu\n", command.timestamp);
        printf("Vehicle action: %u\n", command.vehicle_action);
    }
    else if (msg.msgid == MAVLINK_MSG_ID_SENSOR_CAMERA_DETECTION)
    {
        // Extract information from the heartbeat message
        mavlink_msg_sensor_camera_detection_decode(&msg, &camera);

        // Populate the custom structure
        printf("Timestamp: %lu\n", camera.timestamp);
        printf("ID Apriltag: %u\n", camera.identified_apriltag);
    }
    else
    {
        // Handle other message types or errors
        printf("Received message is not a MAVLink heartbeat message.\n");
        printf("message id: %u\n", msg.msgid);
    }

    // Close the socket (unreachable in this example, as it's an infinite loop)
    close(sockfd);

    return 0;
}

