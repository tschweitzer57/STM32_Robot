import socket
import threading
from time import sleep

# create a socket object
client = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
server_ip = "192.168.1.16"  # replace with the server's IP address
server_port = 8000  # replace with the server's port number

# establish connection with server
client.connect((server_ip, server_port))


def send_client():
    
    while True:
        # input message and send it to the server
        msg = input("Enter message: ")
        client.send(msg.encode("utf-8")[:1024])

        sleep(0.3)

        # if server sent us "closed" in the payload, we break out of the loop and close our socket
        if msg == "close":
            break

    # close client socket (connection to the server)
    print("Closing server connection ...")

def rec_client():

    while True:
        # receive message from the server
        response = client.recv(1024)
        response = response.decode("utf-8")

        # if server sent us "closed" in the payload, we break out of the loop and close our socket
        if response.lower() == "closed":
            break

        print(f"Received: {response}")

    # close client socket (connection to the server)
    client.close()
    print("Connection to server closed")

# recvThread create
recThread = threading.Thread(target=rec_client)
sendThread = threading.Thread(target=send_client)

recThread.start()
sendThread.start()
