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

t_trig_ab get_trig_ab(const t_vars vars)
{
	t_trig_ab trig_ab;

	trig_ab.a = sqrt(pow(vars.x, 2) + pow(vars.y, 2)); 
	trig_ab.b = sqrt(pow(vars.x, 2) + pow(vars.y, 2) + pow(vars.z, 2)); 

	trig_ab.sin_a = vars.x / trig_ab.a; //changed formula
	trig_ab.cos_a = vars.y / trig_ab.a; 
	trig_ab.sin_b = vars.z / trig_ab.b;
	trig_ab.cos_b = trig_ab.a / trig_ab.b;
	return (trig_ab);
}

void change_cor(t_cor *map, int size, t_vars vars, t_trig_ab trig_ab)
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
		cor.x = map[i].x - vars.x;
		cor.y = map[i].y - vars.y;
		cor.z = map[i].z - vars.z;

		//rotate
		map[i].x = cos_b * cos_a * cor.x\
				+ cos_b * sin_a * cor.y\
				+ sin_b * cor.z;
		map[i].y = -sin_a * cor.x\
				+ cos_a * cor.y;
		map[i].z = - sin_b * cos_a * cor.x\
				- sin_b * sin_a * cor.y\
				+ cos_b * cor.z;

		/*
		//rotate
		map[i].x = cos_b * sin_a * cor.x\
				+ cos_b * cos_a * cor.y\
				+ sin_b * cor.z;
		map[i].y = cos_a * cor.x\
				+ sin_a * cor.y;
		map[i].z = - sin_b * sin_a * cor.x\
				- sin_b * cos_a * cor.y\
				+ cos_b * cor.z;
		*/
		i++;
	}
}

int	key_down(int keycode, t_vars *vars)
{
	printf("keycode = %d\n", keycode);
	if (keycode == ESC)
	{
		mlx_destroy_window(vars->mlx, vars->win);
		exit(0);
	}
	else if (keycode == UP)
		vars->y -= 1;
	else if (keycode == DOWN)
		vars->y += 1;
	else if (keycode == LEFT)
		vars->x -= 1;
	else if (keycode == RIGHT)
		vars->x += 1;
	else if (keycode == Z_UP_Q)
		vars->z += 1;
	else if (keycode == Z_DOWN_Q)
		vars->z -= 1;
	else
	{
		vars->x = 10;
		vars->y = 10;
		vars->z = 10;
		// printf("reset!\n");
	}

	//destroy
	mlx_destroy_image(vars->mlx, vars->img);
	vars->img = mlx_new_image(vars->mlx, DIS_W, DIS_H);
	vars->addr = mlx_get_data_addr(vars->img, &vars->bits_per_pixel, &vars->line_length, &vars->endian);
	// printf("destory!\n");

	printf("(x y z) = (%d, %d, %d)\n", (int)vars->x, (int)vars->y, (int)vars->z);
	//print
	print_map(vars);
	return (0);
}

int mouse_down(int button, int x, int y, t_vars *vars)
{
	printf("button = %d\n", button);
	if (button == M_UP)
		vars->zoom += 1;
	if (button == M_DOWN)
		vars->zoom -= 1;
	
	printf("(x y z) = (%d, %d, %d)\n", (int)vars->x, (int)vars->y, (int)vars->z);
	(void)x;
	(void)y;
	//destroy
	mlx_destroy_image(vars->mlx, vars->img);
	vars->img = mlx_new_image(vars->mlx, DIS_W, DIS_H);
	vars->addr = mlx_get_data_addr(vars->img, &vars->bits_per_pixel, &vars->line_length, &vars->endian);

	//print
	print_map(vars);
	return (0);
}

int red_cross_mark(t_vars *vars)
{
	printf("red_cross\n");
	mlx_destroy_window(vars->mlx, vars->win);
	exit(0);
	return 0;
}

int	main(int argc, char **argv)
{
	t_vars	vars;

	if (argc != 2)
	{
		printf("invalid argc\n");
		return 0;
	}
	//initialize
	vars.mlx = mlx_init();
	vars.win = mlx_new_window(vars.mlx, DIS_W, DIS_H, "fdf");
	vars.img = mlx_new_image(vars.win, DIS_W, DIS_H);
	vars.addr = mlx_get_data_addr(vars.img, &vars.bits_per_pixel, &vars.line_length, &vars.endian);

	//perspective
	vars.x = 10;
	vars.y = 10;
	vars.z = 10;

	//zoom
	vars.zoom = 10;

	//set map
	vars.size = get_map_size((const char**)argv);
	vars.save_map = get_map((const char**)argv, (vars.size.w * vars.size.h));

	//first_print
	print_map(&vars);

	//print
	mlx_hook(vars.win, ON_KEYDOWN, 0, key_down, &vars);
	mlx_hook(vars.win, ON_MOUSEDOWN, 0, mouse_down, &vars);
	mlx_hook(vars.win, ON_DESTROY, 0, red_cross_mark, &vars);
	mlx_loop(vars.mlx);

}