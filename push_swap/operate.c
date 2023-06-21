/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operate.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atokamot <atokamot@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/20 13:24:29 by atokamot          #+#    #+#             */
/*   Updated: 2023/06/21 14:23:44 by atokamot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void swap(t_list **list)
{
    t_list *tmp;
    t_list *p1;
    t_list *p2;

    if (ft_lstsize(*list) < 2)
        return ;
    tmp = *list;
    p1 = tmp;
    p2 = tmp->next;
    p1->next = p2->next;
    p2->next = p1;
    *list = p2;
    return ;
}

void push(t_list **list_a, t_list **list_b) //Interchange a and b as the case
{
    t_list *lst;

    if (ft_lstsize(*list_a) == 1)
    {
        ft_lstadd_back(list_b, ft_lstlast(*list_a));
        *list_a = NULL;
    }
    else
    {
        ft_lstadd_back(list_b, ft_lstlast(*list_a));
        lst = ft_lstseclast(*list_a);
        lst->next = NULL;
    }
}

void rotate(t_list **list)
{
    t_list *p1;
    t_list *p2;

    if (ft_lstsize(*list) <= 2)
    {
        swap(list);
        return ;
    }
    p1 = ft_lstseclast(*list);
    p2 = ft_lstlast(*list);
    p1->next = NULL;
    p2->next = *list;
    *list = p2;
}

void rev_rotate(t_list **list)
{
    t_list *p1;
    t_list *p2;
    t_list *head;

    if (ft_lstsize(*list) <= 2)
    {
        swap(list);
        return ;
    }
    head = *list;
    p1 = ft_lstlast(*list);
    p2 = head->next;
    p1->next = head;
    head->next = NULL;
    *list = p2;
}