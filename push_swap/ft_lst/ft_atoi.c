/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atokamot <atokamot@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/15 17:15:23 by atokamot          #+#    #+#             */
/*   Updated: 2023/07/04 23:58:34 by atokamot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/push_swap.h"
#include "../header/algorithm.h"
#include "../header/ft_lst.h"
#include "../header/operate.h"
#include "../header/sort.h"

static long	get_min_result(const char *str)
{
	int		i;
	long	result;

	i = 0;
	result = 0;
	while (str[i] >= '0' && str[i] <= '9')
	{
		if (result < LONG_MIN / 10)
			return (LONG_MIN);
		if (result * 10 < LONG_MIN + str[i] - '0')
			return (LONG_MIN);
		result = result * 10 - str[i] + '0';
		i++;
	}
	return (result);
}

static long	get_max_result(const char *str)
{
	int		i;
	long	result;

	i = 0;
	result = 0;
	while (str[i] >= '0' && str[i] <= '9')
	{
		if (result > LONG_MAX / 10)
			return (LONG_MAX);
		if (result * 10 > LONG_MAX - str[i] + '0')
			return (LONG_MAX);
		result = result * 10 + str[i] - '0';
		i++;
	}
	return (result);
}

long	ft_atoi_long(const char *str)
{
	int		sign;
	int		i;
	long	result;

	sign = 1;
	i = 0;
	while ((str[i] >= '\t' && str[i] <= '\r') || str[i] == ' ')
		i++;
	if (str[i] == '+' || str[i] == '-')
	{
		if (str[i] == '-')
			sign = -1;
		i++;
	}
	if (sign == 1)
		result = get_max_result(&str[i]);
	else
		result = get_min_result(&str[i]);
	return (result);
}
