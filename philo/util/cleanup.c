/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cleanup.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atokamot <atokamot@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/06 14:59:34 by atokamot          #+#    #+#             */
/*   Updated: 2024/06/17 16:17:21 by atokamot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	clean_up_common(t_common *common)
{
	pthread_mutex_destroy(&common->print_mutex);
	pthread_mutex_destroy(&common->full_mutex);
	pthread_mutex_destroy(&common->dead_mutex);
}

void	clean_up_forks(t_fork *forks, int num_of_philos)
{
	int	i;

	i = 0;
	while (i < num_of_philos)
	{
		pthread_mutex_destroy(&forks[i].fork_mutex);
		pthread_mutex_destroy(&forks[i].owner_mutex);
		i++;
	}
	free(forks);
}

void	clean_up(t_philo *philos, t_fork *forks, t_common *common, t_data *data)
{
	free(philos);
	clean_up_forks(forks, data->num_of_philos);
	clean_up_common(common);
}
