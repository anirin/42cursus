#include "philo.h"

int	main(int argc, char *argv[])
{
	t_philo *philos;
	t_fork *forks;
	t_data data;
	t_common common_value;
	long start_time;

	if (check_error(argc, argv) == 1)
		return (1);
	data = set_data(argv);
	common_value = init_common();
	start_time = get_current_time();
	forks = init_forks(data.num_of_philos);
	philos = init_philos(data, forks, start_time, common_value);
	run_simulation(data.num_of_philos, philos);
	clean_up(philos, forks, common_value);
	return (0);
}