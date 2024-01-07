import serial
import time

# Define the UART port and baud rate 
uart_port = 9600

# Create a serial object
#ser = serial.Serial(uart_port, baud_rate, timeout=1)

try:
    while True:
        # Get user input to send over UART
        data_to_send = input("Enter data to send")
        
        # Send the data over UART
        #ser.write(data_to_send.encode('utf-8'))
        print(data_to_send.encode('utf-8'))
        
        # Wait for a short time to avoid overwhelming the UART
        time.sleep(0.1)
        
except KeyboardInterrupt:
    # Handle Ctrl+C gracefully
    print("\nExiting the script")

finally:
    # Close the serial connection when done
    #ser.close()
    print("end")