/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_format1.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atokamot <atokamot@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/01 11:39:10 by atokamot          #+#    #+#             */
/*   Updated: 2023/06/01 23:23:50 by atokamot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft.h"

size_t	c_format(va_list ap)
{
	int	c;

	c = va_arg(ap, int);
	ft_putchar_fd(c, FD);
	return (1);
}

size_t	s_format(va_list ap)
{
	char	*s;

	s = va_arg(ap, char *);
	ft_putstr_fd(s, FD);
	return (ft_strlen(s));
}

size_t	p_format(va_list ap)
{
	long		p;
	char		*s;
	const char	hex[];
	size_t		len;
	size_t		i;

	hex[] = "0123456789abcdef";
	i = 0;
	p = va_arg(ap, long);
	s = tohex(p, hex);
	s = rev_arry(s);
	ft_putstr_fd("0x", FD);
	ft_putstr_fd(s, FD);
	len = ft_strlen(s);
	free(s);
	return (len + 2);
}

size_t	d_format(va_list ap)
{
	int	d;

	d = va_arg(ap, int);
	ft_putnbr_fd(d, FD);
	return (ft_get_numlen(d));
}

size_t	i_format(va_list ap)
{
	int	i;

	i = va_arg(ap, int);
	ft_putnbr_fd(i, FD);
	return (ft_get_numlen(i));
}
