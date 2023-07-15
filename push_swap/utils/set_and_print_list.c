/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_and_print_list.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atokamot <atokamot@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/19 20:18:33 by atokamot          #+#    #+#             */
/*   Updated: 2023/07/04 23:57:51 by atokamot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/push_swap.h"
#include "../header/algorithm.h"
#include "../header/ft_lst.h"
#include "../header/operate.h"
#include "../header/sort.h"

t_list	*set_list(int size, int *array)
{
	int		i;
	long	num;
	t_list	*new;
	t_list	*list;

	i = 0;
	list = NULL;
	while (i < size)
	{
		num = (long)array[i++];
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

void	print_list(t_list *list)
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

void	print_swap_and_push(t_list *list)
{
	if ((int)list->content == SA)
		write(1, "sa\n", 3);
	else if ((int)list->content == SB)
		write(1, "sb\n", 3);
	else if ((int)list->content == SS)
		write(1, "ss\n", 3);
	else if ((int)list->content == PA)
		write(1, "pa\n", 3);
	else if ((int)list->content == PB)
		write(1, "pb\n", 3);
}

int	print_rotate(t_list *list)
{
	if ((int)list->content == RA)
	{
		if (list->next != NULL && (int)list->next->content == RB)
		{
			write(1, "rr\n", 3);
			return (OK);
		}
		else
			write(1, "ra\n", 3);
	}
	else if ((int)list->content == RB)
	{
		if (list->next != NULL && (int)list->next->content == RA)
		{
			write(1, "rr\n", 3);
			return (OK);
		}
		else
			write(1, "rb\n", 3);
	}
	else if ((int)list->content == RR)
		write(1, "rr\n", 3);
	return (NG);
}

void	print_rev_rotate(t_list *list)
{
	if ((int)list->content == RRA)
		write(1, "rra\n", 4);
	else if ((int)list->content == RRB)
		write(1, "rrb\n", 4);
	else if ((int)list->content == RRR)
		write(1, "rrr\n", 4);
}
