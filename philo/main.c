#include "philo.h"

int	main(int argc, char **argv)
{
	t_setting		setting;
	t_philo		*philos;
	pthread_t 	*philo_threads;
	pthread_mutex_t		*forks;
	t_data	*data;
	t_time *times;
	struct timeval tv;

	//error
	if (argc != 6)
	{
		printf("Error: invalid number of arguments\n");
		return (0);
	}

	//init
	setting = get_setting(argv);
	forks = init_forks(setting.number);
	philos = init_philos(setting, forks);
	times = init_time(setting.number);
	data = integrate_data(setting, philos, times);

	//philo lifecycle
	philo_threads = create_philos_thread(data);

	//finish
	//動的に確保したスレッドの処理が必要
	finish_pthreads(setting.number, philo_threads);
	finish_mutex(setting.number, forks);

	return (0);
}
