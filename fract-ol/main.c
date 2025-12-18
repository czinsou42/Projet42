/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: czinsou <czinsou@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/09 19:00:17 by czinsou           #+#    #+#             */
/*   Updated: 2025/10/16 13:55:39 by czinsou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	init_data(int argc, char **argv, t_data *d)
{
	d->width = WIDTH;
	d->height = HEIGHT;
	d->min_re = -2.0;
	d->max_re = 1.0;
	d->min_im = -1.5;
	d->max_im = 1.5;
	d->img = NULL;
	d->fract_type = 0;
	if (ft_strcmp(argv[1], "Mandelbrot") == 0)
		d->fract_type = 1;
	else if (ft_strcmp(argv[1], "Julia") == 0)
	{
		d->fract_type = 2;
		d->c_re = -0.7;
		d->c_im = 0.27015;
		if (argc == 4)
		{
			d->c_re = ft_atod(argv[2]);
			d->c_im = ft_atod(argv[3]);
		}
	}
	else if (ft_strcmp(argv[1], "Burningship") == 0)
		d->fract_type = 3;
	return (0);
}

int	main(int argc, char **argv)
{
	t_data	d;

	if (argc < 2 || (ft_strcmp(argv[1], "Mandelbrot") != 0
			&& (ft_strcmp(argv[1], "Julia") != 0) && ft_strcmp(argv[1],
				"Burningship") != 0))
	{
		ft_putendl_fd("Usage: ./fractol Mandelbrot|Julia|Burningship", 2);
		return (1);
	}
	if (init_data(argc, argv, &d) != 0)
		return (1);
	d.mlx = mlx_init();
	d.win = mlx_new_window(d.mlx, WIDTH, HEIGHT, "Fract-ol");
	if (ft_strcmp(argv[1], "Mandelbrot") == 0)
		render(&d);
	else if (ft_strcmp(argv[1], "Julia") == 0)
		render(&d);
	else if (ft_strcmp(argv[1], "Burningship") == 0)
		render(&d);
	mlx_key_hook(d.win, key_hook, &d);
	mlx_mouse_hook(d.win, mouse_hook, &d);
	mlx_hook(d.win, 17, 0, close_window, &d);
	mlx_loop(d.mlx);
	return (0);
}
