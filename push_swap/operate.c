/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operate.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atokamot <atokamot@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/20 13:24:29 by atokamot          #+#    #+#             */
/*   Updated: 2023/06/21 20:54:06y atokamot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void swap(t_list **list, int flag)
{
    t_list *tmp;
    t_list *p1;
    t_list *p2;

    if (flag == A)
        ft_printf("sa\n");
    if (flag == B)
        ft_printf("sb\n");
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

void push(t_list **list_a, t_list **list_b, int flag)
{
    t_list *lst;
    t_list *tmp;

    if (flag == A)
        ft_printf("pa\n");
    if (flag == B)
        ft_printf("pb\n");
    if (ft_lstsize(*list_a) == 1)
    {
        ft_lstadd_front(list_b, *list_a);
        *list_a = NULL;
    }
    else
    {
        tmp = (*list_a)->next;
        ft_lstadd_front(list_b, *list_a);
        *list_a = tmp;
    }
}

void rotate(t_list **list, int flag)
{
    t_list *p1;
    t_list *p2;
    t_list *head;

    if (flag == A)
        ft_printf("ra\n");
    if (flag == B)
        ft_printf("rb\n");
    if (ft_lstsize(*list) <= 2)
    {
        swap(list, C);
        return ;
    }
    head = *list;
    p1 = ft_lstlast(*list);
    p2 = head->next;
    p1->next = head;
    head->next = NULL;
    *list = p2;
}

void rev_rotate(t_list **list, int flag)
{
    t_list *p1;
    t_list *p2;

    if (flag == A)
        ft_printf("rra\n");
    if (flag == B)
        ft_printf("rrb\n");
    if (ft_lstsize(*list) <= 2)
    {
        swap(list, C);
        return ;
    }
    p1 = ft_lstseclast(*list);
    p2 = ft_lstlast(*list);
    p1->next = NULL;
    p2->next = *list;
    *list = p2;
}
