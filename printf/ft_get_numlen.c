/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_numlen.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atokamot <atokamot@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/01 12:46:55 by atokamot          #+#    #+#             */
/*   Updated: 2023/06/01 12:49:14 by atokamot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int ft_get_numlen(long num)
{
    int len;

    len = 1;
    if (num < 0)
    {
        num *= -1;
        len++;
    }
    while (num > 0)
    {
        num /= 10;
        len++;
    }
    return (len);
}