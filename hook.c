/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hook.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hakobaya <hakobaya@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/25 21:58:10 by hakobaya          #+#    #+#             */
/*   Updated: 2024/01/25 21:58:29 by hakobaya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	key_hook(int keycode, void *param)
{
	// キーイベントが発生したときの処理
	printf("key\n");
	return (0);
}

int	mouse_hook(int button, int x, int y, void *param)
{
	// マウスクリックイベントが発生したときの処理
	printf("click\n");
	return (0);
}