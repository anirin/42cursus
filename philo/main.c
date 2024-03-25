#include "philo.h"

int	main(int argc, char **argv)
{
	t_setting		setting;
	t_philo		*philos;
	pthread_t 	*philo_threads;
	pthread_mutex_t		*forks;
	t_limiter	limiter;
	t_data	*data;
	struct timeval tv;

	//error
	if (argc != 6)
	{
		printf("Error: invalid number of arguments\n");
		return (0);
	}

	//time start
	gettimeofday(&tv, NULL);

	//init
	setting = get_setting(argv);
	forks = init_forks(setting.number_of_philosophers);
	philos = init_philos_data(setting, forks, tv);
	limiter = limiter_init(setting);
	data = integrate_data(setting, philos, limiter);

	//philo lifecycle
	philo_threads = create_philos_thread(data);

	//finish
	finish_pthreads(setting.number_of_philosophers, philo_threads);
	finish_mutex(setting.number_of_philosophers, forks);

	return (0);
}
