/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_format2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atokamot <atokamot@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/01 11:39:10 by atokamot          #+#    #+#             */
/*   Updated: 2023/06/01 12:36:50 by atokamot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int u_format(va_list ap)
{
    unsigned int u;

    u = va_arg(ap, unsigned int);
    ft_putunbr_fd(c, FD);
    return (?);
}

int lo_x_format(va_list ap)
{
    unsigned int lo_x;
    char *s;

    lo_x = va_arg(ap, unsigned int);
    s = ft_tohex(lo_x);
    ft_tolowwer(s);
    ft_putstr_fd(s, FD);
    return (ft_strlen(s));
}

int up_x_format(va_list ap)
{
    unsigned int up_x;
    char *s;

    up_x = va_arg(ap, unsigned int);
    s = ft_tohex(up_x);
    ft_toupper(s);
    ft_putstr_fd(s, FD);
    return (ft_strlen(s)); 
}

int per_format(va_ldst ap)
{
    char per;

    per = '%';
    ft_putchar_fd(per, FD);
    return (1);
}
