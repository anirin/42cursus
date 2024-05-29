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

	pthread_create(&get_left_fork_thread, NULL, &get_left_fork, (void *)philo);
	pthread_create(&get_right_fork_thread, NULL, &get_right_fork, (void *)philo);

	pthread_join(get_left_fork_thread, NULL);
	pthread_join(get_right_fork_thread, NULL);

	// if (philo->id == 1)
	// {
	// 	printf("take fork: time %d, id:%d, check_point:%d, left owner %d, right owner %d\n",
	// 		get_current_time() - philo->start_time , philo->id, philo->check_point, philo->left_fork->owner, philo->right_fork->owner);
	// }

	currnt_time = get_current_time();
	// printf("id:%d start:%ld, current:%ld, diff:%ld\n",philo->id, philo->start_time, currnt_time, currnt_time - philo->start_time);
	if (currnt_time - philo->start_time - philo->check_point > Buffer)
	{
		philo->check_point += philo->data.time_to_eat;
	}
	else if (currnt_time - philo->start_time - philo->check_point > Buffer + philo->data.time_to_eat)
	{
		philo->check_point += philo->data.time_to_eat * 2;
	}

	// print_philo_status(philo, Fork);
}

void	eat(t_philo *philo)
{
	print_philo_status(philo, Eat);
	philo->check_point += philo->data.time_to_eat;
	philo->left_fork->status = Dirty;
	philo->right_fork->status = Dirty;
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

	while(i < 5)
	{
		get_fork(philo);
		eat(philo);
		clean_fork(philo);
		philo_sleep(philo);
		think(philo);

		i++;
	}

	return NULL;
}

void *monitor(void *arg)
{
	t_philo	*philo;
	int i;

	philo = (t_philo *)arg;

	while(1)
	{
		printf("time %d, id:%d, check_point:%d, left owner %d, right owner %d\n",
			get_current_time() - philo->start_time , philo->id, philo->check_point, philo->left_fork->owner, philo->right_fork->owner);
		usleep(1000 * 100);
	}
}

void	run_simulation(t_data data, t_philo *philos)
{
	int i;

	i = 0;
	while (i < data.num_of_philos)
	{
		pthread_create(&philos[i].routine_thread, NULL, &philo_routine, &philos[i]);
		i++;
	}

	// debug
	// pthread_t monitor_thread;
	// pthread_create(&monitor_thread, NULL, &monitor, (void *)&philos[1]);

	i = 0;
	while (i < data.num_of_philos)
	{
		pthread_join(philos[i].routine_thread, NULL);
		i++;
	}
}