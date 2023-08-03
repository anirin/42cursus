/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   connect_dot.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atsu <atsu@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/29 15:41:57 by atsu              #+#    #+#             */
/*   Updated: 2023/08/03 14:25:39 by atokamot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/fdf.h"
#include "../header/libft.h"

static void	connect_vertical(t_equation equ, t_vars *vars, int color1,
		int color2)
{
	int	x;
	int	y;

	x = (int)equ.min_x;
	y = (int)equ.min_y;
	while (y <= (int)equ.max_y)
	{
		if ((x + DIS_W / 2 > 0 && x + DIS_W / 2 < DIS_W) && (y + DIS_H / 2 > 0
				&& y + DIS_H / 2 < DIS_H))
			my_mlx_pixel_put(vars, x + DIS_W / 2, y + DIS_H / 2,
				connect_color(color1, color2, (double)y - equ.min_y,
					equ.max_y - equ.min_y));
		y++;
	}
}

static void	connect_horizontall(t_equation equ, t_vars *vars, int color1,
		int color2)
{
	int	x;
	int	y;

	x = (int)equ.min_x;
	y = (int)equ.min_y;
	while (x <= (int)equ.max_x)
	{
		if ((x + DIS_W / 2 > 0 && x + DIS_W / 2 < DIS_W) && (y + DIS_H / 2 > 0
				&& y + DIS_H / 2 < DIS_H))
			my_mlx_pixel_put(vars, x + DIS_W / 2, y + DIS_H / 2,
				connect_color(color1, color2, (double)x - equ.min_x,
					equ.max_x - equ.min_x));
		x++;
	}
}

static void	connect_other_x(t_equation equ, t_vars *vars, int color1,
		int color2)
{
	int	x;
	int	y;

	x = (int)round(equ.min_x);
	while (x < (int)equ.max_x)
	{
		y = (int)round((double)x * equ.slope + equ.intercept);
		if ((x + DIS_W / 2 > 0 && x + DIS_W / 2 < DIS_W) && (y + DIS_H / 2 > 0
				&& y + DIS_H / 2 < DIS_H))
		{
			my_mlx_pixel_put(vars, x + DIS_W / 2, y + DIS_H / 2,
				connect_color(color1, color2, x - equ.min_x, equ.max_x
					- equ.min_x));
		}
		x++;
	}
}

static void	connect_other_y(t_equation equ, t_vars *vars, int color1,
		int color2)
{
	int	x;
	int	y;

	y = (int)round(equ.min_y);
	while (y < (int)equ.max_y)
	{
		x = (int)round(((double)y - equ.intercept) / equ.slope);
		if ((x + DIS_W / 2 > 0 && x + DIS_W / 2 < DIS_W) && (y + DIS_H / 2 > 0
				&& y + DIS_H / 2 < DIS_H))
		{
			my_mlx_pixel_put(vars, x + DIS_W / 2, y + DIS_H / 2,
				connect_color(color1, color2, y - equ.min_y, equ.max_y
					- equ.min_y));
		}
		y++;
	}
}

void	connect_dot(t_cor cor1, t_cor cor2, t_vars *vars)
{
	t_equation	equ;

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
	if (cor1.x == equ.min_x)
		connect_other_x(equ, vars, cor1.color, cor2.color);
	else
		connect_other_x(equ, vars, cor2.color, cor1.color);
	if (cor1.y == equ.min_y)
		connect_other_y(equ, vars, cor1.color, cor2.color);
	else
		connect_other_y(equ, vars, cor2.color, cor1.color);
}
