/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atokamot <atokamot@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/06 14:59:46 by atokamot          #+#    #+#             */
/*   Updated: 2024/06/06 23:21:47 by atokamot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	print_philo_status(t_philo *philo, char *status)
{
	int	diff;

	if (philo->common->alive == false || philo->common->full == philo->data.num_of_philos)
		return ;
	diff = get_current_time() - philo->common->start_time;
	pthread_mutex_lock(&philo->common->print_mutex);
	printf("%d %d %s", diff, philo->id, status);
	pthread_mutex_unlock(&philo->common->print_mutex);
}
