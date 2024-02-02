/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hook.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hakobaya <hakobaya@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/25 21:58:10 by hakobaya          #+#    #+#             */
/*   Updated: 2024/02/02 22:18:32 by hakobaya         ###   ########.fr       */
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

int	mouse_hook(int mousecode, t_fractol *fractol)
{
	// マウスクリックイベントが発生したときの処理
	if (mousecode == SCROLL_UP)
		zoom_hook(fractol, 1.111);
	if (mousecode == SCROLL_DOWN)
		zoom_hook(fractol, 0.9);
	printf("click\n");
	return (0);
}

int	zoom_hook(t_fractol *fractol, double ratio)
{
	
	printf("zoom\n");
	return (0);
}

int	close_hook(t_fractol *fractol, int button, int x, int y)
{
	mlx_destroy_window(fractol->mlx, fractol->win);
	return (0);
}
