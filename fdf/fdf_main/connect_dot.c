/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   connect_dot.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atsu <atsu@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/29 15:41:57 by atsu              #+#    #+#             */
/*   Updated: 2023/07/29 16:01:23 by atsu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/libft.h"
#include "../header/fdf.h"

static int connect_color(int color1, int color2, double dist, double max_dist)
{
	double ratio;
	double diff;

	ratio = dist / max_dist;
	diff = (double)(color2 - color1) * ratio;
	return ((int)diff + color1);
}

static void connect_vertical(t_equation equ, t_vars *vars, int color1, int color2)
{
	int x;
	int y;

	x = (int)equ.min_x;
	y = (int)equ.min_y;
	while(y <= (int)equ.max_y)	
	{
		my_mlx_pixel_put(vars, x + DIS_W / 2 , y + DIS_H, connect_color(color1, color2, (double)y - equ.min_y, equ.max_y - equ.min_y));
		y++;
	}
}

static void connect_horizontall(t_equation equ, t_vars *vars, int color1, int color2)
{
	int x;
	int y;

	x = (int)equ.min_x;
	y = (int)equ.min_y;
	while(x <= (int)equ.max_x)	
	{
		my_mlx_pixel_put(vars, x + DIS_W / 2 , y + DIS_H, connect_color(color1, color2, (double)x - equ.min_x, equ.max_x - equ.min_x));
		x++;
	}
}

static void connect_other(t_equation equ, t_vars *vars, int color1, int color2)
{
	int x;
	int y;

	x = (int)round(equ.min_x);
	while (x < (int)equ.max_x)
	{
		y = (int)round((double)x * equ.slope + equ.intercept);
		my_mlx_pixel_put(vars, x + DIS_W / 2 , y + DIS_H, connect_color(color1, color2, x - equ.min_x, equ.max_x - equ.min_x));
		x++;
	}
}

void connect_dot(t_cor cor1, t_cor cor2, t_vars *vars)
{
	t_equation equ;

	equ.max_x = fmax(cor1.x, cor2.x);
	equ.max_y = fmax(cor1.y, cor2.y);
	equ.min_x = fmin(cor1.x, cor2.x);
	equ.min_y = fmin(cor1.y, cor2.y);
	if (cor1.x == cor2.x)
		return (connect_vertical(equ, vars, cor1.color, cor2.color));
	else if (cor1.y == cor2.y)
		return (connect_horizontall(equ, vars, cor1.color, cor2.color));
	equ.slope = get_slope(cor1, cor2);	
	equ.intercept = get_intercept(cor1, equ.slope);
	connect_other(equ, vars, cor1.color, cor2.color);
}