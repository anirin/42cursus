#include "philo.h"

void	think(t_philo *philo)
{
	wait_check_point(philo);
	print_philo_status(philo, Think);
}