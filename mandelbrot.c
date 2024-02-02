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

void	calc_mandel(t_fractol *m)
{
	double	tmp_real;
	double	tmp_im;

	tmp_real = (m->real * m->real) - (m->im * m->im) + m->a;
	tmp_im = 2 * m->real * m->im + m->b;
	m->real = tmp_real;
	m->im = tmp_im;
}

void	judge_mandel(t_fractol *m, int x, int y, int limit)
{
	int	offset;

	while (y < HEIGHT)
	{
		x = 0;
		while (x < WIDTH)
		{
			m->a = (x - WIDTH / 1.5) * 4.0 / WIDTH; // x - WIDTH / 2.0 real軸の中央、原点を設定
			m->b = (y - HEIGHT / 2.0) * 4.0 / HEIGHT; // y - HEIGHT / 2.0 imの中央、原点を設定
			offset = (y * m->line_len) + (x * (m->bpp / 8));
			m->real = 0;
			m->im = 0;
			limit = 100;
			while (limit-- > 0)
				calc_mandel(m);
			//if ((m->real * m->real + m->a) * (m->im * m->im + m->b) < 4)
			if ((m->real * m->real) + (m->im * m->im) < 4)
				m->color = 0xFFFFFF;
			else
				m->color = 0x000000;
			*(int *)(m->addr + offset) = m->color;
			x++;
		}
		y++;
	}
}

void	mandelbrot(void)
{
	t_fractol	*m;
	int			limit;
	int			x;
	int			y;

	m = (t_fractol *)malloc(sizeof(t_fractol));
	m->mlx = mlx_init();
	if (m->mlx == NULL)
		free_exit(m);
	m->win = mlx_new_window(m->mlx, WIDTH, HEIGHT, "Mandelbrot");
	m->real = 0;
	m->im = 0;
	m->bpp = 32;
	m->img = mlx_new_image(m->mlx, WIDTH, HEIGHT);
	m->addr = mlx_get_data_addr(m->img, &m->bpp, &m->line_len, &m->endian);
	judge_mandel(m, 0, 0, 100);
	mlx_put_image_to_window(m->mlx, m->win, m->img, 0, 0);
	//mlx_key_hook(m->win, key_hook, NULL);
	//mlx_mouse_hook(m->win, key_hook, NULL);
	//mlx_destroy_window(m->mlx, m->win);
	mlx_loop(m->mlx);
	return ;
}
