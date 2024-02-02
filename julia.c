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

//void	zoom_julia(t_fractol *julia, double ratio)
//{
//	WIDTH *= ratio;
//	HEIGHT *= ratio;

//}

void	calc_julia(t_fractol *j, int x, int y, int offset)
{
	double	tmp_real;
	double	tmp_im;
	double	real;
	double	im;

	tmp_real = (j->real * j->real) - (j->im * j->im) + j->a;
	tmp_im = 2 * j->real * j->im + j->b;
	j->real = tmp_real;
	j->im = tmp_im;
}

void	judge_julia(t_fractol *j, double x, double y, int limit)
{
	int	offset;

	while (y < HEIGHT)
	{
		x = 0;
		while (x < WIDTH)
		{
			j->real = -2 + (x / WIDTH * 4.0);
			j->im = -2 + (y / HEIGHT * 4.0);
			offset = (y * j->line_len) + (x * (j->bpp / 8));
			limit = 100;
			while (limit-- > 0)
				calc_julia(j, x, y, offset);
			if ((j->real * j->real) + (j->im * j->im) < 4)
				j->color = 0xFFFFFF;
			else
				j->color = 0x000000;
			*(int *)(j->addr + offset) = j->color;
			x++;
		}
		y++;
	}
}

void	julia(double real, double im)
{
	t_fractol	*j;

	printf("enter julia\n");
	j = (t_fractol *)malloc(sizeof(t_fractol));
	j->mlx = mlx_init();
	if (j->mlx == NULL)
		free_exit(j);
	j->win = mlx_new_window(j->mlx, WIDTH, HEIGHT, "Julia");
	j->a = real;
	j->b = im;
	j->real = 0;
	j->im = 0;
	j->bpp = 32;
	j->img = mlx_new_image(j->mlx, WIDTH, HEIGHT);
	j->addr = mlx_get_data_addr(j->img, &j->bpp, &j->line_len, &j->endian);
	judge_julia(j, 0, 0, 100);
	mlx_put_image_to_window(j->mlx, j->win, j->img, 0, 0);
	mlx_key_hook(j->win, key_hook, NULL);
	mlx_mouse_hook(j->win, key_hook, NULL);
	//mlx_destroy_window(j->mlx, j->win);
	mlx_loop(j->mlx);
	return ;
}
