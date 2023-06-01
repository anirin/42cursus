/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_format1.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atokamot <atokamot@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/01 11:39:10 by atokamot          #+#    #+#             */
/*   Updated: 2023/06/01 12:38:54 by atokamot         ###   ########.fr       */
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

int p_format(va_list ap)
{
    void *p;

    p = va_arg(ap, void *);
    ft_??(p, FD);
    return (?); 
}

int d_format(va_ldst ap)
{
    int d;

    d = va_arg(ap, int);
    ft_putnbr_fd(d, FD);
    return (ft_strlen(ft_dtoa(d)));
}

int i_format(va_list ap)
{
    int i;

    i = va_arg(ap, int);
    ft_putnbr_fd(i, FD);
    return (ft_strlen(ft_itoa(i)));
}