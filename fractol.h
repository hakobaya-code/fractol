/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hakobaya <hakobaya@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/24 08:09:10 by hakobaya          #+#    #+#             */
/*   Updated: 2024/01/25 22:47:11 by hakobaya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# include <stdio.h>
# include "minilibx-linux/mlx.h"
# include <math.h>
# include <unistd.h>
# include <stdlib.h>

typedef struct	s_graphics {
	void	*mlx;        // MiniLibXの接続
	void	*win;        // ウィンドウ
	void	*img;        // 画像
	char	*addr;       // 画像データ
	int		bits_per_pixel; // 1ピクセルあたりのビット数
	int		line_length;    // 1行あたりのバイト数
	int		endian;         // エンディアン情報
}				t_graphics;

typedef struct	s_fractol {
	char	*name;
	double	real;
	double	imaginary;
	double	z;
	double	c;
}				t_fractol;

// hook
int		key_hook(int keycode, void *param);
int		mouse_hook(int button, int x, int y, void *param);

// fractol
void	julia(t_fractol *julia, char **argv);
void	mandelbrot(t_fractol *mandelbrot, char **argv);

#endif
