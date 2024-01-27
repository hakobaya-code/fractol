/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   julia.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hakobaya <hakobaya@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/25 22:23:59 by hakobaya          #+#    #+#             */
/*   Updated: 2024/01/27 19:35:38 by hakobaya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

double	ft_atof(char *str)
{
	double	ret;

	ret = 0.1;
	return (ret);
}

void	julia_calc(double real, double imaginary, int x, int y)
{
	return ;
}

void	julia(t_fractol *julia, char **argv, int limit)
{
	julia->mlx = mlx_init();
	if (julia->mlx == NULL)
		free_exit(julia);
	julia->win = mlx_new_window(julia->mlx, 800, 600, "Julia");
	if (argv[2] && argv[3])
	{
		julia->real = ft_atof(argv[2]); // atod?作る
		julia->imaginary = ft_atof(argv[3]);
	}
	while (limit-- > 0)
	{
		break ;
	}
	mlx_put_image_to_window(julia->mlx, julia->win, julia->x, julia->y); // あってる？
	mlx_key_hook(julia->win, key_hook, NULL);
	mlx_mouse_hook(julia->win, key_hook, NULL);
	mlx_destroy_window(julia->mlx, julia->win);
	mlx_loop(julia->mlx);
	return ;
}
