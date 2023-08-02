/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atsu <atsu@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/09 14:28:48 by atokamot          #+#    #+#             */
/*   Updated: 2023/08/02 18:03:52by atsu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
#define FDF_H

#include <libc.h>
#include <mlx.h>
#include <math.h>

// #define ZOOM 10
#define DIS_W 1000
#define DIS_H 1000
#define ESC 53
#define UP 126
#define DOWN 125
#define LEFT 123
#define RIGHT 124
#define M_UP 4
#define M_DOWN 5
#define Z_UP_Q 12
#define Z_DOWN_Q 13
#define POS_X 6
#define NEG_X 0
#define POS_Y 7
#define NEG_Y 1
#define POS_Z 8
#define NEG_Z 2

enum {
	ON_KEYDOWN = 2,
	ON_KEYUP = 3,
	ON_MOUSEDOWN = 4,
	ON_MOUSEUP = 5,
	ON_MOUSEMOVE = 6,
	ON_EXPOSE = 12,
	ON_DESTROY = 17
};

typedef struct	s_cor {
	double x;
	double y;
	double z;
	int color;
}				t_cor;

typedef struct	s_wid_hig {
	int w;
	int h;
}				t_wid_hig;

typedef struct	s_trig_ab {
	double a;
	double b;
	double sin_a;
	double cos_a;
	double sin_b;
	double cos_b;
}				t_trig_ab;

typedef struct s_equation
{
	double slope;
	double intercept;
	double max_x;
	double min_x;
	double max_y;
	double min_y;
}				t_equation;

typedef struct s_color{
	int t;
	int r;
	int g;
	int b;
}				t_color;

typedef struct	s_vars {
	//mlx
	void	*mlx;
	void	*win;

	//img
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;

	//size
	t_wid_hig size;

	//map
	t_cor *save_map;
	t_cor *map;

	//perspective
	double x;
	double y;
	double z;

	//rotate
	int x_degree;
	int y_degree;
	int z_degree;

	//zoom
	int zoom;

	//trig
	t_trig_ab trig_ab;
}				t_vars;

//connect
void connect_dot(t_cor cor1, t_cor cor2, t_vars *vars);

//output
void	my_mlx_pixel_put(t_vars *vars, int x, int y, int color);
void print_map(t_vars *vars);

//map
t_wid_hig get_map_size(const char **argv);
t_cor *get_map(const char **argv, size_t size);
t_cor *copy_map(t_cor *map, size_t size);

//tool
void print_cor(t_cor *map);

//main
t_trig_ab get_trig_ab(const t_vars vars);
void change_cor(t_cor *map, int size, t_vars vars, t_trig_ab trig_ab);
int mouse_down(int button, int x, int y, t_vars *vars);
int	key_down(int keycode, t_vars *vars);

//helper
int get_color(const char *str);
void zoom_cor(t_cor *map, int size, int zoom);
int	create_trgb(unsigned char t, unsigned char r, unsigned char g, unsigned char b);
unsigned char	get_t(int trgb);
unsigned char	get_r(int trgb);
unsigned char	get_g(int trgb);
unsigned char	get_b(int trgb);
int connect_color(int color1, int color2, double dist, double max_dist);

//equation
double get_slope(t_cor cor1, t_cor cor2);
double get_intercept(t_cor cor1, double slope);

//rotate
void rotate_cor_x(t_cor *map, int size, int degree);
void rotate_cor_y(t_cor *map, int size, int degree);
void rotate_cor_z(t_cor *map, int size, int degree);
void change_cor_isometic(t_cor *map, int size);

#endif
