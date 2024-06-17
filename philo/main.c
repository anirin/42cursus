/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atsu <atsu@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/06 14:59:55 by atokamot          #+#    #+#             */
/*   Updated: 2024/06/17 16:09:42 by atsu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static int	init_philo_and_fork(t_data data, t_philo **philos, t_fork **forks,
		t_common *common_value)
{
	if (init_common(common_value) == ERROR)
		return (ERROR);
	*forks = init_forks(data.num_of_philos);
	if (!*forks)
	{
		clean_up_common(common_value);
		return (ERROR);
	}
	*philos = init_philos(data, *forks, common_value);
	if (!*philos)
	{
		clean_up_common(common_value);
		clean_up_forks(*forks, data.num_of_philos);
		return (ERROR);
	}
	return (OK);
}

int	main(int argc, char *argv[])
{
	t_philo		*philos;
	t_fork		*forks;
	t_data		data;
	t_common	common_value;

	philos = NULL;
	forks = NULL;
	if (check_error(argc, argv) == ERROR)
		return (ERROR);
	data = set_data(argv);
	if (init_philo_and_fork(data, &philos, &forks, &common_value) == ERROR)
		return (ERROR);
	if (run_simulation(data.num_of_philos, philos) == ERROR)
	{
		clean_up(philos, forks, &common_value, &data);
		return (ERROR);
	}
	clean_up(philos, forks, &common_value, &data);
	return (0);
}

// __attribute__((destructor))
// static void destructor() {
//     system("leaks -q philo");
// }
