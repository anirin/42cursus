#include "philo.h"

void	clean_fork(t_philo *philo)
{
	pthread_mutex_unlock(&philo->left_fork->mutex);
	pthread_mutex_unlock(&philo->right_fork->mutex);
	philo->left_fork->status = Clean;
	philo->left_fork->owner = (philo->id - 1 + philo->data.num_of_philos)
		% philo->data.num_of_philos;
	philo->right_fork->status = Clean;
	philo->right_fork->owner = (philo->id + 1) % philo->data.num_of_philos;
}
