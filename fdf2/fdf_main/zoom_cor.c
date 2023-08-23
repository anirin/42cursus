/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   zoom_cor.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atsu <atsu@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/02 18:14:27 by atsu              #+#    #+#             */
/*   Updated: 2023/08/03 14:14:41 by atokamot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/fdf.h"
#include "../header/libft.h"

void	zoom_cor(t_cor *map, int size, int zoom)
{
	int	i;

	i = 0;
	while (i < size)
	{
		map[i].x *= zoom;
		map[i].y *= zoom;
		map[i].z *= zoom;
		i++;
	}
}
