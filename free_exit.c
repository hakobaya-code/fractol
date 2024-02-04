/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_exit.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hakobaya <hakobaya@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/26 15:49:01 by hakobaya          #+#    #+#             */
/*   Updated: 2024/02/04 17:34:44 by hakobaya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	error_handle(int index)
{
	if (index == INPUT_ERROR)
	{
		ft_putstr_fd("🚨ERROR🚨\nPLEASE ENTER THE CORRECT LETTER.\
		\n\n./fractol Mandelbrot \n./fractol Julia <num> <num>\n\n", 2);
		ft_putstr_fd("*** If you want to make Juliaset ***\n	Reccomended values are\n\
		\n   1: Julia 0.32 0.043\n   2: Julia 0.27334 0.00742\n   3: Julia -0.15652 1.03225\
		\n\n************************************\n", 1);
		exit(1);
	}
	if (index == ATOF_ERROR)
	{
		ft_putstr_fd("🚨ERROR🚨\nPLEASE ENTER THE CORRECT NUMBER.\
		\n\n   🐩 -2.0 < INPUT NUMBER < 2.0 💭   \n\n", 2);
		ft_putstr_fd("*** If you want to make Juliaset ***\n	Reccomended values are\n\
		\n   1: Julia 0.32 0.043\n   2: Julia 0.27334 0.00742\n   3: Julia -0.15652 1.03225\
		\n\n************************************\n", 1);
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
