/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atokamot <atokamot@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/29 11:07:58 by atokamot          #+#    #+#             */
/*   Updated: 2023/07/02 22:37:34 by atokamot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SORT_H
# define SORT_H

# define SMALL 0
# define BIG 1

typedef struct s_location
{
	int		max;
	int		min;
}			t_location;

void		sort_two_a(t_list **list, t_list **swap_result);
void		sort_three_a(t_list **list, t_list **swap_result);
void		sort_recursive_a(t_list **list_a, t_list **list_b, int size,
				t_list **swap_result);
void		sort_recursive_b(t_list **list_a, t_list **list_b, int size,
				t_list **swap_result);
t_location	get_location(t_list *list, int size);

void		help_rotate_min(t_list **list, int flag, int size,
				t_list **swap_result);
void		help_rotate_max(t_list **list, int flag, int size,
				t_list **swap_result);
int			rotate_max_or_min(t_list **list, int size, int flag,
				t_list **swap_result);
int			get_min(int i, int size);

#endif
