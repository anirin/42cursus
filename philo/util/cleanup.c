/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cleanup.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atokamot <atokamot@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/06 14:59:34 by atokamot          #+#    #+#             */
/*   Updated: 2024/06/06 23:18:36 by atokamot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	clean_up(t_philo *philos, t_fork *forks, t_common *common)
{
	int	i;

	i = 0;
	while (i < philos->data.num_of_philos)
	{
		pthread_mutex_destroy(&forks[i].mutex);
		i++;
	}
	free(forks);
	free(philos);
	pthread_mutex_destroy(&common->print_mutex);
	pthread_mutex_destroy(&common->full_mutex);
}
