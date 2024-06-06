/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atokamot <atokamot@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/06 14:59:41 by atokamot          #+#    #+#             */
/*   Updated: 2024/06/06 23:42:08 by atokamot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

t_data	set_data(char *argv[])
{
	t_data	data;

	data.num_of_philos = ft_atoi(argv[1]);
	data.time_to_die = ft_atoi(argv[2]);
	data.time_to_eat = ft_atoi(argv[3]);
	data.time_to_sleep = ft_atoi(argv[4]);
	if (argv[5])
		data.num_of_times_each_philo_must_eat = ft_atoi(argv[5]);
	else
		data.num_of_times_each_philo_must_eat = -1;
	return (data);
}

void	init_common(t_common *common)
{
	common->alive = true;
	common->full = 0;
	pthread_mutex_init(&common->print_mutex, NULL);
	pthread_mutex_init(&common->full_mutex, NULL);
	common->start_time = get_current_time();
}

t_fork	*init_forks(int num_of_philos)
{
	t_fork	*forks;
	int		i;

	forks = malloc(sizeof(t_fork) * num_of_philos);
	if (!forks)
		return (NULL);
	i = 0;
	while (i < num_of_philos)
	{
		if (pthread_mutex_init(&forks[i].mutex, NULL) != 0)
		{
			while (i > 0)
				pthread_mutex_destroy(&forks[--i].mutex);
			free(forks);
			return (NULL);
		}
		forks[i].owner = (i / 2) * 2;
		i++;
	}
	return (forks);
}

t_philo	*init_philos(t_data data, t_fork *forks, t_common *common_value)
{
	t_philo	*philos;
	int		i;

	philos = malloc(sizeof(t_philo) * data.num_of_philos);
	if (!philos)
		return (NULL);
	i = 0;
	while (i < data.num_of_philos)
	{
		philos[i].id = i;
		philos[i].left_fork = &forks[i];
		philos[i].right_fork = &forks[(i + 1) % data.num_of_philos];
		philos[i].latest_eat_time = 0;
		philos[i].data = data;
		philos[i].common = common_value;
		i++;
	}
	return (philos);
}
