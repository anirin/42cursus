#include "philo.h"

long	get_current_time(void)
{
	struct timeval	tv;

	gettimeofday(&tv, NULL);
	return (long)(tv.tv_sec * 1000 + tv.tv_usec / 1000);
}