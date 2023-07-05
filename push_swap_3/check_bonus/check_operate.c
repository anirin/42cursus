/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_operate.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atokamot <atokamot@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/05 01:03:02 by atokamot          #+#    #+#             */
/*   Updated: 2023/07/05 16:40:28 by atokamot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/algorithm.h"
#include "../header/bonus_check.h"
#include "../header/ft_lst.h"
#include "../header/get_next_line.h"
#include "../header/operate.h"
#include "../header/push_swap.h"
#include "../header/sort.h"

void	check_swap(char *str, t_three_lists *lists)
{
	if (ft_strcmp(str, "sa\n") == 0)
		swap(&lists->sub_list_a, C, &lists->sub_swap_result);
	if (ft_strcmp(str, "sb\n") == 0)
		swap(&lists->sub_list_b, C, &lists->sub_swap_result);
	if (ft_strcmp(str, "sb\n") == 0)
	{
		swap(&lists->sub_list_a, C, &lists->sub_swap_result);
		swap(&lists->sub_list_b, C, &lists->sub_swap_result);
	}
}

void	check_push(char *str, t_three_lists *lists)
{
	if (ft_strcmp(str, "pa\n") == 0)
		push(&lists->sub_list_a, &lists->sub_list_b, C,
			&lists->sub_swap_result);
	if (ft_strcmp(str, "pb\n") == 0)
		push(&lists->sub_list_b, &lists->sub_list_a, C,
			&lists->sub_swap_result);
}

void	check_rotate(char *str, t_three_lists *lists)
{
	if (ft_strcmp(str, "ra\n") == 0)
		rotate(&lists->sub_list_a, C, &lists->sub_swap_result);
	if (ft_strcmp(str, "rb\n") == 0)
		rotate(&lists->sub_list_b, C, &lists->sub_swap_result);
	if (ft_strcmp(str, "rr\n") == 0)
	{
		rotate(&lists->sub_list_a, C, &lists->sub_swap_result);
		rotate(&lists->sub_list_b, C, &lists->sub_swap_result);
	}
}

void	check_rev_rotate(char *str, t_three_lists *lists)
{
	if (ft_strcmp(str, "rra\n") == 0)
		rev_rotate(&lists->sub_list_a, C, &lists->sub_swap_result);
	if (ft_strcmp(str, "rrb\n") == 0)
		rev_rotate(&lists->sub_list_b, C, &lists->sub_swap_result);
	if (ft_strcmp(str, "rrr\n") == 0)
	{
		rev_rotate(&lists->sub_list_a, C, &lists->sub_swap_result);
		rev_rotate(&lists->sub_list_b, C, &lists->sub_swap_result);
	}
}
