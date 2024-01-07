import Mavlink_lib_vci

import socket
import struct
import time

# Define the UDP server address and port
udp_host = "127.0.0.1"  # Replace with the actual IP address
udp_port = 14550  # Choose an appropriate port

# Create a UDP socket
udp_socket = socket.socket(socket.AF_INET, socket.SOCK_DGRAM)

# Create a MAVLink instance
file = open('buf1.txt', 'rb')
mav = Mavlink_lib_vci.MAVLink(file)

try:
    while True:
        # Create a heartbeat message
        heartbeat_msg = mav.heartbeat_vci_encode(int(time.time()), Mavlink_lib_vci.DEVICE_ID_GCS)
        # Pack the message
        heartbeat_msg_packed = heartbeat_msg.pack(mav)
        print(heartbeat_msg_packed)
        # Send the message
        udp_socket.sendto(heartbeat_msg_packed, (udp_host, udp_port))
        
        time.sleep(0.2)

        # Create a vehicle_command_action message
        command_msg = mav.vehicle_command_action_encode(int(time.time()), Mavlink_lib_vci.VEHICLE_ACTION_IDLE)
        # Pack the message
        command_msg_packed = command_msg.pack(mav)
        # Send the message
        udp_socket.sendto(command_msg_packed, (udp_host, udp_port))
        
        time.sleep(0.2)
        
        # Create a vehicle_command_action message
        camera_msg = mav.sensor_camera_detection_encode(int(time.time()), Mavlink_lib_vci.CAMERA_DETECTION_APRILTAG_0)
        # Pack the message
        camera_msg_packed = camera_msg.pack(mav)
        # Send the message
        udp_socket.sendto(camera_msg_packed, (udp_host, udp_port))
        
        time.sleep(0.2)

except KeyboardInterrupt:
    # Handle Ctrl+C gracefully
    print("\nExiting the script")

finally:
    # Close the UDP socket when done
    udp_socket.close()
