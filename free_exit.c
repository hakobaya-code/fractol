/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_exit.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hakobaya <hakobaya@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/26 15:49:01 by hakobaya          #+#    #+#             */
/*   Updated: 2024/01/26 15:55:43 by hakobaya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	error_exit(int index)
{
	if (index == 0)
		perror("ERROR : Please enter the correct letter \n[Julia] or [Mandelbrot]\n");
	exit(0);
	if (index == 1) // init失敗時
		perror("ERROR : init has FAILED !!!!\n");
}

void	free_fractol(t_fractol *fractol)
{
	free(fractol);
	fractol = NULL;
}

void	free_exit(t_fractol *fractol)
{
	free_fractol(fractol);
	error_exit(1);
}
