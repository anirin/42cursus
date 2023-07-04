/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_is_check.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atokamot <atokamot@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/16 16:17:12 by atokamot          #+#    #+#             */
/*   Updated: 2023/07/04 23:59:51 by atokamot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/algorithm.h"
#include "../header/ft_lst.h"
#include "../header/operate.h"
#include "../header/push_swap.h"
#include "../header/sort.h"

int	ft_isdigit(int c)
{
	if (c >= '0' && c <= '9')
		return (OK);
	else
		return (NG);
}

int	ft_issapce(int c)
{
	if (c == ' ')
		return (OK);
	else
		return (NG);
}

int	is_plus_minus(int c)
{
	if (c == '+' || c == '-')
		return (OK);
	else
		return (NG);
}
