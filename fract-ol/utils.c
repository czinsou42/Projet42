/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: czinsou <czinsou@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/09 19:08:35 by czinsou           #+#    #+#             */
/*   Updated: 2025/10/16 14:21:18 by czinsou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	my_mlx_pixel_put(t_data *d, int x, int y, int color)
{
	char	*dst;

	dst = d->addr + (y * d->line_len + x * (d->bpp / 8));
	*(unsigned int *)dst = color;
}

t_complex	get_complex_coord(t_data *d, int x, int y)
{
	t_complex	c;

	c.re = d->min_re + x * (d->max_re - d->min_re) / WIDTH;
	c.im = d->min_im + y * (d->max_im - d->min_im) / HEIGHT;
	return (c);
}

void	render(t_data *d)
{
	if (d->img != NULL)
		mlx_destroy_image(d->mlx, d->img);
	d->img = mlx_new_image(d->mlx, WIDTH, HEIGHT);
	d->addr = mlx_get_data_addr(d->img, &d->bpp, &d->line_len, &d->endian);
	if (d->fract_type == 1)
		draw_mandelbrot(d);
	else if (d->fract_type == 2)
		draw_julia(d);
	else if (d->fract_type == 3)
		draw_burningship(d);
	mlx_put_image_to_window(d->mlx, d->win, d->img, 0, 0);
}

void	zoom(t_data *d, double mouse_re, double mouse_im, double zoom_factor)
{
	double	range_re;
	double	range_im;
	double	min_range;

	range_re = d->max_re - d->min_re;
	range_im = d->max_im - d->min_im;
	min_range = 1e-14;
	range_re *= zoom_factor;
	range_im *= zoom_factor;
	if (range_re < min_range || range_im < min_range)
		return ;
	d->min_re = mouse_re + (d->min_re - mouse_re) * zoom_factor;
	d->max_re = mouse_re + (d->max_re - mouse_re) * zoom_factor;
	d->min_im = mouse_im + (d->min_im - mouse_im) * zoom_factor;
	d->max_im = mouse_im + (d->max_im - mouse_im) * zoom_factor;
}

int	get_color(int iter, int max_iter)
{
	int	colors[5];

	colors[0] = 0xff595e;
	colors[1] = 0xffca3a;
	colors[2] = 0x8ac926;
	colors[3] = 0x1982c4;
	colors[4] = 0x6a4c93;
	if (iter == max_iter)
		return (0x000000);
	return (colors[iter % 5]);
}
