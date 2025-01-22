/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   monitor.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atokamot <atokamot@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/17 13:59:01 by atsu              #+#    #+#             */
/*   Updated: 2024/06/17 17:34:36 by atokamot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static int	is_dead(t_philo philo, long current_time)
{
	int	diff;

	diff = current_time - philo.latest_eat_time - philo.common->start_time;
	if (diff >= philo.data.time_to_die)
	{
		pthread_mutex_lock(&philo.common->dead_mutex);
		print_philo_died(&philo, DIE);
		philo.common->alive = false;
		pthread_mutex_unlock(&philo.common->dead_mutex);
		return (true);
	}
	return (false);
}

static int	is_simulation_end(t_philo philo)
{
	pthread_mutex_lock(&philo.common->dead_mutex);
	pthread_mutex_lock(&philo.common->full_mutex);
	if (philo.common->alive == false
		|| philo.common->full == philo.data.num_of_philos)
	{
		pthread_mutex_unlock(&philo.common->dead_mutex);
		pthread_mutex_unlock(&philo.common->full_mutex);
		return (true);
	}
	pthread_mutex_unlock(&philo.common->dead_mutex);
	pthread_mutex_unlock(&philo.common->full_mutex);
	return (false);
}

void	monitor(t_philo *philos)
{
	int		i;
	long	current_time;

	while (1)
	{
		i = 0;
		current_time = get_current_time();
		while (i < philos[0].data.num_of_philos)
		{
			if (is_dead(philos[i], current_time) == true)
				break ;
			i++;
		}
		if (is_simulation_end(philos[0]) == true)
			break ;
		usleep(100 * 1);
	}
}
