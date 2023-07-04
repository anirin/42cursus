/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_check.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atokamot <atokamot@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/03 21:57:17 by atokamot          #+#    #+#             */
/*   Updated: 2023/07/05 00:17:29 by atokamot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/algorithm.h"
#include "../header/ft_lst.h"
#include "../header/operate.h"
#include "../header/push_swap.h"
#include "../header/sort.h"

int	check_invalid_str(int argc, char **argv)
{
	int		i;
	int		j;
	char	*str;

	i = 1;
	j = 0;
	while (i < argc)
	{
		str = argv[i++];
		j = 0;
		while (str[j] != '\0')
		{
			if (ft_issapce(str[j]) == NG && ft_isdigit(str[j]) == NG
				&& is_plus_minus(str[j]) == NG)
				return (NG);
			if (is_plus_minus(str[j]) == OK && ft_isdigit(str[j + 1]) == NG)
				return (NG);
			if (ft_isdigit(str[j]) == OK && is_plus_minus(str[j + 1]) == OK)
				return (NG);
			j++;
		}
	}
	return (OK);
}

int	check_dup(int *sorted_array, int size)
{
	int	i;

	i = 0;
	if (size <= 1)
		return (OK);
	while (i + 1 < size)
	{
		if (sorted_array[i] == sorted_array[i + 1])
			return (NG);
		i++;
	}
	return (OK);
}

int	check_sorted(int size, t_list *list)
{
	int	*array;
	int	count;

	array = malloc(sizeof(int) * size);
	if (array == NULL)
		print_error_and_exit();
	set_array(array, list);
	count = bub_sort_array(array, size);
	free(array);
	if (count == 0)
		return (OK);
	else
		return (NG);
}

void	print_error_and_exit(void)
{
	write(1, "ERROR\n", 6);
	exit(1);
}
