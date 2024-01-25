/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   julia.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hakobaya <hakobaya@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/25 22:23:59 by hakobaya          #+#    #+#             */
/*   Updated: 2024/01/25 22:49:08 by hakobaya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	julia(t_fractol *julia, char **argv)
{
	julia->name = "julia";
	if (argv[2] && argv[3])
	{
		julia->real = ft_atoi(argv[2]);
		julia->imaginary = ft_atoi(argv[3]);
	}
	return ;
}
