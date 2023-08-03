/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   connect_color.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atsu <atsu@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/02 17:27:05 by atsu              #+#    #+#             */
/*   Updated: 2023/08/03 14:13:50 by atokamot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/fdf.h"
#include "../header/libft.h"

int	connect_color(int color1, int color2, double dist, double max_dist)
{
	double	ratio;
	int		color;
	t_color	diff;
	t_color	trgb1;
	t_color	trgb2;

	ratio = dist / max_dist;
	trgb1.t = (int)get_t(color1);
	trgb1.r = (int)get_r(color1);
	trgb1.g = (int)get_g(color1);
	trgb1.b = (int)get_b(color1);
	trgb2.t = (int)get_t(color2);
	trgb2.r = (int)get_r(color2);
	trgb2.g = (int)get_g(color2);
	trgb2.b = (int)get_b(color2);
	diff.t = ratio * (double)(trgb2.t - trgb1.t);
	diff.r = ratio * (double)(trgb2.r - trgb1.r);
	diff.g = ratio * (double)(trgb2.g - trgb1.g);
	diff.b = ratio * (double)(trgb2.b - trgb1.b);
	color = create_trgb(trgb1.t + diff.t, trgb1.r + diff.r, trgb1.g + diff.g,
			trgb1.b + diff.b);
	return (color);
}
