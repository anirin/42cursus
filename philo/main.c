/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atokamot <atokamot@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/06 14:59:55 by atokamot          #+#    #+#             */
/*   Updated: 2024/06/06 23:31:53 by atokamot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	main(int argc, char *argv[])
{
	t_philo		*philos;
	t_fork		*forks;
	t_data		data;
	t_common	common_value;

	if (check_error(argc, argv) == 1)
		return (1);
	data = set_data(argv);
	init_common(&common_value);
	forks = init_forks(data.num_of_philos);
	if (!forks)
		return (1);
	philos = init_philos(data, forks, &common_value);
	if (!philos)
	{
		free(forks);
		return (1);
	}
	run_simulation(data.num_of_philos, philos);
	clean_up(philos, forks, &common_value);
	return (0);
}
