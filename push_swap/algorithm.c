/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algorithm.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atokamot <atokamot@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/21 20:40:22 by atokamot          #+#    #+#             */
/*   Updated: 2023/06/21 21:38:43 by atokamot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void find_rotate(t_list **list_a, long num)
{
    int i;
    t_list *tmp;

    i = 0;
    // while (1)
    while (i < 10)
    {
        tmp = ft_lstlast(*list_a);
        if (tmp->content == (void *)num)
            break ;
        rotate(list_a, A);
        i++;
    }
}

void push_all(t_list **list_a, t_list **list_b, int *arry)
{
    int size;
    int i;

    size = ft_lstsize(*list_a);
    i = 0;
    while (i < size)
    {
        find_rotate(list_a, (long)arry[i]);
        printf("             -----i=%d, conent=%d, arry=%d\n", i, (int)(*list_a)->content, arry[i]);
        push(list_a, list_b, B);
        i++;
    }
}