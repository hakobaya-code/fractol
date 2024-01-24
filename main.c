/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hakobaya <hakobaya@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/24 08:08:55 by hakobaya          #+#    #+#             */
/*   Updated: 2024/01/24 12:47:54 by hakobaya         ###   ########.fr       */
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


#include <mlx.h>

void *mlx;
void *win;

int key_hook(int keycode, void *param)
{
    // キーイベントが発生したときの処理
	printf("key\n");
    return (0);
}

int mouse_hook(int button, int x, int y, void *param)
{
    // マウスクリックイベントが発生したときの処理
	printf("click\n");
    return (0);
}

int main()
{
    mlx = mlx_init();
    win = mlx_new_window(mlx, 800, 600, "minilibx window");

    mlx_key_hook(win, key_hook, NULL);
    mlx_mouse_hook(win, mouse_hook, NULL);

    mlx_loop(mlx);
    return (0);
}
