/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_fork.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atokamot <atokamot@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/06 14:59:20 by atokamot          #+#    #+#             */
/*   Updated: 2024/06/06 23:29:44 by atokamot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	*get_left_fork(void *arg)
{
	t_philo	*philo;

	philo = (t_philo *)arg;
	while (1)
	{
		if (philo->left_fork->owner == philo->id)
			break ;
		if (philo->common->alive == false)
			return (NULL);
		usleep(1000 * 1);
	}
	pthread_mutex_lock(&philo->left_fork->mutex);
	return (NULL);
}

void	*get_right_fork(void *arg)
{
	t_philo	*philo;

	philo = (t_philo *)arg;
	while (1)
	{
		if (philo->right_fork->owner == philo->id)
			break ;
		if (philo->common->alive == false)
			return (NULL);
		usleep(1000 * 1);
	}
	pthread_mutex_lock(&philo->right_fork->mutex);
	return (NULL);
}

void	get_fork(t_philo *philo)
{
	pthread_t	get_left_fork_thread;
	pthread_t	get_right_fork_thread;

	pthread_create(&get_left_fork_thread, NULL, &get_left_fork, (void *)philo);
	pthread_create(&get_right_fork_thread, NULL, &get_right_fork,
		(void *)philo);
	pthread_join(get_left_fork_thread, NULL);
	pthread_join(get_right_fork_thread, NULL);
	print_philo_status(philo, FORK);
}
