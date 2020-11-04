import serial

ser = serial.Serial(
    "/dev/ttyS0",
    baudrate = 9600,
    parity=serial.PARITY_NONE,
    stopbits=serial.STOPBITS_ONE,
    bytesize=serial.EIGHTBITS,
    timeout=2)
while 1:
    rx_data=ser.readline()
    print(rx_data)