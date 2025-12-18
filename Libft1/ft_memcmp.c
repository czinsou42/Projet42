/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: czinsou <czinsou@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/06 16:06:21 by czinsou           #+#    #+#             */
/*   Updated: 2025/05/15 18:00:00 by czinsou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	size_t				i;
	const unsigned char	*str1;
	const unsigned char	*str2;

	str1 = (const unsigned char *)s1;
	str2 = (const unsigned char *)s2;
	i = 0;
	while (i < n)
	{
		if (!(str1[i] == str2[i]))
			return (str1[i] - str2[i]);
		i++;
	}
	return (0);
}

/*int	main()
{
	const char *s1 = "Chacha";
        const char *s2 = "Chucky";
        printf("La rps avec la bonne fct est : %d\n", memcmp(s1, s2, 3));
        printf("La rps avec la fct reecrite est : %d\n", ft_memcmp(s1, s2, 3));
        return (0);
}*/
