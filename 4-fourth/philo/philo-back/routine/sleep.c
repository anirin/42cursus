#include "philo.h"

void	philo_sleep(t_philo *philo)
{
	print_philo_status(philo, SLEEP);
	usleep(1000 * philo->data.time_to_sleep);
}
