/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_img.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: DCCXXVi <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/09 14:47:50 by DCCXXVi           #+#    #+#             */
/*   Updated: 2019/07/23 19:52:32 by thorker          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol3d.h"

static void	set_kernel_arg(t_fractol3d *fractol3d)
{
	fractol3d->error |= clSetKernelArg(fractol3d->kernel, 0, sizeof(cl_mem),
	            &(fractol3d->memobj));
	fractol3d->error |= clSetKernelArg(fractol3d->kernel, 1, sizeof(double),
                &(fractol3d->camera.x));
	fractol3d->error |= clSetKernelArg(fractol3d->kernel, 2, sizeof(double),
                &(fractol3d->camera.y));
	fractol3d->error |= clSetKernelArg(fractol3d->kernel, 3, sizeof(double),
                &(fractol3d->camera.z));
	fractol3d->error |= clSetKernelArg(fractol3d->kernel, 4, sizeof(double),
                &(fractol3d->camera.alpha));
	fractol3d->error |= clSetKernelArg(fractol3d->kernel, 5, sizeof(double),
                &(fractol3d->camera.teta));
	fractol3d->error |= clSetKernelArg(fractol3d->kernel, 6, sizeof(int),
			&(fractol3d->max_color));
	fractol3d->error |= clSetKernelArg(fractol3d->kernel, 7, sizeof(int),
			&(fractol3d->max_iter));
	fractol3d->error |= clSetKernelArg(fractol3d->kernel, 8, sizeof(double),
			&(fractol3d->max_dist));
}

void	fill_img(t_fractol3d *fractol3d)
{
	set_kernel_arg(fractol3d);
	fractol3d->error = clEnqueueNDRangeKernel(fractol3d->command_queue, fractol3d->kernel,
            1, 0, &(fractol3d->limit), 0, 0, 0, 0);
	if (fractol3d->error != CL_SUCCESS)
        check_error_n_exit(1, "EnqueueNDRangeKernel problem");
    fractol3d->error = clEnqueueReadBuffer(fractol3d->command_queue, fractol3d->memobj,
            CL_TRUE, 0, fractol3d->limit * sizeof(int), fractol3d->fill_string, 0, 0, 0);
    ft_memcpy(fractol3d->screen->pixels, fractol3d->fill_string, fractol3d->limit * sizeof(int));
}
