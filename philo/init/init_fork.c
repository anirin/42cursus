/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_fork.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atsu <atsu@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/17 13:45:50 by atsu              #+#    #+#             */
/*   Updated: 2024/06/17 16:09:54 by atsu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static void	*clean_up_fork(t_fork *forks, int i)
{
	while (i > 0)
	{
		pthread_mutex_destroy(&forks[--i].fork_mutex);
		pthread_mutex_destroy(&forks[--i].owner_mutex);
	}
	free(forks);
	return (NULL);
}

t_fork	*init_forks(int num_of_philos)
{
	t_fork *forks;
	int i;
	int err;

	forks = malloc(sizeof(t_fork) * num_of_philos);
	if (!forks)
		return (NULL);
	i = 0;
	while (i < num_of_philos)
	{
		forks[i].owner = (i / 2) * 2;
		err = pthread_mutex_init(&forks[i].fork_mutex, NULL);
		if (err != 0)
			return (clean_up_fork(forks, i));
		err = pthread_mutex_init(&forks[i].owner_mutex, NULL);
		if (err != 0)
		{
			pthread_mutex_destroy(&forks[i].fork_mutex);
			return (clean_up_fork(forks, i));
		}
		i++;
	}
	return (forks);
}