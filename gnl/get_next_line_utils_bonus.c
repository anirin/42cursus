/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atokamot <atokamot@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/31 09:51:40 by atokamot          #+#    #+#             */
/*   Updated: 2023/05/31 10:00:33 by atokamot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

size_t	ft_strlen(const char *str)
{
	size_t	n;

	n = 0;
	while (*str != 0)
	{
		n++;
		str++;
	}
	return (n);
}

void	*ft_memset(void *buf, int ch, size_t n)
{
	size_t			i;
	unsigned char	*p;

	p = buf;
	i = 0;
	while (i < n)
	{
		*p++ = (unsigned char)ch;
		i++;
	}
	return (buf);
}

void	*ft_calloc(size_t num, size_t size)
{
	void	*ret;

	if (size != 0 && num > SIZE_MAX / size)
		return (NULL);
	ret = malloc(num * size);
	if (ret == NULL)
		return (NULL);
	ft_memset(ret, 0, num * size);
	return (ret);
}

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

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*substr;
	int		i;

	i = 0;
	if (s == NULL)
		return (NULL);
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
