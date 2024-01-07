import Mavlink_py

import socket
import struct

# Define the UDP server address and port
udp_host = "127.0.0.1"  # Replace with the actual IP address
udp_port = 14550  # Choose the same port as in the sender script

# Create a UDP socket
udp_socket = socket.socket(socket.AF_INET, socket.SOCK_DGRAM)
udp_socket.bind((udp_host, udp_port))

# Create a MAVLink instance
file = open('test.txt', 'rb')
mav = Mavlink_py.MAVLink(file)

try:
    while True:
        # Receive data from the UDP socket
        data, addr = udp_socket.recvfrom(1024)
        print(data)

        # Unpack the received binary data into a MAVLink message
        imu_msg = mav.parse_buffer(data)
        print(imu_msg[0].msgname)
        print(imu_msg[0].zacc)
        print("\n")

        #if imu_msg:
            # Decode and print the IMU message
            #timestamp, accel_x, accel_y, accel_z, gyro_x, gyro_y, gyro_z = mav.decode(imu_msg)
            #print(f"Timestamp: {timestamp}, Accelerometer: ({accel_x}, {accel_y}, {accel_z}), Gyroscope: ({gyro_x}, {gyro_y}, {gyro_z})")

except KeyboardInterrupt:
    # Handle Ctrl+C gracefully
    print("\nExiting the script")

finally:
    # Close the UDP socket when done
    udp_socket.close()