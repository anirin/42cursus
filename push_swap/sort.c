/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atokamot <atokamot@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/24 07:53:51 by atokamot          #+#    #+#             */
/*   Updated: 2023/06/24 08:11:16atokamot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void sort_three(t_list **list, int flag)
{
    int arry[3];
    
    set_arry(*list, arry);
    if (((int)(*list)->content == arry[0]) && ((int)(*list)->next->content == arry[1]) && ((int)(*list)->next->next->content == arry[2])) 
    {
        rotate(list, flag);
        swap(list, flag);
    }
    if (((int)(*list)->content == arry[0]) && ((int)(*list)->next->content == arry[2]) && ((int)(*list)->next->next->content == arry[1])) 
        rotate(list, flag);
    if (((int)(*list)->content == arry[1]) && ((int)(*list)->next->content == arry[0]) && ((int)(*list)->next->next->content == arry[2])) 
        rev_rotate(list, flag);
    if (((int)(*list)->content == arry[1]) && ((int)(*list)->next->content == arry[2]) && ((int)(*list)->next->next->content == arry[0])) 
        swap(list, flag);
    if (((int)(*list)->content == arry[2]) && ((int)(*list)->next->content == arry[0]) && ((int)(*list)->next->next->content == arry[1])) 
    {
        swap(list, flag);
        rotate(list, flag);
    }
}