import Mavlink_lib_vci

import socket
import struct

# Define the UDP server address and port
udp_host = "127.0.0.1"  # Replace with the actual IP address
udp_port = 14550  # Choose the same port as in the sender script

# Create a UDP socket
udp_socket = socket.socket(socket.AF_INET, socket.SOCK_DGRAM)
udp_socket.bind((udp_host, udp_port))

# Create a MAVLink instance
file = open('buf2.txt', 'rb')
mav = Mavlink_lib_vci.MAVLink(file)

try:
    while True:
        # Receive data from the UDP socket
        data, addr = udp_socket.recvfrom(1024)

        # Unpack the received binary data into a MAVLink message
        msg = mav.parse_buffer(data)
        msg = msg[0]
        
        if msg.id == Mavlink_lib_vci.MAVLINK_MSG_ID_HEARTBEAT_VCI :
            print('----- Heartbeat Message -----')
            print(f'Data:\tTimestamp: {msg.timestamp}\tDevice: {msg.device_id}')
            print('\n')
        elif msg.id == Mavlink_lib_vci.MAVLINK_MSG_ID_VEHICLE_COMMAND_ACTION :
            print('----- Heartbeat Message -----')
            print(f'Data:\tTimestamp: {msg.timestamp}\tAction:{msg.vehicle_action}')
            print('\n')
        elif msg.id == Mavlink_lib_vci.MAVLINK_MSG_ID_SENSOR_CAMERA_DETECTION :
            print('----- Heartbeat Message -----')
            print(f'Data:\tTimestamp: {msg.timestamp}\tApriltag:{msg.identified_apriltag}')
            print('\n')
        else :
            print('----- Unknown Message -----')
            print('\n')

except KeyboardInterrupt:
    # Handle Ctrl+C gracefully
    print("\nExiting the script")

finally:
    # Close the UDP socket when done
    udp_socket.close()