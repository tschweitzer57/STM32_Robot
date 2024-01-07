#include "mavlink.h"

int main() {
    // Create a MAVLink message buffer
    uint8_t buf[MAVLINK_MSG_ID_HEARTBEAT_VCI_LEN];

    // Initialize the system and component IDs
    uint8_t system_id = 1;      // Your system ID
    uint8_t component_id = 1;   // Your component ID
    uint64_t timestamp = 11234;
    uint8_t device_id = 1;

    // Create a MAVLink heartbeat message
    mavlink_message_t msg;
    mavlink_heartbeat_vci_t heartbeat;
    mavlink_msg_heartbeat_vci_pack(system_id, component_id, &msg, timestamp, device_id);

    // Copy the message to the buffer
    uint16_t len = mavlink_msg_to_send_buffer(buf, &msg);

    // TODO: Send the buffer over your communication channel (e.g., UART, UDP, etc.)

    // For demonstration purposes, let's print the raw bytes of the message
    printf("MAVLink Heartbeat Message (Raw Bytes): ");
    for (uint16_t i = 0; i < len; ++i) { //len
        printf("%02X ", buf[i]);
    }
    printf("\n");
    
    // Replace 'received_buf' with the actual buffer received over the communication channel
    //uint8_t received_buf[MAVLINK_MAX_PACKET_LEN];
    mavlink_message_t rec_msg;
    memset(&rec_msg, 0, sizeof(mavlink_message_t));
    mavlink_status_t status;
    
    // Parse the message
    for (uint16_t i = 0; i < len; ++i)
    {
        if (mavlink_parse_char(MAVLINK_COMM_0, buf[i], &rec_msg, &status))
        {
            // Message successfully parsed
            break;
        }
    }
    
    // Check if the parsed message is a heartbeat message
    if (rec_msg.msgid == MAVLINK_MSG_ID_HEARTBEAT_VCI)
    {
        // Extract information from the heartbeat message
        mavlink_msg_heartbeat_vci_decode(&rec_msg, &heartbeat);

        // Populate the custom structure
        printf("Timestamp: %lu\n", heartbeat.timestamp);
        printf("Device ID: %u\n", heartbeat.device_id);
    }
    else
    {
        // Handle other message types or errors
        printf("Received message is not a MAVLink heartbeat message.\n");
        printf("message id: %u\n", rec_msg.msgid);
        printf("message id: %u\n", msg.msgid);
    }

    // Create an instance of the MAVLink heartbeat structure
    

    // Decode the MAVLink heartbeat message

    // Now, 'heartbeat' structure contains the decoded information

    // Example: Print the decoded information
    
    return 0;
}
