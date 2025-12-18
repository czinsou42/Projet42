/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_fractol.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: czinsou <czinsou@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/09 19:13:12 by czinsou           #+#    #+#             */
/*   Updated: 2025/10/16 13:46:14 by czinsou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	draw_mandelbrot(t_data *d)
{
	int			x;
	int			y;
	int			iter;
	t_complex	c;

	y = 0;
	while (y < HEIGHT)
	{
		x = 0;
		while (x < WIDTH)
		{
			c = get_complex_coord(d, x, y);
			iter = mandelbrot_iter(c.re, c.im, MAX_ITER);
			my_mlx_pixel_put(d, x, y, get_color(iter, MAX_ITER));
			x++;
		}
		y++;
	}
}

void	draw_julia(t_data *d)
{
	int			x;
	int			y;
	int			iter;
	t_complex	z;

	y = 0;
	while (y < HEIGHT)
	{
		x = 0;
		while (x < WIDTH)
		{
			z = get_complex_coord(d, x, y);
			iter = julia_iter(z, d->c_re, d->c_im, MAX_ITER);
			my_mlx_pixel_put(d, x, y, get_color(iter, MAX_ITER));
			x++;
		}
		y++;
	}
}

void	draw_burningship(t_data *d)
{
	int			x;
	int			y;
	int			iter;
	t_complex	c;

	y = 0;
	while (y < HEIGHT)
	{
		x = 0;
		while (x < WIDTH)
		{
			c = get_complex_coord(d, x, y);
			iter = burningship_iter(c.re, c.im, MAX_ITER);
			my_mlx_pixel_put(d, x, y, get_color(iter, MAX_ITER));
			x++;
		}
		y++;
	}
}
