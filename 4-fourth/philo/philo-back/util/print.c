#include "philo.h"

void	print_philo_status(t_philo *philo, char *status)
{
	int diff;

	if (*philo->alive == false || *philo->full == philo->data.num_of_philos)
		return ;
	diff = get_current_time() - philo->start_time;
	pthread_mutex_lock(philo->print_mutex);
	printf("%d %d %s", diff, philo->id, status);
	pthread_mutex_unlock(philo->print_mutex);
}