/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hakobaya <hakobaya@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/03 14:00:13 by hakobaya          #+#    #+#             */
/*   Updated: 2024/02/03 17:02:21 by hakobaya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	calc_color(int color, int limit)
{
	int		r;
	int		g;
	int		b;
	double	per;

	per = (double)color / (double)limit;
	r = (int)(255 * per);
	g = (int)(255 * per) * 20;
	b = (int)(255 * per) * 20;
	return ((r << 16) | (g << 8) | b);
}
