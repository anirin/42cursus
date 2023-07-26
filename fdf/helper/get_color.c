/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_color.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atokamot <atokamot@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/26 19:57:16 by atokamot          #+#    #+#             */
/*   Updated: 2023/07/26 20:20:17 by atokamot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int get_color(const char *str)
{ 
    char *hex_num;
    size_t len;
    int color;

    hex_num = ft_strchr(str, ',') + 1;
    len = ft_strlen(hex_num);
    while(len-- >= 2)
    {
        if (is_num(hex_num[len]))
            color = 16 * color + hex_num[len] - '0';
        else
            color = 16 * color + hex_num[len] - 'A' + 10;
    }
}