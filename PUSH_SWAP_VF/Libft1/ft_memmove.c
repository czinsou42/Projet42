/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: czinsou <czinsou@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/05 15:51:34 by czinsou           #+#    #+#             */
/*   Updated: 2025/05/19 12:53:32 by czinsou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	unsigned char			*d;
	const unsigned char		*s;
	size_t					i;

	d = (unsigned char *)dest;
	s = (const unsigned char *)src;
	if ((s == d) || (n == 0))
		return (dest);
	if (d < s)
	{
		i = 0;
		while (i < n)
		{
			d[i] = s[i];
			i++;
		}
	}
	else
	{
		while (n--)
			d[n] = s[n];
	}
	return (dest);
}

// int	main()
// {
// 	char	s[]= "Ceci est un test";
// 	char	d[] = "Berny";
// 	char *res = memmove( s+8, s, 4);
// 	printf("%s\n", res);
// 	printf("%s\n", (unsigned char *)ft_memmove(s+8, s, 4));
// 	return (0);
// }
