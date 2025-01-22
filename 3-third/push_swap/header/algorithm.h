/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algorithm.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atokamot <atokamot@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/29 19:22:51 by atokamot          #+#    #+#             */
/*   Updated: 2023/07/05 00:00:05 by atokamot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ALGORITHM_H
# define ALGORITHM_H

# include "../header/push_swap.h"

void	first_half_push(t_three_lists *three_lists, int *pivot, int size);
void	second_half_push(t_three_lists *three_lists, int *pivot, int size);
void	recursive_half_push(t_three_lists *three_lists);
void	push_swap(t_three_lists *three_lists);

int		can_rotate(t_three_lists *three_lists);
int		can_swap_rotate(t_three_lists *three_lists);
void	get_three_pivot(t_list **list, int size, int *pivot);

int		first_finish_condition(t_three_lists *three_lists);
int		finish_condition(t_three_lists *three_lists);
void	half_push_to_a(t_three_lists *three_lists, int *pivot, int size);
void	half_push_back_to_b(t_three_lists *three_lists, int size);
void	half_push_back_to_b_help(t_three_lists *lsts, int size,
			int *sorted_array);
int		rotate_nmax_and_nmin(t_list *list, int *sorted_array, int size, int i);

#endif
