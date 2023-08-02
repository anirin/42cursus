/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atsu <atsu@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/17 12:01:58 by atokamot          #+#    #+#             */
/*   Updated: 2023/08/02 18:02:04 by atsu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/libft.h"
#include "../header/fdf.h"

void	my_mlx_pixel_put(t_vars *vars, int x, int y, int color)
{
	char	*dst;

	dst = vars->addr + (y * vars->line_length + x * (vars->bits_per_pixel / 8));
	*(unsigned int*)dst = color;
}

static void put_pixel_to_map(t_wid_hig size, t_cor *map, t_vars *vars)
{
	int x;
	int y;
	int num;

	y = 0;
	while(y < size.h)	
	{
		x = 0;
		while(x < size.w)
		{
			num = x + y * size.w;
			if (y < size.h - 1)
			{
				connect_dot(map[num], map[num + size.w], vars);
			}
			if (x < size.w - 1)
			{
				connect_dot(map[num], map[num + 1], vars);
			}
			x++;
		}
		y++;
	}
}

void print_map(t_vars *vars)
{
	vars->map = copy_map(vars->save_map, vars->size.w * vars->size.h);
	rotate_cor_x(vars->map, vars->size.w * vars->size.h, vars->x_degree);
	rotate_cor_y(vars->map, vars->size.w * vars->size.h, vars->y_degree);
	rotate_cor_z(vars->map, vars->size.w * vars->size.h, vars->z_degree);
	change_cor_isometic(vars->map, vars->size.w * vars->size.h);
	zoom_cor(vars->map, vars->size.w * vars->size.h, vars->zoom);
	put_pixel_to_map(vars->size, vars->map, vars);
	free(vars->map);
	mlx_put_image_to_window(vars->mlx, vars->win, vars->img, 0, 0);
}