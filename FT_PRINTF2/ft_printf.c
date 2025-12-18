/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: czinsou <czinsou@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/22 17:58:44 by czinsou           #+#    #+#             */
/*   Updated: 2025/06/30 20:25:55 by czinsou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_check_format(char format, va_list args)
{
	if (format == 'c')
		return (ft_putchar(va_arg(args, int)));
	else if (format == 's')
		return (ft_putstr(va_arg(args, char *)));
	else if (format == 'd' || format == 'i')
		return (ft_putnbr(va_arg(args, int)));
	else if (format == 'p')
		return (ft_putptr(va_arg(args, void *)));
	else if (format == 'x')
		return (ft_putnbr_base(va_arg(args, unsigned int), "0123456789abcdef"));
	else if (format == 'X')
		return (ft_putnbr_base(va_arg(args, unsigned int), "0123456789ABCDEF"));
	else if (format == 'u')
		return (ft_putunsigned(va_arg(args, unsigned int)));
	else if (format == '%')
		return (write(1, "%", 1));
	return (0);
}

int	ft_printf(const char *s, ...)
{
	va_list	args;
	int		i;
	int		count;

	i = 0;
	count = 0;
	va_start(args, s);
	if (!s)
		return (0);
	while (s[i])
	{
		if ((s[i] == '%') && (s[i + 1]))
		{
			count += ft_check_format(s[i + 1], args);
			i++;
		}
		else
			count += write(1, &s[i], 1);
		i++;
	}
	va_end(args);
	return (count);
}

// int	main(void)
// {
// 	char			c;
// 	char			*str;
// 	int				num;
// 	unsigned int	u_num;
// 	int				*ptr;
// 	char			*null_ptr;

// 	c = 'A';
// 	str = "Bonjour, monde !";
// 	num = 42;
// 	u_num = 123456;
// 	ptr = &num;
// 	null_ptr = NULL;
// 	ft_printf("Caractère: %c\n", c);
// 	ft_printf("Chaîne: %s\n", str);
// 	ft_printf("Entier (d): %d\n", num);
// 	ft_printf("Entier (i): %i\n", num);
// 	ft_printf("Pointeur (p): %p\n", ptr);
// 	ft_printf("Pointeur NULL (p): %p\n", null_ptr);
// 	ft_printf("Hexa minuscule (x): %x\n", num);
// 	ft_printf ("Hexa majuscule (X): %X\n", num);
// 	ft_printf("Entier non signé (u): %u\n", u_num);
// 	ft_printf("Pourcentage: %%\n");
// 	ft_printf(0);
// 	return (0);
// }
