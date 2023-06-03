/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tohex.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atokamot <atokamot@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/01 22:04:09 by atokamot          #+#    #+#             */
/*   Updated: 2023/06/02 18:11:34y atokamot         ###   ########.fr       */
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
		tmp[i++] = s[len - 1];
        len--;
	}
	strlcpy(s, tmp, strlen(s) + 1);
	return (s);
}

char	*tohex(unsigned long num, const char *hex)
{
	char	*hex_num;
	int		i;

	i = 0;
	hex_num = calloc(17, 1);
	if (hex_num == NULL)
		return (NULL);
	if (num == 0)
		hex_num[i] = hex[0];
	while (num != 0)
	{
		hex_num[i++] = hex[num % 16];
		num /= 16;
	}
	return (hex_num);
}
