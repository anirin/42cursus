/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_philo.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atsu <atsu@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/17 13:56:36 by atsu              #+#    #+#             */
/*   Updated: 2024/06/17 16:10:02 by atsu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

t_philo	*init_philos(t_data data, t_fork *forks, t_common *common_value)
{
	t_philo *philos;
	int i;

	philos = malloc(sizeof(t_philo) * data.num_of_philos);
	if (!philos)
		return (NULL);
	i = 0;
	while (i < data.num_of_philos)
	{
		philos[i].id = i;
		philos[i].latest_eat_time = 0;
		philos[i].left_fork = &forks[i];
		philos[i].right_fork = &forks[(i + 1) % data.num_of_philos];
		philos[i].common = common_value;
		philos[i].data = data;
		i++;
	}
	return (philos);
}
