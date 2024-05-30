#include "philo.h"

void	eat(t_philo *philo)
{
	print_philo_status(philo, Eat);
	philo->check_point += philo->data.time_to_eat;
	philo->left_fork->status = Dirty;
	philo->right_fork->status = Dirty;
	philo->latest_eat_time = philo->check_point;
}
