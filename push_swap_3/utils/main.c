/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atokamot <atokamot@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/29 10:09:10 by atokamot          #+#    #+#             */
/*   Updated: 2023/07/05 22:44:17 by atokamot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/algorithm.h"
#include "../header/ft_lst.h"
#include "../header/operate.h"
#include "../header/push_swap.h"
#include "../header/sort.h"

int	main(int argc, char **argv)
{
	int				*array;
	int				size;
	t_three_lists	three_lists;
	t_list			*list;

	list = NULL;
	if (check_invalid_str(argc, argv) == NG || argc <= 1)
		print_error_and_exit();
	if (first_set_list(argc, argv, &list) == NG)
		print_error_and_exit();
	size = ft_lstsize(list);
	array = set_main_array(size, list);
	if (array == NULL)
		print_error_and_exit();
	set_main_lists(&three_lists, size, array);
	if (check_sorted(size, list) == NG)
		push_swap(&three_lists);
	print_list(three_lists.sub_swap_result);
	free(array);
	ft_lstclear(&list, &del);
	ft_lstclear(&three_lists.sub_list_a, &del);
	ft_lstclear(&three_lists.sub_swap_result, &del);
	return (0);
}

//gcc *.c ./*/*.c -I ./header
