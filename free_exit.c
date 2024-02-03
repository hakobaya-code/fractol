/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_exit.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hakobaya <hakobaya@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/26 15:49:01 by hakobaya          #+#    #+#             */
/*   Updated: 2024/02/03 20:01:18 by hakobaya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	error_handle(int index)
{
	if (index == INPUT_ERROR)
	{
		ft_putstr_fd("🚨ERROR🚨\nPLEASE ENTER THE CORRECT LETTER.\
		\n [Mandelbrot] or [Julia <num> <num>]\n", 2);
		ft_putstr_fd("If you want to make Juliaset, Reccomended values are\
		\nJulia	0.32 0.043\nJulia	0.273 0.0074\nJulia	-0.156 1.032\n", 1);
		exit(1);
	}
	if (index == ATOF_ERROR)
	{
		ft_putstr_fd("🚨ERROR🚨\nPLEASE ENTER THE CORRECT NUMBER.\
		\n*** -2.0 < INPUT NUMBER < 2.0 ***\n", 2);
		ft_putstr_fd("If you want to make Juliaset, Reccomended values are\
		\n Julia 0.32 0.043\nJulia 0.27334 0.00742\nJulia -0.15652 1.03225", 1);
		exit(1);
	}
	exit(0);
}

void	free_fractol(t_fractol *fractol)
{
	free(fractol);
	fractol = NULL;
}

void	free_exit(t_fractol *fractol)
{
	free_fractol(fractol);
	fractol = NULL;
	exit(1);
}
