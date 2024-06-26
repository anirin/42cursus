/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate_pivot.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atokamot <atokamot@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/29 17:18:38 by atokamot          #+#    #+#             */
/*   Updated: 2023/07/02 22:21:57 by atokamot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/push_swap.h"
#include "../header/algorithm.h"
#include "../header/ft_lst.h"
#include "../header/operate.h"
#include "../header/sort.h"

int	can_rotate(t_three_lists *three_lists)
{
	t_list	**list_a;
	t_list	**list_b;
	t_list	**swap_result;

	list_a = &three_lists->sub_list_a;
	list_b = &three_lists->sub_list_b;
	swap_result = &three_lists->sub_swap_result;
	if ((int)(*list_a)->content == (int)ft_lstlast(*list_a)->content + 1)
	{
		rotate(list_a, A, swap_result);
		return (OK);
	}
	else
		return (NG);
}

int	can_swap_rotate(t_three_lists *three_lists)
{
	t_list	**list_a;
	t_list	**list_b;
	t_list	**swap_result;

	list_a = &three_lists->sub_list_a;
	list_b = &three_lists->sub_list_b;
	swap_result = &three_lists->sub_swap_result;
	if (((int)(*list_a)->content == (int)ft_lstlast(*list_a)->content + 2)
		&& ((int)(*list_a)->content == (int)(*list_a)->next->content + 1))
	{
		swap(list_a, A, swap_result);
		rotate(list_a, A, swap_result);
		rotate(list_a, A, swap_result);
		return (OK);
	}
	else
		return (NG);
}

int	rotate_nmax_and_nmin(t_list *list, int *sorted_array, int size, int i)
{
	int	finish_size_1;
	int	finish_size_2;
	int	n;

	finish_size_1 = 1;
	finish_size_2 = 4;
	n = 3;
	if (ft_lstsize(list) <= finish_size_1 || size - i <= finish_size_2)
		return (NG);
	if ((int)list->content >= sorted_array[size - n]
		|| (int)list->content <= sorted_array[n - 1])
		return (OK);
	else
		return (NG);
}

void	get_three_pivot(t_list **list, int size, int *pivot)
{
	int	*array;

	array = malloc(sizeof(int) * size);
	if (array == NULL)
		exit (1);
	set_array_num(array, *list);
	bub_sort_array(array, size);
	pivot[0] = array[(size / 4) - 1];
	pivot[1] = array[(size / 2) - 1];
	pivot[2] = array[(size / 2) + (size / 4) - 1];
	free(array);
}
