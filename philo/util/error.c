#include "philo.h"

int check_error(int argc, char *argv[])
{
	if (argc != 5 && argc != 6)
	{
		printf("Error: Wrong number of arguments\n");
		return (1);
	}
	if (atoi(argv[1]) < 1)
	{
		printf("Error: Number of philosophers must be greater than 0\n");
		return (1);
	}
	if (atoi(argv[4]) < 1 || atoi(argv[3]) < 1 || atoi(argv[2]) < 1)
	{
		printf("Error: Time to die, eat, and sleep must be greater than 0\n");
		return (1);
	}
	if (argc == 6 && atoi(argv[5]) < 1)
	{
		printf("Error: Number of times each philosopher must eat must be greater than 0\n");
		return (1);
	}
	return (0);
}