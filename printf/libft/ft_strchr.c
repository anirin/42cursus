/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atokamot <atokamot@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/17 12:59:23 by atokamot          #+#    #+#             */
/*   Updated: 2023/05/23 16:38:38 by atokamot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	while (*s != 0)
	{
		if (*s == (char)c)
			return ((char *)s);
		s++;
	}
	if (c == 0)
		return ((char *)s);
	return (NULL);
}

/*
#include <stdio.h>

int	main(void)
{
	char	*s;

	s = "libft-test-tokyo";
	printf("ft:%s ori:%s\n", ft_strchr(s, 'l' + 256), strchr(s, 'l' + 256));
	printf("ft:%s ori:%s\n", ft_strchr(s, 'l' + 256), strchr(s, 'l' + 256));
	printf("ft:%s ori:%s\n", ft_strchr(s, 'l' - 256), strchr(s, 'l' - 256));
	printf("ft:%s ori:%s\n", ft_strchr(s, 'l' - 256), strchr(s, 'l' - 256));
	return (0);
}
*/
