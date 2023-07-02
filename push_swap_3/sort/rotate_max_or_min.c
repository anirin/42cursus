/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate_max_or_min.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atokamot <atokamot@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/02 21:58:58 by atokamot          #+#    #+#             */
/*   Updated: 2023/07/02 22:37:49 by atokamot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/algorithm.h"
#include "../header/ft_lst.h"
#include "../header/operate.h"
#include "../header/push_swap.h"
#include "../header/sort.h"

void	help_rotate_min(t_list **list, int flag, int size, t_list **swap_result)
{
	t_location	location;
	int			i;

	i = 0;
	location = get_location(*list, size);
	if (location.min < size / 2 + 1)
	{
		while (i < get_min(location.min, size))
		{
			rotate(list, flag, swap_result);
			i++;
		}
	}
	else
	{
		while (i < get_min(location.min, size))
		{
			rev_rotate(list, flag, swap_result);
			i++;
		}
	}
}

void	help_rotate_max(t_list **list, int flag, int size, t_list **swap_result)
{
	t_location	location;
	int			i;

	i = 0;
	location = get_location(*list, size);
	if (location.max < size / 2 + 1)
	{
		while (i < get_min(location.max, size))
		{
			rotate(list, flag, swap_result);
			i++;
		}
	}
	else
	{
		while (i < get_min(location.max, size))
		{
			rev_rotate(list, flag, swap_result);
			i++;
		}
	}
}

int	rotate_max_or_min(t_list **list, int size, int flag, t_list **swap_result)
{
	t_location	location;

	location = get_location(*list, size);
	if (get_min(location.min, size) <= get_min(location.max, size))
	{
		help_rotate_min(list, flag, size, swap_result);
		return (SMALL);
	}
	else
	{
		help_rotate_max(list, flag, size, swap_result);
		return (BIG);
	}
}
