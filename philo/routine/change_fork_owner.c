/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   change_fork_owner.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atsu <atsu@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/06 14:59:24 by atokamot          #+#    #+#             */
/*   Updated: 2024/06/17 13:37:32 by atsu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	change_fork_owner(t_philo *philo)
{
	pthread_mutex_unlock(&philo->left_fork->fork_mutex);
	pthread_mutex_unlock(&philo->right_fork->fork_mutex);

	pthread_mutex_lock(&philo->left_fork->owner_mutex);
	philo->left_fork->owner = (philo->id - 1 + philo->data.num_of_philos)
		% philo->data.num_of_philos;
	pthread_mutex_unlock(&philo->left_fork->owner_mutex);

	pthread_mutex_lock(&philo->right_fork->owner_mutex);
	philo->right_fork->owner = (philo->id + 1) % philo->data.num_of_philos;
	pthread_mutex_unlock(&philo->right_fork->owner_mutex);
}
