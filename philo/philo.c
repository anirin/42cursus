#include "philo.h"

void print_fork_address(t_data data)
{
	printf("philo [%d] address left[%d]:%p right[%d]:%p\n", data.philo.index, data.philo.index ,data.philo.left_fork,(data.philo.index + 1) % data.setting.number, data.philo.right_fork);
}

void philo_get_forks(t_data data)
{
	pthread_mutex_lock(data.philo.left_fork);
	pthread_mutex_lock(data.philo.right_fork);
	print_fork_address(data);
	print_state(data, FORK);
}

void philo_eat(t_data data)
{
	print_state(data, EATING);
	my_usleep(data.time, data.setting.time_to_eat);
}

void philo_put_forks(t_data data)
{
	pthread_mutex_unlock(data.philo.left_fork);
	pthread_mutex_unlock(data.philo.right_fork);
}

void philo_sleep(t_data data)
{
	print_state(data, SLEEPING);
	my_usleep(data.time, data.setting.time_to_sleep);
}

void philo_think(t_data data)
{
	print_state(data, THINKING);
}

void philo_lifecycle(t_data data)
{
	int i;

	i = 0;
	while (data.setting.eat_times > i)
	{
		philo_get_forks(data);
		philo_eat(data);
		philo_put_forks(data);
		philo_sleep(data);
		philo_think(data);
		i++;
	}
}

pthread_t *create_philos_thread(t_data *data)
{
	pthread_t	*philo_thread;
	int i;

	i = 0;
	philo_thread = malloc(data[0].setting.number * sizeof(pthread_t));

	while (data[0].setting.number > i)
	{
		printf("philo [%d] is born\n", data[i].philo.index);
		pthread_create(&philo_thread[i], NULL, (void *)philo_lifecycle, &data[i]);
		i++;
	}
	return (philo_thread);
}