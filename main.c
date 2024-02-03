/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hakobaya <hakobaya@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/24 08:08:55 by hakobaya          #+#    #+#             */
/*   Updated: 2024/02/03 19:01:09 by hakobaya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	error_handle(int index)
{
	if (index == INPUT_ERROR)
	{
		ft_putstr_fd("ERROR :Please enter the correct letter\
		\n[Julia] or [Mandelbrot]\n", 2);
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

int	main(int argc, char **argv)
{
	double	real;
	double	imaginary;

	(void)argc;
	(void)argv;
	if (argc < 2)
		error_handle(INPUT_ERROR);
	if (argc == 2 || !(ft_strncmp(argv[1], "Mandelbrot", 11)))
		mandelbrot();
	else if (argc == 4 || !(ft_strncmp(argv[1], "Julia", 6)))
	{
		real = ft_atof(argv[2]);
		imaginary = ft_atof(argv[3]);
		julia(real, imaginary);
	}
	else
		error_handle(INPUT_ERROR);
	return (0);
}

__attribute__((destructor))
static void destructor() {
    system("leaks -q fractol");
}