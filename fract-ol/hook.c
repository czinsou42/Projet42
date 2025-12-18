/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hook.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: czinsou <czinsou@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/09 19:25:45 by czinsou           #+#    #+#             */
/*   Updated: 2025/10/16 14:14:47 by czinsou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	move_view(int keycode, t_data *d)
{
	double	range_re;
	double	range_im;

	range_re = d->max_re - d->min_re;
	range_im = d->max_im - d->min_im;
	if (keycode == 65361)
	{
		d->min_re -= 0.1 * range_re;
		d->max_re -= 0.1 * range_re;
	}
	else if (keycode == 65363)
	{
		d->min_re += 0.1 * range_re;
		d->max_re += 0.1 * range_re;
	}
	else if (keycode == 65362)
	{
		d->min_im += 0.1 * range_im;
		d->max_im += 0.1 * range_im;
	}
	else if (keycode == 65364)
	{
		d->min_im -= 0.1 * range_im;
		d->max_im -= 0.1 * range_im;
	}
}

int	key_hook(int keycode, t_data *d)
{
	if (keycode == 65307)
		close_window(d);
	move_view(keycode, d);
	if (ft_strcmp("Mandelbrot", "") != 0)
		render(d);
	else
		render(d);
	return (0);
}

void	zoom_safe(t_data *d, double mouse_re, double mouse_im,
		double zoom_factor)
{
	double	range_re;
	double	range_im;
	double	new_range_re;
	double	new_range_im;

	range_re = d->max_re - d->min_re;
	range_im = d->max_im - d->min_im;
	new_range_re = range_re * zoom_factor;
	new_range_im = range_im * zoom_factor;
	d->min_re = mouse_re - (mouse_re - d->min_re) * zoom_factor;
	d->max_re = d->min_re + new_range_re;
	d->min_im = mouse_im - (mouse_im - d->min_im) * zoom_factor;
	d->max_im = d->min_im + new_range_im;
}

int	mouse_hook(int button, int x, int y, t_data *d)
{
	t_complex	mouse;

	mouse = get_complex_coord(d, x, y);
	if (button == 4)
		zoom_safe(d, mouse.re, mouse.im, 0.8);
	if (button == 5)
		zoom_safe(d, mouse.re, mouse.im, 1.25);
	if (ft_strcmp("Mandelbrot", "") != 0)
		render(d);
	else
		render(d);
	return (0);
}

int	close_window(t_data *d)
{
	mlx_destroy_image(d->mlx, d->img);
	mlx_destroy_window(d->mlx, d->win);
	mlx_destroy_display(d->mlx);
	free(d->mlx);
	exit(0);
	return (0);
}
