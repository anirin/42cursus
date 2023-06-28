/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   _algorithm2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atokamot <atokamot@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/24 09:19:55 by atokamot          #+#    #+#             */
/*   Updated: 2023/06/27 09:08:50y atokamot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"


int first_finish_condition(t_list **list_a, t_list **list_b)
{
    if(ft_lstsize(*list_a) == 2)
        sort_two_a(list_a);
    if(ft_lstsize(*list_a) == 3)
        sort_three_a(list_a);
    if(ft_lstsize(*list_a) == 4)
        sort_four_a(list_a, list_b);
    if(ft_lstsize(*list_a) == 5)
        sort_five_a(list_a, list_b);
    if (ft_lstsize(*list_a) <= 5)
        return (OK);
    else
        return (NG);
}

int finish_condition(t_list **list_a, t_list **list_b)
{
    if(ft_lstsize(*list_b) == 2)
        sort_two_b(list_b);
    if(ft_lstsize(*list_b) == 3)
        sort_three_b(list_b);
    if(ft_lstsize(*list_b) == 4)
        sort_four_b(list_a, list_b);
    if(ft_lstsize(*list_b) == 5)
        sort_five_b(list_a, list_b);
    if (ft_lstsize(*list_b) <= 5)
    {
        all_push_rotate(list_a, list_b);
        return (OK);
    }
    else
        return (NG);
}

void half_recursive_push(t_list **list_a, t_list **list_b)
{
    int size;
    int pivot[3];

    if (finish_condition(list_a, list_b) == OK)
        return ;
    size = ft_lstsize(*list_b);
    get_three_pivot(list_b, size, pivot);

    half_push(list_a, list_b, pivot, size);
    if (finish_condition(list_a, list_b) == NG)
        half_recursive_push(list_a, list_b);

    half_push_back(list_a, list_b, size);
    if (finish_condition(list_a, list_b) == NG)
        half_recursive_push(list_a, list_b);
}

void push_swap(t_list **list_a, t_list **list_b)
{
    int size;
    int pivot[3];

    if (first_finish_condition(list_a, list_b) == OK)
        return ;
    size = ft_lstsize(*list_a);
    get_three_pivot(list_a, size, pivot);

    // printf("pivoit = %d\n", pivot[0]);
    // printf("pivoit = %d\n", pivot[1]);
    // printf("pivoit = %d\n", pivot[2]);

    //first
    first_half_push(list_a, list_b, pivot, size);
    half_recursive_push(list_a, list_b);

    //second
    second_half_push(list_a, list_b, pivot, size);
    half_recursive_push(list_a, list_b);
}
