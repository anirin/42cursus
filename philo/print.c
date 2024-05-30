#include "philo.h"

void	print_philo_status(t_philo *philo, char *status)
{
	if (*philo->alive == false || *philo->full == philo->data.num_of_philos)
		return ;
	if (strcmp(status, Die) == 0)
	{
		philo->check_point += philo->data.time_to_die;
	}

	pthread_mutex_lock(philo->print_mutex);
	printf("%d %d %s", philo->check_point, philo->id, status);
	pthread_mutex_unlock(philo->print_mutex);
}