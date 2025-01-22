/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_recursive.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atokamot <atokamot@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/29 09:25:06 by atokamot          #+#    #+#             */
/*   Updated: 2023/07/02 22:22:23 by atokamot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/push_swap.h"
#include "../header/algorithm.h"
#include "../header/ft_lst.h"
#include "../header/operate.h"
#include "../header/sort.h"

void	sort_recursive_a(t_list **list_a, t_list **list_b, int size,
		t_list **swap_result)
{
	int	flag;

	if (size == 2)
	{
		sort_two_a(list_a, swap_result);
		return ;
	}
	if (size == 3)
	{
		sort_three_a(list_a, swap_result);
		return ;
	}
	flag = rotate_max_or_min(list_a, size, A, swap_result);
	push(list_a, list_b, B, swap_result);
	if (flag == BIG)
	{
		sort_recursive_a(list_a, list_b, size - 1, swap_result);
		push(list_b, list_a, A, swap_result);
		rotate(list_a, A, swap_result);
	}
	if (flag == SMALL)
	{
		sort_recursive_a(list_a, list_b, size - 1, swap_result);
		push(list_b, list_a, A, swap_result);
	}
}

void	sort_recursive_b(t_list **list_a, t_list **list_b, int size,
		t_list **swap_result)
{
	int	flag;

	if (size == 1)
	{
		push(list_b, list_a, A, swap_result);
		rotate(list_a, A, swap_result);
		return ;
	}
	flag = rotate_max_or_min(list_b, size, B, swap_result);
	if (flag == BIG)
	{
		push(list_b, list_a, A, swap_result);
		sort_recursive_b(list_a, list_b, size - 1, swap_result);
		rotate(list_a, A, swap_result);
	}
	if (flag == SMALL)
	{
		push(list_b, list_a, A, swap_result);
		rotate(list_a, A, swap_result);
		sort_recursive_b(list_a, list_b, size - 1, swap_result);
	}
}

int	get_min(int i, int size)
{
	if (i < size - i)
		return (i);
	else
		return (size - i);
}

t_location	get_location(t_list *list, int size)
{
	int			*array;
	int			i;
	t_location	location;

	array = malloc(sizeof(int) * size);
	if (array == NULL)
		exit(1);
	i = 0;
	set_array_num(array, list);
	bub_sort_array(array, size);
	while (list != NULL)
	{
		if (array[0] == (int)list->content)
			location.min = i;
		if (array[size - 1] == (int)list->content)
			location.max = i;
		list = list->next;
		i++;
	}
	free(array);
	return (location);
}
