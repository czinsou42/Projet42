/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: czinsou <czinsou@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/09 19:16:03 by czinsou           #+#    #+#             */
/*   Updated: 2025/10/16 13:56:08 by czinsou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# include "minilibx-linux/mlx.h"
# include <math.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

# define WIDTH 800
# define HEIGHT 800
# define MAX_ITER 100

typedef struct s_data
{
	void	*mlx;
	void	*win;
	void	*img;
	char	*addr;
	int		bpp;
	int		line_len;
	int		endian;
	int		width;
	int		height;
	double	min_re;
	double	max_re;
	double	min_im;
	double	max_im;
	double	c_re;
	double	c_im;
	int		fract_type;
}			t_data;

typedef struct s_complex
{
	double	re;
	double	im;
}			t_complex;

void		my_mlx_pixel_put(t_data *d, int x, int y, int color);
t_complex	get_complex_coord(t_data *d, int x, int y);
void		render(t_data *d);
void		zoom(t_data *d, double mouse_re, double mouse_im,
				double zoom_factor);
void		draw_mandelbrot(t_data *d);
void		draw_julia(t_data *d);
void		move_view(int keycode, t_data *d);
int			mouse_hook(int button, int x, int y, t_data *d);
int			key_hook(int keycode, t_data *d);
int			ft_strcmp(char *s1, char *s2);
void		ft_putendl_fd(char *s, int fd);
int			get_color(int iter, int max_iter);
int			mandelbrot_iter(double c_re, double c_im, int max_iter);
int			julia_iter(t_complex z, double c_re, double c_im, int max_iter);
int			init_data(int argc, char **argv, t_data *d);
int			close_window(t_data *d);
double		ft_atod(char *str);
int			burningship_iter(double c_re, double c_im, int max_iter);
void		draw_burningship(t_data *d);

#endif
