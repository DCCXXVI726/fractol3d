/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_loop.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: DCCXXVi <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/28 14:00:01 by DCCXXVi           #+#    #+#             */
/*   Updated: 2019/07/11 20:01:26 by thorker          ###   ########.fr       */
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
		SDL_GetMouseState(&(fractol3d->mouse_x), &(fractol3d->mouse_y));
		fractol3d->camera.teta += (300 - fractol3d->mouse_y) / 30;
		fractol3d->camera.alpha += (fractol3d->mouse_x - 300) / 30;// написать отдельную функцию
		SDL_WarpMouseInWindow(fractol3d->window, 300, 300);
		fill_img(fractol3d);
		SDL_UpdateWindowSurface(fractol3d->window);
	}
}
