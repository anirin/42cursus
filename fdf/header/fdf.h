/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atokamot <atokamot@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/09 14:28:48 by atokamot          #+#    #+#             */
/*   Updated: 2023/07/13 21:31:59 by atokamot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
#define FDF_H

#include <mlx.h>
#include <math.h>

#define ZOOM 20
#define DIS_W 1920
#define DIS_H 1000

typedef struct	s_data {
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}				t_data;

typedef struct	s_cor {
	double x;
	double y;
	double z;
}				t_cor;

typedef struct	s_wid_hig {
	int w;
	int h;
}				t_wid_hig;

//map
int get_map_width(const char *one_line);
t_wid_hig get_map_size(const char **argv);
void get_map_info(char **result, t_cor *map);
t_cor *get_map(const char **argv, size_t size);

//tool
void print_cor(t_cor *map);

//main

#endif
