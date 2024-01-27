/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mandelbrot.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hakobaya <hakobaya@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/25 22:26:03 by hakobaya          #+#    #+#             */
/*   Updated: 2024/01/27 19:37:52 by hakobaya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	mandelbrot(t_fractol *mandel, char **argv, int limit)
{
	mandel->mlx = mlx_init();
	if (mandel->mlx == NULL)
		free_exit(mandel);
	mandel->win = mlx_new_window(mandel->mlx, 800, 600, "Mandelbrot");
	while (limit-- > 0)
	{
		break ;
	}
	mlx_key_hook(mandel->win, key_hook, NULL);
	mlx_mouse_hook(mandel->win, key_hook, NULL);
	mlx_destroy_window(mandel->mlx, mandel->win);
	mlx_loop(mandel->mlx);
	return ;
}
