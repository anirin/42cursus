#include "philo.h"

t_setting	get_setting(char **argv)
{
	int		number_of_philosophers;
	int		time_to_die;
	int		time_to_eat;
	int		time_to_sleep;
	int		eat_times;
	t_setting	data;

	//argvから値を取得
	number_of_philosophers = atoi(argv[1]);
	time_to_die = atoi(argv[2]);
	time_to_eat = atoi(argv[3]);
	time_to_sleep = atoi(argv[4]);
	eat_times = atoi(argv[5]);

	//構造体に格納
	data.number_of_philosophers = number_of_philosophers;
	data.time_to_die = time_to_die;
	data.time_to_eat = time_to_eat;
	data.time_to_sleep = time_to_sleep;
	data.eat_times = eat_times;
	return (data);
}

pthread_mutex_t	*init_forks(int number_of_philosophers)
{
	pthread_mutex_t	*forks;
	int				i;

	i = 0;
	forks = malloc(sizeof(pthread_mutex_t) * number_of_philosophers);
	while (i < number_of_philosophers)
	{
		pthread_mutex_init(&forks[i], NULL);
		i++;
	}
	return (forks);
}

t_philo	*init_philos_data(t_setting data, pthread_mutex_t *forks, struct timeval tv)
{
	t_philo	*philo;
	pthread_mutex_t print_mutex;
	int		i;

	i = 0;
	philo = malloc(sizeof(t_philo) * data.number_of_philosophers);
	pthread_mutex_init(&print_mutex, NULL);
	while (i < data.number_of_philosophers)
	{
		philo[i].index = i;
		philo[i].left_fork = &forks[i];
		philo[i].right_fork = &forks[(i + 1) % data.number_of_philosophers];
		philo[i].start_sec = tv.tv_sec;
		philo[i].start_usec = tv.tv_usec;
		i++;
	}
	return (philo);
}

t_limiter	limiter_init(t_setting data)
{
	t_limiter	limiter;
	pthread_mutex_t	*limites;
	int		i;
	int 	max_eat_philos;

	i = 0;
	max_eat_philos = data.number_of_philosophers - 1;
	limites = malloc(sizeof(pthread_mutex_t) * max_eat_philos);
	while (i < max_eat_philos)
	{
		pthread_mutex_init(&limites[i], NULL);
		i++;
	}
	limiter.limites = limites;
	return (limiter);
}

t_data	*integrate_data(t_setting setting, t_philo *philo, t_limiter limiter)
{
	t_data	*data;
	int i;

	i = 0;
	data = malloc(sizeof(t_data) * setting.number_of_philosophers);
	while (i < setting.number_of_philosophers)
	{
		data[i].setting = setting;
		data[i].philo = philo[i];
		data[i].limiter = limiter;
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
// 	while (i < data.number_of_philosophers)
// 	{
// 		print_philo(philo[i]);
// 		i++;
// 	}
// }	

// void print_data(t_data data)
// {
// 	printf("number_of_philosophers: %d\n", data.number_of_philosophers);
// 	printf("time_to_die: %d\n", data.time_to_die);
// 	printf("time_to_eat: %d\n", data.time_to_eat);
// 	printf("time_to_sleep: %d\n", data.time_to_sleep);
// 	printf("eat_times: %d\n", data.eat_times);
// }