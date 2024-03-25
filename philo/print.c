#include "philo.h"

void philo_print(t_philo philo, char *str)
{
	struct timeval tv;
	long diff_time;

	gettimeofday(&tv, NULL);
	diff_time = (tv.tv_sec - philo.start_sec) * 1000 + (tv.tv_usec - philo.start_usec) / 1000;
	printf("%d philo[%d] %s\n", diff_time, philo.index, str);
}