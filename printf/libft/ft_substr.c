/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atokamot <atokamot@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/17 16:26:35 by atokamot          #+#    #+#             */
/*   Updated: 2023/05/26 10:56:29 by atokamot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*substr;
	int		i;

	i = 0;
	if (s == NULL)
		return (NULL);
	if ((unsigned int)ft_strlen(s) < start + 1)
		return (ft_strdup(""));
	if (len <= ft_strlen(s))
		substr = ft_calloc(len + 1, 1);
	else
		substr = ft_calloc(ft_strlen(s) + 1, 1);
	if (substr == NULL)
		return (NULL);
	while (len-- && s[i + start] != '\0')
	{
		substr[i] = s[i + start];
		i++;
	}
	return (substr);
}

/*
#include <stdio.h>

int	main(void)
{
	char const		s[];
	unsigned int	start;
	size_t			len;

	s[] = "abcdefg";
	start = 4;
	len = 40;
	printf("%s\n", ft_substr(s, start, len));
}
*/
