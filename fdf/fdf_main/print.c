/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atsu <atsu@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/17 12:01:58 by atokamot          #+#    #+#             */
/*   Updated: 2023/07/29 12:20:43 by atsu             ###   ########.fr       */
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

void put_pixel_to_map(t_wid_hig size, t_cor *map, t_vars *vars)
{
	int x;
	int y;
	int num;

	x = 0;
	y = 0;
	while(y < size.h)	
	{
		x = 0;
		while(x < size.w)
		{
			num = x + y * size.w;
			if (y < size.h - 1)
			{
				// printf("x=%f, y=%f, x=%f, y=%f\n", map[num].x, map[num].y, map[num + size.w].x, map[num + size.w].y);
				connect_dot(map[num], map[num + size.w].x, vars);
			}
			if (x < size.w - 1)
			{
				connect_dot(map[num], map[num + size.w].x, vars);
			}
			x++;
		}
		y++;
	}
}

void print_map(t_vars *vars)
{
	//set map
	vars->map = copy_map(vars->save_map, vars->size.w * vars->size.h);
	vars->trig_ab = get_trig_ab((const t_vars)*vars);

	//rotate
	change_cor(vars->map, vars->size.w * vars->size.h, *vars, vars->trig_ab);
	
	//zoom
	zoom_cor(vars->map, vars->size.w * vars->size.h, vars->zoom);

	//print
	put_pixel_to_map(vars->size, vars->map, vars);

	free(vars->map);

	mlx_put_image_to_window(vars->mlx, vars->win, vars->img, 0, 0);
}