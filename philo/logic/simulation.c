/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   simulation.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atokamot <atokamot@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/17 16:16:04 by atokamot          #+#    #+#             */
/*   Updated: 2024/06/17 16:16:46 by atokamot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static void	count_num_of_full_philo(t_philo *philo, int i)
{
	if (philo->data.num_of_times_each_philo_must_eat == i)
	{
		pthread_mutex_lock(&philo->common->full_mutex);
		philo->common->full++;
		pthread_mutex_unlock(&philo->common->full_mutex);
	}
}

static void	*philo_routine(void *arg)
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
		count_num_of_full_philo(philo, i);
		change_fork_owner(philo);
		philo_sleep(philo);
		think(philo);
		if (philo->common->alive == false
			|| philo->common->full == philo->data.num_of_philos)
			break ;
		i++;
	}
	return (NULL);
}

int	run_simulation(int num_of_philos, t_philo *philos)
{
	int	i;
	int	err;

	i = 0;
	while (i < num_of_philos)
	{
		err = pthread_create(&philos[i].routine_thread, NULL, &philo_routine,
				&philos[i]);
		if (err != 0)
		{
			while (i > 0)
				pthread_join(philos[--i].routine_thread, NULL);
			return (ERROR);
		}
		i++;
	}
	monitor(philos);
	i = 0;
	while (i < num_of_philos)
	{
		pthread_join(philos[i].routine_thread, NULL);
		i++;
	}
	return (OK);
}
