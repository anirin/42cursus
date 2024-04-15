#include "philo.h"

long get_current_time()
{
	struct timeval tv;

	gettimeofday(&tv, NULL);
	return (tv.tv_sec * 1000 + tv.tv_usec / 1000);
}

t_time *init_time(int number)
{
	int i;
	long current_time;
	t_time *time;

	i = 0;
	time = malloc(sizeof(t_time) * number);
	current_time = get_current_time();
	while (i < number)
	{
		time[i].start = current_time;
		time[i].current = malloc(sizeof(long));
		*time[i].current = current_time;
		i++;
	}
	return (time);
}

void my_usleep(t_time time, int u_time)
{
	long end_time;

	end_time = *time.current + u_time;
	while (*time.current <= end_time)
	{
		usleep(10);
		*time.current = get_current_time();
	}
	*time.current = end_time;
}
