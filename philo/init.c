#include "philo.h"

t_setting	get_setting(char **argv)
{
	int		number;
	int		time_to_die;
	int		time_to_eat;
	int		time_to_sleep;
	int		eat_times;
	t_setting	data;

	//argvから値を取得
	number = atoi(argv[1]);
	time_to_die = atoi(argv[2]);
	time_to_eat = atoi(argv[3]);
	time_to_sleep = atoi(argv[4]);
	eat_times = atoi(argv[5]);

	//構造体に格納
	data.number = number;
	data.time_to_die = time_to_die;
	data.time_to_eat = time_to_eat;
	data.time_to_sleep = time_to_sleep;
	data.eat_times = eat_times;
	return (data);
}

pthread_mutex_t	*init_forks(int number)
{
	pthread_mutex_t	*forks;
	int				i;

	i = 0;
	forks = malloc(sizeof(pthread_mutex_t) * number);
	while (i < number)
	{
		pthread_mutex_init(&forks[i], NULL);
		i++;
	}
	return (forks);
}

t_philo	*init_philos(t_setting data, pthread_mutex_t *forks)
{
	int		i;
	t_philo	*philo;
	pthread_mutex_t print_mutex;

	i = 0;
	philo = malloc(sizeof(t_philo) * data.number);
	pthread_mutex_init(&print_mutex, NULL);
	while (i < data.number)
	{
		philo[i].index = i;
		philo[i].left_fork = &forks[i];
		philo[i].right_fork = &forks[(i + 1) % data.number];
		i++;
	}
	return (philo);
}

t_data	*integrate_data(t_setting setting, t_philo *philo, t_time *time)
{
	t_data	*data;
	int i;

	i = 0;
	data = malloc(sizeof(t_data) * setting.number);
	while (i < setting.number)
	{
		data[i].setting = setting;
		data[i].philo = philo[i];
		data[i].time = time[i];
		i++;
	}
	return (data);
}

// void print_philo(t_philo philo)
// {
// 	printf("index: %d\n", philo.index);
// 	printf("time_to_die: %d\n", philo.time_to_die);
// 	printf("time_to_eat: %d\n", philo.time_to_eat);
// 	printf("time_to_sleep: %d\n", philo.time_to_sleep);
// 	printf("eat_times: %d\n", philo.eat_times);
// 	printf("--------------------\n");
// }

// void print_philos(t_data data, t_philo *philo)
// {
// 	int i;

// 	i = 0;
// 	while (i < data.number)
// 	{
// 		print_philo(philo[i]);
// 		i++;
// 	}
// }	

// void print_data(t_data data)
// {
// 	printf("number: %d\n", data.number);
// 	printf("time_to_die: %d\n", data.time_to_die);
// 	printf("time_to_eat: %d\n", data.time_to_eat);
// 	printf("time_to_sleep: %d\n", data.time_to_sleep);
// 	printf("eat_times: %d\n", data.eat_times);
// }