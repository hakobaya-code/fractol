/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   j.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hakobaya <hakobaya@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/25 22:23:59 by hakobaya          #+#    #+#             */
/*   Updated: 2024/02/02 18:17:26 by hakobaya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static void	calc_julia(t_fractol *j)
{
	double	tmp_real;
	double	tmp_im;

	tmp_real = (j->real * j->real) - (j->im * j->im) + j->a;
	tmp_im = 2 * j->real * j->im + j->b;
	j->real = tmp_real;
	j->im = tmp_im;
}

void	draw_julia(t_fractol *j, double x, double y, int limit)
{
	int	offset;

	while (++y < HEIGHT)
	{
		x = 0;
		while (++x < WIDTH)
		{
			j->real = (-2 / j->scale) + (x / WIDTH * 4.0) / j->scale;
			j->im = (-2 / j->scale) + (y / HEIGHT * 4.0) / j->scale;
			j->color = 0;
			offset = (y * j->line_len) + (x * (j->bpp / 8));
			limit = LIMIT;
			while (limit-- > 0 && (j->real * j->real) + (j->im * j->im) < 4)
			{
				calc_julia(j);
				if ((j->real * j->real) + (j->im * j->im) < 4)
					j->color++;
			}
			j->color = calc_color(j->color, LIMIT);
			*(int *)(j->addr + offset) = j->color;
		}
	}
}

void	zoom_julia(t_fractol *j)
{
	mlx_destroy_image(j->mlx, j->img);
	j->img = mlx_new_image(j->mlx, WIDTH, HEIGHT);
	j->addr = mlx_get_data_addr(j->img, &j->bpp, &j->line_len, &j->endian);
	draw_julia(j, 0, 0, LIMIT);
	mlx_put_image_to_window(j->mlx, j->win, j->img, 0, 0);
}

void	julia(double real, double im)
{
	t_fractol	*j;

	j = (t_fractol *)malloc(sizeof(t_fractol));
	j->mlx = mlx_init();
	if (j->mlx == NULL)
		free_exit(j);
	j->win = mlx_new_window(j->mlx, WIDTH, HEIGHT, "Julia");
	if (j->win == NULL)
		free_exit(j);
	j->a = real;
	j->b = im;
	j->real = 0;
	j->im = 0;
	j->bpp = 32;
	j->scale = 1.0;
	j->img = mlx_new_image(j->mlx, WIDTH, HEIGHT);
	j->addr = mlx_get_data_addr(j->img, &j->bpp, &j->line_len, &j->endian);
	draw_julia(j, 0, 0, LIMIT);
	mlx_put_image_to_window(j->mlx, j->win, j->img, 0, 0);
	mlx_hook(j->win, ON_KEYDOWN, 0L, key_event_handler, j);
	mlx_hook(j->win, ON_MOUSEDOWN, 0L, j_mouse_event_handler, j);
	mlx_hook(j->win, ON_DESTROY, 0L, close_event_handler, j);
	mlx_loop(j->mlx);
	return ;
}
