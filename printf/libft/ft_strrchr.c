/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atokamot <atokamot@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/17 13:14:24 by atokamot          #+#    #+#             */
/*   Updated: 2023/05/29 16:26:17 by atokamot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	size_t	len;

	len = ft_strlen(s);
	while (len >= 0)
	{
		if (s[len] == (char)c)
			return ((char *)&s[len]);
		if (len == 0)
			break ;
		len--;
	}
	return (NULL);
}

/*
int	main(void)
{
	char	*s;

	s = "libft-test-tokyo";
	printf("ft:%s ori:%s\n", ft_strrchr(s, 'a'), strrchr(s, 'a'));
	printf("ft:%s ori:%s\n", ft_strrchr(s, '~'), strrchr(s, '~'));
	return (0);
}
*/
