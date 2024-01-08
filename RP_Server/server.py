import socket
import serial
import Mavlink_lib_vci
import time

def run_server():
    # create a socket object
    server = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
    server_ip = "192.168.1.16"
    port = 8000

    # bind the socket to a specific address and port
    server.bind((server_ip, port))

    # listen for incoming connections
    server.listen(0)
    print(f"Listening on {server_ip}:{port}")

    # accept incoming connections
    client_socket, client_address = server.accept()
    print(f"Accepted connection from {client_address[0]}:{client_address[1]}")
    
    # Create a UART port
    baudrate = 115200
    uart_port = "/dev/ttyS0"
    ser = serial.Serial(uart_port, baudrate)
    
    # Create a MAVLink instance
    file = open('buf_server.txt', 'rb')
    mav = Mavlink_lib_vci.MAVLink(file)

    # receive data from the client
    while True:
        request = client_socket.recv(1024)
        request = request.decode("utf-8") # convert bytes to string

        # if we receive "close" from the client, then we break
        # out of the loop and close the conneciton
        if request.lower() == "close":
            # send response to the client which acknowledges that the
            # connection should be closed and break out of the loop
            client_socket.send("closed".encode("utf-8"))
            break

        elif request.lower() == "idle":
            # Send a vehicle_command_action message
            msg = mav.vehicle_command_action_encode(int(time.time()), Mavlink_lib_vci.VEHICLE_ACTION_IDLE)
            client_socket.send("robot doing nothing".encode("utf-8"))
        
        elif request.lower() == "stop":
            msg = mav.vehicle_command_action_encode(int(time.time()), Mavlink_lib_vci.VEHICLE_ACTION_STOP)
            client_socket.send("robot stopping action".encode("utf-8"))

        elif request.lower() == "pause":
            msg = mav.vehicle_command_action_encode(int(time.time()), Mavlink_lib_vci.VEHICLE_ACTION_PAUSE)
            client_socket.send("robot pausing ...".encode("utf-8"))
                
        elif request.lower() == "resume":
            msg = mav.vehicle_command_action_encode(int(time.time()), Mavlink_lib_vci.VEHICLE_ACTION_RESUME)
            client_socket.send("resume action".encode("utf-8"))
                
        elif request.lower() == "forward":
            msg = mav.vehicle_command_action_encode(int(time.time()), Mavlink_lib_vci.VEHICLE_ACTION_MOVE_FWD)
            client_socket.send("robot moving forward".encode("utf-8"))

        elif request.lower() == "backward":
            msg = mav.vehicle_command_action_encode(int(time.time()), Mavlink_lib_vci.VEHICLE_ACTION_MOVE_BWD)
            client_socket.send("robot moving backward".encode("utf-8"))

        elif request.lower() == "left":
            msg = mav.vehicle_command_action_encode(int(time.time()), Mavlink_lib_vci.VEHICLE_ACTION_ROTATE_L)
            client_socket.send("robot rotating left".encode("utf-8"))

        elif request.lower() == "right":
            msg = mav.vehicle_command_action_encode(int(time.time()), Mavlink_lib_vci.VEHICLE_ACTION_ROTATE_R)
            
            client_socket.send("robot rotating right".encode("utf-8"))
                
        elif request.lower() == "square":
            msg = mav.vehicle_command_action_encode(int(time.time()), Mavlink_lib_vci.VEHICLE_ACTION_SQUARE)
            client_socket.send("robot moving in square".encode("utf-8"))

        elif request.lower() == "circle":
            msg = mav.vehicle_command_action_encode(int(time.time()), Mavlink_lib_vci.VEHICLE_ACTION_CIRCLE)
            client_socket.send("robot moving in circle".encode("utf-8"))

        msg_packed = msg.pack(mav)
        ser.write(msg_packed)
        print(f"Received: {request}")

        # response = "accepted".encode("utf-8") # convert string to bytes
        # convert and send accept response to the client
        # client_socket.send(response)

    # close connection socket with the client
    client_socket.close()
    print("Connection to client closed")
    # close server socket
    server.close()
    ser.close()

if '__name__' == '__main__':
    run_server()