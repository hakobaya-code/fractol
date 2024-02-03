/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hakobaya <hakobaya@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/24 08:08:55 by hakobaya          #+#    #+#             */
/*   Updated: 2024/02/03 17:26:07 by hakobaya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

//int	create_trgb(int t, int r, int g, int b)
//{
//	return (t << 24 | r << 16 | g << 8 | b);
//}

//void	my_mlx_pixel_put(t_data *data, int x, int y, int color)
//{
//	char	*dst;

//	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
//	*(unsigned int*)dst = color;
//}

size_t	ft_strlen(const char *s)
{
	int		i;
	char	*str;

	i = 0;
	str = (char *)s;
	while (s[i] != '\0')
		i++;
	return ((size_t) i);
}

void	ft_putstr_fd(char *s, int fd)
{
	int	len;

	if (s == NULL)
		return ;
	len = ft_strlen(s);
	write(fd, s, len);
}

void	error_handle(int index)
{
	if (index == INPUT_ERROR)
	{
		ft_putstr_fd("ERROR :Please enter the correct letter\
		\n[Julia] or [Mandelbrot]\n", 2);
		exit(1);
	}
	if (index == ATOF_ERROR)
	{
		ft_putstr_fd("🚨ERROR🚨\nPLEASE ENTER THE CORRECT NUMBER.\
		\n*** -2.0 < INPUT NUMBER < 2.0 ***\n", 2);
		exit(1);
	}

	exit(0);
}

//void	fractol_init(t_fractol *fractol)
//{

//}

int	main(int argc, char **argv)
{
	double	real;
	double	imaginary;

	(void)argc;
	(void)argv;
	if (argc == 2 || !(ft_strncmp(argv[1], "Mandelbrot", 11)))
		mandelbrot();
	else if ((argc == 4 || !(ft_strncmp(argv[1], "Julia"), 6)))
	{
		real = ft_atof(argv[2]);
		imaginary = ft_atof(argv[3]);
		julia(real, imaginary);
	}
	else
		error_handle(INPUT_ERROR);
	return (0);
}
