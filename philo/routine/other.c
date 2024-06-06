/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   other.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atokamot <atokamot@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/06 14:59:24 by atokamot          #+#    #+#             */
/*   Updated: 2024/06/06 15:01:32 by atokamot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	clean_fork(t_philo *philo)
{
	pthread_mutex_unlock(&philo->left_fork->mutex);
	pthread_mutex_unlock(&philo->right_fork->mutex);
	philo->left_fork->status = CLEAN;
	philo->left_fork->owner = (philo->id - 1 + philo->data.num_of_philos)
		% philo->data.num_of_philos;
	philo->right_fork->status = CLEAN;
	philo->right_fork->owner = (philo->id + 1) % philo->data.num_of_philos;
}
