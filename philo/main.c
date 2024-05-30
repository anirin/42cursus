#include "philo.h"

int main(int argc, char *argv[])
{
	t_philo *philos;
	t_fork *forks;
	t_data data;
	long start_time;
	bool *alive;

	if (argc != 5 && argc != 6)
	{
		printf("Error: Invalid number of arguments\n");
		return (1);
	}

	data = set_data(argv);

	alive = init_alive();
	start_time = get_current_time();
	forks = init_forks(data.num_of_philos);
	philos = init_philos(data, forks, start_time, alive);

	run_simulation(data, philos);
}