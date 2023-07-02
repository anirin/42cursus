/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   array2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atokamot <atokamot@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/02 16:12:42 by atokamot          #+#    #+#             */
/*   Updated: 2023/07/02 16:14:11 by atokamot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/ft_lst.h"
#include "../header/operate.h"
#include "../header/push_swap.h"
#include "../header/sort.h"

void	set_array(int *array, int size, char **argv)
{
	int	i;

	i = 0;
	while (i < size)
	{
		array[i] = ft_atoi(argv[i + 1]);
		i++;
	}
}

void	set_array_num(int *array, t_list *list)
{
	int	i;

	i = 0;
	while (list != NULL)
	{
		array[i++] = (int)list->content;
		list = list->next;
	}
}

void	set_array_num_by_size(int *array, t_list *list, int size)
{
	int	i;

	i = 0;
	while (i < size)
	{
		array[i++] = (int)list->content;
		list = list->next;
	}
}
