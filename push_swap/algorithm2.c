/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algorithm2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atokamot <atokamot@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/24 09:19:55 by atokamot          #+#    #+#             */
/*   Updated: 2023/06/26 18:32:11 by atokamot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int finish_condition(t_list **list_a, t_list **list_b)
{
    if(ft_lstsize(*list_b) == 2)
        sort_two_b(list_b, B);
    if(ft_lstsize(*list_b) == 3)
        sort_three_b(list_b, B);
    if(ft_lstsize(*list_b) == 4)
        sort_four_b(list_b, list_a, B, 4);
    if(ft_lstsize(*list_b) == 5)
        sort_five_b(list_b, list_a, B, 5);
    if (ft_lstsize(*list_b) == 5 || ft_lstsize(*list_b) == 4 || ft_lstsize(*list_b) == 3 || ft_lstsize(*list_b) == 2)
    {
        all_push_rotate(list_a, list_b);
        return (OK);
    }
    else
        return (NG);
}

void recursive_push(t_list **list_a, t_list **list_b)
{
    int count;
    int size;

    if (finish_condition(list_a, list_b) == OK)
        return ;
    size = ft_lstsize(*list_b);
    count = half_push(list_b, list_a, B, OVER, size);
    if (finish_condition(list_a, list_b) == NG)
        recursive_push(list_a, list_b);
    half_push_back(list_a, list_b, B, count);
    if (finish_condition(list_a, list_b) == NG)
        recursive_push(list_a, list_b);
}

/*------------------
half_push(A) 10 : 10 (OVER)
    half_push(B) 10 + 5 : 5
        half_push(B) 10 + 5 + 2 : 3
            sort_three(B)
            all_push_rotate(A) 3 + 10 + 5 + 2 : 0
        half_push_back(B) 3 + 10 + 5 : 2
            sort_two(B)
            all_push_rotate(A) 2 + 3 + 10 + 5 : 0
    half_push_back(B) 2 + 3 + 10 : 5 
        half_push(B) 2 + 3 + 10 + 2 : 3
            sort_three(B)
            all_push_rotate(A) 3 + 2 + 3 + 10 + 2 : 0
        half_push_back(B) 3 + 10 + 5 : 2
            sort_two(B)
            all_push_rotate(A) 2 + 3 + 10 + 5 : 0
-------------------*/
