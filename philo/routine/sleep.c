#include "philo.h"

void	philo_sleep(t_philo *philo)
{
	print_philo_status(philo, Sleep);
	usleep(1000 * philo->data.time_to_sleep);
}
