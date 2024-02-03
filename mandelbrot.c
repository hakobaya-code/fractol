/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mbrot.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hakobaya <hakobaya@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/25 22:26:03 by hakobaya          #+#    #+#             */
/*   Updated: 2024/02/02 16:39:25 by hakobaya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"


static void	calc_mandel(t_fractol *m)
{
	double	tmp_real;
	double	tmp_im;

	tmp_real = (m->real * m->real) - (m->im * m->im) + m->a;
	tmp_im = 2 * m->real * m->im + m->b;
	m->real = tmp_real;
	m->im = tmp_im;
}

void	draw_mandel(t_fractol *m, int x, int y, int limit)
{
	int	offset;

	while (++y < HEIGHT)
	{
		x = 0;
		while (++x < WIDTH)
		{
			m->a = (x - WIDTH / 2.0) * (4.0 / m->scale) / WIDTH;
			m->b = (y - HEIGHT / 2.0) * (4.0 / m->scale) / HEIGHT;
			offset = (y * m->line_len) + (x * (m->bpp / 8));
			m->real = 0;
			m->im = 0;
			m->color = 0;
			limit = LIMIT;
			while (limit-- > 0 && (m->real * m->real) + (m->im * m->im) < 4)
			{
				calc_mandel(m);
				if ((m->real * m->real) + (m->im * m->im) < 4)
					m->color++;
			}
			m->color = calc_color(m->color, LIMIT);
			*(int *)(m->addr + offset) = m->color;
		}
	}
}

void	zoom_mandel(t_fractol *m)
{
	mlx_destroy_image(m->mlx, m->img);
	m->img = mlx_new_image(m->mlx, WIDTH, HEIGHT);
	m->addr = mlx_get_data_addr(m->img, &m->bpp, &m->line_len, &m->endian);
	draw_mandel(m, 0, 0, LIMIT);
	mlx_put_image_to_window(m->mlx, m->win, m->img, 0, 0);
}

void	mandelbrot(void)
{
	t_fractol	*m;

	m = (t_fractol *)malloc(sizeof(t_fractol));
	if (!m)
		exit(1);
	m->mlx = mlx_init();
	if (m->mlx == NULL)
		free_exit(m);
	m->win = mlx_new_window(m->mlx, WIDTH, HEIGHT, "Mandelbrot");
	if (m->win == NULL)
		free_exit(m);
	m->real = 0;
	m->im = 0;
	m->bpp = 32;
	m->scale = 1.0;
	m->img = mlx_new_image(m->mlx, WIDTH, HEIGHT);
	m->addr = mlx_get_data_addr(m->img, &m->bpp, &m->line_len, &m->endian);
	draw_mandel(m, 0, 0, LIMIT);
	mlx_put_image_to_window(m->mlx, m->win, m->img, 0, 0);
	mlx_hook(m->win, ON_KEYDOWN, 0L, key_event_handler, m);
	mlx_hook(m->win, ON_MOUSEDOWN, 0L, m_mouse_event_handler, m);
	mlx_hook(m->win, ON_DESTROY, 0L, close_event_handler, m);
	mlx_loop(m->mlx);
	return ;
}
