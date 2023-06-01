/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_format1.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atokamot <atokamot@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/01 11:39:10 by atokamot          #+#    #+#             */
/*   Updated: 2023/06/01 19:23:59 by atokamot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int c_format(va_list ap)
{
    char c;

    c = va_arg(ap, char);
    ft_putchar_fd(c, FD);
    return (1);
}

int s_format(va_list ap)
{
    char *s;

    s = va_arg(ap, char *);
    ft_putstr_fd(s, FD);
    return (ft_strlen(s));
}

size_t p_format(va_list ap)
{
    long p;
    char *s;
    size_t len;

    p = va_arg(ap, long);
    s = ft_tohex(p);
    s = rev_arry(s);
    tolowwer(s);
    ft_putstr_fd("0x", FD);
    ft_putstr_fd(s, FD);
    len = ft_strlen(s);
    free(s);
    return (len + 2); 
}

int d_format(va_ldst ap)
{
    int d;

    d = va_arg(ap, int);
    ft_putnbr_fd(d, FD);
    return (ft_get_numlen(d));
}

int i_format(va_list ap)
{
    int i;

    i = va_arg(ap, int);
    ft_putnbr_fd(i, FD);
    return (ft_get_numlen(i));
}