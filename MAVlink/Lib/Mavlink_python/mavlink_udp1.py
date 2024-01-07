import Mavlink_py

import socket
import struct
import time

# Define the UDP server address and port
udp_host = "127.0.0.1"  # Replace with the actual IP address
udp_port = 14550  # Choose an appropriate port

# Create a UDP socket
udp_socket = socket.socket(socket.AF_INET, socket.SOCK_DGRAM)

# Create a MAVLink instance
file = open('test.txt', 'rb')
mav = Mavlink_py.MAVLink(file)

try:
    while True:
        # Create an IMU message
        imu_msg = mav.raw_imu_encode(
            1250,    # Timestamp
            1,             # Accelerometer X
            2,             # Accelerometer Y
            3,             # Accelerometer Z
            0,             # Gyroscope X
            0,             # Gyroscope Y
            0,             # Gyroscope Z
            2,
            8,
            0,
            5,
            8
        )

        # Pack the message
        imu_msg_packed = imu_msg.pack(mav)
        print(imu_msg_packed)
        # Send the IMU message over UDP
        udp_socket.sendto(imu_msg_packed, (udp_host, udp_port))
        print("sended")

        # Wait for a short time (adjust as needed)
        time.sleep(1)

except KeyboardInterrupt:
    # Handle Ctrl+C gracefully
    print("\nExiting the script")

finally:
    # Close the UDP socket when done
    udp_socket.close()