/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atsu <atsu@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/06 14:59:55 by atokamot          #+#    #+#             */
/*   Updated: 2024/06/17 14:34:48 by atsu             ###   ########.fr       */
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
		return (ERROR);

	data = set_data(argv);

	if (init_common(&common_value) == ERROR)
		return (ERROR);

	forks = init_forks(data.num_of_philos);
	if (!forks)
	{
		clean_up_common(&common_value);
		return (ERROR);
	}

	philos = init_philos(data, forks, &common_value);
	if (!philos)
	{
		clean_up_common(&common_value);
		clean_up_forks(forks, data.num_of_philos);
		return (ERROR);
	}

	run_simulation(data.num_of_philos, philos);

	clean_up(philos, forks, &common_value, &data);
	return (0);
}
