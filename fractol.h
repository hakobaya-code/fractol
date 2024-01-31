/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hakobaya <hakobaya@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/24 08:09:10 by hakobaya          #+#    #+#             */
/*   Updated: 2024/01/31 20:38:07 by hakobaya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# include "minilibx-linux/mlx.h"
# include <stdio.h>
# include <math.h>
# include <unistd.h>
# include <stdlib.h>

# define KeyPress 2
# define ButtonPress 3
# define ON_MOUSEDOWN 4
# define FocusIn 9
# define FocusOut 10
# define ON_DESTROY 17
# define ESC 53

# define INPUT_ERROR 0
# define ATOF_ERROR 1

# define TRUE 1
# define FALSE 0

# define LIMIT 100


typedef struct	s_fractol {
	void	*mlx;        // MiniLibXの接続
	void	*win;        // ウィンドウ

	double	real;
	double	imaginary;
	double	a;
	double	b;

	double	zoom_factor;
	int		color;

	void	*img;        // 画像
	char	*addr;       // 画像データ
	int		bits_per_pixel; // 1ピクセルあたりのビット数
	int		line_length;    // 1行あたりのバイト数
	int		endian;         // エンディアン情報
}				t_fractol;

// hook
int		key_hook(int keycode, void *param);
int		mouse_hook(int button, int x, int y, void *param);

// fractol
void	julia(double real, double imaginary);
void	mandelbrot(void);

// free
void	free_fractol(t_fractol *fractol);

// error
void	error_handle(int index);

// util
double	ft_atof(char *str);

#endif
