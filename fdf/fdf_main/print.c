/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atokamot <atokamot@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/17 12:01:58 by atokamot          #+#    #+#             */
/*   Updated: 2023/07/26 23:27:15 by atokamot         ###   ########.fr       */
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

int diff_color(int color1, int color2, int x, int min_x, int max_x)
{
	double ratio;
	double diff;

	ratio = (double)x - (double)min_x / (double)max_x - (double)min_x;
	diff = (double)(color2 - color1) * ratio;
	return ((int)diff);
}

void print_vertical()
{
	int y;

	y = min_y();
	while(y <= max_y)	
	{
		my_mlx_pixel_put(vars, x + DIS_W / 2 , y + DIS_H, color1 + diff_color());
		y++;
	}
}

void print_horizontall()
{
	int x;

	x = min_x();
	while(y <= max_x)	
	{
		my_mlx_pixel_put(vars, x + DIS_W / 2 , y + DIS_H, color1 + diff_color());
		y++;
	}
}

void connect_dot(double ax, double ay, double bx, double by, t_vars *vars, int zoom, int color1, int color2)
{
	int x;
	int y;
	int min_x;
	int max_x;
	double slope;
	double intercept;

	if (ax == bx)
		return (print_vertical());
	else if (ay == by)
		return (print_horizontall());
	slope = get_slope();	
	intercept = get_intercept();
	min_x = fmin(ax, bx);
	max_x = fmax(ax, bx);
	while (x < fmax)
	{
		y = round((double)x * slope + intercept);
		my_mlx_pixel_put(vars, x + DIS_W / 2 , y + DIS_H, color1 + diff_color());
		x++;
	}
}

/*connect dot
void connect_dot(double ax, double ay, double bx, double by, t_vars *vars, int zoom)
{
	int x;
	int y;
	double slope;
	double intercept;
	double check;

	//zoom
	ax = zoom * ax;
	ay = zoom * ay;
	bx = zoom * bx;
	by = zoom * by;

	if (ax == bx)
	{
		y = (int)fmin(ay, by);
		x = ax;
		while (y < (int)fmax(ay, by))
		{
			if ((int)x + DIS_W / 2 > 0 && (int)x + DIS_W / 2 < DIS_W \
				&& (int)y + DIS_H / 2 > 0 && (int)y + DIS_H / 2 < DIS_H)
			{
				my_mlx_pixel_put(vars, (int)x + DIS_W / 2 , (int)y + DIS_H / 2, 0x00FFFFFF);
			}
			y++;
		}
		return ;
	}

	if (ay == by)
	{
		x = (int)fmin(ax, bx);
		y = ay;
		while (x < (int)fmax(ax, bx))
		{
			if ((int)x + DIS_W / 2 > 0 && (int)x + DIS_W / 2 < DIS_W \
				&& (int)y + DIS_H / 2 > 0 && (int)y + DIS_H / 2 < DIS_H)
			{
				my_mlx_pixel_put(vars, (int)x + DIS_W / 2 , (int)y + DIS_H / 2, 0x00FFFFFF);
			}
			x++;
		}
		return ;
	}

	if (ax != bx)
	{
		slope = (by - ay) / (bx - ax);
		intercept = ay - slope * ax;
	}


	if (ax <= bx)
		x = ax;
	else
		x = bx;
	
	if (ay <= by)
		y = ay;
	else
		y = by;
	
	// printf("connect ax=%f, ay=%f, bx=%f, by=%f\n", ax, ay, bx, by);
	// printf("int connect ax=%d, bx=%d, ay=%d, by=%d\n", (int)ax, (int)bx, (int)ay, (int)by);
	if (ax == bx)
	{
		while(y <= by || y <= ay)
		{
			if ((int)x + DIS_W / 2 > 0 && (int)x + DIS_W / 2 < DIS_W \
				&& (int)y + DIS_H / 2 > 0 && (int)y + DIS_H / 2 < DIS_H)
			{
				my_mlx_pixel_put(vars, (int)x + DIS_W / 2 , (int)y + DIS_H / 2, 0x00FFFFFF);
			}
			y++;
		}
	}
	// printf("min x=%d, y=%d\n", x, y);
	// printf("slope = %f, intercept = %f\n", slope, intercept);
	int tmp = (int)y;
	while(x <= bx || x <= ax)
	{
		y = tmp;	
		while(y <= by || y <= ay)
		{
			check = y - slope * x - intercept;
			// printf("check = %f\n", check);
			if (check < 2 && check > -2)
			{
				// printf("-----put pixel------\n");
				if ((int)x + DIS_W / 2 > 0 && (int)x + DIS_W / 2 < DIS_W \
					&& (int)y + DIS_H / 2 > 0 && (int)y + DIS_H / 2 < DIS_H)
				{
					my_mlx_pixel_put(vars, (int)x + DIS_W / 2 , (int)y + DIS_H / 2, 0x00FFFFFF);
				}
			}
			// printf("x=%d, y=%d\n", x + DIS_W / 2 , y + DIS_H / 2);
			y++;
		}
		x++;
	}
}
*/

void put_pixel_to_map(t_wid_hig size, t_cor *map, t_vars *vars, int zoom)
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
				connect_dot(map[num].x, map[num].y, map[num + size.w].x, map[num + size.w].y, vars, zoom);
			}
			if (x < size.w - 1)
			{
				connect_dot(map[num].x, map[num].y, map[num + 1].x, map[num + 1].y, vars, zoom);
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

	//print
	put_pixel_to_map(vars->size, vars->map, vars, vars->zoom);

	free(vars->map);

	mlx_put_image_to_window(vars->mlx, vars->win, vars->img, 0, 0);
}