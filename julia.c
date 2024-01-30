/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   julia.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hakobaya <hakobaya@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/25 22:23:59 by hakobaya          #+#    #+#             */
/*   Updated: 2024/01/30 17:54:43 by hakobaya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	julia_calc(double real, double imaginary, int x, int y)
{
	return ;
}

void	julia(double real, double imaginary)
{
	t_fractol	*julia;

	julia = (t_fractol *)malloc(sizeof(t_fractol));
	julia->mlx = mlx_init();
	if (julia->mlx == NULL)
		free_exit(julia);
	julia->win = mlx_new_window(julia->mlx, 800, 600, "Julia");
	julia->real = real;
	julia->imaginary = imaginary;
	//while (limit-- > 0)
	//{
	//	break ;
	//}
	mlx_put_image_to_window(julia->mlx, julia->win, julia->img, julia->x, julia->y); // あってる？
	//mlx_key_hook(julia->win, key_hook, NULL);
	//mlx_mouse_hook(julia->win, key_hook, NULL);
	//mlx_destroy_window(julia->mlx, julia->win);
	mlx_loop(julia->mlx);
	return ;
}
