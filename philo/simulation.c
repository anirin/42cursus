#include "philo.h"

void	get_left_fork(t_philo *philo)
{
	if (philo->left_fork->status == Clean)
	{
		pthread_mutex_lock(&philo->left_fork->mutex);
		philo->left_fork->status = Dirty;
	}
	else
	{
		philo->left_fork->requested = Request;
		while (philo->left_fork->status == Dirty)
			;
		pthread_mutex_lock(&philo->left_fork->mutex);
		philo->left_fork->status = Dirty;
	}
}

void	get_right_fork(t_philo *philo)
{
	if (philo->right_fork->status == Clean)
	{
		pthread_mutex_lock(&philo->right_fork->mutex);
		philo->right_fork->status = Dirty;
	}
	else
	{
		philo->right_fork->requested = Request;
		while (philo->right_fork->status == Dirty)
			;
		pthread_mutex_lock(&philo->right_fork->mutex);
		philo->right_fork->status = Dirty;
	}
}

void get_fork(t_philo *philo)
{
	get_left_fork(philo);
	get_right_fork(philo);
	print_philo_status(philo, Fork);
}

void	eat(t_philo *philo)
{
	print_philo_status(philo, Eat);
	philo->check_point += philo->data.time_to_eat;
}

void	philo_sleep(t_philo *philo)
{
	print_philo_status(philo, Sleep);
	philo->check_point += philo->data.time_to_sleep;
}

void	think(t_philo *philo)
{
	print_philo_status(philo, Think);
}

void	*philo_routine(void *arg)
{
	t_philo	*philo;

	philo = (t_philo *)arg;

	while(1)
	{
		get_fork(philo);
		eat(philo);
		philo_sleep(philo);
		think(philo);
	}
}

void	run_simulation(t_data data, t_philo *philos)
{
	int i;

	i = 0;
	while (i < data.num_of_philos)
	{
		pthread_create(&philos[i].thread, NULL, &philo_routine, &philos[i]);
		i++;
	}
}