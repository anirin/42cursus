/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lst_1.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atokamot <atokamot@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/19 20:18:33 by atokamot          #+#    #+#             */
/*   Updated: 2023/06/30 15:24:15by atokamot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/ft_lst.h"
#include "../header/operate.h"
#include "../header/sort.h"
#include "../header/push_swap.h"

t_list  *set_list(int size, int *arry)
{
    int i;
    long num;
    t_list *new;
    t_list *list;

    i = 0;
    list = NULL;
    while (i < size)
    {
        num = (long)arry[i++];
        new = ft_lstnew((void *)num);
        if (new == NULL)
        {
            ft_lstclear(&list, &del);
            return (NULL);
        }
        ft_lstadd_back(&list, new);
    }
    return (list);
}

void print_list(t_list *list)
{
    if (ft_lstsize(list) == 0)
        return ;
    while (list != NULL)
    {
        print_swap_and_push(list);
        if (print_rotate(list) == OK)
            list = list->next;
        print_rev_rotate(list);
        list = list->next;
    }
    return ;
}

void print_swap_and_push(t_list *list)
{
    if ((int)list->content == SA)
        printf("sa\n");
    else if ((int)list->content == SB)
        printf("sb\n");
    else if ((int)list->content == SS)
        printf("ss\n");
    else if ((int)list->content == PA)
        printf("pa\n");
    else if ((int)list->content == PB)
        printf("pb\n");
}

int print_rotate(t_list *list)
{
    if ((int)list->content == RA)
    {
        if (list->next != NULL && (int)list->next->content == RB)
        {
            printf("rr\n");
            return (OK);
        }
        else
            printf("ra\n");
    }
    else if ((int)list->content == RB)
    {
        if (list->next != NULL && (int)list->next->content == RA)
        {
            printf("rr\n");
            return (OK);
        }
        else
            printf("rb\n");
    }
    else if ((int)list->content == RR)
        printf("rr\n");
    return (NG);
}

void print_rev_rotate(t_list *list)
{
    if ((int)list->content == RRA)
        printf("rra\n");
    else if ((int)list->content == RRB)
        printf("rrb\n");
    else if ((int)list->content == RRR)
        printf("rrr\n");
}