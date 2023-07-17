/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atokamot <atokamot@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/17 13:27:48 by atokamot          #+#    #+#             */
/*   Updated: 2023/05/23 16:38:36 by atokamot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *buf, int ch, size_t n)
{
	const unsigned char	*p;

	p = buf;
	while (n--)
	{
		if (*p == (unsigned char)ch)
			return ((void *)p);
		p++;
	}
	return (NULL);
}
