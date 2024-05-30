#include "philo.h"

long	get_current_time(void)
{
	struct timeval tv;

	gettimeofday(&tv, NULL);

	return (long)(tv.tv_sec * 1000 + tv.tv_usec / 1000);
}

void	wait_check_point(t_philo *philo)
{
	long current_time;

	while (1)
	{
		current_time = get_current_time();
		if (current_time >= philo->check_point + philo->start_time)
			break;
		usleep(1000 * 10);
	}
}