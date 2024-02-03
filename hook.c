/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hook.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hakobaya <hakobaya@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/25 21:58:10 by hakobaya          #+#    #+#             */
/*   Updated: 2024/02/03 20:03:59 by hakobaya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	key_event_handler(int keycode, void *param)
{
	t_fractol	*fractol;

	fractol = (t_fractol *)param;
	if (keycode == ESC)
	{
		mlx_destroy_window(fractol->mlx, fractol->win);
		exit(0);
	}
	return (0);
}

int	m_mouse_event_handler(int button, int x, int y, void *param)
{
	t_fractol	*mandel;

	(void)x;
	(void)y;
	mandel = (t_fractol *)param;
	if (button == SCROLL_UP)
		mandel->scale /= 0.9;
	if (button == SCROLL_DOWN)
		mandel->scale *= 0.9;
	if (button == ON_DESTROY)
		exit(0);
	zoom_mandel(mandel);
	return (0);
}

int	j_mouse_event_handler(int button, int x, int y, void *param)
{
	t_fractol	*julia;

	(void)x;
	(void)y;
	julia = (t_fractol *)param;
	if (button == SCROLL_UP)
		julia->scale /= 0.9;
	if (button == SCROLL_DOWN)
		julia->scale *= 0.9;
	zoom_julia(julia);
	return (0);
}

int	close_event_handler(void *param)
{
	t_fractol	*fractol;

	fractol = (t_fractol *)param;
	mlx_destroy_window(fractol->mlx, fractol->win);
	exit(0);
	return (0);
}
