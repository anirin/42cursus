/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tohex.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atokamot <atokamot@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/01 22:04:09 by atokamot          #+#    #+#             */
/*   Updated: 2023/06/01 23:24:25 by atokamot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft.h"

char	*rev_arry(char *s)
{
	int		len;
	int		i;
	char	tmp[17];

	if (s == NULL)
		return (NULL);
	len = strlen(s);
	i = 0;
	while (len)
	{
		tmp[i++] = s[len-- - 1];
	}
	strlcpy(s, tmp, strlen(s));
	return (s);
}

char	*tohex(long num, const char *hex)
{
	char	*hex_num;
	int		i;

	i = 0;
	hex_num = calloc(17, 1);
	if (hex_num == NULL)
		return (NULL);
	if (num == 0)
	{
		hex_num[i] = hex[0];
		return (hex_num);
	}
	if (num < 0)
	{
		hex_num[i++] = '-';
		num *= -1;
	}
	while (num > 0)
	{
		hex_num[i++] = hex[num % 16];
		num /= 16;
	}
	return (hex_num);
}
