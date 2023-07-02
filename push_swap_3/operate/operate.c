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

#include "../header/ft_lst.h"
#include "../header/operate.h"
#include "../header/sort.h"

void swap(t_list **list, int flag, t_list **swap_result)
{
    t_list *tmp;
    t_list *p1;
    t_list *p2;
    t_list *new;

    if (ft_lstsize(*list) < 2)
        return ;
    if (flag == A || flag == B || flag == R)
        swap_result_exit(swap_result, flag + 10);
    //printf
    // if (flag == A)
    //     printf("--SA\n");
    // if (flag == B)
    //     printf("--SB\n");

    tmp = *list;
    p1 = tmp;
    p2 = tmp->next;
    p1->next = p2->next;
    p2->next = p1;
    *list = p2;
    return ;
}

void push(t_list **list_a, t_list **list_b, int flag, t_list **swap_result)
{
    t_list *lst;
    t_list *tmp;
    t_list *new;

    if (flag == A || flag == B)
        swap_result_exit(swap_result, flag + 30);
    //print
    // if (flag == A)
    //     printf("--PA\n");
    // if (flag == B)
    //     printf("--PB\n");

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

void rotate(t_list **list, int flag, t_list **swap_result)
{
    t_list *p1;
    t_list *p2;
    t_list *head;
    t_list *new;

    if (flag == A || flag == B || flag == R)
        swap_result_exit(swap_result, flag + 20);
    //print
    // if (flag == A)
    //     printf("--RA\n");
    // if (flag == B)
    //     printf("--RB\n");
    // if (flag == R)
    //     printf("--RR\n");

    if (ft_lstsize(*list) <= 2)
    {
        swap(list, C, swap_result);
        return ;
    }
    head = *list;
    p1 = ft_lstlast(*list);
    p2 = head->next;
    p1->next = head;
    head->next = NULL;
    *list = p2;
}

void rev_rotate(t_list **list, int flag, t_list **swap_result)
{
    t_list *p1;
    t_list *p2;
    t_list *new;

    if (flag == A || flag == B || flag == R)
        swap_result_exit(swap_result, flag + 40);
    //print
    // if (flag == A)
    //     printf("--RRA\n");
    // if (flag == B)
    //     printf("--RRB\n");
    // if (flag == R)
    //     printf("--RRR\n");
    if (ft_lstsize(*list) <= 2)
    {
        swap(list, C, swap_result);
        return ;
    }
    p1 = ft_lstseclast(*list);
    p2 = ft_lstlast(*list);
    p1->next = NULL;
    p2->next = *list;
    *list = p2;
}
