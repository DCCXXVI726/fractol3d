/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_opencl.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: DCCXXVi <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/09 12:06:35 by DCCXXVi           #+#    #+#             */
/*   Updated: 2019/07/09 15:32:41 by DCCXXVi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol3d.h"

static void     load_kernel2(char **tmp, char **old_tmp, int fd)
{
	if (ft_strlen(*tmp) != 0)
    {
        *old_tmp = *tmp;
        *tmp = ft_strjoin(*old_tmp, "\n");
        free(*old_tmp);
    }
    else
        ft_strdel(tmp);
    close(fd);
}

static char     *load_kernel(void)
{
    int     fd;
    char    *line;
    char    *tmp;
    char    *old_tmp;
    int     gnl;

    tmp = ft_strnew(0);
    if ((fd = open("src/fractol3d.cl", O_RDONLY)) < 0)
        check_error_n_exit(1, "Didn't open file");
    while ((gnl = get_next_line(fd, &line)) != 0)
    {
        if (gnl < 0)
            check_error_n_exit(1, "Didn't read file");
        old_tmp = tmp;
        tmp = ft_strjoin(old_tmp, "\n");
        free(old_tmp);
        old_tmp = tmp;
        tmp = ft_strjoin(old_tmp, line);
        free(line);
        free(old_tmp);
    }
    load_kernel2(&tmp, &old_tmp, fd);
    return (tmp);
}

static void     init_opencl2(t_fractol3d *frac)
{
    frac->memobj = clCreateBuffer(frac->context, CL_MEM_WRITE_ONLY,
            600 * 600 * sizeof(int), NULL, &(frac->error));
    if (frac->error != CL_SUCCESS)
        check_error_n_exit(1, "CreateBuffer problem");
    frac->program = clCreateProgramWithSource(frac->context,
            1, (const char **)&(frac->src_kernel_str),
            (const size_t *)&(frac->src_kernel_size), &(frac->error));
    if (frac->error != CL_SUCCESS)
        check_error_n_exit(1, "CreateProgramWithSource problem");
    frac->error = clBuildProgram(frac->program, 0, 0, 0, 0, 0);
    if (frac->error != CL_SUCCESS)
        check_error_n_exit(1, "BuildProgram problem");
    frac->kernel = clCreateKernel(frac->program, "fractil3d", &(frac->error));
    if (frac->error != CL_SUCCESS)
        check_error_n_exit(1, "CreateKernel problem");
}

int             init_opencl(t_fractol3d *frac)
{
    frac->src_kernel_str = load_kernel();
    frac->src_kernel_size = ft_strlen(frac->src_kernel_str);
    frac->error = clGetDeviceIDs(0, CL_DEVICE_TYPE_GPU, 1, &(frac->device_id), 0);
    if (frac->error != CL_SUCCESS)
        check_error_n_exit(1, "GetDeviceIDS problem");
    frac->context = clCreateContext(0, 1, &(frac->device_id), 0, 0,
            &(frac->error));
    if (frac->error != CL_SUCCESS)
        check_error_n_exit(1, "CreateContext problem");
    frac->command_queue = clCreateCommandQueue(frac->context, frac->device_id,
            0, &(frac->error));
    if (frac->error != CL_SUCCESS)
        check_error_n_exit(1, "CreateCommandQueue problem");
    init_opencl2(frac);
    return (0);
}

