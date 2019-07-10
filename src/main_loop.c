/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_loop.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: DCCXXVi <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/28 14:00:01 by DCCXXVi           #+#    #+#             */
/*   Updated: 2019/07/09 15:01:20 by DCCXXVi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol3d.h"

void	main_loop(t_fractol3d	*fractol3d)
{
	int	flag;

	flag = 1;
	while (flag)
	{
		flag = key_hook(fractol3d);
		*((int*)fractol3d->screen->pixels) = 0xFFFFFF;
		fill_img(fractol3d);
		SDL_UpdateWindowSurface(fractol3d->window);
	}
}
