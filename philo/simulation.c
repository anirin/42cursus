#include "philo.h"

void	*get_left_fork(void *arg)
{
	t_philo	*philo;

	philo = (t_philo *)arg;

	while(1)
	{
		if (philo->left_fork->owner == philo->id)
			break;
		usleep(1000 * 10);
	}

	pthread_mutex_lock(&philo->left_fork->mutex);

	return NULL;
}

void	*get_right_fork(void *arg)
{
	t_philo	*philo;

	philo = (t_philo *)arg;

	while(1)
	{
		if (philo->right_fork->owner == philo->id)
			break;
		usleep(1000 * 10);
	}
	pthread_mutex_lock(&philo->right_fork->mutex);

	return NULL;
}

void get_fork(t_philo *philo)
{
	pthread_t get_left_fork_thread;
	pthread_t get_right_fork_thread;
	long currnt_time;
	int diff;

	pthread_create(&get_left_fork_thread, NULL, &get_left_fork, (void *)philo);
	pthread_create(&get_right_fork_thread, NULL, &get_right_fork, (void *)philo);

	pthread_join(get_left_fork_thread, NULL);
	pthread_join(get_right_fork_thread, NULL);

	currnt_time = get_current_time();
	diff = currnt_time - philo->start_time - philo->check_point;


	if ((diff > Buffer) && (diff <= Buffer + philo->data.time_to_eat))
	{
		philo->check_point += philo->data.time_to_eat;
	}
	else if (diff > Buffer + philo->data.time_to_eat)
	{
		philo->check_point += philo->data.time_to_eat * 2;
	}

	print_philo_status(philo, Fork);
}

void	eat(t_philo *philo)
{
	print_philo_status(philo, Eat);
	philo->check_point += philo->data.time_to_eat;
	philo->left_fork->status = Dirty;
	philo->right_fork->status = Dirty;
	philo->latest_eat_time = philo->check_point;
}

void	clean_fork(t_philo *philo)
{
	wait_check_point(philo);
	pthread_mutex_unlock(&philo->left_fork->mutex);
	pthread_mutex_unlock(&philo->right_fork->mutex);

	philo->left_fork->status = Clean;
	philo->left_fork->owner = (philo->id - 1 + philo->data.num_of_philos) % philo->data.num_of_philos;

	philo->right_fork->status = Clean;
	philo->right_fork->owner = (philo->id + 1) % philo->data.num_of_philos;
}

void	philo_sleep(t_philo *philo)
{
	wait_check_point(philo);
	print_philo_status(philo, Sleep);
	philo->check_point += philo->data.time_to_sleep;
}

void	think(t_philo *philo)
{
	wait_check_point(philo);
	print_philo_status(philo, Think);
}

void	*philo_routine(void *arg)
{
	t_philo	*philo;
	int i;

	philo = (t_philo *)arg;

	i = 0;

	while(1)
	{
		get_fork(philo);
		eat(philo);
		clean_fork(philo);
		philo_sleep(philo);
		think(philo);
		if (*philo->alive == false || *philo->full == philo->data.num_of_philos)
			break;

		i++;

		if (philo->data.num_of_times_each_philo_must_eat == i)
		{
			pthread_mutex_lock(philo->full_mutex);
			*philo->full += 1;
			pthread_mutex_unlock(philo->full_mutex);
		}
	}

	return NULL;
}

void *monitor(void *arg)
{
	t_philo	*philo;
	int i;
	long current_time;
	int diff;

	philo = (t_philo *)arg;

	while(1)
	{
		current_time = get_current_time();
		diff = current_time - philo->start_time - philo->latest_eat_time;
		if (diff >= philo->data.time_to_die)
		{
			print_philo_status(philo, Die);
			*philo->alive = false;
			break;
		}
		if (*philo->alive == false)
			break;
		usleep(1000 * 1);
	}

	return NULL;
}

void	run_simulation(t_data data, t_philo *philos)
{
	int i;

	i = 0;
	while (i < data.num_of_philos)
	{
		pthread_create(&philos[i].routine_thread, NULL, &philo_routine, &philos[i]);
		pthread_create(&philos[i].monitor_thread, NULL, &monitor, &philos[i]);
		i++;
	}

	i = 0;
	while (i < data.num_of_philos)
	{
		pthread_join(philos[i].routine_thread, NULL);
		i++;
	}
}