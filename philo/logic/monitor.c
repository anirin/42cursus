/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   monitor.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atsu <atsu@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/17 13:59:01 by atsu              #+#    #+#             */
/*   Updated: 2024/06/17 13:59:06 by atsu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	monitor(t_philo *philos)
{
	t_philo	philo;
	long	current_time;
	int		diff;
	int		i;

	while (1)
	{
		i = 0;
		current_time = get_current_time();
		while (i < philos[0].data.num_of_philos)
		{
			philo = philos[i];
			diff = current_time - philo.common->start_time
				- philo.latest_eat_time;
			//mutex
			if (diff >= philo.data.time_to_die)
			{
				print_philo_status(&philo, DIE);
				philo.common->alive = false;
				break ;
			}
			i++;
		}
		//条件要検討
		if (philo.common->alive == false
			|| philo.common->full == philo.data.num_of_philos)
			break ;
		usleep(1000 * 1);
	}
}
