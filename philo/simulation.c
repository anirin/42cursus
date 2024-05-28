#include "philo.h"

void *philo_routine(void *arg)
{
	t_philo *philo;

	philo = (t_philo *)arg;

	
}

void run_simulation(t_data data, t_philo *philos)
{
	int i;

	i = 0;
	while (i < data.num_of_philos)
	{
		pthread_create(&philos[i].thread, NULL, &philo_routine, &philos[i]);
		i++;
	}
}