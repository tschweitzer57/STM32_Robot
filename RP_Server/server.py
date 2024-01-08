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
                client_socket.send("robot doing nothing".encode("utf-8"))
        
        elif request.lower() == "stop":
                client_socket.send("robot stopping action".encode("utf-8"))

        elif request.lower() == "pause":
                client_socket.send("robot pausing ...".encode("utf-8"))
                
        elif request.lower() == "resume":
                client_socket.send("resume action".encode("utf-8"))
                
        elif request.lower() == "forward":
                client_socket.send("robot moving forward".encode("utf-8"))

        elif request.lower() == "backward":
                client_socket.send("robot moving backward".encode("utf-8"))

        elif request.lower() == "left":
                client_socket.send("robot rotating left".encode("utf-8"))

        elif request.lower() == "right":
                client_socket.send("robot rotating right".encode("utf-8"))
                
        elif request.lower() == "square":
                client_socket.send("robot moving in square".encode("utf-8"))

        elif request.lower() == "circle":
                client_socket.send("robot moving in circle".encode("utf-8"))

        print(f"Received: {request}")

        # response = "accepted".encode("utf-8") # convert string to bytes
        # convert and send accept response to the client
        # client_socket.send(response)

    # close connection socket with the client
    client_socket.close()
    print("Connection to client closed")
    # close server socket
    server.close()

if '__name__' == '__main__':
    run_server()  