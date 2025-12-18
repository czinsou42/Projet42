/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: czinsou <czinsou@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/06 15:18:58 by czinsou           #+#    #+#             */
/*   Updated: 2025/05/06 19:23:29 by czinsou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	size_t				i;
	const unsigned char	*ptr;

	i = 0;
	ptr = (const unsigned char *)s;
	while (i < n)
	{
		if (ptr[i] == (unsigned char )c)
			return ((void *)&ptr[i]);
		i++;
	}
	return (NULL);
}

/*int 	main()
{
	const char	*str = "Chaka";
	const char	*res1 = memchr(str, 'u', 4);
	const char	*res2 = ft_memchr(str, 'u', 4);
	printf("Resultat avec fonction d'origine :%s\n", res1);
	printf("Res avec fonction reecrite :%s\n", res2);
	return (0);
}*/
