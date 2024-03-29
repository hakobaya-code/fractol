/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hakobaya <hakobaya@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/24 08:09:10 by hakobaya          #+#    #+#             */
/*   Updated: 2024/02/07 18:29:40 by hakobaya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# include "mlx/mlx.h"
# include <math.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

// key
# define ON_KEYDOWN 2
# define ON_MOUSEDOWN 4
# define ON_DESTROY 17
# define ESC 53

// mouse
# define SCROLL_DOWN 4
# define SCROLL_UP 5

// error
# define INPUT_ERROR 0
# define ATOF_ERROR 1

# define TRUE 1
# define FALSE 0

# define LIMIT 100
# define WIDTH 800
# define HEIGHT 800

typedef struct s_fractol
{
	void	*mlx;
	void	*win;

	double	real;
	double	im;
	double	a;
	double	b;

	double	scale;
	int		color;

	void	*img;
	char	*addr;
	int		bpp;
	int		line_len;
	int		endian;
}			t_fractol;

// hook
int			key_event_handler(int keycode, void *param);
int			m_mouse_event_handler(int button, int x, int y, void *param);
int			j_mouse_event_handler(int button, int x, int y, void *param);
int			close_event_handler(void *param);

// fractol
void		julia(double real, double imaginary);
void		draw_julia(t_fractol *j, double x, double y, int limit);
void		zoom_julia(t_fractol *j);
void		mandelbrot(void);
void		draw_mandel(t_fractol *m, int x, int y, int limit);
void		zoom_mandel(t_fractol *m);

// color
int			calc_color(int color, int limit);

// free
void		free_fractol(t_fractol *fractol);
void		free_exit(t_fractol *fractol);

// error
void		error_handle(int index);

// util
double		ft_atof(char *str);
int			ft_strncmp(const char *s1, const char *s2, size_t n);
void		ft_putstr_fd(char *s, int fd);
int			ft_strlen(char *str);
void		check_zero(char *str);

#endif
