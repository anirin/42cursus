int add_shade(double dis, int trbg)
{
	unsigned char t;
	unsigned char r;
	unsigned char b;
	unsigned char g;

	t = get_t(trbg);
	r = get_r(trbg);
	b = get_b(trbg);
	g = get_g(trbg);
	// printf("t=%x,r=%x,b=%x,g=%x\n", t, r, b, g);
	t = (unsigned char)((double)t * dis);
	printf("dis = %f, result = %f\n", dis, (double)t * dis);
	// printf("t=%x,r=%x,b=%x,g=%x\n", t, r, b, g);
	return (create_trgb(t, r, g, b));
}

int drow_line(t_data *img)
{
	int h;
	int w;
	double d_w;
	int trgb;
	int tmp;

	h = 500;
	w = 0;
	tmp = create_trgb(0xFF, 0xFF, 0xFF, 0xFF);

	while(w < 1000)
	{
		d_w = (double)w;
		trgb = add_shade(d_w / (double)1000, tmp);
		printf("t=%x\n", get_t(trgb));
		my_mlx_pixel_put(img, w, h, trgb);
		w++;
	}
	return 0;
}

int	win_close(int button, int x, int y, void *vars)
{
	(void)vars;
	printf("button = %d, x = %d, y = %d\n", button, x, y);
	//mlx_destroy_window(vars->mlx, vars->win);
	return (0);
}

int get_angle(int button, int x, int y, void *vars)
{
	(void)vars;
	(void)button;
	static double x1 = 0;
	static double y1 = 0;

	double x2;
	double y2;

	x2 = (double)x;
	y2 = (double)-y;
	
	if (y2 - y1 != 0)
	{
		printf("x1 = %d, y1 = %d, x2 = %d, y2 = %d\n", (int)x1, (int)y1, (int)x2, (int)y2);
		printf("slope = %f\n", (double)(y2 - y1) / (double)(x2 - x1));
		double angle = atan((double)(y2 - y1) / (double)(x2 - x1));
		// double angle = atan(y2 - y1 / x2 - x1);
		angle *= 180 / M_PI;
		printf("angle = %f\n", angle);
	}
	x1 = (double)x;
	y1 = (double)-y;
	return 0;
}