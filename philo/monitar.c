#include "philo.h"

void self_monitar(t_data data)
{
	long current_time;

	current_time = get_current_time();
	while(1)
	{
		current_time = get_current_time();
		if (data.time.check_point >= current_time)
		{

		}

		//check mutex lock
		//status mutex lock
		if (data.philo.status = WATING)
		{
			data.time.check_point += data.setting.time_to_eat;
		}
		else if (data.philo.status = ONEFORK) //後付けでは帰れない！〜
		{
			pthread_mutex_unlock(data.philo.left_fork);
			data.time.check_point += data.setting.time_to_eat;
			data.philo.status = WATING;
		}
		usleep(100);
	}
}