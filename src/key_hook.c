/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_hook.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: DCCXXVi <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/28 14:20:06 by DCCXXVi           #+#    #+#             */
/*   Updated: 2019/07/14 17:55:02 by thorker          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol3d.h"

static void	move_camera(t_fractol3d *fractol3d, double alpha, double teta)
{
	alpha += fractol3d->camera.alpha;
	teta += fractol3d->camera.teta;
	alpha = alpha / 180 * 3.14;
	teta = teta / 180 * 3.14;
	fractol3d->camera.x += 0.01 * cos(alpha) * sin(teta);
	fractol3d->camera.y += 0.01 * sin(alpha) * sin(teta);
	fractol3d->camera.z += 0.01 * cos(teta);
	ft_putstr("x = ");
	ft_putnbrln(fractol3d->camera.x * 10000);
	ft_putstr("y = ");
	ft_putnbrln(fractol3d->camera.y * 10000);
	ft_putstr("z = ");
	ft_putnbrln(fractol3d->camera.z * 10000);
}

int		key_hook(t_fractol3d *fractol3d)
{
	SDL_Event e;
	(void)fractol3d;
	while(SDL_PollEvent(&e))
	{
		if ((e.type == SDL_KEYDOWN && e.key.keysym.sym == SDLK_ESCAPE) || e.type == SDL_QUIT)
			return(0);
		if (e.type == SDL_KEYDOWN && e.key.keysym.sym == SDLK_w)
			move_camera(fractol3d, 0, 0);
		if (e.type == SDL_KEYDOWN && e.key.keysym.sym == SDLK_s)
			move_camera(fractol3d, 0, 180);
		if (e.type == SDL_KEYDOWN && e.key.keysym.sym == SDLK_a)
			move_camera(fractol3d, -90, 0);
		if (e.type == SDL_KEYDOWN && e.key.keysym.sym == SDLK_d)
			move_camera(fractol3d, 90, 0);
		if (e.type == SDL_KEYDOWN && e.key.keysym.sym == SDLK_c)
			move_camera(fractol3d, 0, -90);
		if (e.type == SDL_KEYDOWN && e.key.keysym.sym == SDLK_SPACE)
			move_camera(fractol3d, 0, 90);
	}
	return(1);
}
