static void	ft_pow(double *x, double *y, double *z, int n)
{
	double fi;
	double teta;
	double r;

	r = sqrt(*x * *x + *y * *y + *z * *z);
	fi = atan(*y / *x);
	fi = fi * n;
	teta = acos(*z / r);
	teta = teta * n;
	r = pow(r, n);
	*x = r * sin(teta) * cos(fi);
	*y = r * sin(teta) * sin(fi);
	*z = r * cos(teta);
}

__kernel void fractil3d(__global char* string, double start_x, double start_y, double start_z, double start_alpha, double start_teta)
{
	double step;
	int count_step;
	int i;
	int max_step;
	int iter;
	int max_iter;
	double xc;
	double yc;
	double zc;
	double alpha;
	double teta;
	double pi;
	double x;
	double y;
	double z;
	int color;

	step = 0.1;
	count_step = 1;
	i = get_global_id(0);
	max_step = 100;
	max_iter = 30;
	pi = 3.14;
	color = 0xFFFFFF;
	alpha = (start_alpha + (i % 600) * 3.0 / 20 - 45) / 180 * pi;
	teta = (start_teta - (i / 600) * 3.0 / 20 + 45) / 180 * pi;
	while (count_step < max_step)
	{
		x = 0;
		y = 0;
		z = 0;
		xc = start_x + cos(alpha) * sin(teta) * count_step * step;
		yc = start_y + sin(alpha) * sin(teta) * count_step * step;
		zc = start_z + cos(teta) * count_step * step;
		iter = 0;
		while (iter < max_iter && (x * x + y * y + z * z) < 4)
		{
			ft_pow(&x, &y, &z, 2);
			x = x + xc;
			y = y + yc;
			z = z + zc;
			iter++;
		}
		if (iter != max_iter)
		{
			color = 0;
			break;
		}
		count_step++;
	}
	((__global int*) string)[i] = color;
}
