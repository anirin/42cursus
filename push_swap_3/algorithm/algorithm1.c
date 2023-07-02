/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algorithm1.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atokamot <atokamot@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/29 16:58:07 by atokamot          #+#    #+#             */
/*   Updated: 2023/07/02 15:55:15 by atokamot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/algorithm.h"
#include "../header/ft_lst.h"
#include "../header/operate.h"
#include "../header/push_swap.h"
#include "../header/sort.h"

void	first_half_push(t_three_lists *three_lists, int *pivot, int size)
{
	int		i;
	t_list	**list_a;
	t_list	**list_b;
	t_list	**swap_result;

	list_a = &three_lists->sub_list_a;
	list_b = &three_lists->sub_list_b;
	swap_result = &three_lists->sub_swap_result;
	i = 0;
	while (i < size)
	{
		if ((int)(*list_a)->content <= pivot[1])
		{
			push(list_a, list_b, B, swap_result);
			i++;
		}
		else
		{
			if (*list_b != NULL && (int)(*list_b)->content <= pivot[0])
			{
				rotate(list_a, R, swap_result);
				rotate(list_b, C, swap_result);
			}
			else
				rotate(list_a, A, swap_result);
		}
	}
}

void	second_half_push(t_three_lists *three_lists, int *pivot, int size)
{
	int		i;
	t_list	**list_a;
	t_list	**list_b;
	t_list	**swap_result;

	list_a = &three_lists->sub_list_a;
	list_b = &three_lists->sub_list_b;
	swap_result = &three_lists->sub_swap_result;
	i = 0;
	while (i < size)
	{
		if (can_rotate(three_lists) == OK)
			i++;
		else if (can_swap_rotate(three_lists) == OK)
			i += 2;
		else if ((int)(*list_a)->content > pivot[1])
		{
			if (!(*list_b == NULL && i == size - 1))
				push(list_a, list_b, B, swap_result);
			i++;
		}
		else
			rotate(list_a, A, swap_result);
	}
}

void	recursive_half_push(t_three_lists *three_lists)
{
	int	pivot[3];
	int	size;

	if (finish_condition(three_lists) == OK)
		return ;
	size = ft_lstsize(three_lists->sub_list_b);
	get_three_pivot(&three_lists->sub_list_b, size, pivot);
	half_push_to_a(three_lists, pivot, size - (size / 2));
	if (finish_condition(three_lists) == NG)
		recursive_half_push(three_lists);
	half_push_back_to_b(three_lists, size - (size / 2));
	if (finish_condition(three_lists) == NG)
		recursive_half_push(three_lists);
}

void	push_swap(t_three_lists *three_lists)
{
	int	pivot[3];
	int	size;

	if (first_finish_condition(three_lists) == OK)
		return ;
	size = ft_lstsize(three_lists->sub_list_a);
	get_three_pivot(&three_lists->sub_list_a, size, pivot);
	first_half_push(three_lists, pivot, size / 2);
	if (finish_condition(three_lists) == NG)
		recursive_half_push(three_lists);
	second_half_push(three_lists, pivot, size - (size / 2));
	if (finish_condition(three_lists) == NG)
		recursive_half_push(three_lists);
}
