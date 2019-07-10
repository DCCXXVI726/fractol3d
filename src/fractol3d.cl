__kernel void fractil3d(__global char* string)
{
	int i;
	i = get_global_id(0);
	((__global unsigned int*) string)[i] = i;
}
