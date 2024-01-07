import serial
import Mavlink_lib_vci
import time

# Define the UART port attributes
baudrate = 115200
uart_port = "/dev/ttyS0"

# Create a UART port
ser = serial.Serial(uart_port, baudrate)

# Create a MAVLink instance
file = open('buf_camera.txt', 'rb')
mav = Mavlink_lib_vci.MAVLink(file)

try:
    while True:
        # Create a heartbeat message
        heartbeat_msg = mav.heartbeat_vci_encode(int(time.time()), Mavlink_lib_vci.DEVICE_ID_GCS)
        # Pack the message
        heartbeat_msg_packed = heartbeat_msg.pack(mav)
        # Send the message
        ser.write(heartbeat_msg_packed.encode('utf-8'))
        
        time.sleep(2)

        # Create a vehicle_command_action message
        command_msg = mav.vehicle_command_action_encode(int(time.time()), Mavlink_lib_vci.VEHICLE_ACTION_IDLE)
        # Pack the message
        command_msg_packed = command_msg.pack(mav)
        # Send the message
        ser.write(command_msg_packed.encode('utf-8'))
        
        time.sleep(2)
        
        # Create a vehicle_command_action message
        camera_msg = mav.sensor_camera_detection_encode(int(time.time()), Mavlink_lib_vci.CAMERA_DETECTION_APRILTAG_0)
        # Pack the message
        camera_msg_packed = camera_msg.pack(mav)
        # Send the message
        ser.write(camera_msg_packed.encode('utf-8'))
        
        time.sleep(2)

except KeyboardInterrupt:
    # Handle Ctrl+C gracefully
    print("\nExiting the script")

finally:
    # Close the UDP socket when done
    ser.close()