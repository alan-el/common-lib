CC = arm-linux-gnueabihf-gcc

CFLAGS = -Wall

libuartz.so: uartz.c uartz.h
	$(CC) $(CFLAGS) -shared uartz.c -o libuartz.so 

uart: uart.c libuartz.so
	$(CC) $(CFLAGS) uart.c -luartz -L. -o uart
