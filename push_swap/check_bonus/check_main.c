/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_main.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atokamot <atokamot@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/05 00:23:34 by atokamot          #+#    #+#             */
/*   Updated: 2023/07/05 22:49:49 by atokamot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/algorithm.h"
#include "../header/bonus_check.h"
#include "../header/ft_lst.h"
#include "../header/get_next_line.h"
#include "../header/operate.h"
#include "../header/push_swap.h"
#include "../header/sort.h"

void	help_check_result(t_three_lists *lists, char *str)
{
	if (ft_strcmp(str, "sa\n") == 0 || ft_strcmp(str, "sb\n") == 0
		|| ft_strcmp(str, "ss\n") == 0)
		check_swap(str, lists);
	else if (ft_strcmp(str, "pa\n") == 0 || ft_strcmp(str, "pb\n") == 0)
		check_push(str, lists);
	else if (ft_strcmp(str, "ra\n") == 0 || ft_strcmp(str, "rb\n") == 0
		|| ft_strcmp(str, "rr\n") == 0)
		check_rotate(str, lists);
	else if (ft_strcmp(str, "rra\n") == 0 || ft_strcmp(str, "rrb\n") == 0
		|| ft_strcmp(str, "rrr\n") == 0)
		check_rev_rotate(str, lists);
	else
		print_error_and_exit();
}

void	check_result(t_three_lists *lists)
{
	char	*str;

	while (1)
	{
		str = get_next_line(0);
		if (str == NULL)
			break ;
		help_check_result(lists, str);
		free(str);
	}
	if (check_sorted(ft_lstsize(lists->sub_list_a), lists->sub_list_a) == OK
		&& ft_lstsize(lists->sub_list_b) == 0)
		write(1, "OK\n", 3);
	else
		write(1, "KO\n", 3);
}

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
	check_result(&three_lists);
	free(array);
	ft_lstclear(&list, &del);
	ft_lstclear(&three_lists.sub_list_a, &del);
	ft_lstclear(&three_lists.sub_list_b, &del);
	return (0);
}
