/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap_result_exit.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atokamot <atokamot@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/30 23:09:23 by atokamot          #+#    #+#             */
/*   Updated: 2023/07/02 22:34:00 by atokamot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/push_swap.h"
#include "../header/algorithm.h"
#include "../header/ft_lst.h"
#include "../header/operate.h"
#include "../header/sort.h"

void	swap_result_exit(t_list **swap_result, int flag)
{
	t_list	*new;
	long	long_flag;

	long_flag = (long)flag;
	new = ft_lstnew((void *)long_flag);
	if (new == NULL)
		exit(1);
	ft_lstadd_back(swap_result, new);
}
