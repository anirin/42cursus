/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atokamot <atokamot@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/24 07:53:51 by atokamot          #+#    #+#             */
/*   Updated: 2023/07/02 16:03:01 by atokamot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/ft_lst.h"
#include "../header/operate.h"
#include "../header/sort.h"

void	sort_two_a(t_list **list, t_list **swap_result)
{
	if ((int)(*list)->content > (int)(*list)->next->content)
		swap(list, A, swap_result);
}

void	sort_three_a(t_list **list, t_list **swap_result)
{
	if ((int)(*list)->content < (int)(*list)->next->next->content
		&& (int)(*list)->next->next->content < (int)(*list)->next->content)
	{
		swap(list, A, swap_result);
		rotate(list, A, swap_result);
	}
	else if ((int)(*list)->next->content < (int)(*list)->content
			&& (int)(*list)->content < (int)(*list)->next->next->content)
		swap(list, A, swap_result);
	else if ((int)(*list)->next->content < (int)(*list)->next->next->content
			&& (int)(*list)->next->next->content < (int)(*list)->content)
		rotate(list, A, swap_result);
	else if ((int)(*list)->next->next->content < (int)(*list)->content
			&& (int)(*list)->content < (int)(*list)->next->content)
		rev_rotate(list, A, swap_result);
	else if ((int)(*list)->next->next->content < (int)(*list)->next->content
			&& (int)(*list)->next->content < (int)(*list)->content)
	{
		swap(list, A, swap_result);
		rev_rotate(list, A, swap_result);
	}
}
