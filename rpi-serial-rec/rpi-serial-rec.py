import serial
import time

# init serial
ser = serial.Serial(
    "/dev/ttyS0",
    baudrate = 9600,
    parity=serial.PARITY_NONE,
    stopbits=serial.STOPBITS_ONE,
    bytesize=serial.EIGHTBITS,
    timeout=2)

while 1:

    # read one line from serial, ultil \n (LF), from Arduino
    print(ser.readline())
    
    # add condition for Red Led
    ser.write('R'.encode('ascii'))
    
"""    
    # add condition for Yellow Led
    ser.write('R'.encode('ascii'))
"""