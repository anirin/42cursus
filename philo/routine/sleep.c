#include "philo.h"

void	philo_sleep(t_philo *philo)
{
	wait_check_point(philo);
	print_philo_status(philo, Sleep);
	philo->check_point += philo->data.time_to_sleep;
}
