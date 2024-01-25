/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hakobaya <hakobaya@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/24 08:08:55 by hakobaya          #+#    #+#             */
/*   Updated: 2024/01/25 22:50:03 by hakobaya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

//typedef struct	s_data{
//	void	*img;
//	char	*addr;
//	int		bits_per_pixel;
//	int		line_length;
//	int		edian;
//}	t_data;

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

//int	main(void)
//{
//	void	*mlx;
//	void	*mlx_win;
//	t_data	img;

//	mlx = mlx_init();
//	mlx_win = mlx_new_window(mlx, 1920, 1080, "Hello World!");
//	img.img = mlx_new_image(mlx, 1920, 1080);
//	img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel, &img.line_length, &img.edian);
//	my_mlx_pixel_put(&img, 5, 5, 0x00FF0000);
//	mlx_put_image_to_window(mlx, mlx_win, img.img, 0, 0);
//	mlx_loop(mlx);
//}

void	error_handle(int index)
{
	if (index == 0)
		perror("ERROR :Please enter the correct letter \n[Julia] or [Mandelbrot]\n");
	exit(0);
}

int	main(int argc, char **argv)
{
	void		*mlx;
	void		*win;
	t_fractol	*fractol;

	//if (argc != 2 || !(ft_strncmp(argv[1], "Julia", 6)) || !(ft_strncmp(argv[1], "Mandelbrot"), 11))
	//	error_handle(0);
	mlx = mlx_init();
	if (mlx == NULL)
		exit(1);
	if (ft_strncmp(argv[1], "Julia", 6))
		julia(fractol, argv);
	if (ft_strncmp(argv[1], "mandelbrot", 6))
		mandelbrot(fractol, argv);
	win = mlx_new_window(mlx, 800, 600, "fract-ol");
	mlx_key_hook(win, key_hook, NULL);
	mlx_mouse_hook(win, mouse_hook, NULL);
	mlx_loop(mlx);
	mlx_destroy_window(mlx, win);
	return (0);
}
