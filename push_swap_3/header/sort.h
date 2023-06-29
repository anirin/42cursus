/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atokamot <atokamot@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/29 11:07:58 by atokamot          #+#    #+#             */
/*   Updated: 2023/06/29 13:33:21 by atokamot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SORT_H
#define SORT_H

#define SMALL 0
#define BIG 1

typedef struct s_location
{
    int max;
    int min;
}              t_location;

void sort_two_a(t_list **list);
void sort_three_a(t_list **list);
void sort_recursive_a(t_list **list_a, t_list **list_b, int size);
void sort_recursive_b(t_list **list_a, t_list **list_b, int size);
t_location get_location(t_list *list, int size);
int rotate_max_or_min(t_list **list, int size, int flag);

#endif