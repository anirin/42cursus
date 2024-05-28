#include "philo.h"

void	print_philo_status(t_philo *philo, char *status)
{
	printf("%ld %d %s", philo->check_point, philo->id, status);
}