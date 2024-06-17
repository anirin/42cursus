/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   simulation.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atsu <atsu@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/06 14:59:17 by atokamot          #+#    #+#             */
/*   Updated: 2024/06/08 04:13:03by atsu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static void	check_philo_is_full(t_philo *philo, int i)
{
	if (philo->data.num_of_times_each_philo_must_eat == i)
	{
		pthread_mutex_lock(&philo->common->full_mutex);
		philo->common->full += 1;
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
		check_philo_is_full(philo, i);
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

void	run_simulation(int num_of_philos, t_philo *philos)
{
	int	i;

	i = 0;
	while (i < num_of_philos)
	{
		pthread_create(&philos[i].routine_thread, NULL, &philo_routine,
				&philos[i]);
		i++;
	}
	monitor(philos);
	i = 0;
	while (i < num_of_philos)
	{
		pthread_join(philos[i].routine_thread, NULL);
		i++;
	}
}
