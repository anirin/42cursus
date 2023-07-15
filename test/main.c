#include <mlx.h>
#include <libc.h>

enum {
	ON_KEYDOWN = 2,
	ON_KEYUP = 3,
	ON_MOUSEDOWN = 4,
	ON_MOUSEUP = 5,
	ON_MOUSEMOVE = 6,
	ON_EXPOSE = 12,
	ON_DESTROY = 17
};

typedef struct	s_data {
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}				t_data;

typedef struct	s_vars {
	void	*mlx;
	void	*win;
}				t_vars;

int	window_close(int keycode, t_vars *vars)
{
	(void)keycode;
	mlx_destroy_window(vars->mlx, vars->win);
	return (0);
}

int keyevent(int keycode, 	t_vars	*vars){
	printf("%d %p\n", keycode, vars);

	return 0;
}
int mouse(int x ,int y, 	t_vars	*vars){
		printf("%d %d %p\n",x, y, vars);
return 0;
}
int mouse_down(int key, int x ,int y, 	t_vars	*vars){
		printf("%d %d %d %p\n",key, x, y, vars);
return 0;
}
int	main(void)
{
	t_vars	vars;

	vars.mlx = mlx_init();
	vars.win = mlx_new_window(vars.mlx, 1920, 1080, "Hello world!");
	// mlx_hook(vars.win, 2, 1L<<0, window_close, &vars);
	mlx_hook(vars.win, ON_KEYDOWN, 0, keyevent, &vars);
	mlx_hook(vars.win, ON_MOUSEMOVE, 0, mouse, &vars);
	mlx_hook(vars.win, ON_MOUSEDOWN, 0, mouse_down, &vars);

	mlx_loop(vars.mlx);
}