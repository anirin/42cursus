#include "philo.h"

void finish_pthreads(int number_of_philosophers, pthread_t *philo)
{
	int i;
	
	i = 0;
	while(i < number_of_philosophers)
	{
		pthread_join(philo[i], NULL);
		i++;
	}
	return ;
}

void finish_mutex(int number_of_philosophers, pthread_mutex_t *forks)
{
	int i;
	
	i = 0;
	while(i < number_of_philosophers)
	{
		pthread_mutex_destroy(&forks[i]);
		i++;
	}
	return ;
}