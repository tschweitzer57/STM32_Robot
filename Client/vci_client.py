import socket
import threading

# Initilize UDP socket
client_socket = socket.socket(socket.AF_INET, socket.SOCK_DGRAM)
host = ""
port = 12345
port2 = 9000
send_address = ('192.168.1.16', port)
rec_address = (host, port2)

def recv():
    count=0
    while True:
        try:
            data, server = client_socket.recvfrom(1024)
            print("Received from server : '{}'".format(data.decode("utf-8")))
        except Exception:
            print("\nException occured . . .\n")
            break

# recvThread create
recvThread = threading.Thread(target=recv)

# Starting message
print("\r\n - - - Vehicle Client - - -\r\n\n"
      + "List of commands: action status \r\n"
      + "Use 'end' to quit the client.\r\n"
)

# Close the socket

if __name__ == '__main__':

    recvThread.start()

    while True:
        try:
            cmd = input("")
            # move forward
            # rotate camera left
            # rotate camera right
            if cmd == 'action':
                msg = 'action requested'

            elif cmd == 'status':
                msg = 'status requested'

            elif not cmd:
                break

            elif "end" in cmd:
                print("EXITING")
                break

            else:
                print("Command not recognized \n\r")
            
            client_socket.sendto(msg.encode('utf-8'), send_address)
        
        except KeyboardInterrupt:
            print("\n Interrupted by user : EXITING\n")
            break

        finally:
            client_socket.close()