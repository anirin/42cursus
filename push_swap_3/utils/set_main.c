/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_main.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atokamot <atokamot@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/05 01:29:51 by atokamot          #+#    #+#             */
/*   Updated: 2023/07/05 16:38:32 by atokamot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/algorithm.h"
#include "../header/ft_lst.h"
#include "../header/operate.h"
#include "../header/push_swap.h"
#include "../header/sort.h"

int	first_set_list(int argc, char **argv, t_list **list)
{
	char	**split_result;
	int		i;
	int		j;
	long	num;

	i = 1;
	j = 0;
	while (i < argc)
	{
		split_result = ft_split(argv[i++], ' ');
		if (split_result[0] == NULL)
			return (NG);
		j = 0;
		while (split_result[j] != NULL)
		{
			num = ft_atoi_long(split_result[j]);
			if (num < INT_MIN || num > INT_MAX)
				return (NG);
			ft_lstadd_back(list, ft_lstnew((void *)num));
			j++;
		}
	}
	return (OK);
}

void	set_main_lists(t_three_lists *three_lists, int size, int *array)
{
	three_lists->sub_list_a = set_list(size, array);
	three_lists->sub_list_b = NULL;
	three_lists->sub_swap_result = NULL;
}

int	*set_main_array(int size, t_list *list)
{
	int	*array;
	int	*sorted_array;

	array = malloc(sizeof(int) * size);
	sorted_array = malloc(sizeof(int) * size);
	if (array == NULL || sorted_array == NULL)
		exit(1);
	set_array(array, list);
	set_array(sorted_array, list);
	bub_sort_array(sorted_array, size);
	if (check_dup(sorted_array, size) == NG)
		return (NULL);
	compress_array(array, sorted_array, size);
	free(sorted_array);
	return (array);
}
