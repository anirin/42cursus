#include "philo.h"

void	eat(t_philo *philo)
{
	philo->latest_eat_time = get_current_time() - philo->start_time;
	print_philo_status(philo, EAT);
	philo->left_fork->status = Dirty;
	philo->right_fork->status = Dirty;
	usleep(1000 * philo->data.time_to_eat);
	philo->latest_eat_time = get_current_time() - philo->start_time;
}
