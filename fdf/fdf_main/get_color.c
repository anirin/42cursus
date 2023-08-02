/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_color.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atsu <atsu@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/26 19:57:16 by atokamot          #+#    #+#             */
/*   Updated: 2023/07/31 13:38:01 by atsu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/libft.h"
#include "../header/fdf.h"

int get_color(const char *str)
{ 
    char *hex_num;
    size_t len;
    int color;
	size_t i;

	color = 0;
	i = 2;
    hex_num = ft_strchr(str, ',') + 1;
    len = ft_strlen(hex_num);
    while(i < len)
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

int	create_trgb(unsigned char t, unsigned char r, unsigned char g, unsigned char b)
{
	return (*(int *)(unsigned char [4]){b, g, r, t});
}

unsigned char	get_t(int trgb)
{
	return (((unsigned char *)&trgb)[3]);
}

unsigned char	get_r(int trgb)
{
	return (((unsigned char *)&trgb)[2]);
}

unsigned char	get_g(int trgb)
{
	return (((unsigned char *)&trgb)[1]);
}

unsigned char	get_b(int trgb)
{
	return (((unsigned char *)&trgb)[0]);
}