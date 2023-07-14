/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atokamot <atokamot@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/09 14:29:58 by atokamot          #+#    #+#             */
/*   Updated: 2023/07/10 15:40:17by atokamot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./header/libft.h"
#include "./header/fdf.h"

void	my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int*)dst = color;
}

void connect_dot(double ax, double ay, double bx, double by, t_data img)
{
	int x;
	int y;
	double slope;
	double intercept;
	double check;

	//zoom
	ax = ZOOM * ax;
	ay = ZOOM * ay;
	bx = ZOOM * bx;
	by = ZOOM * by;

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
	
	printf("connect ax=%f, ay=%f, bx=%f, by=%f\n", ax, ay, bx, by);
	// printf("int connect ax=%d, bx=%d, ay=%d, by=%d\n", (int)ax, (int)bx, (int)ay, (int)by);
	
	if (ax == bx)
	{
		while(y <= by || y <= ay)
		{
			if ((int)x + DIS_W / 2 > 0 && (int)x + DIS_W / 2 < DIS_W \
				&& (int)y + DIS_H / 2 > 0 && (int)y + DIS_H / 2 < DIS_H)
			{
				my_mlx_pixel_put(&img, (int)x + DIS_W / 2 , (int)y + DIS_H / 2, 0x00FF0000);
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
			if (check < 1.5 && check > -1.5)
			{
				// printf("-----put pixel------\n");
				if ((int)x + DIS_W / 2 > 0 && (int)x + DIS_W / 2 < DIS_W \
					&& (int)y + DIS_H / 2 > 0 && (int)y + DIS_H / 2 < DIS_H)
				{
					my_mlx_pixel_put(&img, (int)x + DIS_W / 2 , (int)y + DIS_H / 2, 0x00FF0000);
				}
			}
			// printf("x=%d, y=%d\n", x + DIS_W / 2 , y + DIS_H / 2);
			y++;
		}
		x++;
	}
}

void print_map(const t_wid_hig size, const t_cor *map, t_data img)
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
				connect_dot(map[num].x, map[num].y, map[num + size.w].x, map[num + size.w].y, img);
			}
			if (x < size.w - 1)
			{
				connect_dot(map[num].x, map[num].y, map[num + 1].x, map[num + 1].y, img);
			}
			x++;
		}
		y++;
	}
}

t_trig_ab get_trig_ab(t_cor ps)
{
	t_trig_ab trig_ab;

	trig_ab.a = sqrt(pow(ps.x, 2) + pow(ps.y, 2)); 
	trig_ab.b = sqrt(pow(ps.x, 2) + pow(ps.y, 2) + pow(ps.z, 2)); 

	//sin cos b = 0 not
	trig_ab.sin_a = ps.x / trig_ab.a; //changed formula
	trig_ab.cos_a = ps.y / trig_ab.a; 
	trig_ab.sin_b = ps.z / trig_ab.b;
	trig_ab.cos_b = trig_ab.a / trig_ab.b;
	return (trig_ab);
}

void change_cor(t_cor *map, int size, t_cor ps, t_trig_ab trig_ab, int d)
{
	int i = 0;
	t_cor cor;
	double sin_a = trig_ab.sin_a;
	double cos_a = trig_ab.cos_a;
	double sin_b = trig_ab.sin_b;
	double cos_b = trig_ab.cos_b;

	while (i < size)
	{
		//diff
		cor.x = map[i].x - ps.x;
		cor.y = map[i].y - ps.y;
		cor.z = map[i].z - ps.z;

		//rotate
		map[i].x = sin_a * sin_b * cor.x\
				- sin_a * cos_b * cor.y\
				+ cos_a * cor.z;
		map[i].y = cos_b * cor.x\
				+ sin_b * cor.y;
		map[i].z = - cos_a * sin_b * cor.x\
				+ cos_a * cos_b * cor.y\
				+ sin_a * cor.z;

		//central projection
		d = (double)d;
		map[i].x *= d / (d + map[i].z);
		map[i].y *= d / (d + map[i].z);

		i++;
	}


	/*
	//test
	while (i < size)
	{
		//diff
		cor.x = map[i].x - ps.x;
		cor.y = map[i].y - ps.y;
		cor.z = map[i].z - ps.z;

		//rotate
		map[i].x = cos_a * cos_b * cor.x\
				+ cos_a * sin_b * cor.y\
				+ sin_a * cor.z;
		map[i].y = -sin_b * cor.x\
				+ cos_b * cor.y;
		map[i].z = - sin_a * cos_b * cor.x\
				- sin_a * sin_b * cor.y\
				+ cos_a * cor.z;

		i++;
	}
	*/
}

int	main(int argc, char **argv)
{
	void	*mlx;
	void	*mlx_win;
	t_data	img;
	t_cor *map;
	t_wid_hig size;

	(void)argc;
	mlx = mlx_init();
	mlx_win = mlx_new_window(mlx, DIS_W, DIS_H, "fdf");
	img.img = mlx_new_image(mlx, DIS_W, DIS_H);
	img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel, &img.line_length,
								&img.endian);
	size = get_map_size((const char**)argv);
	map = get_map((const char**)argv, (size.w * size.h));

	//perspective
	t_cor ps;
	ps.x = 10; //over 20 danger : move like z??
	ps.y = 10; //move as y
	ps.z = 30; //mave as -x

	//depth
	int d = 10;

	t_trig_ab trig_ab;
	trig_ab = get_trig_ab(ps);
	//rotate
	printf("--rotate--\n");
	change_cor(map, size.w * size.h, ps, trig_ab, d);

	//print
	printf("--print--\n");
	print_map((const t_wid_hig)size, (const t_cor*)map, img);

	mlx_put_image_to_window(mlx, mlx_win, img.img, 0, 0);
	mlx_loop(mlx);
	free(map);
}