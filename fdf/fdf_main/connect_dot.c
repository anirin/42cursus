int diff_color(int color1, int color2, int x, int min_x, int max_x)
{
	double ratio;
	double diff;

	ratio = (double)x - (double)min_x / (double)max_x - (double)min_x;
	diff = (double)(color2 - color1) * ratio;
	return ((int)diff);
}

void connect_vertical()
{
	int y;

	y = min_y();
	while(y <= max_y)	
	{
		my_mlx_pixel_put(vars, x + DIS_W / 2 , y + DIS_H, color1 + diff_color());
		y++;
	}
}

void connect_horizontall()
{
	int x;

	x = min_x();
	while(y <= max_x)	
	{
		my_mlx_pixel_put(vars, x + DIS_W / 2 , y + DIS_H, color1 + diff_color());
		y++;
	}
}

void connect_other(t_equation equ, t_vars vars, int color1, int color2)
{
	int x;
	int y;

	x = (int)round(equ.min_x);
	while (x < (int)equ.max_x)
	{
		y = (int)round((double)x * equ.slope + equ.intercept);
		my_mlx_pixel_put(vars, x + DIS_W / 2 , y + DIS_H, color1 + diff_color());
		x++;
	}
}

void connect_dot(t_cor cor1, t_cor cor2, t_vars *vars)
{
	t_equation equ;

	equ.max_x = fmax(cor1.x, cor2.x);
	equ.max_y = fmax(cor1.y, cor2.y);
	equ.min_x = fmin(cor1.x, cor2.x);
	equ.min_y = fmin(cor1.y, cor2.y);
	if (cor1.x == cor2.x)
		return (connect_vertical(equ, vars));
	else if (cor1.y == cor2.y)
		return (connect_horizontall(equ, vars));
	equ.slope = get_slope(cor1, cor2);	
	equ.intercept = get_intercept(cor1, equ.slope);
	connect_other(equ, vars, cor1.color, cor2.color);
}