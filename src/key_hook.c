/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_hook.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: DCCXXVi <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/28 14:20:06 by DCCXXVi           #+#    #+#             */
/*   Updated: 2019/07/08 17:12:26 by DCCXXVi          ###   ########.fr       */
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
	}
	return(1);
}
