#include "philo.h"

int main(int argc, char *argv[])
{
	t_philo *philos;
	t_fork *forks;
	t_data data;

	if (argc != 5 && argc != 6)
	{
		printf("Error: Invalid number of arguments\n");
		return (1);
	}

	data = set_data(argv);

	forks = init_forks(data.num_of_philos);
	philos = init_philos(data, forks);

	run_simulation(data, philos);

	// free_forks(forks, data.num_of_philos);
	// free_philos(philos);
}