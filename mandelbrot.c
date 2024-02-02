/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mandelbrot.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hakobaya <hakobaya@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/25 22:26:03 by hakobaya          #+#    #+#             */
/*   Updated: 2024/02/01 12:08:24 by hakobaya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	calc_mandel(t_fractol *mandel, int limit)
{
	double	a;
	double	b;
	double	r;
	double	i;

	a = mandel->a;
	b = mandel->b;
	while (limit-- > 0)
	{
		r = mandel->real;
		i = mandel->imaginary;
		mandel->real = (r * r) - (i * i);
		mandel->imaginary = 2 * r * i;
		mandel->real += a;
		mandel->imaginary += b;
		if ((mandel->real * mandel->real + \
			mandel->imaginary * mandel->imaginary) > 4)
			return (FALSE);
	}
	return (TRUE);
}

void	mandelbrot(void)
{
	t_fractol	*mandel;
	int			limit;
	int			judge;

	mandel = (t_fractol *)malloc(sizeof(t_fractol));
	mandel->mlx = mlx_init();
	if (mandel->mlx == NULL)
		free_exit(mandel);
	mandel->win = mlx_new_window(mandel->mlx, 800, 600, "Mandelbrot");
	mandel->real = 0;
	mandel->imaginary = 0;
	judge = calc_mandel(mandel, LIMIT);
	mandel->img = mlx_new_image(mandel->mlx, 800, 600);
	mandel->addr = mlx_get_data_addr(mandel->mlx, &mandel->bits_per_pixel, \
					&mandel->line_length, &mandel->endian);
	mlx_key_hook(mandel->win, key_hook, NULL);
	mlx_mouse_hook(mandel->win, key_hook, NULL);
	mlx_destroy_window(mandel->mlx, mandel->win);
	mlx_loop(mandel->mlx);
	return ;
}
