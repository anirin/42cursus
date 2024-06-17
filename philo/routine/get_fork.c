/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_fork.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atsu <atsu@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/06 14:59:20 by atokamot          #+#    #+#             */
/*   Updated: 2024/06/17 16:11:02 by atsu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static void	*get_left_fork(void *arg)
{
	t_philo	*philo;

	philo = (t_philo *)arg;
	while (1)
	{
		pthread_mutex_lock(&philo->left_fork->owner_mutex);
		if (philo->left_fork->owner == philo->id)
		{
			pthread_mutex_unlock(&philo->left_fork->owner_mutex);
			break ;
		}
		pthread_mutex_unlock(&philo->left_fork->owner_mutex);
		if (philo->common->alive == false)
			return (NULL);
		usleep(500 * 1);
	}
	pthread_mutex_lock(&philo->left_fork->fork_mutex);
	print_philo_status(philo, FORK);
	return (NULL);
}

static void	*get_right_fork(void *arg)
{
	t_philo	*philo;

	philo = (t_philo *)arg;
	while (1)
	{
		pthread_mutex_lock(&philo->right_fork->owner_mutex);
		if (philo->right_fork->owner == philo->id)
		{
			pthread_mutex_unlock(&philo->right_fork->owner_mutex);
			break ;
		}
		pthread_mutex_unlock(&philo->right_fork->owner_mutex);
		if (philo->common->alive == false)
			return (NULL);
		usleep(500 * 1);
	}
	pthread_mutex_lock(&philo->right_fork->fork_mutex);
	print_philo_status(philo, FORK);
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
}
