/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   zoom_cor.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atsu <atsu@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/02 18:14:27 by atsu              #+#    #+#             */
/*   Updated: 2023/08/02 18:16:12 by atsu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/libft.h"
#include "../header/fdf.h"

void zoom_cor(t_cor *map, int size, int zoom)
{
	int i;

	i = 0;
	while (i < size)
	{
		map[i].x *= zoom;
		map[i].y *= zoom;
		map[i].z *= zoom;
		i++;
	}
}