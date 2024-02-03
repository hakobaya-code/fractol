/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hakobaya <hakobaya@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/24 08:08:55 by hakobaya          #+#    #+#             */
/*   Updated: 2024/02/03 20:07:37 by hakobaya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"



int	main(int argc, char **argv)
{
	double	real;
	double	imaginary;

	(void)argc;
	(void)argv;
	if (argc < 2)
		error_handle(INPUT_ERROR);
	if (argc == 2 && !(ft_strncmp(argv[1], "Mandelbrot", 11)))
		mandelbrot();
	else if (argc == 4 && !(ft_strncmp(argv[1], "Julia", 6)))
	{
		real = ft_atof(argv[2]);
		imaginary = ft_atof(argv[3]);
		julia(real, imaginary);
	}
	else
		error_handle(INPUT_ERROR);
	return (0);
}

//__attribute__((destructor))
//static void destructor() {
//    system("leaks -q fractol");
//}