/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putunbr_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atokamot <atokamot@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/02 21:58:20 by atokamot          #+#    #+#             */
/*   Updated: 2023/06/02 22:06:30 by atokamot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft.h"

void	ft_putunbr_fd(unsigned int n, int fd)
{
	if (n / 10 != 0)
		ft_putunbr_fd(n / 10, fd);
	ft_putchar_fd(n % 10 + '0', fd);
}