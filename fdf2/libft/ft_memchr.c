/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atsu <atsu@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/17 13:27:48 by atokamot          #+#    #+#             */
/*   Updated: 2023/08/02 18:23:47 by atsu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/libft.h"

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
