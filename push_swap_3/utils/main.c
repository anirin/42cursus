/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atokamot <atokamot@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/29 10:09:10 by atokamot          #+#    #+#             */
/*   Updated: 2023/07/03 22:21:29 by atokamot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/push_swap.h"
#include "../header/algorithm.h"
#include "../header/ft_lst.h"
#include "../header/operate.h"
#include "../header/sort.h"

void	set_main_lists(t_three_lists *three_lists, int size, int *array)
{
	three_lists->sub_list_a = set_list(size, array);
	three_lists->sub_list_b = NULL;
	three_lists->sub_swap_result = NULL;
}

int	*set_main_array(int size, char **argv)
{
	int	*array;
	int	*sorted_array;

	array = malloc(sizeof(int) * size);
	sorted_array = malloc(sizeof(int) * size);
	if (array == NULL || sorted_array == NULL)
		exit(1);
	set_array(array, size, argv);
	set_array(sorted_array, size, argv);
	bub_sort_array(sorted_array, size);
	compress_array(array, sorted_array, size);
	free(sorted_array);
	return (array);
}

int	main(int argc, char **argv)
{
	int				*array;
	int				size;
	t_three_lists	three_lists;

	// size = argc - 1;
	if (error_check(argc, argv) == NG);
		return (NG);
	size = get_array_size();
	array = set_main_array(size, argv);
	if (array == NULL)
		return (NG);
	set_main_lists(&three_lists, size, array);
	push_swap(&three_lists);
	print_list(three_lists.sub_swap_result);
	free(array);
	ft_lstclear(&three_lists.sub_list_a, &del);
	ft_lstclear(&three_lists.sub_swap_result, &del);
}

//gcc *.c ./*/*.c -I ./header
