/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mandelbrot.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hakobaya <hakobaya@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/25 22:26:03 by hakobaya          #+#    #+#             */
/*   Updated: 2024/01/25 22:48:47 by hakobaya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	mandelbrot(t_fractol *mandelbrot, char **argv)
{
	mandelbrot->name = "mandelbrot";
	if (argv[2] && argv[3])
	{
		mandelbrot->real = ft_atoi(argv[2]);
		mandelbrot->imaginary = ft_atoi(argv[3]);
	}
	return ;
}