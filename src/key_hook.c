/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_hook.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: DCCXXVi <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/28 14:20:06 by DCCXXVi           #+#    #+#             */
/*   Updated: 2019/07/11 15:36:53 by thorker          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol3d.h"

int		key_hook(t_fractol3d *fractol3d)
{
	SDL_Event e;
	(void)fractol3d;
	while(SDL_PollEvent(&e))
	{
		if ((e.type == SDL_KEYDOWN && e.key.keysym.sym == SDLK_ESCAPE) || e.type == SDL_QUIT)
			return(0);
		if (e.type == SDL_KEYDOWN && e.key.keysym.sym == SDLK_w)
		{
			fractol3d->camera.x += 0.01;
			ft_putstr("x = ");
			ft_putnbrln(fractol3d->camera.x * 1000);
		}
		if (e.type == SDL_KEYDOWN && e.key.keysym.sym == SDLK_s)
		{
			fractol3d->camera.x -= 0.01;
			ft_putstr("x = ");
			ft_putnbrln(fractol3d->camera.x * 1000);
		}
		if (e.type == SDL_KEYDOWN && e.key.keysym.sym == SDLK_a)
		{
			fractol3d->camera.y += 0.01;
			ft_putstr("y = ");
			ft_putnbrln(fractol3d->camera.y * 1000);
		}
		if (e.type == SDL_KEYDOWN && e.key.keysym.sym == SDLK_d)
		{
			fractol3d->camera.y -= 0.01;
			ft_putstr("y = ");
			ft_putnbrln(fractol3d->camera.y * 1000);
		}
		if (e.type == SDL_KEYDOWN && e.key.keysym.sym == SDLK_c)
		{
			fractol3d->camera.z -= 0.01;
			ft_putstr("z = ");
			ft_putnbrln(fractol3d->camera.z * 1000);
		}
		if (e.type == SDL_KEYDOWN && e.key.keysym.sym == SDLK_SPACE)
		{
			fractol3d->camera.z += 0.01;
			ft_putstr("z = ");
			ft_putnbrln(fractol3d->camera.z * 1000);
		}
	}
	return(1);
}
