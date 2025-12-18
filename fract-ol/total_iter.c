/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   total_iter.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: czinsou <czinsou@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/10 15:22:17 by czinsou           #+#    #+#             */
/*   Updated: 2025/10/14 13:16:25 by czinsou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	mandelbrot_iter(double c_re, double c_im, int max_iter)
{
	double	z_re;
	double	z_im;
	double	tmp;
	int		iter;

	z_re = 0;
	z_im = 0;
	iter = 0;
	while (z_re * z_re + z_im * z_im <= 4 && iter < max_iter)
	{
		tmp = z_re * z_re - z_im * z_im + c_re;
		z_im = 2 * z_re * z_im + c_im;
		z_re = tmp;
		iter++;
	}
	return (iter);
}

int	julia_iter(t_complex z, double c_re, double c_im, int max_iter)
{
	double	tmp;
	int		iter;

	iter = 0;
	while (z.re * z.re + z.im * z.im <= 4 && iter < max_iter)
	{
		tmp = z.re * z.re - z.im * z.im + c_re;
		z.im = 2 * z.re * z.im + c_im;
		z.re = tmp;
		iter++;
	}
	return (iter);
}

int	burningship_iter(double c_re, double c_im, int max_iter)
{
	double	z_re;
	double	z_im;
	double	tmp;
	int		iter;

	z_re = 0;
	z_im = 0;
	iter = 0;
	while (z_re * z_re + z_im * z_im <= 4 && iter < max_iter)
	{
		tmp = z_re * z_re - z_im * z_im + c_re;
		z_im = 2 * fabs(z_re) * fabs(z_im) + c_im;
		z_re = tmp;
		iter++;
	}
	return (iter);
}
