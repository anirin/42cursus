/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort2.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atokamot <atokamot@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/25 18:20:26 by atokamot          #+#    #+#             */
/*   Updated: 2023/06/25 18:49:55by atokamot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void sort_four_a(t_list **list_a, t_list **list_b)
{
    int arry[4];
    
    if (set_arry(*list_a, arry) == OK)
        return ;
    num_min_rotate(list_a, arry[0], arry, 4, A);
    push(list_a, list_b, B);
    sort_three_a(list_a);
    push(list_b, list_a, A);
}

void sort_four_b(t_list **list_a, t_list **list_b)
{
    int arry[4];
    
    set_arry(*list_b, arry);
    num_min_rotate(list_b, arry[0], arry, 4, B);
    push(list_b, list_a, A);
    rotate(list_a, A);
    sort_three_b(list_b);
    // push(list_a, list_b, B);
}

void sort_five_a(t_list **list_a, t_list **list_b)
{
    int arry[5];

    if(set_arry(*list_a, arry) == OK)
        return ;
    num_min_rotate(list_a, arry[0], arry, 4, A);
    push(list_a, list_b, B);
    num_min_rotate(list_a, arry[1], arry, 4, A);
    push(list_a, list_b, B);
    sort_three_a(list_a);
    push(list_b, list_a, A);
    push(list_b, list_a, A);
}


void sort_five_b(t_list **list_a, t_list **list_b)
{
    int arry[5];
    
    set_arry(*list_b, arry);
    num_min_rotate(list_b, arry[0], arry, 4, B);
    push(list_b, list_a, A);
    rotate(list_a, A);
    num_min_rotate(list_b, arry[1], arry, 4, B);
    push(list_b, list_a, A);
    rotate(list_a, A);
    sort_three_b(list_b);
    // push(list_a, list_b, B);
    // push(list_a, list_b, B);
}