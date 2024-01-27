/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hakobaya <hakobaya@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/24 08:08:55 by hakobaya          #+#    #+#             */
/*   Updated: 2024/01/27 19:36:59 by hakobaya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

//int	create_trgb(int t, int r, int g, int b)
//{
//	return (t << 24 | r << 16 | g << 8 | b);
//}

//void	my_mlx_pixel_put(t_data *data, int x, int y, int color)
//{
//	char	*dst;

//	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
//	*(unsigned int*)dst = color;
//}

void	error_handle(int index)
{
	if (index == 0)
		ft_putstr_fd("ERROR :Please enter the correct letter\
		\n[Julia] or [Mandelbrot]\n", 2);
	exit(0);
}

int	main(int argc, char **argv)
{
	void				*mlx;
	void				*win;
	static t_fractol	fractol; // static領域はNULL埋められているからゼロ埋めしなくていい

	if (argc == 2 || !(ft_strncmp(argv[1], "Mandelbrot", 11)))
	{
		//fractol_init(&fractol);
		julia(&fractol, argv, Limit);
	}
	else if ((argc == 4 || !(ft_strncmp(argv[1], "Julia"), 6)))
	{
		//fractol_init(&fractol);
		mandelbrot(&fractol, argv, Limit);
	}
	else

	//win = mlx_new_window(mlx, 800, 600, "fract-ol");
	//mlx_key_hook(win, key_hook, NULL);
	//mlx_mouse_hook(win, mouse_hook, NULL);
	//mlx_loop(mlx);
	//mlx_destroy_window(mlx, win);
	return (0);
}
