/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_common.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atsu <atsu@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/17 13:55:31 by atsu              #+#    #+#             */
/*   Updated: 2024/06/17 14:21:14 by atsu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int		init_common(t_common *common)
{
	int err;

	common->alive = true;
	common->full = 0;
	err = pthread_mutex_init(&common->print_mutex, NULL);
	if (err)
		return ERROR;
	err = pthread_mutex_init(&common->full_mutex, NULL);
	if (err)
	{
		pthread_mutex_destroy(&common->print_mutex);
		return ERROR;
	}
	err = pthread_mutex_init(&common->dead_mutex, NULL);
	if (err)
	{
		pthread_mutex_destroy(&common->print_mutex);
		pthread_mutex_destroy(&common->full_mutex);
		return ERROR;
	}
	common->start_time = get_current_time();
	return OK;
}
