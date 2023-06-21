/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   setarry.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atokamot <atokamot@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/21 14:35:08 by atokamot          #+#    #+#             */
/*   Updated: 2023/06/21 14:53:55 by atokamot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void sort_arry(int *arry)
{
    
}

int *set_arry(t_list *list)
{
    int i;
    int arry[ft_lstsize(list)]; //もしむりならmax_size を事前に定義する

    i = 0;
    while (list != NULL)
    {
        arry[i++] = (int)list->content;
        list = list->next;
    }
    return (arry);
}