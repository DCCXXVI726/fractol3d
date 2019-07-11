static void	ft_pow(double *x, double *y, double *z, int n)
{
	double fi;
	double teta;
	double r;

	r = sqrt(*x * *x + *y * *y + *z * *z);
	fi = atan(*y / *x);
	fi = fi * n;
	teta = atan(sqrt(*x * *x + *y * *y) / *z);
	teta = teta * n;
	r = pow(r, n);
	*x = r * sin(teta) * cos(fi);
	*y = r * sin(teta) * sin(fi);
	*z = r * cos(teta);
}

static void	ft_pow3(double *x, double *y, double *z)
{
	double x0;
	double y0;
	double z0;

	x0 = ((3 * *z * *z - *x * *x - *y * *y) * *x * (*x * *x - 3 * *y * *y)) / (*x * *x + *y * *y);
	y0 = ((3 * *z * *z - *x * *x - *y * *y) * *y * (3 * *x * *x - *y * *y)) / (*x * *x + *y * *y);
	z0 = *z * (*z * *z - 3 * *x * *x - 3 * *y * *y);
	*x = x0;
	*y = y0;
	*z = z0;
}

static void	ft_julia(double *x, double *y, double z)
{
	double x0;
	double y0;
	
	x0 = *x * *x - *y * *y + z;
	y0 = 2 * *x * *y + z;
	*x = x0;
	*y = y0;
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

	i = get_global_id(0);
	step = 0.1;
	count_step = 1;
	max_step = 50;
	max_iter = 50;
	pi = 3.14;
	color = 0xFFFFFF;
	alpha = (start_alpha + (i % 600) * 3.0 / 20 - 45) / 180 * pi;
	teta = (start_teta - (i / 600) * 3.0 / 20 + 45) / 180 * pi;
	while (count_step < max_step)
	{
		xc = start_x + cos(alpha) * sin(teta) * count_step * step;
		yc = start_y + sin(alpha) * sin(teta) * count_step * step;
		zc = start_z + cos(teta) * count_step * step;
		x = xc;
		y = yc;
		z = zc;
		iter = 0;
		while (iter < max_iter && (x * x + y * y) <= 4)
		{
			ft_julia(&x, &y, z);
			iter++;
		}
		if (iter > max_iter / 2)
		{
			color = ((double)(max_iter - iter)) / (max_iter / 2) * 255;
			count_step = max_step;
		}
		count_step++;
	}
	((__global int*) string)[i] = color;
}
