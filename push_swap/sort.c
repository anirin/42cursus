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

void sort_two_b(t_list **list, int flag)
{
    if ((int)(*list)->content < (int)(*list)->next->content)
        swap(list, flag);
}

void sort_two_a(t_list **list, int flag)
{
    if ((int)(*list)->content > (int)(*list)->next->content)
        swap(list, flag);
}

void sort_three_b(t_list **list, int flag)
{
    if ((int)(*list)->content < (int)(*list)->next->content && (int)(*list)->next->content < (int)(*list)->next->next->content) 
    {
        rotate(list, flag);
        swap(list, flag);
    }
    else if ((int)(*list)->content < (int)(*list)->next->next->content  && (int)(*list)->next->next->content < (int)(*list)->next->content) 
        rotate(list, flag);
    else if ((int)(*list)->next->content < (int)(*list)->content  && (int)(*list)->content < (int)(*list)->next->next->content) 
        rev_rotate(list, flag);
    else if ((int)(*list)->next->content < (int)(*list)->next->next->content && (int)(*list)->next->next->content  < (int)(*list)->content) 
    {
        swap(list, flag);
        rotate(list, flag);
    }
    else if ((int)(*list)->next->next->content < (int)(*list)->content && (int)(*list)->content < (int)(*list)->next->content) 
        swap(list, flag);
}

void sort_three_a(t_list **list, int flag)
{
    if ((int)(*list)->content < (int)(*list)->next->next->content  && (int)(*list)->next->next->content < (int)(*list)->next->content) 
    {
        swap(list, flag);
        rotate(list, flag);
    }
    else if ((int)(*list)->next->content < (int)(*list)->content  && (int)(*list)->content < (int)(*list)->next->next->content) 
        swap(list, flag);
    else if ((int)(*list)->next->content < (int)(*list)->next->next->content && (int)(*list)->next->next->content  < (int)(*list)->content) 
        rotate(list, flag);
    else if ((int)(*list)->next->next->content < (int)(*list)->content && (int)(*list)->content < (int)(*list)->next->content) 
        rev_rotate(list, flag);
    else if ((int)(*list)->next->next->content < (int)(*list)->next->content && (int)(*list)->next->content < (int)(*list)->content) 
    {
        swap(list, flag);
        rev_rotate(list, flag);
    }
}