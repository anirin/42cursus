/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algorithm.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atokamot <atokamot@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/21 20:40:22 by atokamot          #+#    #+#             */
/*   Updated: 2023/06/22 15:01:35 by atokamot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void find_rotate(t_list **list_a, long num)
{
    int i;
    t_list *tmp;

    i = 0;
    while (1)
    {
        tmp = *list_a;
        if (tmp->content == (void *)num)
            break ;
        rotate(list_a, A);
        i++;
    }
}

void sort_push(t_list **list_a, t_list **list_b, int *arry)
{
    int size;
    int i;

    size = ft_lstsize(*list_a);
    i = 0;
    while (i < size)
    {
        find_rotate(list_a, (long)arry[i]);
        push(list_a, list_b, B);
        i++;
    }
}

void all_push(t_list **list_a, t_list **list_b)
{
    int size;

    size = ft_lstsize(*list_b);
    while(size--)
    {
        push(list_b, list_a, A);
    }
}