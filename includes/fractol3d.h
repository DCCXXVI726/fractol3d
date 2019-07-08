/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol3d.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: DCCXXVi <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/28 11:12:22 by DCCXXVi           #+#    #+#             */
/*   Updated: 2019/07/08 16:41:40 by DCCXXVi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL3D_H
# define FRACTOL3D_H
# include "libft.h"
# include <SDL.h>

typedef struct  s_camera
{
    double      x;
    double      y;
    double      z;
    double      alpha;
    double      teta;
}               t_camera;

typedef struct	s_fractol3d
{
	SDL_Window	*window;
	SDL_Surface	*screen;
	t_camera	camera;
}				t_fractol3d;

int				key_hook(t_fractol3d *fractol3d);
t_fractol3d		*create_struct(void);
void			main_loop(t_fractol3d *fractol3d);
#endif
