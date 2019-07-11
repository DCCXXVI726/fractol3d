/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: DCCXXVi <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/28 10:53:58 by DCCXXVi           #+#    #+#             */
/*   Updated: 2019/07/11 19:55:56 by thorker          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol3d.h"

int	main(int ac, char **av)
{
	t_fractol3d	*fractol3d;

	fractol3d = create_struct();
	main_loop(fractol3d);
	(void)av;
	(void)ac;
	return(0);
}
