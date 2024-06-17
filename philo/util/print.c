/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atokamot <atokamot@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/06 14:59:46 by atokamot          #+#    #+#             */
/*   Updated: 2024/06/17 16:54:16 by atokamot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	print_philo_status(t_philo *philo, char *status)
{
	int	diff;

	pthread_mutex_lock(&philo->common->dead_mutex);
	pthread_mutex_lock(&philo->common->full_mutex);
	if (philo->common->alive == false
		|| philo->common->full == philo->data.num_of_philos)
	{
		pthread_mutex_unlock(&philo->common->dead_mutex);
		pthread_mutex_unlock(&philo->common->full_mutex);
		return ;
	}
	pthread_mutex_unlock(&philo->common->dead_mutex);
	pthread_mutex_unlock(&philo->common->full_mutex);
	diff = get_current_time() - philo->common->start_time;
	pthread_mutex_lock(&philo->common->print_mutex);
	printf("%d %d %s", diff, philo->id + 1, status);
	pthread_mutex_unlock(&philo->common->print_mutex);
}
