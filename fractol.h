/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hakobaya <hakobaya@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/24 08:09:10 by hakobaya          #+#    #+#             */
/*   Updated: 2024/02/02 22:19:17 by hakobaya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# include "minilibx-linux/mlx.h"
# include <stdio.h>
# include <math.h>
# include <unistd.h>
# include <stdlib.h>

# define ON_KEYDOWN 2
# define ON_KEYUP 3
# define ON_MOUSEDOWN 4
# define ON_MOUSEUP 5
# define ON_MOUSEMOVE 6
# define FOCUS_IN 9
# define FOCUS_OUT 10
# define ON_EXPOSE 12
# define ON_DESTROY 17
# define ESC 53

// mouse
# define LEFT_CLICK 1
# define RIGHT_CLICK 2
# define MIDDLE CLICK 3
# define SCROLL_UP 4
# define SCROLL_DOWN 5

# define INPUT_ERROR 0
# define ATOF_ERROR 1

# define TRUE 1
# define FALSE 0

# define LIMIT 100

# define WIDTH 800
# define HEIGHT 800


typedef struct	s_fractol {
	void	*mlx;        // MiniLibXの接続
	void	*win;        // ウィンドウ

	double	real;
	double	im;
	double	a;
	double	b;

	double	zoom_factor;
	int		color;

	//int		x; // pixel動かす時用 初期値0
	//int		y; // pixel動かす時用
	void	*img;        // 画像
	char	*addr;       // 画像データ
	int		bpp; // 1ピクセルあたりのビット数
	int		line_len;    // 1行あたりのバイト数
	int		endian;         // エンディアン情報
}				t_fractol;

// hook
int		key_hook(t_fractol *fractol, int keycode);
int		mouse_hook(t_fractol *fractol, int mousecode);
int		zoom_hook(t_fractol *fractol, double ratio);
int		close_hook(t_fractol *fractol, int button, int x, int y);

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
