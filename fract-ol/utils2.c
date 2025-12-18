/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: czinsou <czinsou@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/09 19:16:44 by czinsou           #+#    #+#             */
/*   Updated: 2025/10/14 14:54:29 by czinsou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	ft_putchar_fd(char c, int fd)
{
	write(fd, &c, 1);
}

void	ft_putstr_fd(char *s, int fd)
{
	if (!s)
		return ;
	while (*s)
	{
		write(fd, s, 1);
		s++;
	}
}

void	ft_putendl_fd(char *s, int fd)
{
	ft_putstr_fd(s, fd);
	ft_putchar_fd('\n', fd);
}

int	ft_strcmp(char *s1, char *s2)
{
	int	i;

	i = 0;
	while ((s1[i] || s2[i]))
	{
		if (s1[i] != s2[i])
			return (s1[i] - s2[i]);
		i++;
	}
	return (0);
}

double	ft_atod(char *str)
{
	int		i;
	int		sign;
	double	res;
	double	div;

	i = 0;
	sign = 1;
	res = 0;
	div = 1;
	while ((str[i] == ' ') || (str[i] >= 9 && str[i] <= 13))
		i++;
	if ((str[i] == '-') || (str[i] == '+'))
		if (str[i++] == '-')
			sign = sign * -1;
	while ((str[i] >= '0') && (str[i] <= '9'))
		res = res * 10 + (str[i++] - '0');
	if (str[i] == '.')
	{
		while (str[++i] >= '0' && str[i] <= '9')
		{
			div /= 10;
			res += (str[i++] - '0') * div;
		}
	}
	return (res * sign);
}
