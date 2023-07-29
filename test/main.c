#include "include.h"

void	my_mlx_pixel_put(t_vars *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int*)dst = color;
}

int	win_close(int button, int x, int y, void *vars)
{
	(void)vars;
	printf("button = %d, x = %d, y = %d\n", button, x, y);
	//mlx_destroy_window(vars->mlx, vars->win);
	return (0);
}

int	render_next_frame(t_vars *vars)
{
	// static int i = 0;
	// if (i == 400)
	// {
	// 	vars->img = mlx_new_image(vars->mlx, 500, 500);
	// 	vars->addr = mlx_get_data_addr(vars->img, &vars->bits_per_pixel, &vars->line_length, &vars->endian);
	// 	i = 0;
	// }
	for(int h = 0; h < 50; h++)
		for(int w = 0; w < 50; w++)
			my_mlx_pixel_put(vars, w + vars->x, h + vars-> y, 0x000000FF);
	mlx_put_image_to_window(vars->mlx, vars->win, vars->img, 0, 0);
	// printf("i = %d\n", i);
	// i++;
	return 0;
}

int set(int keycode, t_vars *vars)
{
	printf("keycode == %d\n", keycode);
	if (keycode == RIGHT)
		vars->x += 10;
	if (keycode == LEFT)
		vars->x -= 10;
	if (keycode == DOWN)
		vars->y += 10;
	if (keycode == UP)
		vars->y -= 10;
	if (keycode == 8)
	{
		mlx_destroy_image(vars->mlx, vars->img);
		vars->img = mlx_new_image(vars->mlx, 500, 500);
		vars->addr = mlx_get_data_addr(vars->img, &vars->bits_per_pixel, &vars->line_length, &vars->endian);
	}
	return 0;
}

int	main(void)
{
	t_vars	vars;

	vars.mlx = mlx_init();
	vars.win = mlx_new_window(vars.mlx, 500, 500, "Hello world!");
	vars.img = mlx_new_image(vars.mlx, 500, 500);
	vars.addr = mlx_get_data_addr(vars.img, &vars.bits_per_pixel, &vars.line_length, &vars.endian);
	vars.x = 0;
	vars.y = 0;

	mlx_loop_hook(vars.mlx, render_next_frame, &vars);
	mlx_hook(vars.win, ON_KEYDOWN, 0, set, &vars);

	mlx_loop(vars.mlx);
}