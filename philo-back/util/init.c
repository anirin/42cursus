#include "philo.h"

t_data	set_data(char *argv[])
{
	t_data	data;

	data.num_of_philos = atoi(argv[1]);
	data.time_to_die = atoi(argv[2]);
	data.time_to_eat = atoi(argv[3]);
	data.time_to_sleep = atoi(argv[4]);
	if (argv[5])
		data.num_of_times_each_philo_must_eat = atoi(argv[5]);
	else
		data.num_of_times_each_philo_must_eat = -1;
	return (data);
}

t_common	init_common(void)
{
	t_common	common;

	common.alive = malloc(sizeof(bool));
	*common.alive = true;
	common.full = malloc(sizeof(int));
	*common.full = 0;
	common.full_mutex = malloc(sizeof(pthread_mutex_t));
	common.print_mutex = malloc(sizeof(pthread_mutex_t));
	pthread_mutex_init(common.print_mutex, NULL);
	pthread_mutex_init(common.full_mutex, NULL);
	return (common);
}

t_fork	*init_forks(int num_of_philos)
{
	t_fork	*forks;
	int		i;

	forks = malloc(sizeof(t_fork) * num_of_philos);
	if (!forks)
		return (NULL);
	i = 0;
	while (i < num_of_philos)
	{
		pthread_mutex_init(&forks[i].mutex, NULL);
		forks[i].status = Clean;
		forks[i].owner = (i / 2) * 2;
		i++;
	}
	return (forks);
}

t_philo	*init_philos(t_data data, t_fork *forks, long start_time,
		t_common common_value)
{
	t_philo *philos;
	int i;

	philos = malloc(sizeof(t_philo) * data.num_of_philos);
	if (!philos)
		return (NULL);
	i = 0;
	while (i < data.num_of_philos)
	{
		philos[i].id = i;
		philos[i].left_fork = &forks[i];
		philos[i].right_fork = &forks[(i + 1) % data.num_of_philos];
		// philos[i].check_point = 0;
		philos[i].start_time = start_time;
		philos[i].latest_eat_time = 0;
		philos[i].data = data;
		philos[i].alive = common_value.alive;
		philos[i].full = common_value.full;
		philos[i].print_mutex = common_value.print_mutex;
		philos[i].full_mutex = common_value.full_mutex;
		i++;
	}
	return (philos);
}