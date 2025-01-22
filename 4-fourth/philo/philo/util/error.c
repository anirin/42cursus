/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atokamot <atokamot@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/06 14:59:36 by atokamot          #+#    #+#             */
/*   Updated: 2024/06/17 16:36:03 by atokamot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	check_error(int argc, char *argv[])
{
	if (argc != 5 && argc != 6)
	{
		printf("Error: Wrong number of arguments\n");
		return (ERROR);
	}
	if (ft_atoi(argv[1]) < 1)
	{
		printf("Error: Wrong number of philosophers\n");
		return (ERROR);
	}
	if (ft_atoi(argv[4]) < 1 || ft_atoi(argv[3]) < 1 || ft_atoi(argv[2]) < 1)
	{
		printf("Error: Wrong number of Time to die, eat, and sleep\n");
		return (ERROR);
	}
	if (argc == 6 && ft_atoi(argv[5]) < 1)
	{
		printf("Error: Wrong number of times \
		each philosopher must eat\n");
		return (ERROR);
	}
	return (OK);
}
