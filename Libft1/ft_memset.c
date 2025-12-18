/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: czinsou <czinsou@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/04 16:49:42 by czinsou           #+#    #+#             */
/*   Updated: 2025/05/06 19:24:02 by czinsou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *s, int c, size_t n)
{
	unsigned char	*p;

	p = (unsigned char *)s;
	while (n--)
		*p++ = (unsigned char)c;
	return (s);
}

/*int	main()
{
	char str[6]= "Chacha";
	printf("%s\n", str);
	memset(str, '8', 6);
	printf("%s\n", str);
	printf("%s", (char *)ft_memset(str, '1', 6));
	return (0);
}*/
