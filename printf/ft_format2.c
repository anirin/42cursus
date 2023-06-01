/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_format2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atokamot <atokamot@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/01 11:39:10 by atokamot          #+#    #+#             */
/*   Updated: 2023/06/01 19:25:27 by atokamot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int u_format(va_list ap)
{
    unsigned int u;

    u = va_arg(ap, unsigned int);
    ft_putnbr_fd(c, FD);
    return (ft_get_numlen(u));
}

size_t lo_x_format(va_list ap)
{
    unsigned int lo_x;
    char *s;
    size_t len;
    

    lo_x = va_arg(ap, unsigned int);
    s = ft_tohex(lo_x);
    ft_tolowwer(s);
    ft_putstr_fd("0x", FD);
    ft_putstr_fd(s, FD);
    len = ft_strlen(s);
    free(s);
    return (len + 2);
}

size_t up_x_format(va_list ap)
{
    unsigned int up_x;
    char *s;
    size_t len;
    

    up_x = va_arg(ap, unsigned int);
    s = ft_tohex(up_x);
    ft_toupwwer(s);
    ft_putstr_fd("0x", FD);
    ft_putstr_fd(s, FD);
    len = ft_strlen(s);
    free(s);
    return (len + 2);
}

int per_format(va_ldst ap)
{
    char per;

    per = '%';
    ft_putchar_fd(per, FD);
    return (1);
}
