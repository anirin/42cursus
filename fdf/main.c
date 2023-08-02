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

int	key_down(int keycode, t_vars *vars)
{
	if (keycode == ESC)
	{
		mlx_destroy_window(vars->mlx, vars->win);
		exit(0);
	}
	else if (keycode == POS_X)
		vars->x_degree += 1;
	else if (keycode == POS_Y)
		vars->y_degree += 1;
	else if (keycode == POS_Z)
		vars->z_degree += 1;
	else if (keycode == NEG_X)
		vars->x_degree -= 1;
	else if (keycode == NEG_Y)
		vars->y_degree -= 1;
	else if (keycode == NEG_Z)
		vars->z_degree -= 1;
	mlx_destroy_image(vars->mlx, vars->img);
	vars->img = mlx_new_image(vars->mlx, DIS_W, DIS_H);
	vars->addr = mlx_get_data_addr(vars->img, &vars->bits_per_pixel, &vars->line_length, &vars->endian);
	print_map(vars);
	return (0);
}

int mouse_down(int button, int x, int y, t_vars *vars)
{
	if (button == M_UP)
		vars->zoom += 1;
	if (button == M_DOWN)
		vars->zoom -= 1;
	(void)x;
	(void)y;
	mlx_destroy_image(vars->mlx, vars->img);
	vars->img = mlx_new_image(vars->mlx, DIS_W, DIS_H);
	vars->addr = mlx_get_data_addr(vars->img, &vars->bits_per_pixel, &vars->line_length, &vars->endian);
	print_map(vars);
	return (0);
}

int red_cross_mark(t_vars *vars)
{
	mlx_destroy_window(vars->mlx, vars->win);
	exit(0);
}

int	main(int argc, char **argv)
{
	t_vars	vars;

	if (argc != 2)
		return 0;
	vars.mlx = mlx_init();
	vars.win = mlx_new_window(vars.mlx, DIS_W, DIS_H, "fdf");
	vars.img = mlx_new_image(vars.win, DIS_W, DIS_H);
	vars.addr = mlx_get_data_addr(vars.img, &vars.bits_per_pixel, &vars.line_length, &vars.endian);
	vars.x_degree = 0;
	vars.y_degree = 0;
	vars.z_degree = 0;
	vars.zoom = 10;
	vars.size = get_map_size((const char**)argv);
	vars.save_map = get_map((const char**)argv, (vars.size.w * vars.size.h));
	print_map(&vars);
	mlx_hook(vars.win, ON_KEYDOWN, 0, key_down, &vars);
	mlx_hook(vars.win, ON_MOUSEDOWN, 0, mouse_down, &vars);
	mlx_hook(vars.win, ON_DESTROY, 0, red_cross_mark, &vars);
	mlx_loop(vars.mlx);
}