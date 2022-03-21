#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <errno.h>
#include <fcntl.h>
#include <termios.h>

void uart_flush(int fd)
{
	int ret = tcflush(fd, TCIOFLUSH);
	if(ret != 0)
		perror("uart_flush:");
}

/* Set UART parameters: baudrate, raw mode, and so on. */
int uart_set(int fd, int baudrate)
{
	struct termios term;

	int ret;

	switch(baudrate)
	{
		case 9600:
			baudrate = B9600;
			break;

		case 19200:
			baudrate = B19200;
			break;
		case 38400:
			baudrate = B38400;
			break;
		case 57600:
			baudrate = B57600;
			break;
		case 115200:
			baudrate = B115200;
			break;
		default:
		   return -1;	
	}

	ret = tcgetattr(fd, &term);
	if(ret < 0)
		return ret;

	ret = cfsetispeed(&term, baudrate);
	if(ret < 0)
		return ret;

	ret = cfsetospeed(&term, baudrate);
	if(ret < 0)
		return ret;

	cfmakeraw(&term);

	term.c_cc[VTIME] = 0;
	term.c_cc[VMIN] = 1;

	ret = tcsetattr(fd, TCSANOW, &term);

	return 0;
}

/* Open UART device: ttyS*. Use ttyS0 if not specified. */
int uart_open(const char *name)
{
	if(!name)
	{
		name = "/dev/ttyS0";
	}

	return open(name, O_RDWR | O_NOCTTY);
}

void uart_close(int fd)
{
	int ret = close(fd);
	if(ret != 0)
		perror("uart_close:");
}

int uart_receive(int fd, char *rb, int count)
{
	int ret = read(fd, rb, count);
	if(ret < 0)
	{
		perror("uart_receive:");
		return -1;
	}

	return ret;
}

int uart_send(int fd, char *tb, int count)
{
	int ret = write(fd, tb, count);
	if(ret < 0)
	{
		perror("uart_send:");
		return -1;
	}

	return ret;
}





