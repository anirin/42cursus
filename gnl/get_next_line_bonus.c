/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atokamot <atokamot@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/31 09:51:42 by atokamot          #+#    #+#             */
/*   Updated: 2023/06/01 17:22:25 by atokamot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

size_t	ft_strlcat(char *dest, const char *src, size_t size)
{
	size_t	d_len;
	size_t	s_len;
	size_t	n;

	if (dest == NULL && size == 0)
		return (ft_strlen(src));
	d_len = ft_strlen(dest);
	s_len = ft_strlen(src);
	if (size <= d_len)
		return (size + s_len);
	n = size - d_len;
	dest += d_len;
	while (n--)
	{
		if (*src == '\0' || n == 0)
			break ;
		*dest++ = *src++;
	}
	*dest = '\0';
	return (s_len + d_len);
}

char	*ft_gnljoin(char const *s1, char const *s2, int check)
{
	char	*result;
	size_t	s1_len;

	if (s1 == NULL)
		return (NULL);
	s1_len = ft_strlen(s1);
	if (s1_len == 0 && check == 0)
		return (NULL);
	result = ft_calloc(s1_len + check + 1, 1);
	if (result == NULL)
		return (NULL);
	ft_strlcat(result, (char *)s1, s1_len + 1);
	ft_strlcat(result, (char *)s2, s1_len + check + 1);
	return (result);
}

char	*get_newline(char *save, int fd)
{
	char	buf[BUFFER_SIZE + 1];
	long	check;
	char	*tmp;

	while (1)
	{
		if (save == NULL || ft_strchr(save, '\n') == NULL)
		{
			check = read(fd, buf, BUFFER_SIZE);
			if (check == -1)
				return (NULL);
			buf[check] = '\0';
			if (save == NULL)
				save = ft_calloc(1, 1);
			tmp = save;
			save = ft_gnljoin(tmp, buf, check);
			free(tmp);
			if (save == NULL)
				return (NULL);
		}
		if (check != BUFFER_SIZE || ft_strchr(save, '\n') != NULL)
			break ;
	}
	return (save);
}

char	*get_next_line(int fd)
{
	static char	*save[OPEN_MAX];
	char		*tmp;
	char		*newline;

	if (fd < 0)
		return (NULL);
	save[fd] = get_newline(save[fd], fd);
	if (save[fd] == NULL)
		return (NULL);
	if (ft_strchr(save[fd], '\n') == NULL)
	{
		newline = ft_substr(save[fd], 0, ft_strlen(save[fd]));
		free(save[fd]);
		save[fd] = NULL;
		return (newline);
	}
	tmp = save[fd];
	newline = ft_substr(tmp, 0, ft_strchr(tmp, '\n') - tmp + 1);
	save[fd] = ft_substr(tmp, ft_strchr(tmp, '\n') - tmp + 1, ft_strlen(tmp));
	free(tmp);
	if (save[fd] == NULL)
		return (NULL);
	return (newline);
}
