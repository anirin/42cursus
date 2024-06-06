/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atokamot <atokamot@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/06 14:59:46 by atokamot          #+#    #+#             */
/*   Updated: 2024/06/06 15:04:53 by atokamot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	print_philo_status(t_philo *philo, char *status)
{
	int	diff;

	if (*philo->alive == false || *philo->full == philo->data.num_of_philos)
		return ;
	diff = get_current_time() - philo->start_time;
	pthread_mutex_lock(philo->print_mutex);
	printf("%d %d %s", diff, philo->id, status);
	pthread_mutex_unlock(philo->print_mutex);
}
