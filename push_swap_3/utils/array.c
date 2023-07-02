/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   array.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atokamot <atokamot@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/21 14:35:08 by atokamot          #+#    #+#             */
/*   Updated: 2023/07/02 16:13:39 by atokamot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/ft_lst.h"
#include "../header/operate.h"
#include "../header/push_swap.h"
#include "../header/sort.h"

void	swap_array(int *a, int *b)
{
	int	tmp;

	tmp = *a;
	*a = *b;
	*b = tmp;
}

int	bub_sort_array(int *array, int size)
{
	int	i;
	int	j;
	int	count;

	count = 0;
	j = 1;
	while (j <= size)
	{
		i = 0;
		while (i < size - j)
		{
			if (array[i] > array[i + 1])
			{
				swap_array(&array[i], &array[i + 1]);
				count++;
			}
			i++;
		}
		j++;
	}
	return (count);
}

void	compress_array(int *array, int *sorted_array, int size)
{
	int	i;
	int	j;

	i = 0;
	while (i < size)
	{
		j = 0;
		while (j < size)
		{
			if (array[i] == sorted_array[j])
			{
				array[i] = j;
				break ;
			}
			j++;
		}
		i++;
	}
}

void	print_array(int *array, int size)
{
	int	i;

	i = 0;
	while (i < size)
	{
		printf("array[%d]=%d\n", i, array[i]);
		i++;
	}
}
