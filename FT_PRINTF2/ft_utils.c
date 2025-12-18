/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: czinsou <czinsou@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/22 13:13:01 by czinsou           #+#    #+#             */
/*   Updated: 2025/06/27 14:25:20 by czinsou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putchar(char c)
{
	return (write(1, &c, 1));
}

int	ft_putstr(char *str)
{
	int	i;

	i = 0;
	if (!str)
		return (write(1, "(null)", 6));
	while (str[i])
	{
		write(1, &str[i], 1);
		i++;
	}
	return (i);
}

int	ft_putnbr(int n)
{
	char	c;
	int		count;

	count = 0;
	if (n == -2147483648)
		return (write(1, "-2147483648", 11));
	else
	{
		if (n < 0)
		{
			count += write(1, "-", 1);
			n = -n;
		}
		if (n >= 10)
			count += ft_putnbr(n / 10);
		c = (n % 10) + '0';
		count += write(1, &c, 1);
	}
	return (count);
}

int	ft_putunsigned(unsigned int n)
{
	char	c;
	int		count;

	count = 0;
	if (n >= 10)
		count += ft_putnbr(n / 10);
	c = (n % 10) + '0';
	count += write(1, &c, 1);
	return (count);
}

int	ft_putnbr_base(unsigned long n, char *base)
{
	int	count;
	int	base_len;

	count = 0;
	base_len = 0;
	while (base[base_len])
		base_len++;
	if (n >= (unsigned long)base_len)
		count += ft_putnbr_base(n / base_len, base);
	count += write(1, &base[n % base_len], 1);
	return (count);
}
