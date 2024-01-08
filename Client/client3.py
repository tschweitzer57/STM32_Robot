import socket
import threading
from time import sleep

# create a socket object
client = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
server_ip = "192.168.1.16"  # replace with the server's IP address
server_port = 8000  # replace with the server's port number

# establish connection with server
client.connect((server_ip, server_port))

def start_client():
    print('\n')
    print('            _     _      _          ___ _ _            _             _   ___  ')
    print(' /\   /\___| |__ (_) ___| | ___    / __\ (_) ___ _ __ | |_  /\   /\ / | / _ \ ')
    print(' \ \ / / _ \ \'_ \| |/ __| |/ _ \  / /  | | |/ _ \ \'_ \| __| \ \ / / | || | | |')
    print('  \ V /  __/ | | | | (__| |  __/ / /___| | |  __/ | | | |_   \ V /  | || |_| |')
    print('   \_/ \___|_| |_|_|\___|_|\___| \____/|_|_|\___|_| |_|\__|   \_/   |_(_)___/ ')
    print('\n\n')
    
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

start_client()
recThread.start()
sendThread.start()
