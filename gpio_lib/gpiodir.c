#include <stdio.h>
#include <stdlib.h>
#include <getopt.h>

#include "gpioz.h"

#define _GNU_SOURCE
#include <errno.h>

extern char *program_invocation_name;

static const struct option longopts[] = 
{
	{"help", 		no_argument, 		NULL, 	'h'},
	{"version", 	no_argument, 		NULL, 	'v'},
	{"number", 		required_argument, 	NULL, 	'n'},
	{"direction",	required_argument, 	NULL,	'd'}
};

static const char *const shortopts = "+hvn:d:";

int main(int argc, char **argv)
{
	int optc,opti;
	char *gpio_num, *dir;
	
	for(;;)
	{
		optc = getopt_long(argc, argv, shortopts, longopts, &opti);
		if(optc < 0)
			break;

		switch(optc)
		{
			case 'h':
				/* TODO print help */
				return EXIT_SUCCESS;
			case 'v':
				/* TODO print version */
				return EXIT_SUCCESS;
			case 'n':
				gpio_num = optarg;
				break;
			case 'd':
				dir = optarg;
				break;
			case '?':
				printf("try %s --help\n", program_invocation_name);
			default:
				abort();
		}
	}

	argc -= optind;
	argv += optind;

	if(argc > 0)
	{
		printf("unrecongnized argument:%s\n", argv[0]);
		return -1;
	}

	gpio_set_direction(gpio_num, dir);
	printf("gpio_set_direction() end.\n");
	return 0;
}
