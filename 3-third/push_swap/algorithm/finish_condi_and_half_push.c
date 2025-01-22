/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   finish_condi_and_half_push.c                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atokamot <atokamot@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/02 22:36:05 by atokamot          #+#    #+#             */
/*   Updated: 2023/07/02 22:36:13 by atokamot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/push_swap.h"
#include "../header/algorithm.h"
#include "../header/ft_lst.h"
#include "../header/operate.h"
#include "../header/sort.h"

int	first_finish_condition(t_three_lists *three_lists)
{
	int		finish_size;
	t_list	**list_a;
	t_list	**list_b;
	t_list	**swap_result;

	list_a = &three_lists->sub_list_a;
	list_b = &three_lists->sub_list_b;
	swap_result = &three_lists->sub_swap_result;
	finish_size = 30;
	if (ft_lstsize(*list_a) <= finish_size)
	{
		sort_recursive_a(list_a, list_b, ft_lstsize(*list_a), swap_result);
		return (OK);
	}
	else
		return (NG);
}

int	finish_condition(t_three_lists *three_lists)
{
	int		finish_size;
	t_list	**list_a;
	t_list	**list_b;
	t_list	**swap_result;

	list_a = &three_lists->sub_list_a;
	list_b = &three_lists->sub_list_b;
	swap_result = &three_lists->sub_swap_result;
	finish_size = 25;
	if (*list_b == NG)
		return (OK);
	if (ft_lstsize(*list_b) <= finish_size)
	{
		sort_recursive_b(list_a, list_b, ft_lstsize(*list_b), swap_result);
		return (OK);
	}
	else
		return (NG);
}

void	half_push_to_a(t_three_lists *three_lists, int *pivot, int size)
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
		if ((int)(*list_b)->content > pivot[1])
		{
			push(list_b, list_a, A, swap_result);
			i++;
		}
		else
			rotate(list_b, B, swap_result);
	}
}

void	half_push_back_to_b(t_three_lists *three_lists, int size)
{
	int	*sorted_array;

	sorted_array = malloc(sizeof(int) * size);
	if (sorted_array == NULL)
		exit(1);
	half_push_back_to_b_help(three_lists, size, sorted_array);
	free(sorted_array);
}

void	half_push_back_to_b_help(t_three_lists *l, int size, int *sorted_array)
{
	int	i;

	i = 0;
	set_array_num_by_size(sorted_array, l->sub_list_a, size);
	bub_sort_array(sorted_array, size);
	while (i < size)
	{
		if (can_rotate(l) == OK)
			i++;
		else if (can_swap_rotate(l) == OK)
			i += 2;
		else
		{
			if (!(l->sub_list_b == NULL && i == size - 1))
			{
				push(&l->sub_list_a, &l->sub_list_b, B, &l->sub_swap_result);
				if (rotate_nmax_and_nmin(l->sub_list_b, sorted_array,
						size, i) == OK)
					rotate(&l->sub_list_b, B, &l->sub_swap_result);
			}
			i++;
		}
	}
}
