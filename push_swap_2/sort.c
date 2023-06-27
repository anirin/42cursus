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

void sort_two_a(t_list **list)
{
    if ((int)(*list)->content > (int)(*list)->next->content)
        swap(list, A);
}

void sort_two_b(t_list **list)
{
    if ((int)(*list)->content < (int)(*list)->next->content)
        swap(list, B);
}

void sort_three_a(t_list **list)
{
    if ((int)(*list)->content < (int)(*list)->next->next->content  && (int)(*list)->next->next->content < (int)(*list)->next->content) 
    {
        swap(list, A);
        rotate(list, A);
    }
    else if ((int)(*list)->next->content < (int)(*list)->content  && (int)(*list)->content < (int)(*list)->next->next->content) 
        swap(list, A);
    else if ((int)(*list)->next->content < (int)(*list)->next->next->content && (int)(*list)->next->next->content  < (int)(*list)->content) 
        rotate(list, A);
    else if ((int)(*list)->next->next->content < (int)(*list)->content && (int)(*list)->content < (int)(*list)->next->content) 
        rev_rotate(list, A);
    else if ((int)(*list)->next->next->content < (int)(*list)->next->content && (int)(*list)->next->content < (int)(*list)->content) 
    {
        swap(list, A);
        rev_rotate(list, A);
    }
}

void sort_three_b(t_list **list)
{
    if ((int)(*list)->content < (int)(*list)->next->content && (int)(*list)->next->content < (int)(*list)->next->next->content) 
    {
        rotate(list, B);
        swap(list, B);
    }
    else if ((int)(*list)->content < (int)(*list)->next->next->content  && (int)(*list)->next->next->content < (int)(*list)->next->content) 
        rotate(list, B);
    else if ((int)(*list)->next->content < (int)(*list)->content  && (int)(*list)->content < (int)(*list)->next->next->content) 
        rev_rotate(list, B);
    else if ((int)(*list)->next->content < (int)(*list)->next->next->content && (int)(*list)->next->next->content  < (int)(*list)->content) 
    {
        swap(list, B);
        rotate(list, B);
    }
    else if ((int)(*list)->next->next->content < (int)(*list)->content && (int)(*list)->content < (int)(*list)->next->content) 
        swap(list, B);
}
