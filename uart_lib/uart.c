#include <stdio.h>
#include <stdlib.h>
#include <error.h>
#include <unistd.h>
#include <string.h>

#include "uartz.h"


int main(int argc, char **argv)
{
	char send_buf[256];
	char recv_buf[256];

	int ret, fd, n, is_st;

	ret = uart_open("/dev/ttyS4");
	if(ret < 0)
	{
		perror("uart_open:");
		exit(EXIT_FAILURE);
	}

	printf("UART opened.\n");

	fd = ret;

	ret = uart_set(fd, 115200);
	if(ret < 0)
	{
		perror("uart_set:");
		exit(EXIT_FAILURE);
	}

	printf("UART set.\n");

	is_st = 1;
	sprintf(send_buf, "b212 ");
	while(1)
	{
		if(is_st == 1)
		{
			ret = write(fd, send_buf, 5);
			if(ret < 0)
			{
				perror("write:");
				exit(EXIT_FAILURE);
			}
			is_st = 0;
		}
		else
		{
			ret = read(fd, recv_buf, sizeof(recv_buf));
			if(ret < 0)
			{
				perror("read:");
				exit(EXIT_FAILURE);
			}
			else
			{
				n = ret;
				ret = printf("receice %d byte(s): %s\n", n, recv_buf);
				if(ret < 0)
				{
					perror("printf:");
					exit(EXIT_FAILURE);
				}
				memset(recv_buf, 0, sizeof(recv_buf));
				is_st = 1;
			}
			printf("One loop complete.\n");
			fflush(stdout);
		}

		sleep(1);
	}


	return 0;
}
