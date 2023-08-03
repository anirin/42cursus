/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_color.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atokamot <atokamot@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/26 19:57:16 by atokamot          #+#    #+#             */
/*   Updated: 2023/08/03 14:23:33 by atokamot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/fdf.h"
#include "../header/libft.h"

int	get_color(const char *str)
{
	char	*hex_num;
	size_t	len;
	int		color;
	size_t	i;

	color = 0;
	i = 2;
	hex_num = ft_strchr(str, ',') + 1;
	len = ft_strlen(hex_num);
	while (i < len)
	{
		if (ft_isdigit(hex_num[i]))
			color = 16 * color + hex_num[i] - '0';
		else if (hex_num[i] >= 'a' && hex_num[i] <= 'z')
			color = 16 * color + hex_num[i] - 'a' + 10;
		else
			color = 16 * color + hex_num[i] - 'A' + 10;
		i++;
	}
	return (color);
}
