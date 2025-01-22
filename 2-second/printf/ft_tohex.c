/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tohex.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atokamot <atokamot@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/01 22:04:09 by atokamot          #+#    #+#             */
/*   Updated: 2023/06/03 20:04:42 by atokamot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft.h"

void	put_hex(unsigned long num, const char *hex)
{
	if (num > 15)
		put_hex(num / 16, hex);
	ft_putchar_fd(hex[num % 16], FD);
}
