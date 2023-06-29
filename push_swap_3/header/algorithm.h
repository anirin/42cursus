/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algorithm.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atokamot <atokamot@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/29 19:22:51 by atokamot          #+#    #+#             */
/*   Updated: 2023/06/29 19:31:23 by atokamot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ALGORITHM_H
#define ALGORITHM_H

void first_half_push(t_list **list_a, t_list **list_b, int *pivot, int size);
void second_half_push(t_list **list_a, t_list **list_b, int *pivot, int size);
void recursive_half_push(t_list **list_a, t_list **list_b);
void push_swap(t_list **list_a, t_list **list_b);

int can_rotate(t_list **list);
int can_swap_rotate(t_list **list);
void get_three_pivot(t_list **list, int size, int *pivot);

int first_finish_condition(t_list **list_a, t_list **list_b);
int finish_condition(t_list **list_a, t_list **list_b);
void half_push_to_a(t_list **list_a, t_list **list_b, int *pivot, int size);
void half_push_back_to_b(t_list **list_a, t_list **list_b, int size);

#endif