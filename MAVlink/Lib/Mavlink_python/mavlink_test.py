#from Mavlink_py import *
import Mavlink_py
import serial
import time

# Define the UART port and baud rate
uart_port = "/dev/serial0"  # Raspberry Pi 0 UART port
baud_rate = 57600  # Adjust this based on your MAVLink configuration

# Create a serial object
#ser = serial.Serial(uart_port, baud_rate, timeout=1)

# Create a MAVLink instance
file = open('test.txt', 'rb')
mav = Mavlink_py.MAVLink(file)

try:
    while True:
        # Create a heartbeat message
        heartbeat_msg = mav.heartbeat_encode(
            Mavlink_py.MAV_TYPE_GCS,  # Ground Control Station
            Mavlink_py.MAV_AUTOPILOT_INVALID,
            0, 0, 0, 0)
        raw_imu_msg = mav.raw_imu_encode(10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10)

        # Send the heartbeat message over UART
        #ser.write(heartbeat_msg.get_msgbuf())
        print(heartbeat_msg.get_msgbuf())
        print(raw_imu_msg.get_header())

        # Wait for a short time (adjust as needed)
        time.sleep(1)

except KeyboardInterrupt:
    # Handle Ctrl+C gracefully
    print("\nExiting the script")

finally:
    print("ended")
    # Close the serial connection when done
    #ser.close()
