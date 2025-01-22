/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atokamot <atokamot@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/19 13:39:18 by atokamot          #+#    #+#             */
/*   Updated: 2023/05/25 22:25:16 by atokamot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	ft_putnbr_fd_sub(long n, int fd)
{
	if (n / 10 != 0)
		ft_putnbr_fd_sub(n / 10, fd);
	ft_putchar_fd(n % 10 + '0', fd);
}

void	ft_putnbr_fd(int n, int fd)
{
	long	tmp;

	tmp = (long)n;
	if (tmp < 0)
	{
		ft_putchar_fd('-', fd);
		ft_putnbr_fd_sub(-tmp, fd);
	}
	else
		ft_putnbr_fd_sub(tmp, fd);
}
