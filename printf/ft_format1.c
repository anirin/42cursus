/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_format1.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atokamot <atokamot@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/01 11:39:10 by atokamot          #+#    #+#             */
/*   Updated: 2023/06/03 20:39:26 by atokamot         ###   ########.fr       */
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
	if (s == NULL)
	{
		write(1, "(null)", 6);
		return (6);
	}
	ft_putstr_fd(s, FD);
	return (ft_strlen(s));
}

size_t	p_format(va_list ap)
{
	unsigned long	p;
	const char		hex[] = "0123456789abcdef";

	p = (unsigned long)va_arg(ap, void *);
	ft_putstr_fd("0x", FD);
	put_hex(p, hex);
	return (ft_get_hexlen(p) + 2);
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
