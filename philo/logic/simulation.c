/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   simulation.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atokamot <atokamot@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/06 14:59:17 by atokamot          #+#    #+#             */
/*   Updated: 2024/06/06 23:27:02 by atokamot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	check_philo_is_full(t_philo *philo, int i)
{
	if (philo->data.num_of_times_each_philo_must_eat == i)
	{
		pthread_mutex_lock(&philo->common->full_mutex);
		philo->common->full += 1;
		pthread_mutex_unlock(&philo->common->full_mutex);
	}
}

void	*philo_routine(void *arg)
{
	t_philo	*philo;
	int		i;

	philo = (t_philo *)arg;
	i = 0;
	while (1)
	{
		if (philo->latest_eat_time == 0 && (philo->id % 2 == 1
				|| philo->id == philo->data.num_of_philos - 1))
			think(philo);
		if (philo->data.num_of_philos == 1)
			break ;
		get_fork(philo);
		eat(philo);
		check_philo_is_full(philo, i);
		clean_fork(philo);
		philo_sleep(philo);
		think(philo);
		if (philo->common->alive == false || philo->common->full == philo->data.num_of_philos)
			break ;
		i++;
	}
	return (NULL);
}

void	*monitor(void *arg)
{
	t_philo	*philo;
	long	current_time;
	int		diff;

	philo = (t_philo *)arg;
	while (1)
	{
		current_time = get_current_time();
		diff = current_time - philo->common->start_time - philo->latest_eat_time;
		if (diff >= philo->data.time_to_die)
		{
			print_philo_status(philo, DIE);
			philo->common->alive = false;
			break ;
		}
		if (philo->common->alive == false)
			break ;
		usleep(1000 * 1);
	}
	return (NULL);
}

void	run_simulation(int num_of_philos, t_philo *philos)
{
	int	i;

	i = 0;
	while (i < num_of_philos)
	{
		pthread_create(&philos[i].routine_thread, NULL, &philo_routine,
			&philos[i]);
		pthread_create(&philos[i].monitor_thread, NULL, &monitor, &philos[i]);
		i++;
	}
	i = 0;
	while (i < num_of_philos)
	{
		pthread_join(philos[i].routine_thread, NULL);
		i++;
	}
	i = 0;
	while (i < num_of_philos)
	{
		pthread_join(philos[i].monitor_thread, NULL);
		i++;
	}
}
