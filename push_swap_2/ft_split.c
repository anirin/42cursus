/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atokamot <atokamot@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/24 10:39:47 by atokamot          #+#    #+#             */
/*   Updated: 2023/06/19 20:19:54 by atokamot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static size_t	get_word_num(char const *s, char c)
{
	size_t	count;
	size_t	i;
	size_t	flag;

	count = 0;
	i = 0;
	flag = HEAD;
	while (s[i])
	{
		while (s[i] == c)
		{
			flag = HEAD;
			i++;
		}
		if (flag == HEAD && s[i] != c && s[i] != 0)
		{
			flag = NOT_HEAD;
			count++;
		}
		i++;
	}
	return (count);
}

static int	set_str(char const *s, int len, char **result, int i)
{
	result[i] = malloc(len + 1);
	if (result[i] == NULL)
	{
		while (i-- >= 0)
		{
			free(result[i]);
		}
		free(result);
		return (NG);
	}
	result[i][len] = '\0';
	while (len-- > 0)
	{
		result[i][len] = *s--;
	}
	return (OK);
}

static char	**ft_split_sub(char **result, char const *s, char c, size_t i)
{
	int	len;

	while (*s)
	{
		len = 0;
		while (*s != c && *s != 0)
		{
			len++;
			s++;
		}
		if (len > 0)
		{
			if (set_str(s - 1, len, result, i++) == NG)
				return (NULL);
		}
		else
			s++;
	}
	result[i] = NULL;
	return (result);
}

char	**ft_split(char const *s, char c)
{
	char	**result;
	size_t	i;

	i = 0;
	if (s == NULL)
		return (NULL);
	result = malloc(sizeof(char *) * (get_word_num(s, c) + 1));
	if (result == NULL)
		return (NULL);
	return (ft_split_sub(result, s, c, i));
}