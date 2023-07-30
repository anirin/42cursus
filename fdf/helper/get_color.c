/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_color.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atsu <atsu@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/26 19:57:16 by atokamot          #+#    #+#             */
/*   Updated: 2023/07/30 14:58:14 by atsu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/libft.h"
#include "../header/fdf.h"

int get_color(const char *str)
{ 
    char *hex_num;
    size_t len;
    int color;

	color = 0;
    hex_num = ft_strchr(str, ',') + 1;
    len = ft_strlen(hex_num);
    while(len-- >= 2)
    {
        if (ft_isdigit(hex_num[len]))
            color = 16 * color + hex_num[len] - '0';
        else
            color = 16 * color + hex_num[len] - 'A' + 10;
    }
	return (color);
}