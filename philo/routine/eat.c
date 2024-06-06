/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   eat.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atokamot <atokamot@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/06 14:59:08 by atokamot          #+#    #+#             */
/*   Updated: 2024/06/06 23:34:31 by atokamot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	eat(t_philo *philo)
{
	// philo->latest_eat_time = get_current_time() - philo->common->start_time;
	print_philo_status(philo, EAT);
	usleep(1000 * philo->data.time_to_eat);
	philo->latest_eat_time = get_current_time() - philo->common->start_time;
}
