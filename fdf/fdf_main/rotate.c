/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atsu <atsu@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/31 14:46:08 by atsu              #+#    #+#             */
/*   Updated: 2023/08/02 17:48:20 by atsu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/libft.h"
#include "../header/fdf.h"

void rotate_cor_x(t_cor *map, int size, int degree)
{
	t_cor cor;
	int i;
	double rad;

	rad = degree * M_PI / 180;
	i = 0;
	while(i < size)
	{
		cor.y = map[i].y;
		cor.z = map[i].z;
		map[i].y = cos(rad) * cor.y - sin(rad) * cor.z;
		map[i].z = sin(rad) * cor.y + cos(rad) * cor.z;
		i++;
	}
}

void rotate_cor_y(t_cor *map, int size, int degree)
{
	t_cor cor;
	int i;
	double rad;

	rad = degree * M_PI / 180;
	i = 0;
	while(i < size)
	{
		cor.x = map[i].x;
		cor.z = map[i].z;
		map[i].x = cos(rad) * cor.x + sin(rad) * cor.z;
		map[i].z =  -sin(rad) * cor.y + cos(rad) * cor.z;
		i++;
	}
}

void rotate_cor_z(t_cor *map, int size, int degree)
{
	t_cor cor;
	int i;
	double rad;

	rad = degree * M_PI / 180;
	i = 0;
	while(i < size)
	{
		cor.x = map[i].x;
		cor.y = map[i].y;
		map[i].x = cos(rad) * cor.x - sin(rad) * cor.y;
		map[i].y = sin(rad) * cor.x + cos(rad) * cor.y;
		i++;
	}
}

void change_cor_isometic(t_cor *map, int size)
{
	t_cor cor;
	int i;
	double rad;

	rad = 30 * M_PI / 180;
	i = 0;
	while(i < size)
	{
		cor.x = map[i].x;
		cor.y = map[i].y;
		cor.z = map[i].z;
		map[i].x = cor.x - cor.y;
		map[i].y = tan(rad) * cor.x + tan(rad) * cor.y - cor.z;
		i++;
	}
}