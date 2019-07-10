/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_img.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: DCCXXVi <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/09 14:47:50 by DCCXXVi           #+#    #+#             */
/*   Updated: 2019/07/09 15:12:57 by DCCXXVi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol3d.h"

static void	set_kernel_arg(t_fractol3d *fractol3d)
{
	fractol3d->error |= clSetKernelArg(fractol3d->kernel, 0, sizeof(cl_mem),
            &(fractol3d->memobj));
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
