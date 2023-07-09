/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atokamot <atokamot@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/09 14:29:58 by atokamot          #+#    #+#             */
/*   Updated: 2023/07/10 07:59:17 by atokamot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int*)dst = color;
}

void connect_dot(double ax, double ay, double bx, double by, t_data img)
{
	double x;
	double y;
	double slope;
	double intercept;
	double check;

	slope = (by - ay) / (bx - ax);
	intercept = ay - slope * ax;

	if (ax <= bx)
		x = ax;
	else
		x = bx;
	
	if (ay <= by)
		y = ay;
	else
		y = by;

	while(x <= bx || x <= ax)
	{
		y = 0;
		while(y <= by || y <= ay)
		{
			check = y - slope * x - intercept;
			if (check < 2 && check > -2)
				my_mlx_pixel_put(&img, x, y, 0x00FF0000);
			y++;
		}
		x++;
	}
}

int	main(void)
{
	void	*mlx;
	void	*mlx_win;
	t_data	img;

	mlx = mlx_init();
	mlx_win = mlx_new_window(mlx, 1920, 1080, "Hello world!");
	img.img = mlx_new_image(mlx, 1920, 1080);
	img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel, &img.line_length,
								&img.endian);

	
	mlx_put_image_to_window(mlx, mlx_win, img.img, 0, 0);
	mlx_loop(mlx);
}