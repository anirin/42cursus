/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   eat.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atsu <atsu@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/06 14:59:08 by atokamot          #+#    #+#             */
/*   Updated: 2024/06/17 11:42:29 by atsu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	eat(t_philo *philo)
{
	// philo->latest_eat_time = get_current_time() - philo->common->start_time;
	print_philo_status(philo, EAT);
	my_usleep(philo->data.time_to_eat);
	philo->latest_eat_time = get_current_time() - philo->common->start_time;
}
