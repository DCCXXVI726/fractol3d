/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_struct.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: DCCXXVi <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/28 13:32:59 by DCCXXVi           #+#    #+#             */
/*   Updated: 2019/07/08 16:41:38 by DCCXXVi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol3d.h"

void		init_sdl(t_fractol3d *fractol3d)
{
	int error;

	error = SDL_Init(SDL_INIT_EVERYTHING);
    if (error < 0)
        check_error_n_exit(1, "Проблема с инициализацией  SDL");
    fractol3d->window = SDL_CreateWindow("Fractol3d", 0, 0, 1000, 1000, SDL_WINDOW_SHOWN);
    if (fractol3d->window == 0)
        check_error_n_exit(1, "Пробема с созданием окна");
    fractol3d->screen = SDL_GetWindowSurface(fractol3d->window);
    if (fractol3d->screen == 0)
        check_error_n_exit(1, "Проблема с surface окна");
}

void		init_start_variable(t_fractol3d *fractol3d)
{
	fractol3d->camera.x = 0;
	fractol3d->camera.y = 0;
	fractol3d->camera.z = 0;
	fractol3d->camera.alpha = 0;
	fractol3d->camera.teta = 0;
}

t_fractol3d	*create_struct()
{
	t_fractol3d	*fractol3d;

	fractol3d = (t_fractol3d*)malloc(sizeof(t_fractol3d));
	if (fractol3d == 0)
		check_error_n_exit(1, "незамолочилась структура");
	init_start_variable(fractol3d);
	init_sdl(fractol3d);
	return (fractol3d);	
}
