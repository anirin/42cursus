/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_format2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atokamot <atokamot@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/01 11:39:10 by atokamot          #+#    #+#             */
/*   Updated: 2023/06/03 20:39:44 by atokamot         ###   ########.fr       */
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
	const char		hex[] = "0123456789abcdef";

	lo_x = va_arg(ap, unsigned int);
	put_hex(lo_x, hex);
	return (ft_get_hexlen(lo_x));
}

size_t	up_x_format(va_list ap)
{
	unsigned int	up_x;
	const char		hex[] = "0123456789ABCDEF";

	up_x = va_arg(ap, unsigned int);
	put_hex(up_x, hex);
	return (ft_get_hexlen(up_x));
}

size_t	per_format(va_list ap)
{
	char	per;

	(void)ap;
	per = '%';
	ft_putchar_fd(per, FD);
	return (1);
}
