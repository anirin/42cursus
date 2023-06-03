/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_format2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atokamot <atokamot@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/01 11:39:10 by atokamot          #+#    #+#             */
/*   Updated: 2023/06/02 22:03:24 by atokamot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft.h"

size_t	u_format(va_list ap)
{
	unsigned int	u;

	u = va_arg(ap, unsigned int);
	ft_putunbr_fd(u, FD);
	return (ft_get_unumlen(u));
}

size_t	lo_x_format(va_list ap)
{
	unsigned int	lo_x;
	char			*s;
	size_t			len;
	size_t			i;
	const char		hex[] = "0123456789abcdef";
	i = 0;
	lo_x = va_arg(ap, unsigned int);
	s = tohex(lo_x, hex);
	s = rev_arry(s);
	ft_putstr_fd(s, FD);
	len = ft_strlen(s);
	free(s);
	return (len);
}

size_t	up_x_format(va_list ap)
{
	unsigned int	up_x;
	char			*s;
	size_t			len;
	size_t			i;
	const char		hex[] = "0123456789ABCDEF";

	i = 0;
	up_x = va_arg(ap, unsigned int);
	s = tohex(up_x, hex);
	s = rev_arry(s);
	ft_putstr_fd(s, FD);
	len = ft_strlen(s);
	free(s);
	return (len);
}

size_t	per_format(va_list ap)
{
	char	per;

	(void)ap;
	per = '%';
	ft_putchar_fd(per, FD);
	return (1);
}
