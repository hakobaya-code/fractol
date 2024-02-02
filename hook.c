/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hook.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hakobaya <hakobaya@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/25 21:58:10 by hakobaya          #+#    #+#             */
/*   Updated: 2024/02/02 22:55:05 by hakobaya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	key_hook(int keycode, t_fractol *fractol)
{
	// キーイベントが発生したときの処理
	//if (keycode == )
	printf("key\n");
	return (0);
}

int	mandel_mouse_hook(int mousecode, t_fractol *mandel)
{
	// マウスクリックイベントが発生したときの処理
	if (mousecode == SCROLL_UP)
		mandel->scale *= 1.1;
	if (mousecode == SCROLL_DOWN)
		mandel->scale *= 0.9;
	redraw_mandel(mandel);
	return (0);
}

//int	julia_mouse_hook(int mousecode, t_fractol *julia)
//{
//	// マウスクリックイベントが発生したときの処理
//	if (mousecode == SCROLL_UP)
//		julia->scale *= 1.1;
//	if (mousecode == SCROLL_DOWN)
//		julia->scale *= 0.9;
//	redraw_julia(julia);
//	return (0);
//}
int	zoom_hook(t_fractol *fractol, double scale)
{

	printf("zoom\n");
	return (0);
}

int	close_hook(t_fractol *fractol, int button, int x, int y)
{
	mlx_destroy_window(fractol->mlx, fractol->win);
	return (0);
}
